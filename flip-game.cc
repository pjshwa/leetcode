class Solution {
public:
  vector<string> generatePossibleNextMoves(string currentState) {
    int N = currentState.size(); vector<string> ans;
    for (int i = 0; i < N - 1; ++i) {
      char c1 = currentState[i], c2 = currentState[i + 1];
      if (c1 == '+' && c2 == '+') {
        string state = currentState;
        state[i] = state[i + 1] = '-';
        ans.push_back(state);
      }
    }
    return ans;
  }
};
