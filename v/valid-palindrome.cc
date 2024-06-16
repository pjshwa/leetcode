class Solution {
public:
  bool isPalindrome(string s) {
    string new_string = "";
    for (char c : s) {
      if ('a' <= c && c <= 'z') new_string += c;
      else if ('0' <= c && c <= '9') new_string += c;
      else if ('A' <= c && c <= 'Z') new_string += c - 'A' + 'a';
    }

    int l = 0, r = new_string.size() - 1;
    while (l < r) {
      if (new_string[l] != new_string[r]) return false;
      l++; r--;
    }
    return true;
  }
};
