#pragma once
#include "json.hpp"


void saveDataToTextFile(const std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& filename);
std::unordered_map<std::string, std::vector<std::string>> loadDataFromTextFile(const std::string & filename);
