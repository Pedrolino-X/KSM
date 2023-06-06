#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include "KnowledgeUtils.h"
#include "LevenshteinFuzzyMatcher.h"
#include "TextFileIO.h"

//// �ָ��ַ���Ϊ����
//std::vector<std::string> splitString(const std::string& input) {
//    std::vector<std::string> result;
//    std::istringstream iss(input);
//    std::string word;
//    while (iss >> word) {
//        result.push_back(word);
//    }
//    return result;
//}
int main() {
    std::unordered_map<std::string, std::vector<std::string>> contentMap;

    // ʾ�����û���ӹؼ��ʺ�����
    std::cout << "������ؼ��ʣ�����ؼ����ÿո�ָ�����";
    std::string keywordInput;
    std::getline(std::cin, keywordInput);

    std::vector<std::string> keywords;
    std::istringstream iss(keywordInput);
    std::string keyword;
    while (iss >> keyword) {
        keywords.push_back(keyword);
    }

    std::cout << "���������ݣ�";
    std::string content;
    std::getline(std::cin, content);
    addContentAndKeyword(contentMap, keywords, content);

     //ʾ�����û���ӹؼ��ʺ�����
    std::vector<std::string> keywordst = { "APK", "ABCDEFGHIJKLMNOPQ" };
    std::string contentt = "�������ݲ���R";
    addContentAndKeyword(contentMap, keywordst, contentt);

    std::vector<std::string> keysec = { "EXE", "ABCDEFGHIJKLMNOPQR" };
    std::string contentsec = "�������ݺ�R";
    addContentAndKeyword(contentMap, keysec, contentsec);

    std::string filename = "data.txt";
    saveDataToTextFile(contentMap, filename);

    contentMap = loadDataFromTextFile(filename);

    saveDataToTextFile(contentMap, filename);
    // �������ݲ��ҹؼ���
    std::string targetContent = "WEWE IOP";
    std::vector<std::string> foundKeywords = findKeywordsByContent(contentMap, targetContent);

    std::cout << "�����������صĹؼ��ʣ�" << std::endl;
    if (!foundKeywords.empty()) {
        for (const std::string& keyword : foundKeywords) {
            std::cout << keyword << std::endl;
        }
    }
    else {
        std::cout << "δ�ҵ������������صĹؼ��ʡ�" << std::endl;
    }


    // ����������
    std::string targetKeyword = "ABCDEFGHIJKsslMNOP";
    std::vector<std::pair<double, std::string>> similarityList = searchKeywordByLevenshteinDistance(contentMap, targetKeyword);

    std::cout << "�����ƶȴӸߵ��͵Ĺؼ����б�" << std::endl;
    for (const auto& pair : similarityList) {
        std::cout << pair.second << " (���ƶ�: " << pair.first << ")" << std::endl << std::endl;
    }

    // ʾ�����޸Ĺؼ���
 //std::string oldKeyword = "Android";
 //std::string newKeyword = "Mobile";
 //modifyKeyword(contentMap, oldKeyword, newKeyword);



    //// ʾ�����޸�����
    //std::string ModifyKeyword = "Android";
    //std::string newContent = "�޸ĺ������...";
    //modifyContent(contentMap, ModifyKeyword, newContent);


    //// ʾ�������ӹؼ���
    //std::string targetContent = "�޸ĺ������...";
    //std::string addKeyword = "��׿";
    //addKeywordToContent(contentMap, targetContent, addKeyword);

    return 0;
}




//
//std::string newContent = "�µ�����..."; // �޸ĺ������
//std::string keywordToModify = "Android";
//
//if (contentMap.count(keywordToModify) > 0) {
//    contentMap[keywordToModify] = newContent;
//    std::cout << "�����ѳɹ��޸ġ�" << std::endl;
//}
//else {
//    std::cout << "δ�ҵ���ؼ���ƥ�����������" << std::endl;
//}
//
//
//std::string oldKeyword = "Android";
//std::string newKeyword = "Mobile";
//
//if (contentMap.count(oldKeyword) > 0) {
//    std::string content = contentMap[oldKeyword];  // ��ȡ�ɹؼ��ʵ�����
//    contentMap.erase(oldKeyword);                  // ɾ���ɹؼ��ʵĴ���
//    contentMap[newKeyword] = content;              // ����¹ؼ��ʺ�����
//    std::cout << "�ؼ����ѳɹ��޸ġ�" << std::endl;
//}
//else {
//    std::cout << "δ�ҵ��ɹؼ��ʶ�Ӧ����������" << std::endl;
//}
