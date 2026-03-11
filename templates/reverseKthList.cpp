#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKthGroup(ListNode* head, int k) {
  ListNode* node = head;
  for (int i = 0; i < k; i++) {
    if (!node) return head;
    node = node->next;
  }

  ListNode* prev = nullptr;
  ListNode* cur = head;
  while (k--) {
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  head->next = reverseKthGroup(cur, k);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
