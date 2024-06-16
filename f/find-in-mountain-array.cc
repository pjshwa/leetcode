/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int peak;
    {
      int l = 0, r = mountainArr.length();
      while (l < r) {
        int m = (l + r) / 2;
        if (m > 0 && mountainArr.get(m - 1) > mountainArr.get(m)) r = m;
        else l = m + 1;
      }
      peak = l - 1;
    }

    // find in left chunk
    {
      int l = 0, r = peak + 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (mountainArr.get(m) < target) l = m + 1;
        else r = m;
      }
      if (l < peak + 1 && mountainArr.get(l) == target) return l;
    }

    // find in right chunk
    {
      int l = peak, r = mountainArr.length();
      while (l < r) {
        int m = (l + r) / 2;
        if (mountainArr.get(m) > target) l = m + 1;
        else r = m;
      }
      if (l < mountainArr.length() && mountainArr.get(l) == target) return l;
    }

    return -1;
  }
};
