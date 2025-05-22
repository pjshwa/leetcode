const int MAXN = 1e5;

class Solution {
  vector<int> A[MAXN];

public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size();
    for (auto& q : queries) A[q[0]].push_back(q[1]);

    vector<int> D(N + 1); int dt = 0, ans = queries.size();
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
      dt += D[i];
      for (int e : A[i]) pq.push(e);
      while (nums[i] > dt) {
        if (pq.empty() || pq.top() < i) return -1;
        int e = pq.top(); pq.pop();
        --D[e + 1]; ++dt; --ans;
      }
    }
    return ans;
  }
};
