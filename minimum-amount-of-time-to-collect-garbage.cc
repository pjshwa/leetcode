class Solution {
public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int N = garbage.size(), Ml = -1, Pl = -1, Gl = -1, ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += garbage[i].size();
      for (char c : garbage[i]) {
        if (c == 'M') Ml = i;
        else if (c == 'P') Pl = i;
        else if (c == 'G') Gl = i;
      }
    }

    for (int i = 0; i < N - 1; ++i) {
      ans += travel[i] * ((i < Ml) + (i < Pl) + (i < Gl));
    }
    return ans; 
  }
};
