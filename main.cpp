#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "KnowledgeUtils.h"
#include "LevenshteinFuzzyMatcher.h"
int main() {
    std::unordered_map<std::string, std::vector<std::string>> contentMap;

    // 示例：用户添加关键词和内容
    std::vector<std::string> keywords = { "APK", "ABCDEFGHIJKLMNOPQ" };
    std::string content = "测试内容不含R";
    addContentAndKeyword(contentMap, keywords, content);

    std::vector<std::string> keysec = { "EXE", "ABCDEFGHIJKLMNOPQR" };
    std::string contentsec = "测试内容含R";
    addContentAndKeyword(contentMap, keysec, contentsec);

    // 检索内容贴
    std::string targetKeyword = "ABCDEFGHIJKLMNOP";
    std::vector<std::pair<double, std::string>> similarityList = searchKeywordByLevenshteinDistance(contentMap, targetKeyword);

    std::cout << "按相似度从高到低的关键词列表：" << std::endl;
    for (const auto& pair : similarityList) {
        std::cout << pair.second << " (相似度: " << pair.first << ")" << std::endl << std::endl;
    }

    // 示例：修改关键词
 //std::string oldKeyword = "Android";
 //std::string newKeyword = "Mobile";
 //modifyKeyword(contentMap, oldKeyword, newKeyword);



    //// 示例：修改内容
    //std::string ModifyKeyword = "Android";
    //std::string newContent = "修改后的内容...";
    //modifyContent(contentMap, ModifyKeyword, newContent);


    //// 示例：增加关键词
    //std::string targetContent = "修改后的内容...";
    //std::string addKeyword = "安卓";
    //addKeywordToContent(contentMap, targetContent, addKeyword);

    return 0;
}




//
//std::string newContent = "新的内容..."; // 修改后的内容
//std::string keywordToModify = "Android";
//
//if (contentMap.count(keywordToModify) > 0) {
//    contentMap[keywordToModify] = newContent;
//    std::cout << "内容已成功修改。" << std::endl;
//}
//else {
//    std::cout << "未找到与关键词匹配的内容贴。" << std::endl;
//}
//
//
//std::string oldKeyword = "Android";
//std::string newKeyword = "Mobile";
//
//if (contentMap.count(oldKeyword) > 0) {
//    std::string content = contentMap[oldKeyword];  // 获取旧关键词的内容
//    contentMap.erase(oldKeyword);                  // 删除旧关键词的词条
//    contentMap[newKeyword] = content;              // 添加新关键词和内容
//    std::cout << "关键词已成功修改。" << std::endl;
//}
//else {
//    std::cout << "未找到旧关键词对应的内容贴。" << std::endl;
//}
