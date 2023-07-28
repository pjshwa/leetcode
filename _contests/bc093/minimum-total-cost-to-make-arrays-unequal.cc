class Solution {
public:
  long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    map<int, int> t1, t2;
    for (int i = 0; i < n; i++) {
      t1[nums1[i]]++; t2[nums2[i]]++;
    }

    int maj_1 = -1, maj_2 = -1;
    for (auto& [k, v] : t1) {
      if (v > n / 2) maj_1 = k;
    }
    for (auto& [k, v] : t2) {
      if (v > n / 2) maj_2 = k;
    }
    if (maj_1 != -1 && maj_1 == maj_2) return -1;

    map<int, int> dmap;
    for (int i = 0; i < n; i++) {
      if (nums1[i] != nums2[i]) continue;
      dmap[nums1[i]]++;
    }
    int dc = 0, mc = 0;
    for (auto& [_, v] : dmap) dc += v, mc = max(mc, v);
  
    long long ans = 0;
    if (2 * mc > dc) {
      int x;
      for (auto& [k, v] : dmap) {
        if (v == mc) x = k;
      }

      int rc = dc - mc;
      vector<int> indices;
      for (int i = 0; i < n; i++) {
        if (nums1[i] != nums2[i]) continue;
        if (nums1[i] == x) {
          if (rc) {
            ans += i;
            rc--;
          }
          else indices.push_back(i);
        }
        else ans += i;
      }

      for (int i = 0; indices.size() && i < n; i++) {
        if (nums1[i] == nums2[i]) continue;
        if (nums1[i] == x || nums2[i] == x) continue;

        ans += i + indices.back();
        indices.pop_back();
      }

    }
    else {
      for (int i = 0; i < n; i++) {
        if (nums1[i] != nums2[i]) continue;
        ans += i;
      }
    }

    return ans;
  }
};
