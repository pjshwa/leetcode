class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    vector<string> words;
    istringstream iss(sentence); string word;
    while (iss >> word) words.push_back(word);

    for (int i = 0; i < words.size(); i++) {
      if (words[i].substr(0, searchWord.size()) == searchWord) {
        return i + 1;
      }
    }
    return -1;
  }
};
