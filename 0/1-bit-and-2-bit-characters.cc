class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    reverse(bits.begin(), bits.end()); int f;
    while (!bits.empty()) {
      if (bits.back() == 0) f = 0, bits.pop_back();
      else {
        if (bits.size() < 2) return false;
        f = 1; bits.pop_back(); bits.pop_back();
      }
    }
    return f == 0;
  }
};
