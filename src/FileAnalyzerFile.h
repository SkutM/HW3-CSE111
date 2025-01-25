// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class FileAnalyzerFile {
 protected:
  std::unique_ptr<char[]> contents_;

 private:
  std::string filename_;
  size_t file_size_;
  static bool hasExtension(const std::string& filename,
                           const std::string& extension);

 public:
  std::string filename() const { return filename_; }
  size_t file_size() const { return file_size_; }
  FileAnalyzerFile(const std::string& filename,
                   const std::vector<std::string>& allowed_extensions = {});
  uint32_t ReadBigEndianInt32(const size_t& addr) const;
  uint32_t ReadLittleEndianInt32(const size_t& addr) const;
  uint32_t ReadLittleEndianInt16(const size_t& addr) const;
};
