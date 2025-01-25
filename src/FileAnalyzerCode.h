// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include "FileAnalyzerFile.h"
#include <string>
#include <stack>

class FileAnalyzerCode : public FileAnalyzerFile {
 public:
  // Constructor: Passes filename and allowed extensions to the base class
  FileAnalyzerCode(const std::string& filename);

  // Method to count non-empty lines
  int GetLines() const;

  // Method to check if parentheses are balanced
  bool CheckParentheses() const;
};
