class Solution {
public:
  int countSeniors(vector<string>& details) {
    int ans = 0;
    for (auto& p : details) {
      int age = stoi(p.substr(11, 2));
      ans += age > 60;
    }
    return ans;
  }
};
