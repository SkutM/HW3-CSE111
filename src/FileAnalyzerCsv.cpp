#include "FileAnalyzerCsv.h"
#include <sstream>
#include <string>
#include <vector>

FileAnalyzerCsv::FileAnalyzerCsv(const std::string& filename)
    : FileAnalyzerFile(filename, {".csv"}) {
}

int FileAnalyzerCsv::GetRows() const {
    int count = 0;
    std::istringstream stream(std::string(contents_.get(), file_size()));
    std::string line;

    while (std::getline(stream, line)) {
        if (!line.empty()) {
            count++;
        }
    }

    return count;
}

int FileAnalyzerCsv::GetColumns() const {
    std::istringstream stream(std::string(contents_.get(), file_size()));
    std::string row;
    int max_cols = 0;

    while (std::getline(stream, row)) {
        if (!row.empty()) {
            int column_count = 0;
            std::istringstream row_stream(row);
            std::string column;

            while (std::getline(row_stream, column, ',')) {
                column_count++;
            }

            max_cols = std::max(max_cols, column_count);
        }
    }

    return max_cols
    
    
    
    ;
}


bool FileAnalyzerCsv::VerifyDimensions() const {
    std::string content(contents_.get(), file_size());
    std::istringstream fileStream(content);

    std::string line;
    size_t ecols = 0;
    bool line1 = true;

    while (std::getline(fileStream, line)) {

        // find_last_not_of
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        line.erase(0, line.find_first_not_of(" \t\r\n"));

        if (line.empty()) {
            continue;
        }

        std::istringstream lineStream(line);
        size_t cols = 0;
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            cols++;
        }

        if (line1) {
            ecols = cols;
            line1 = false;
        } else if (cols != ecols) {
            return false;
        }
    }

    return true;
}