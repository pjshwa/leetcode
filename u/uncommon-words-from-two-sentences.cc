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
  vector<string> uncommonFromSentences(string s1, string s2) {
    map<string, int> m1, m2;
    for (auto word : split(s1, ' ')) ++m1[word];
    for (auto word : split(s2, ' ')) ++m2[word];

    vector<string> ans;
    for (auto [word, count] : m1) {
      if (count == 1 && !m2.count(word)) ans.push_back(word);
    }
    for (auto [word, count] : m2) {
      if (count == 1 && !m1.count(word)) ans.push_back(word);
    }
    return ans;
  }
};
