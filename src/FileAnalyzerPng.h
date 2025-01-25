// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include "src/FileAnalyzerFile.h"

class FileAnalyzerPng : public FileAnalyzerFile {
 private:
 public:
  FileAnalyzerPng(const std::string& filename);
  uint32_t width() const;
  uint32_t height() const;
  static const std::vector<std::string> allowed_extensions;
};
