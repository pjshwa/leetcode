class Solution {

public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    
    int N = deck.size(), pt = 0;
    vector<int> ans(N);

    helper(0, 1, 0, pt, ans, deck, N);
    return ans;
  }

  void helper(int start, int step, int o, int& pt, vector<int>& ans, vector<int>& deck, int N) {
    if (pt == N) return;

    int cnt = 0, maxi, new_o = 0;
    for (int i = start; i < N; i += step) maxi = i;
    for (int i = start + o * step; i < N; i += 2 * step) {
      ans[i] = deck[pt++], cnt++;
      new_o |= (i == maxi);
    }

    helper(start + (1 - o) * step, step * 2, new_o, pt, ans, deck, N);
  }
};
