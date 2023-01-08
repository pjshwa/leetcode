class Solution {
public:
  long long maxKelements(vector<int>& nums, int k) {
    long long ans = 0;
    priority_queue<int> max_heap;
    for (int num : nums) {
      max_heap.push(num);
    }

    while (k--) {
      int t = max_heap.top(); max_heap.pop();
      ans += t;

      max_heap.push((t - 1) / 3 + 1);
    }

    return ans;
  }
};
