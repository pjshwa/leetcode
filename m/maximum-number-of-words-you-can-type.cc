class Solution {
  vector<string> split(const string &str, string delim) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(delim, start)) != string::npos) {
      tokens.push_back(str.substr(start, end - start));
      start = end + delim.size();
    }

    tokens.push_back(str.substr(start));
    return tokens;
  }

public:
  int canBeTypedWords(string text, string brokenLetters) {
    int ans = 0;
    for (auto word : split(text, " ")) {
      int ok = 1;
      for (auto c : brokenLetters) {
        for (auto t : word) ok &= (c != t);
      }
      ans += ok;
    }
    return ans;
  }
};
