// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include "FileAnalyzerFile.h"
#include <string>
#include <vector>
#include <unordered_map>

class FileAnalyzerText : public FileAnalyzerFile {
 public:
 
  FileAnalyzerText(const std::string& filename);

  std::vector<std::string> GetMostCommonWords() const;

  std::vector<std::string> GetLeastCommonWords() const;

  std::unordered_map<char, int> GetLetterCount() const;

  std::vector<std::pair<char, int>> GetLetterCountSorted() const;
};
