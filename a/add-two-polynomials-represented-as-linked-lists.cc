/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

using ll = long long;

class Solution {
public:
  PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
    map<int, ll> by_pw;

    PolyNode* p1 = poly1;
    PolyNode* p2 = poly2;
    while (p1) by_pw[p1->power] += p1->coefficient, p1 = p1->next;
    while (p2) by_pw[p2->power] += p2->coefficient, p2 = p2->next;

    vector<pair<int, ll>> v;
    for (auto& [pw, coef] : by_pw) {
      if (coef) v.push_back({pw, coef});
    }
    sort(v.begin(), v.end(), greater<>());

    PolyNode* head = new PolyNode();
    PolyNode* cur = head;
    for (auto& [pw, coef] : v) {
      cur->next = new PolyNode(coef, pw);
      cur = cur->next;
    }
    return head->next;
  }
};
