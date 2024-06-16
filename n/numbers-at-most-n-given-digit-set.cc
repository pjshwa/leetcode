#include <bits/stdc++.h>
using namespace std;

class Solution {
  int w[11];
  bool de[10];
public:
  int atMostNGivenDigitSet(vector<string> digits, int n) {
    string str = to_string(n);
    int cur = 0, addend = digits.size();

    w[0] = 1;
    for (int i = 1; i <= 10; i++) w[i] = w[i - 1] * digits.size();
    memset(de, 0, sizeof(de));
    for (string& d : digits) de[d[0] - '0'] = true;

    int ans = 0;
    for (int i = 1; i < str.size(); i++) ans += w[i];

    for (int i = 0; i < str.size(); i++) {
      int d = str[i] - '0', wi = str.size() - 1 - i;
      for (int j = 1; j < d; j++) if (de[j]) ans += w[wi];

      if (!de[d]) break;
      else if (i == str.size() - 1) ans++;
    }
    return ans;
  }
};

int main() {
  cout << Solution().atMostNGivenDigitSet({ "1", "3", "5", "7" }, 777) << endl;
  cout << Solution().atMostNGivenDigitSet({ "1", "3", "5", "7" }, 100) << endl;
}
