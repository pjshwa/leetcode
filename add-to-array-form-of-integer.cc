const int MAX = 1e4;

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> ans;
    reverse(num.begin(), num.end());

    int carry = 0;
    for (int i = 0; i <= MAX; i++) {
      int u = k % 10; k /= 10;
      int v = i < num.size() ? num[i] : 0;

      int s = u + v + carry;
      ans.push_back(s % 10);
      carry = s / 10;
    }

    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
