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
  bool areSentencesSimilar(string sentence1, string sentence2) {
    deque<string> s1, s2;
    for (auto word : split(sentence1, ' ')) s1.push_back(word);
    for (auto word : split(sentence2, ' ')) s2.push_back(word);
    if (s1.size() < s2.size()) swap(s1, s2);

    while (!s1.empty() && !s2.empty() && s1.front() == s2.front()) {
      s1.pop_front();
      s2.pop_front();
    }
    while (!s1.empty() && !s2.empty() && s1.back() == s2.back()) {
      s1.pop_back();
      s2.pop_back();
    }
    return s2.empty();
  }
};
