// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include "FileAnalyzerFile.h"
#include <string>

class FileAnalyzerCsv : public FileAnalyzerFile {
 public:
  FileAnalyzerCsv(const std::string& filename);

  int GetRows() const;

  int GetColumns() const;

  bool VerifyDimensions() const;
};
