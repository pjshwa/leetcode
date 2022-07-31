class Solution {
public:
  int maximumGroups(vector<int>& grades) {
    long long n = grades.size();
    long long g = 1;
    while ((g + 1) * (g + 2) / 2 <= n) g++;
    return g;
  }
};
