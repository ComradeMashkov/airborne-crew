#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <SFML/Network.hpp>

namespace utils {

namespace aviation_handler {

class AviationHandler {
public:
    AviationHandler() {
        srand(static_cast<unsigned int>(time(0))); 
        ParseSettingsFile();
    }

    void Initialize() {
        GenerateJSON();
        ProcessAviationValues();
    }

private:
    const std::string settings_path = "../utils/aviation_settings.txt";
    std::string outfile_path;

public:
    size_t fcount;

    std::vector<std::string> flight_numbers;
    std::vector<std::string> departure_times;
    std::vector<std::string> arrival_times;
    std::vector<std::string> flight_statuses;

private:
    void ProcessAviationValues() {
        boost::property_tree::ptree pt;
        boost::property_tree::read_json(outfile_path, pt);

        for (const auto& element : pt) {
            const auto& child = element.second;
            flight_numbers.push_back(child.get<std::string>("flight_number"));
            departure_times.push_back(child.get<std::string>("departure_time"));
            arrival_times.push_back(child.get<std::string>("arrival_time"));
            flight_statuses.push_back(child.get<std::string>("flight_status"));
        }
    }

    void GenerateJSON() {
        std::ofstream outfile{ "../utils/aviation.json" };

        std::string buffer = "[";

        for (int i = 0; i < fcount; ++i) {
            std::string flight_number = GenerateRandomFlightNumber();
            std::string departure_time = GenerateRandomTime();
            std::string arrival_time = GenerateRandomTime();
            std::string flight_status = GenerateRandomFlightStatus();

            std::string flight = "{";
            flight += "\"flight_number\":\"" + flight_number + "\",";
            flight += "\"departure_time\":\"" + departure_time + "\",";
            flight += "\"arrival_time\":\"" + arrival_time + "\",";
            flight += "\"flight_status\":\"" + flight_status + "\"}";

            if (i != fcount - 1) {
                flight += ",";
            }

            buffer += flight;
        }

        buffer += "]";

        outfile << buffer;

        outfile.close();
    }

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

            fcount = std::stoi(params[0]);
            outfile_path = params[1];

            settings.close();
            return 0;
        }

        return -1;
    }

    std::string GenerateRandomString(size_t length) const {
        const std::string alphabet_numeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string result;

        for (int i = 0; i < length; ++i) {
            result += alphabet_numeric[rand() % alphabet_numeric.length()];
        }

        return result;
    }

    std::string GenerateRandomFlightNumber() const {
        const std::string letters = GenerateRandomString(2);
        const std::string numbers = std::to_string(rand() % 9000 + 1000);

        return letters + numbers;
    }

    std::string GenerateRandomTime() const {
        int hours = rand() % 24;
        int minutes = rand() % 60;

        return (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes);
    }

    std::string GenerateRandomFlightStatus() const {
        const std::array<std::string, 3> statuses = { "On Time", "Delayed", "Cancelled" };
        return statuses[rand() % 3];
    }
};

} // namespace aviation_handler

} // namespace utils