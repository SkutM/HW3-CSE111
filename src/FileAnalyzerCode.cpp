#include "FileAnalyzerCode.h"
#include <sstream>
#include <stack>

FileAnalyzerCode::FileAnalyzerCode(const std::string& filename)
    : FileAnalyzerFile(filename, {".cpp", ".c"}) {}

        
int FileAnalyzerCode::GetLines() const {
    int count = 0;
    std::istringstream stream(std::string(contents_.get(), file_size()));
    std::string line;

    while (std::getline(stream, line)) {
        if (!line.empty()) {
            bool isWhitespace = true;
            for (char ch : line) {
                if (!std::isspace(ch)) {
                    isWhitespace = false;
                    break;
                }
            }
            if (!isWhitespace) {
                count++;
            }
        }
    }
    return count; 
}

bool FileAnalyzerCode::CheckParentheses() const {
    std::stack<char> parens;

    for (size_t i = 0; i < file_size(); i++) {
        char ch = contents_[i];

        // open brackets onto stack
        if (ch == '(' || ch == '[' || ch == '{') {
            parens.push(ch);
        } 
        else if (ch == ')' || ch == ']' || ch == '}') {
            // if stack empty = unbalanced
            if (parens.empty()) {
                return false;
            }

            // top of the stack matches?
            char open = parens.top();
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                return false;
            }

            // pop opening bracket
            parens.pop();
        }
    }

    return parens.empty();
}

