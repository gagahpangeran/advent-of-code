#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef pair<ll, ll> pll;

map<pll, ll> memo;

ll solve(ll cur, ll depth)
{
  if (memo.find({cur, depth}) != memo.end())
    return memo[{cur, depth}];

  if (depth == 0)
  {
    memo[{cur, depth}] = 1;
    return 1;
  }

  int d = (int)log10(cur) + 1;

  ll res;
  if (cur == 0)
  {
    res = solve(1, depth - 1);
  }
  else if (d % 2 == 0)
  {
    int p = pow(10, d / 2);
    res = solve(cur / p, depth - 1) + solve(cur % p, depth - 1);
  }
  else
  {
    res = solve(cur * 2024, depth - 1);
  }

  memo[{cur, depth}] = res;

  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x;
  vector<ll> a;

  while (cin >> x)
    a.push_back(x);

  ll res = 0;
  for (auto cur : a)
    res += solve(cur, 25);

  cout << res << nl;

  ll res2 = 0;
  for (auto cur : a)
    res2 += solve(cur, 75);

  cout << res2 << nl;

  return 0;
}
