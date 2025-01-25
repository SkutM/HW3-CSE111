// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#include "src/FileAnalyzerFile.h"

#include <fstream>
#include <iostream>

FileAnalyzerFile::FileAnalyzerFile(
    const std::string& filename,
    const std::vector<std::string>& allowed_extensions)
    : filename_(filename) {
  bool valid_extension = 0;
  valid_extension |= (allowed_extensions.size() == 0);
  for (const auto& extension : allowed_extensions) {
    valid_extension |= hasExtension(filename, extension);
  }
  if (!valid_extension) {
    std::cerr << "Unsupported file extension." << std::endl;
    exit(1);
  }

  // Open the file
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  // Check if file is opened successfully
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  // Get the size of the file
  file_size_ = file.tellg();

  // Reset file pointer to the beginning
  file.seekg(0, std::ios::beg);

  // Allocate memory to store the contents of the file
  contents_ = std::make_unique<char[]>(file_size_);

  // Read the contents of the file into the allocated memory
  file.read(contents_.get(), file_size_);

  // Close the file
  file.close();
}

uint32_t FileAnalyzerFile::ReadBigEndianInt32(const size_t& addr) const {
  uint32_t out = 0;
  for (int i = 0; i < 4; i++) {
    out <<= 8;
    out |= (uint8_t)contents_[addr + i];
  }
  return out;
}

uint32_t FileAnalyzerFile::ReadLittleEndianInt32(const size_t& addr) const {
  uint32_t out = 0;
  for (int i = 3; i >= 0; i--) {
    out <<= 8;
    out |= (uint8_t)contents_[addr + i];
  }
  return out;
}

uint32_t FileAnalyzerFile::ReadLittleEndianInt16(const size_t& addr) const {
  uint32_t out = 0;
  for (int i = 1; i >= 0; i--) {
    out <<= 8;
    out |= (uint8_t)contents_[addr + i];
  }
  return out;
}

bool FileAnalyzerFile::hasExtension(const std::string& filename,
                                    const std::string& extension) {
  return (filename.size() >= extension.size()) &&
         (filename.compare(filename.size() - extension.size(), extension.size(),
                           extension) == 0);
}
