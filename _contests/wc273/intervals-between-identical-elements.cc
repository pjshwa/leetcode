class Solution {
  vector<int> inv[100001];
  int cur[100001];
  long long csum[100001];
public:
  vector<long long> getDistances(vector<int>& arr) {
    memset(csum, 0, sizeof(csum));
    memset(cur, 0, sizeof(cur));
    for (int i = 0; i < arr.size(); i++) {
      inv[arr[i]].push_back(i);
    }
    for (int i = 0; i < 100001; i++) {
      for (int j = 1; j < inv[i].size(); j++) {
        csum[i] += (inv[i][j] - inv[i][0]);
      }
    }

    vector<long long> ans;
    for (int i = 0; i < arr.size(); i++) {
      int e = arr[i];
      int idx = cur[e];
      ans.push_back(csum[e]);

      if (idx == inv[e].size() - 1) continue;
      else {
        cur[e]++;
        int diff = inv[e][cur[e]] - inv[e][idx];
        csum[e] += (long long)cur[e] * diff;
        csum[e] -= (long long)(inv[e].size() - cur[e]) * diff;
      }
    }

    return ans;
      
  }
};
