class Solution {
public:
  int closestTarget(vector<string>& words, string target, int startIndex) {
    int N = words.size(), ans = N;
    for (int a = 0; a < N; ++a) {
      int i = (startIndex + a) % N, j = (startIndex - a + N) % N;
      if (words[i] == target || words[j] == target) return a;
    }
    return -1;
  }
};
