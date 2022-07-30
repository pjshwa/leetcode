class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans;
    int gfilter[26] = {0};

    for (auto& word : words2) {
      int filter[26] = {0};
      for (char& c : word) filter[c - 'a']++;
      for (int j = 0; j < 26; j++) gfilter[j] = max(gfilter[j], filter[j]);
    }

    for (auto& word : words1) {
      int tally[26] = {0};
      for (char& c : word) tally[c - 'a']++;

      bool ok = true;
      for (int j = 0; j < 26; j++) {
        if (tally[j] < gfilter[j]) {
          ok = false;
          break;
        }
      }

      if (ok) ans.push_back(word);
    }

    return ans;
  }
};
