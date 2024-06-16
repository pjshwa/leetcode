class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int z = strs[0].size();
    for (int i = 1; i <= strs[0].size(); i++) {
      int f = 1; char c = strs[0][i - 1];
      for (int j = 1; j < strs.size(); j++) {
        f &= strs[j][i - 1] == c;
        if (!f) break;
      }
      if (!f) {
        z = i - 1;
        break;
      }
    }

    return strs[0].substr(0, z);
  }
};
