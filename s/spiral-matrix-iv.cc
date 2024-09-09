/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> res(m, vector<int>(n, -1));
    int i = 0, j = 0, dir = 0; auto cur = head;

    auto oob = [&](int x, int y) {
      return x < 0 || x >= m || y < 0 || y >= n;
    };
    while (cur) {
      res[i][j] = cur->val;
      int ni = i + dx[dir], nj = j + dy[dir];
      if (oob(ni, nj) || res[ni][nj] != -1) {
        dir = (dir + 1) % 4;
        ni = i + dx[dir], nj = j + dy[dir];
      }
      i = ni, j = nj; cur = cur->next;
    }
    return res;
  }
};
