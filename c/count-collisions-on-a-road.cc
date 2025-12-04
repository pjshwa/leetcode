class Solution {
public:
  int countCollisions(string directions) {
    int N = directions.size();
    int ans = N, i = 0;
    while (i < N && directions[i] == 'L') ++i;
    ans -= i; i = N - 1;
    while (i >= 0 && directions[i] == 'R') --i;
    ans -= (N - 1 - i);
    for (int i = 0; i < N; ++i) ans -= (directions[i] == 'S');
    return ans;
  }
};
