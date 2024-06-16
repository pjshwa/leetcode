/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

using uint = unsigned int;

class Solution {
public:
  int guessNumber(int n) {
    uint left = 1, right = (uint)n + 1;
    while (left < right) {
      uint mid = (left + right) / 2;
      int res = guess(mid);
      if (res == 0) return mid;

      if (res == -1) right = mid;
      else left = mid + 1;
    }
    return left;
  }
};
