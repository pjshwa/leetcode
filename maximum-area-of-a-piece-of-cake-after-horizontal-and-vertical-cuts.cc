class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);
    verticalCuts.push_back(0);
    verticalCuts.push_back(w);

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int hz = horizontalCuts.size(), vz = verticalCuts.size();
    long long mh = 0, mw = 0;
    for (int i = 0; i < hz - 1; i++) mh = max(mh, (long long)horizontalCuts[i + 1] - horizontalCuts[i]);
    for (int i = 0; i < vz - 1; i++) mw = max(mw, (long long)verticalCuts[i + 1] - verticalCuts[i]);

    long long ans = (long long)mh * mw;
    return ans % 1000000007;
  }
};
