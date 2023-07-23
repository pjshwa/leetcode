using ll = long long;

class Solution {
public:
  long long maxArrayValue(vector<int>& nums) {
    vector<ll> V;
    for (auto num : nums) V.push_back(num);
    
    while (V.size() > 1) {
      ll b1 = V.back(); V.pop_back();
      ll b2 = V.back(); V.pop_back();
      if (b2 <= b1) b2 += b1;
      V.push_back(b2);
    }
    return V[0];
  }
};
