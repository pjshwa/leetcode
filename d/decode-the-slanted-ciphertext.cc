class Solution {
public:
  string decodeCiphertext(string encodedText, int rows) {
    int N = encodedText.size();
    int cols = N / rows; string ans;
    auto push = [&](int i, int j) {
      if (i >= rows || j >= cols) return;
      ans.push_back(encodedText[i * cols + j]);
    };
    for (int j = 0; j < cols; ++j) for (int i = 0; i < rows; ++i) {
      push(i, j + i);
    }
    while (!ans.empty() && ans.back() == ' ') ans.pop_back();
    return ans;
  }
};
