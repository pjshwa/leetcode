/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* new_head = new Node(head->val);

    map<Node*, int> omap;
    Node *cur = head;
    int i = 0;
    while (cur) {
      omap[cur] = i++;
      cur = cur->next;
    }

    int rid[i];
    cur = head, i = 0;
    while (cur) {
      rid[i++] = cur->random ? omap[cur->random] : -1;
      cur = cur->next;
    }

    cur = head, i = 0;
    Node *new_cur = new_head;
    while (1) {
      cur = cur->next;
      if (!cur) break;
      new_cur->next = new Node(cur->val);
      new_cur = new_cur->next;
    }

    map<int, Node*> nmap_inv;
    new_cur = new_head, i = 0;
    while (new_cur) {
      nmap_inv[i++] = new_cur;
      new_cur = new_cur->next;
    }

    new_cur = new_head, i = 0;
    while (new_cur) {
      if (rid[i] != -1) new_cur->random = nmap_inv[rid[i]];
      i++;
      new_cur = new_cur->next;
    }

    return new_head;
  }
};
