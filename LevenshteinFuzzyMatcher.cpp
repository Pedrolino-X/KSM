#include "LevenshteinFuzzyMatcher.h"

int calculateLevenshteinDistance(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;

    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
        }
    }

    return dp[m][n];
}


std::vector<std::pair<double, std::string>> searchKeywordByLevenshteinDistance(const std::unordered_map<std::string, std::vector<std::string>>& contentMap, const std::string& targetKeyword) {
    std::vector<std::pair<double, std::string>> similarityList;

    for (const auto& entry : contentMap) {
        const std::vector<std::string>& keywords = entry.second;

        for (const std::string& keyword : keywords) {
            if (keyword == targetKeyword) {
                double similarity = 1.0 - static_cast<double>(calculateLevenshteinDistance(keyword, targetKeyword)) / std::max(keyword.length(), targetKeyword.length());
                if (similarity >= 0.6 && similarity <= 1.0) {
                    similarityList.emplace_back(similarity, keyword);
                }
                break;  // Í£Ö¹¼ÌÐø¼ìË÷ÆäËû¹Ø¼ü´Ê
            }
        }
    }

    std::sort(similarityList.rbegin(), similarityList.rend());

    return similarityList;
}
