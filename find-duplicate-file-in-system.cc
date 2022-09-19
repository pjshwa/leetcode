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
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    map<string, vector<string>> m;
    for (auto& path : paths) {
      auto tokens = split(path, " ");
      string prefix = tokens[0];
      for (int i = 1; i < tokens.size(); i++) {
        auto file = split(tokens[i], "(");
        string filename = file[0];
        string content = file[1];

        m[content].push_back(prefix + "/" + filename);
      }
    }

    vector<vector<string>> ans;
    for (auto& [k, v] : m) {
      if (v.size() > 1) {
        ans.push_back(v);
      }
    }
    return ans;
  }
};
