class Solution {
public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> V; int N = nums1.size();

    set<int> L;
    for (int i = 0; i < N; i++) {
      V.push_back({nums2[i], nums1[i]});
      L.insert(-nums2[i]);
    }
    sort(V.begin(), V.end(), greater<pair<int, int>>());

    int i = 0; long long sum = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> W;
    for (int l : L) {
      l = -l;
      while (i < N && V[i].first >= l) {
        W.push(V[i].second);
        sum += V[i].second;
        i++;
      }
      while (W.size() > k) sum -= W.top(), W.pop();
      if (W.size() == k) ans = max(ans, sum * l);
    }
    return ans;
  }
};
