class Solution {
public:
  string nearestPalindromic(string s) {
    int N = s.size(), i;

    string A = s, B = s, C = s;
    for (int i = 0; i < N / 2; ++i) C[N - 1 - i] = C[i];

    i = (N - 1) / 2;
    while (i >= 0 && A[i] == '0') A[i] = '9', --i;
    if (i == 0 && A[i] == '1') A = N > 1 ? string(N - 1, '9') : "0";
    else {
      --A[i];
      for (int i = 0; i < N / 2; ++i) A[N - 1 - i] = A[i];
    }

    i = (N - 1) / 2;
    while (i >= 0 && B[i] == '9') B[i] = '0', --i;
    if (i < 0) B = '1' + string(N, '0'), B[N] = '1';
    else {
      ++B[i];
      for (int i = 0; i < N / 2; ++i) B[N - 1 - i] = B[i];
    }

    string ans = ""; long long diff = LLONG_MAX;
    for (auto& c : {A, B, C}) {
      if (c == s) continue;
      long long d = abs(stoll(s) - stoll(c));
      if (d < diff || (d == diff && stoll(c) < stoll(ans))) ans = c, diff = d;
    }
    return ans;
  }
};
