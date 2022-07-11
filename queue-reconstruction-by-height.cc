class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    int n = people.size();
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[0] != b[0]) return a[0] > b[0];
      return a[1] < b[1];
    });

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) ans.insert(ans.begin() + people[i][1], people[i]);
    return ans;
  }
};
