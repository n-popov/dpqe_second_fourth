#include <map>
#include <fstream>
#include <iostream>
#include "json.hpp"

using nlohmann::json;

int main() {
    std::map<std::string, int> data = {
            {"1", 42},
            {"2", 12},
            {"3", 15},
            {"4", 11},
            {"5", 34},
            {"6", 0},
            {"7", 150},
            {"8", 1},
            {"9", 16},
            {"10", 81},
    };

    json data_as_json(data);

    std::string dumped = data_as_json.dump();
    std::cout << dumped << std::endl;

    std::fstream fout("../data.json", std::ios::out);

    fout << dumped;

    fout.close();
}