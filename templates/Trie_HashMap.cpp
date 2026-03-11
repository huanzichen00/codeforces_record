#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Trie {
private:
    class Node {
    public:
        unordered_map<char, Node*> next;
        bool isEnd;

        Node() {
            isEnd = false;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // 插入字符串
    void insert(const string& word) {
        Node* cur = root;

        for (char c : word) {
            if (!cur->next.count(c)) {
                cur->next[c] = new Node();
            }
            cur = cur->next[c];
        }

        cur->isEnd = true;
    }

    // 查找完整单词
    bool search(const string& word) {
        Node* cur = root;

        for (char c : word) {
            if (!cur->next.count(c)) {
                return false;
            }
            cur = cur->next[c];
        }

        return cur->isEnd;
    }

    // 查找前缀
    bool startsWith(const string& prefix) {
        Node* cur = root;

        for (char c : prefix) {
            if (!cur->next.count(c)) {
                return false;
            }
            cur = cur->next[c];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << trie.search("apple") << endl;     // 1
    cout << trie.search("app") << endl;       // 1
    cout << trie.startsWith("ap") << endl;    // 1
}
