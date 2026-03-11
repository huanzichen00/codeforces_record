#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Trie {
private :
  class Node {
    public:
      Node* next[26];
      int end;
      int pass;

      Node() {
        pass = 0;
        end = 0;
        for (int i = 0; i < 26; i++) {
          next[i] = nullptr;
        }
      }
  };

  Node* root;

public :
  Trie() {
    root = new Node();
  }

  // 插入单词
  void insert(const string& word) {
    Node* cur = root;
    cur->pass++;
    for (char ch : word) {
      int path = ch - 'a';
      if (cur->next[path] == nullptr) {
        cur->next[path] = new Node();
      }
      cur = cur->next[path];
      cur->pass++;
    }
    cur->end++;
  }
 
  int search(const string& word) {
    Node* cur = root;
    for (char ch : word) {
      int path = ch - 'a';
      if (cur->next[path] == nullptr) {
        return false;
      }
      cur = cur->next[path];
    }
    return cur->end;
  }

 int prefixNumber(const string& prefix) {
    Node* cur = root;
    for (char ch : prefix) {
      int path = ch - 'a';
      if (cur->next[path] == nullptr) {
        return 0;
      }
      cur = cur->next[path];
    }
    return cur->pass;
  }

  void erase(const string& word) {
    if (search(word) == 0) {
      return;
    }
    Node* cur = root;
    cur->pass--;
    for (char ch : word) {
      int path = ch - 'a';
      if (--cur->next[path]->pass == 0) {
        cur->next[path] = nullptr;
        return;
      }
      cur = cur->next[path];
    }
    cur->end--;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Trie trie;

  trie.insert("apple");

  
  return 0;
}
