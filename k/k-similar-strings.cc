#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  map<string, int> c;

  int kSimilarity(string A, string B) {
    int sz = A.size();

    if (c.count(B)) return c[B];

    int ans;
    if (sz == 0) ans = 0;
    else {
      if (A[0] == B[0]) ans = kSimilarity(A.substr(1), B.substr(1));
      else {
        int mv = 1e9;
        for (int i = 1; i < sz; i++) {
          if (B[i] == A[0]) {
            char tmp = B[0];
            B[0] = B[i];
            B[i] = tmp;
            mv = min(mv, 1 + kSimilarity(A.substr(1), B.substr(1)));
            B[i] = B[0];
            B[0] = tmp;
          }
        }
        ans = mv;
      }
    }

    c[B] = ans;
    return ans;
  }
};

int main() {
  string A, B;
  A = "abcdefabcdefabcdefabcd";
  B = "bcdefabcdefabcdefabacd";
  cout << (new Solution())->kSimilarity(A, B) << endl;

  A = "abc";
  B = "bca";
  cout << (new Solution())->kSimilarity(A, B) << endl;

  A = "abac";
  B = "baca";
  cout << (new Solution())->kSimilarity(A, B) << endl;

  A = "aabc";
  B = "abca";
  cout << (new Solution())->kSimilarity(A, B) << endl;
}
