#include "FileAnalyzerText.h"
#include <cctype>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <climits>

FileAnalyzerText::FileAnalyzerText(const std::string& filename)
    : FileAnalyzerFile(filename, {".txt"}) {}

std::vector<std::string> splitWords(const std::string& str) {
    std::istringstream stream(str);
    std::vector<std::string> words(
        std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{});
    return words;
}

std::vector<std::string> FileAnalyzerText::GetMostCommonWords() const {
    std::unordered_map<std::string, int> wordCounts;
    std::istringstream stream(std::string(contents_.get(), file_size()));
    std::string line;

    while (std::getline(stream, line)) {
        for (const auto& word : splitWords(line)) {
            wordCounts[word]++;
        }
    }

    int maxCount = 0;
    for (const auto& pair : wordCounts) {
        maxCount = std::max(maxCount, pair.second);
    }

    std::vector<std::string> mostCommon;
    for (const auto& pair : wordCounts) {
        if (pair.second == maxCount) {
            mostCommon.push_back(pair.first);
        }
    }

    return mostCommon;
}

std::vector<std::string> FileAnalyzerText::GetLeastCommonWords() const {
    std::unordered_map<std::string, int> wordCounts;
    std::istringstream stream(std::string(contents_.get(), file_size()));
    std::string line;

    while (std::getline(stream, line)) {
        for (const auto& word : splitWords(line)) {
            wordCounts[word]++;
        }
    }

    int minCount = INT_MAX;
    for (const auto& pair : wordCounts) {
        minCount = std::min(minCount, pair.second);
    }

    std::vector<std::string> leastCommon;
    for (const auto& pair : wordCounts) {
        if (pair.second == minCount) {
            leastCommon.push_back(pair.first);
        }
    }

    return leastCommon;
}

std::unordered_map<char, int> FileAnalyzerText::GetLetterCount() const {
    std::unordered_map<char, int> letterCounts;
    std::string content = std::string(contents_.get(), file_size());

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        letterCounts[ch] = 0;
    }

    for (char ch : content) {
        if (std::isalpha(ch)) {
            letterCounts[std::tolower(ch)]++;
        }
    }

    return letterCounts;
}




std::vector<std::pair<char, int>> FileAnalyzerText::GetLetterCountSorted() const {
    auto letterCounts = GetLetterCount();

    std::vector<std::pair<char, int>> sortedCounts(letterCounts.begin(), letterCounts.end());

    std::sort(sortedCounts.begin(), sortedCounts.end(),
          [](const auto& a, const auto& b) {
              if (a.second == b.second) {
                  return a.first < b.first;
              }
              return a.second > b.second;
          });

    return sortedCounts;
}

