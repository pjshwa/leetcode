class Solution {
public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ret; int cur = 1;
    for (int e : target) {
      while (e > cur) {
        ret.push_back("Push");
        ret.push_back("Pop");
        ++cur;
      }
      ret.push_back("Push");
      ++cur;
    }
    return ret;
  }
};
