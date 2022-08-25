class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    multiset<char> u;
    for (char c : magazine) u.insert(c);
    for (char c : ransomNote) {
      if (u.count(c) > 0) u.erase(u.find(c));
      else return false;
    }
    return true;
  }
};
