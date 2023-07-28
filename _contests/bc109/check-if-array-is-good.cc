class Solution {
public:
  bool isGood(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return false;
    N--;

    map<int, int> t;
    for (int e : nums) t[e]++;

    int f = 1;
    for (int i = 1; i <= N - 1; i++) f &= t[i] == 1;
    f &= t[N] == 2;
    return f;
  }
};
