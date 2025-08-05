class Solution {
public:
  int countHillValley(vector<int>& nums) {
    vector<int> V;
    for (int e : nums) {
      if (!V.empty() && V.back() == e) V.pop_back();
      V.push_back(e);
    }
    int N = V.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      int hl = i > 0 && V[i - 1] < V[i];
      int hr = i < N - 1 && V[i + 1] < V[i];
      int vl = i > 0 && V[i - 1] > V[i];
      int vr = i < N - 1 && V[i + 1] > V[i];
      ans += (hl && hr) || (vl && vr);
    }
    return ans;
  }
};
