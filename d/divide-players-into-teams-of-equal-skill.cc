class Solution {
public:
  long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end()); int N = skill.size();
    long long ans = 0, sum = skill[0] + skill[N - 1];
    for (int i = 0; i < N / 2; ++i) {
      if (skill[i] + skill[N - i - 1] != sum) return -1;
      long long cur = skill[i];
      cur *= skill[N - i - 1];
      ans += cur;
    }
    return ans;
  }
};
