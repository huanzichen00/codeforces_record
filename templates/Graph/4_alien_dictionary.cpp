#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  string alienOrder(vector<string>& words) {
    // 入度表
    // -1 : 这个字符没出现过    
    //  0 : 这个字母出现过，但当前没有前驱
    vector<int> indegree(26, -1);

    // 先吧所有在 words 中出现过的字母标出来
    for (string& w : words) {
      for (char c : w) {
        indegree[ c - 'a'] = 0;
      }
    }

    // 动态邻接表
    vector<vector<int>> graph(26);

    // 根据相邻单词建立字母之间的先后关系
    for (int i = 0; i < (int)words.size(); i++) {
      string& cur = words[i];
      string& next = words[i + 1];

      int len = min((int)cur.size(), (int)next.size());
      int j = 0;

      // 找第一个不同的位置
      for (; j < len; j++) {
        if (cur[j] != next[j]) {
          // cur[j] < next[j];
          graph[cur[j] - 'a'].push_back(next[j] - 'a');
          indegree[next[j] - 'a']++;
          break;
        }
      }

      // 前缀冲突
      if (j < (int)cur.size() && j == (int)next.size()) {
        return "";
      }
    }
    // 数组模拟队列
    vector<int> queue(26);
    int l = 0, r = 0;

    // kinds : 实际出现过多少种字母
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
        if (--indegree[next] == 0) {
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
