#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

void saveDataToTextFile(const std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto& entry : contentMap) {
        const std::string& content = entry.first;
        const std::vector<std::string>& keywords = entry.second;

        file << "Keywords: " << content << std::endl;
        file << "Content: ";
        for (const std::string& keyword : keywords) {
            file << keyword << ", ";
        }
        file << std::endl << std::endl;
    }

    file.close();
}

std::unordered_map<std::string, std::vector<std::string>> loadDataFromTextFile(const std::string& filename) {
    std::unordered_map<std::string, std::vector<std::string>> contentMap;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return contentMap;
    }

    std::string line;
    std::string currentContent;
    std::vector<std::string> currentKeywords;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "Keywords:") {
            if (!currentContent.empty()) {
                contentMap[currentContent] = currentKeywords;
                currentKeywords.clear();
            }
            std::string content;
            iss >> content;
            currentContent = content;
        }
        else if (prefix == "Content:") {
            std::string keyword;
            while (iss >> keyword) {
                // Remove trailing comma if present
                if (keyword.back() == ',') {
                    keyword.pop_back();
                }
                currentKeywords.push_back(keyword);
            }
        }
    }

    // Add the last entry
    if (!currentContent.empty()) {
        contentMap[currentContent] = currentKeywords;
    }

    file.close();

    return contentMap;
}
