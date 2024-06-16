class Solution {
public:
  int minSetSize(vector<int>& arr) {
    map<int, int> t;
    for (int e : arr) t[e]++;

    vector<int> tv;
    for (auto p : t) tv.push_back(p.second);
    sort(tv.begin(), tv.end());
    reverse(tv.begin(), tv.end());

    int run = 0;
    for (int i = 0; i < tv.size(); i++) {
      if (2 * run >= arr.size()) return i;
      run += tv[i];
    }
    return tv.size();
  }
};
