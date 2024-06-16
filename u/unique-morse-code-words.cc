class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    set<string> u;
    string c2m[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    for (auto& word : words) {
      string cur = "";
      for (char& c : word) cur += c2m[c - 'a'];
      u.insert(cur);
    }

    return u.size();
  }
};
