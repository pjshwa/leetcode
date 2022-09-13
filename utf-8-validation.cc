class Solution {
public:
  bool validUtf8(vector<int>& data) {
    int n = data.size(), i = 0;
    int mask[4] = {0b10000000, 0b11100000, 0b11110000, 0b11111000};
    int seqs[4] = {0b00000000, 0b11000000, 0b11100000, 0b11110000};
    int subm = 0b11000000, subs = 0b10000000;

    while (i < n) {
      int d = data[i];

      bool found = false;
      for (int j = 0; j < 4; j++) {
        if ((d & mask[j]) != seqs[j]) continue;
        found = true;

        if (i + j >= n) return false;
        for (int k = i + 1; k <= i + j; k++) {
          if ((data[k] & subm) != subs) return false;
        }

        i += j + 1;
        break;
      }

      if (!found) return false;
    }

    return true;
  }
};
