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

class Solution {
  bool startsWith(const string &s, const string &prefix) {
    return s.substr(0, prefix.size()) == prefix;
  }

public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    string ans = "";
    for (auto &word : split(sentence, " ")) {
      for (auto &root : dictionary) {
        if (startsWith(word, root)) {
          word = root;
          break;
        }
      }
      ans += word + " ";
    }
    ans.pop_back();
    return ans;
  }
};
