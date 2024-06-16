class Solution {
public:
  int minimumKeypresses(string s) {
    priority_queue<int, vector<int>, greater<int>> avail;
    for (int i = 0; i < 9; ++i) for (int j = 1; j <= 3; ++j) avail.push(j);

    map<char, int> tal;
    for (char& c : s) ++tal[c];

    vector<int> occ;
    for (auto& [_, v] : tal) occ.push_back(v);
    sort(occ.begin(), occ.end(), greater<int>());

    int ans = 0;
    for (int o : occ) {
      int t = avail.top(); avail.pop();
      ans += t * o;
    }
    return ans;
  }
};
