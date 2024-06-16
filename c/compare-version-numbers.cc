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
public:
  int compareVersion(string version1, string version2) {
    auto vtokens1 = split(version1, ".");
    auto vtokens2 = split(version2, ".");
    int n = max(vtokens1.size(), vtokens2.size());

    for (int i = 0; i < n; i++) {
      auto vr1 = i < vtokens1.size() ? stoi(vtokens1[i]) : 0;
      auto vr2 = i < vtokens2.size() ? stoi(vtokens2[i]) : 0;
      if (vr1 > vr2) return 1;
      if (vr1 < vr2) return -1;
    }

    return 0;
  }
};
