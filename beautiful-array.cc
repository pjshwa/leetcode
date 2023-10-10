class Solution {
public:
  vector<int> beautifulArray(int n) {
    if (n == 1) return {1};

    int r = n / 2;
    int l = n - r;

    auto lv = beautifulArray(l), rv = beautifulArray(r);

    vector<int> ret;
    for (int e : lv) ret.emplace_back(2 * e - 1);
    for (int e : rv) ret.emplace_back(2 * e);

    return ret;
  }
};
