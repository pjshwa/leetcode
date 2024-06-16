class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    queue<char> qs[numRows];
    int x = 0, d = 1;
    for (char& c : s) {
      qs[x].push(c);
      x += d;
      if (x == 0 || x == numRows - 1) d = -d;
    }

    string out = "";
    for (int i = 0; i < numRows; i++) {
      while (!qs[i].empty()) {
        out += qs[i].front();
        qs[i].pop();
      }
    }

    return out;
  }
};
