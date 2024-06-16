class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    sort(flowers.begin(), flowers.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });
    set<int> people_s(people.begin(), people.end());

    priority_queue<int, vector<int>, greater<int>> end_times;
    map<int, int> fcnt;

    int Z = flowers.size(), i = 0;
    for (auto p : people_s) {
      while (i < Z && flowers[i][0] <= p) {
        end_times.push(flowers[i][1]);
        i++;
      }
      while (!end_times.empty() && end_times.top() < p) {
        end_times.pop();
      }
      fcnt[p] = end_times.size();
    }

    vector<int> ans;
    for (auto p : people) ans.push_back(fcnt[p]);
    return ans;
  }
};
