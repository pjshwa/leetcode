class Solution {
public:
  char kthCharacter(int k) {
    string W = "a";
    while (W.size() < k) {
      string T = W;
      for (char& c : T) {
        if (c == 'z') c = 'a';
        else ++c;
      }
      W += T;
    }
    return W[k - 1];
  }
};
