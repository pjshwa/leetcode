class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  long long countOfSubstrings(string word, int k) {
    int N = word.size(), l1 = 0, l2 = 0, ccnt1 = 0, ccnt2 = 0, C1[26] = {}, C2[26] = {};
    auto all_vowels = [](int C[26]) {
      return C['a' - 'a'] && C['e' - 'a'] && C['i' - 'a'] && C['o' - 'a'] && C['u' - 'a'];
    };
    auto inc1 = [&](int i, int d) {
      if (is_vowel(word[i])) C1[word[i] - 'a'] += d;
      else ccnt1 += d;
    };
    auto inc2 = [&](int i, int d) {
      if (is_vowel(word[i])) C2[word[i] - 'a'] += d;
      else ccnt2 += d;
    };

    long long ans = 0;
    for (int r = 0; r < N; ++r) {
      inc1(r, 1); inc2(r, 1);
      if (!all_vowels(C1) || ccnt1 < k) continue;
      while (ccnt1 > k) inc1(l1++, -1);
      while (all_vowels(C2) && ccnt2 >= k) inc2(l2++, -1);
      // cout << "l1=" << l1 << " l2=" << l2 << " r=" << r << endl;
      ans += max(0, l2 - l1);
    }
    return ans;
  }
};
