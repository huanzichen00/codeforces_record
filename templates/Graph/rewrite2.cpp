#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  string alienOrder(vector<string>& words) {
    vector<int> indegree(26, -1);
    for (string& w : words) {
      for (char c : w) {
        indegree[c - 'a'] = 0;
      }
    }
    vector<vector<int>> graph(26);
    for (int i = 0; i < (int)words.size() - 1; i++) {
      string& cur = words[i];
      string& next = words[i + 1];
      int len = min((int)cur.size(), (int)next.size());
      int j = 0;
      for (; j < len; j++) {
        if (cur[j] != next[j]) {
          graph[cur[j] - 'a'].push_back(next[j] - 'a'); 
          indegree[next[j] - 'a']++;
          break;
        }
      }

      if (j < (int)cur.size() && j == (int)next.size()) {
        return "";
      }
    }
    vector<int> queue(26);
    int l = 0, r = 0;
    // 避免出现环，所以统计kinds
    int kinds = 0;
    for (int i = 0; i < 26; i++) {
      if (indegree[i] != -1) {
        kinds++;
      }
      if (indegree[i] == 0) {
        queue[r++] = i;
      }
    }
    string ans;

    // 拓扑排序
    while (l < r) {
      int cur = queue[l++];
      ans.push_back((char)(cur + 'a'));
      for (int next : graph[cur]) {
        if (--indegree[cur] == 0) {
          queue[r++] = next;
        }
      }
    }
    return (int)ans.size() == kinds ? ans : "";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}
