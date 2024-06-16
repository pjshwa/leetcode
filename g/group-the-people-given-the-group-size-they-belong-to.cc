class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int N = groupSizes.size();
    vector<int> by_group_size[N + 1];
    for (int i = 0; i < N; ++i) {
      by_group_size[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> ans;
    for (int gs = 1; gs <= N; ++gs) {
      int iter_count = by_group_size[gs].size() / gs;

      for (int it = 0; it < iter_count; ++it) {
        vector<int> group; int rem = gs;

        while (rem--) {
          int peep = by_group_size[gs].back();
          by_group_size[gs].pop_back();
          group.push_back(peep);
        }
        ans.push_back(group);
      }
    }

    return ans;
  }
};
