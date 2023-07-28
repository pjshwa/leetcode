

class Solution {
  vector<string> split(const string &str, const char delimiter) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(delimiter, start)) != string::npos) {
      tokens.push_back(str.substr(start, end - start));
      start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
  }
public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> ans;
    for (auto word : words) {
      auto tokens = split(word, separator);
      for (auto token : tokens) {
        if (token.empty()) continue;
        ans.push_back(token);
      }
    }
    return ans;
  }
};
