const int MAX = 1e5;

class Solution {
  int t[MAX + 1];
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    memset(t, 0, sizeof(t));
    for (int e : changed) t[e]++;
    
    vector<int> ans;
    if (t[0] & 1) return {};
    for (int j = 0; j < t[0] / 2; j++) ans.push_back(0);

    for (int i = 1; i <= MAX; i++) {
      while (t[i]) {
        if (2 * i > MAX || t[2 * i] == 0) return {};
        t[i]--;
        t[2 * i]--;

        ans.push_back(i);
      }
    }

    return ans;
  }
};
