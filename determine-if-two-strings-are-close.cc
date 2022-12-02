class Solution {
public:
  bool closeStrings(string word1, string word2) {
    map<int, int> T1, T2;
    for (auto c : word1) T1[c]++;
    for (auto c : word2) T2[c]++;

    set<char> K1, K2; vector<int> V1, V2;
    for (auto [c, v] : T1) K1.insert(c), V1.push_back(v);
    for (auto [c, v] : T2) K2.insert(c), V2.push_back(v);
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());

    return K1 == K2 && V1 == V2;
  }
};
