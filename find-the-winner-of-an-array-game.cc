class Solution {
public:
  int getWinner(vector<int>& arr, int k) {
    int n = arr.size();
    k = min(k, n);

    queue<int> wait;
    int winner = arr[0], winc = 0;
    for (int i = 1; i < n; ++i) wait.push(arr[i]);

    while (winc < k) {
      int a = winner, b = wait.front();
      wait.pop();
      if (a > b) {
        wait.push(b);
        ++winc;
      }
      else {
        wait.push(a);
        winner = b;
        winc = 1;
      }
    }

    return winner;
  }
};
