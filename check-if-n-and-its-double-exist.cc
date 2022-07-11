class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    map<int, int> t;
    for (int e : arr) t[e]++;
    if (t[0] >= 2) return true;
    for (int e : arr) if (e && t[e * 2]) return true;
    return false;
  }
};
