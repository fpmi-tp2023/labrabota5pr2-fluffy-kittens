#include "../includes/string_operations.h"

namespace kittens {
namespace utils {
vector<string> SplitString(string s) {
  vector<string> parts;
  string current_part = "";
  for (char c : s) {
    if (isspace(c)) {
      if (!current_part.empty()) {
        parts.push_back(current_part);
        current_part = "";
      }
    } else {
      current_part += c;
    }
  }
  if (!current_part.empty()) {
    parts.push_back(current_part);
  }
  return parts;
}

vector<string> SplitLine(string line, int line_width) {
  vector<string> words = SplitString(line);
  vector<string> lines;
  string current_line = "";
  for (auto &word : words) {
    if (current_line.empty()) {
      current_line = word;
    } else if (current_line.length() + word.length() + 1 <= line_width) {
      current_line += " " + word;
    } else {
      lines.push_back(current_line);
      current_line = word;
    }
  }
  if (!current_line.empty()) {
    lines.push_back(current_line);
  }
  return lines;
}
}  // namespace utils
}  // namespace kittens