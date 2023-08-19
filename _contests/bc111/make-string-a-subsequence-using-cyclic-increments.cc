class Solution {
public:
  bool canMakeSubsequence(string str1, string str2) {
    vector<int> A, B;
    for (char c : str1) A.push_back(c - 'a');
    for (char c : str2) B.push_back(c - 'a');

    int j = 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] == B[j] || (A[i] + 1) % 26 == B[j]) j++;
      if (j == B.size()) return true;
    }
    return false;
  }
};
