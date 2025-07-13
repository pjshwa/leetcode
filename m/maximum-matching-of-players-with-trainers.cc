class Solution {
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    int Pn = players.size(), Tn = trainers.size();
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    int i = 0, j = 0;
    while (i < Pn && j < Tn) {
      if (players[i] <= trainers[j]) ++i, ++j;
      else ++j;
    }
    return i;
  }
};
