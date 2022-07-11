#include <bits/stdc++.h>
using namespace std;

class Solution {
  int sz1, sz2, lcs[501][501];
public:
  Solution(){
    memset(lcs, 0, sizeof(lcs));
  }

  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    sz1 = A.size();
    sz2 = B.size();

    for (int i = 1; i <= sz1; i++) {
      for (int j = 1; j <= sz2; j++) {
        if (A[i - 1] == B[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
        else lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
      }
    }

    return lcs[sz1][sz2];
  }
};

int main() {
  int a[3] = {1, 4, 2};
  int b[3] = {1, 2, 4};
  vector<int> A(a, a + 3);
  vector<int> B(b, b + 3);
  cout << (new Solution())->maxUncrossedLines(A, B) << endl;

  int a[5] = {2, 5, 1, 2, 5};
  int b[6] = {10,5,2,1,5,2};
  vector<int> A(a, a + 5);
  vector<int> B(b, b + 6);
  cout << (new Solution())->maxUncrossedLines(A, B) << endl;

  int a[6] = {1,3,7,1,7,5};
  int b[5] = {1,9,2,5,1};
  vector<int> A(a, a + 6);
  vector<int> B(b, b + 5);
  cout << (new Solution())->maxUncrossedLines(A, B) << endl;
}
