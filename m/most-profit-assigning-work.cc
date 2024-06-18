class Solution {
public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int N = difficulty.size();

    vector<pair<int, int>> jobs(N);
    for (int i = 0; i < N; ++i) jobs[i] = {difficulty[i], profit[i]};
    sort(jobs.begin(), jobs.end());

    sort(worker.begin(), worker.end()); int i = 0, maxp = 0, ans = 0;
    for (int e : worker) {
      while (i < N && jobs[i].first <= e) maxp = max(maxp, jobs[i++].second);
      ans += maxp;
    }
    return ans;
  }
};
