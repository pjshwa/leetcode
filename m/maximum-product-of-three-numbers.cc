class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    vector<int> pos, neg; int z = 0;
    for (int e : nums) {
      if (e > 0) pos.push_back(e);
      else if (e < 0) neg.push_back(e);
      else ++z;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    vector<int> V; int pz = pos.size(), nz = neg.size();
    if (pz < 6) V = pos;
    else {
      for (int i = 0; i < 3; ++i) {
        V.push_back(pos[i]);
        V.push_back(pos[pz - 1 - i]);
      }
    }
    if (nz < 6) V.insert(V.end(), neg.begin(), neg.end());
    else {
      for (int i = 0; i < 3; ++i) {
        V.push_back(neg[i]);
        V.push_back(neg[nz - 1 - i]);
      }
    }
    while (z--) V.push_back(0);

    int n = V.size(), ans = INT_MIN;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) for (int k = j + 1; k < n; ++k) {
      ans = max(ans, V[i] * V[j] * V[k]);
    }
    return ans;
  }
};
