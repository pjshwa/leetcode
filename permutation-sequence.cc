class Solution {
public:
  string getPermutation(int n, int k) {
    int P[n]; iota(P, P + n, 1);

    do {
      if (--k == 0) break;
    } while (next_permutation(P, P + n));

    string ret;
    for (int i = 0; i < n; i++) ret += '0' + P[i];
    return ret;
  }
};
