#pragma once

#include <array>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <curl/curl.h>
#include <fstream>

namespace utils {

namespace weather_handler {

class WeatherHandler {
public:
    WeatherHandler() {
        ParseSettingsFile();
        curl = curl_easy_init();
    }

    void Initialize() {
        SendRequest();
        ProcessWeatherValues();
    }

private:
    char is_day;
    int wind_angle;

public:
    std::string temperature;
    std::string pressure;
    std::string humidity;
    std::string wind_speed;
    std::string wind_dir;
    std::string times_of_day;

private:
    CURL* curl;
    CURLcode res;

    const std::string settings_path = "../utils/settings.txt";

    std::string api_key;
    std::string region;
    std::string outfile_path;

    std::string buffer;

    int ParseSettingsFile() {
        std::ifstream settings{ settings_path };

        if (settings.is_open()) {
            const char EQUAL_SIGN = '=';
            size_t i = 0;
            std::array<std::string, 3> params;

            std::string line;
            while (std::getline(settings, line)) {
                if (line[0] != '#') {
                    std::string param = line.substr(line.find(EQUAL_SIGN) + 2);
                    params[i++] = param;
                }
            }

            api_key = params[0];
            region = params[1];
            outfile_path = params[2];

            settings.close();
            return 0;
        }

        return -1;
    }

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
        size_t realsize = size * nmemb;
        buffer->append((char*)contents, realsize);
        return realsize;
    }

    void SendRequest() {
        std::ofstream outfile{ outfile_path };
        const std::string query = "https://api.weatherapi.com/v1/current.json?key=" + api_key + "&q=" + region + "&aqi=no";

        curl_easy_setopt(curl, CURLOPT_URL, query.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            outfile << "Failed to get data:" << curl_easy_strerror(res) << '\n';
        } 
        else {
            outfile << buffer << '\n';
        }

        curl_easy_cleanup(curl);

        outfile.close();
    }

    std::string GetWindDirection(int wind_angle) {
        std::array<std::string, 9> directions = { "С", "СВ", "В", "ЮВ", "Ю", "ЮЗ", "З", "СЗ", "С" };
        size_t index = static_cast<int>((wind_angle + 22.5) / 45) % 8;
        return directions[index];
    }

    void ProcessWeatherValues() {
        boost::property_tree::ptree pt;
        boost::property_tree::read_json("../utils/weather.json", pt);

        temperature = std::move(pt.get<std::string>("current.temp_c"));
        pressure = std::move(pt.get<std::string>("current.pressure_mb"));
        humidity = std::move(pt.get<std::string>("current.humidity"));
        wind_speed = std::move(pt.get<std::string>("current.wind_kph"));

        wind_angle = pt.get<int>("current.wind_degree");
        wind_dir = std::move(GetWindDirection(wind_angle));

        is_day = pt.get<char>("current.is_day");
        switch(is_day) {
            case '0':
                times_of_day = std::move("Вечер");
                break;
            case '1':
                times_of_day = std::move("День");
                break;
        }
    }
};

} // namespace weather_handler

} // namespace utils