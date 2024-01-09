#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <SFML/Network.hpp>

namespace utils {

namespace weather_handler {

class WeatherHandler {
public:
    WeatherHandler() {
        ParseSettingsFile();
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
    std::string timezone;

private:
    const std::string settings_path = "../utils/weather_settings.txt";

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
                std::string param = line.substr(line.find(EQUAL_SIGN) + 2);
                params[i++] = param;
            }

            api_key = params[0];
            region = params[1];
            outfile_path = params[2];

            settings.close();
            return 0;
        }

        return -1;
    }

    void SendRequest() {
        std::ofstream outfile{ outfile_path };

        sf::Http::Request request("/v1/current.json?key=" + api_key + "&q=" + region + "&aqi=no");
        sf::Http http("http://api.weatherapi.com");

        sf::Http::Response response = http.sendRequest(request);
        if (response.getStatus() == sf::Http::Response::Ok) {
            buffer = response.getBody();
            outfile << buffer << '\n';
        }
        else {
            outfile << "Request failed with status code: " << response.getStatus() << '\n';
        }

        outfile.close();
    }

    std::string GetWindDirection(int wind_angle) const {
        std::array<std::string, 9> directions = { "С", "СВ", "В", "ЮВ", "Ю", "ЮЗ", "З", "СЗ", "С" };
        size_t index = static_cast<int>((wind_angle + 22.5) / 45) % 8;
        return directions[index];
    }

    void ProcessWeatherValues() {
        boost::property_tree::ptree pt;
        boost::property_tree::read_json(outfile_path, pt);

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

        timezone = pt.get<std::string>("location.tz_id");
    }
};

} // namespace weather_handler

} // namespace utils