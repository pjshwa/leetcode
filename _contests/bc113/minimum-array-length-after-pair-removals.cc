class Solution {
public:
  int minLengthAfterRemovals(vector<int>& nums) {
    map<int, int> tal;
    for (int e : nums) tal[e]++;

    vector<int> freqs;
    for (auto& p : tal) freqs.push_back(p.second);
    sort(freqs.begin(), freqs.end());

    int msum = accumulate(freqs.begin(), freqs.end(), 0);
    int mmax = freqs.back();

    if (mmax * 2 <= msum) return msum & 1;
    else return mmax - (msum - mmax);
  }
};
