class Solution {
public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> Co(10), Cc(10);
    for (int d : digits) ++Cc[d];

    vector<int> ans;
    for (int c = 100; c < 1000; c += 2) {
      string s = to_string(c);
      for (char d : s) ++Cc[d - '0'];

      int ok = 1;
      for (int i = 0; i < 10; ++i) ok &= (Cc[i] <= Co[i]);
      if (ok) ans.push_back(c);
      for (char d : s) --Cc[d - '0'];
    }
    return ans;
  }
};
