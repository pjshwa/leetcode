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
  string reverseWords(string s) {
    auto tokens = split(s, ' ');
    string ans;
    for (auto token : tokens) {
      reverse(token.begin(), token.end());
      ans += token + ' ';
    }
    ans.pop_back();
    return ans;
  }
};
