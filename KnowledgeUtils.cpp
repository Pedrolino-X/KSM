#include "KnowledgeUtils.h"
//����ؼ���
void addKeywordToContent(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& targetContent, const std::string& addKeyword) {
    bool contentFound = false;

    for (auto& entry : contentMap) {
        std::vector<std::string>& keywords = entry.second;
        if (std::find(keywords.begin(), keywords.end(), targetContent) != keywords.end()) {
            if (std::find(keywords.begin(), keywords.end(), addKeyword) == keywords.end()) {
                keywords.push_back(addKeyword);
                contentFound = true;
                break;
            }
        }
    }

    if (contentFound) {
        std::cout << "�ɹ���ӹؼ��ʡ�" << std::endl;
    }
    else {
        std::cout << "δ�ҵ�������ƥ�����������" << std::endl;
    }
}
//��ӹؼ��ʺ�����
void addContentAndKeyword(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::vector<std::string>& keywords, const std::string& content) {
    for (const std::string& keyword : keywords) {
        contentMap[keyword] = { content, keyword };
    }
}

void modifyContent(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& keyword, const std::string& newContent) {
    bool keywordFound = false;

    for (auto& entry : contentMap) {
        std::vector<std::string>& keywords = entry.second;
        if (std::find(keywords.begin(), keywords.end(), keyword) != keywords.end()) {
            for (std::string& content : entry.second) {
                content = newContent;
            }
            keywordFound = true;
        }
    }

    if (keywordFound) {
        std::cout << "�����ѳɹ��޸ġ�" << std::endl;
    }
    else {
        std::cout << "δ�ҵ���ؼ���ƥ�����������" << std::endl;
    }
}


void modifyKeyword(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& oldKeyword, const std::string& newKeyword) {
    if (contentMap.count(oldKeyword) > 0) {
        std::vector<std::string> entry = contentMap[oldKeyword];
        contentMap.erase(oldKeyword);
        entry[1] = newKeyword;
        contentMap[newKeyword] = entry;
        std::cout << "�ؼ����ѳɹ��޸ġ�" << std::endl;
    }
    else {
        std::cout << "δ�ҵ��ɹؼ��ʶ�Ӧ����������" << std::endl;
    }
}

void deleteContent(std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& keyword) {
    if (contentMap.count(keyword) > 0) {
        contentMap.erase(keyword);
        std::cout << "���ݼ���ؼ����ѳɹ�ɾ����" << std::endl;
    }
    else {
        std::cout << "δ�ҵ���ؼ���ƥ�����������" << std::endl;
    }
}
