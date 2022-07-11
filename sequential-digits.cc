class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    for (int s = 1; s <= 8; s++) {
      long long x = s;
      int next = s + 1;
      while (next <= 10 && x <= high) {
        if (x >= low) ans.push_back(x);
        x = x * 10 + next;
        next++;
      }
    }
    sort(ans.begin(), ans.end());
    return ans;      
  }
};
