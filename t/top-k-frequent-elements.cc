class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto& p : freq) {
      pq.push({p.second, p.first});
      if (pq.size() > k) pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;      
  }
};
