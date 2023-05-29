#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "KnowledgeUtils.h"
#include "LevenshteinFuzzyMatcher.h"
int main() {
    std::unordered_map<std::string, std::vector<std::string>> contentMap;

    // ʾ�����û���ӹؼ��ʺ�����
    std::vector<std::string> keywords = { "APK", "ABCDEFGHIJKLMNOPQ" };
    std::string content = "�������ݲ���R";
    addContentAndKeyword(contentMap, keywords, content);

    std::vector<std::string> keysec = { "EXE", "ABCDEFGHIJKLMNOPQR" };
    std::string contentsec = "�������ݺ�R";
    addContentAndKeyword(contentMap, keysec, contentsec);

    // ����������
    std::string targetKeyword = "ABCDEFGHIJKLMNOP";
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
