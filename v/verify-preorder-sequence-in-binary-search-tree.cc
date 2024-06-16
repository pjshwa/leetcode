class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    if (preorder.size() <= 1) return true;

    int N = preorder.size(), f = N, s = preorder[0];
    for (int i = 1; i < N; ++i) if (preorder[i] > s) {
      f = i; break;
    }

    for (int i = 1; i < f; ++i) if (preorder[i] > s) return false;
    for (int i = f; i < N; ++i) if (preorder[i] < s) return false;

    auto PL = vector<int>(preorder.begin() + 1, preorder.begin() + f);
    auto PR = vector<int>(preorder.begin() + f, preorder.end());
    return verifyPreorder(PL) && verifyPreorder(PR);
  }
};
