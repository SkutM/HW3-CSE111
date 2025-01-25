// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include "FileAnalyzerFile.h"

class FileAnalyzerWav : public FileAnalyzerFile {
 public:
  FileAnalyzerWav(const std::string& filename);

  int GetBitrate() const;

  int GetChannels() const;
};
