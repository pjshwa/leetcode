class Solution {
public:
  bool winnerOfGame(string colors) {
    int Aturn = 0, Bturn = 0, N = colors.size();
    for (int i = 1; i < N - 1; ++i) {
      if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
        if (colors[i] == 'A') ++Aturn;
        else ++Bturn;
      }
    }
    return Aturn > Bturn;
  }
};
