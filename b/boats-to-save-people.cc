class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end());

    int sp = 0, ans = 0;
    for (int ep = n - 1; ep >= 0; ep--) {
      if (sp > ep) break;

      if (people[ep] + people[sp] <= limit) sp++;
      ans++;
    }

    return ans;
  }
};
