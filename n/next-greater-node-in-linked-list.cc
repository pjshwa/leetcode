class Solution {
public:
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> t;
    t.resize(10000);
    stack<pair<int, int>> s;

    auto n = head;
    int i = 0;
    while (1) {
      if (n == nullptr) break;

      while (!s.empty() && s.top().first < n->val) {
        t[s.top().second] = n->val;
        s.pop();
      }
      s.push({n->val, i});

      n = n->next;
      i++;
    }

    vector<int> ans;
    for (int j = 0; j < i; j++) ans.push_back(t[j]);
    return ans;
  }
};
