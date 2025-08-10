class Solution {
public:
  bool reorderedPowerOf2(int n) {
    vector<string> P; int pw = 1;
    while (pw <= 1e9) {
      P.push_back(to_string(pw));
      pw *= 2;
    }
    for (auto& s : P) sort(s.begin(), s.end(), greater<char>());
    string S = to_string(n);
    sort(S.begin(), S.end(), greater<char>());
    for (auto& s : P) if (s == S) return true;
    return false;
  }
};
