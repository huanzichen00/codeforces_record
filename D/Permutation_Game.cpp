#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string f(ll i, ll k, vector<ll> p, vector<ll> a);

void solve(ll n, ll k, vector<ll> p, vector<ll> a) {  
  cout << f(0, k, p, a);
}

ll main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll tt;
  cin >> tt;
  while (tt--) {
    ll n, k, Pb, Ps;
    cin >> n >> k >> Pb >> Ps;
    vector<ll> p, a;
    p.reserve(n);
    a.reserve(n);

    ll num;
    for (int i = 0; i < n; i++) {
      cin >> num;
      p.push_back(num);
    }
    for (int i = 0; i < n; i++) {
      cin >> num;
      p.push_back(num);
    }

    solve(n, k, p, a);
  }
}

string f(ll i, ll k, vector<ll> p, vector<ll> a) {
  string cur = 
  if (i >= k) return cur;
}
