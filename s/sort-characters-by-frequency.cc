class Solution {
public:
  string frequencySort(string s) {
    map<char, int> T;
    for (auto c : s) T[c]++;

    vector<pair<int, char>> V;
    for (auto p : T) V.push_back({p.second, p.first});
    sort(V.begin(), V.end(), greater<pair<int, char>>());

    string ret = "";
    for (auto p : V) {
      for (int i = 0; i < p.first; i++) ret += p.second;
    }
    return ret;
  }
};
