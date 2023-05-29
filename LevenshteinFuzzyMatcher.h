#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
int calculateLevenshteinDistance(const std::string& str1, const std::string& str2);
std::vector<std::pair<double, std::string>> searchKeywordByLevenshteinDistance(const std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& targetKeyword);