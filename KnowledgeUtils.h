#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


void addKeywordToContent(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& targetContent, const std::string& addKeyword);
void addContentAndKeyword(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::vector<std::string>& keywords, const std::string& content);
void modifyContent(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& keyword, const std::string& newContent);
void modifyKeyword(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& oldKeyword, const std::string& newKeyword);
void deleteContent(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& keyword);