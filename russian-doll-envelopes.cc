class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [] (vector<int>& a, vector<int>& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });

    vector<int> nums;
    for (auto& envelope : envelopes) nums.push_back(envelope[1]);

    int n = nums.size();

    vector<int> lis_vector;
    lis_vector.push_back(-(1e9 + 1));
    for (int i = 0; i < n; i++) {
      int next = nums[i];

      if (next < lis_vector[0]) lis_vector[0] = next;
      else if (next > lis_vector.back()) lis_vector.push_back(next);
      else {
        auto it = upper_bound(lis_vector.begin(), lis_vector.end(), next - 1);
        *it = next;
      }
    }

    return lis_vector.size() - 1;
  }
};
