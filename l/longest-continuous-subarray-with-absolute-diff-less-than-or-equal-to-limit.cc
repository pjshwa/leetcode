#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9 + 7;
const int MIN = 0;

struct SegMin {
  int flag;
  vector<int> t;

  void build(int N, vector<int>& nums) {
    for (flag = 1; flag < N; flag <<= 1);
    t.resize(2 * flag);

    for (int i = flag; i < flag + N; i++) t[i] = nums[i - flag];
    for (int i = flag - 1; i >= 1; i--) t[i] = min(t[i << 1], t[i << 1 | 1]);
  }
  void modify(int p, int value) {  // set value at position p
    for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
  }
  int query(int L, int R) {
    return query(L, R, 1, 1, flag);
  }
  int query(int L, int R, int n, int nL, int nR) {  // min on interval [L, R]
    if (R < nL || nR < L) return MAX;
    if (L <= nL && nR <= R) return t[n];

    int mid = (nL + nR) / 2;
    return min(query(L, R, n << 1, nL, mid), query(L, R, n << 1 | 1, mid + 1, nR));
  }
} seg_min;

struct SegMax {
  int flag;  // array size
  vector<int> t;

  void build(int N, vector<int>& nums) {
    for (flag = 1; flag < N; flag <<= 1);
    t.resize(2 * flag);

    for (int i = flag; i < flag + N; i++) t[i] = nums[i - flag];
    for (int i = flag - 1; i >= 1; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
  }
  void modify(int p, int value) {  // set value at position p
    for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
  }
  int query(int L, int R) {
    return query(L, R, 1, 1, flag);
  }
  int query(int L, int R, int n, int nL, int nR) {  // min on interval [L, R]
    if (R < nL || nR < L) return MIN;
    if (L <= nL && nR <= R) return t[n];

    int mid = (nL + nR) / 2;
    return max(query(L, R, n << 1, nL, mid), query(L, R, n << 1 | 1, mid + 1, nR));
  }
} seg_max;

class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    seg_min.build(n, nums);
    seg_max.build(n, nums);

    int a = 1, b = 1;
    int max_length = 0;

    while (b != n + 1) {
      int min_v = seg_min.query(a, b);
      int max_v = seg_max.query(a, b);

      // cout << "a: " << a << ", b: " << b << ", max_length: " << max_length << endl;
      // cout << "min_v: " << min_v << ", max_v: " << max_v << endl;

      if (max_v - min_v <= limit) {
        max_length = max(max_length, b - a + 1);
        b++;
      }
      else a++;
    }
    
    return max_length;
  }
};

int main() {
  Solution solution;

  vector<int> nums1{ 10,1,2,4,7,2 };
  cout << solution.longestSubarray(nums1, 5) << endl;

  vector<int> nums2{ 4,2,2,2,4,4,2,2 };
  cout << solution.longestSubarray(nums2, 0) << endl;
}
