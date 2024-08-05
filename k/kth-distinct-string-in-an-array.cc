class Solution {
public:
  string kthDistinct(vector<string>& arr, int k) {
    map<string, int> tal; int N = arr.size();
    for (int i = 0; i < N; ++i) ++tal[arr[i]];
    for (int i = 0; i < N; ++i) {
      if (tal[arr[i]] > 1) continue;
      if (--k == 0) return arr[i];
    }
    return "";
  }
};
