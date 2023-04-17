class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int L = *max_element(candies.begin(), candies.end());

    vector<bool> ret;
    for (auto& c : candies) ret.push_back(c + extraCandies >= L);
    return ret;
  }
};
