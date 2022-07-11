class Solution {
  int m[26];
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    memset(m, -1, sizeof(m));
    for (int i = 0; i < n; i++) m[s[i] - 'a'] = max(m[s[i] - 'a'], i);

    int li = 0;
    set<int> cur;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      cur.insert(s[i] - 'a');
      if (m[s[i] - 'a'] == i) cur.erase(s[i] - 'a');

      if (cur.size() == 0) {
        ans.push_back(i - li + 1);
        li = i + 1;
      }
    }

    return ans;
  }
};
