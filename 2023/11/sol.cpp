#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  // NOTE: Change this size based on space size
  // For part 1 is 2 and for part 2 is 1e6
  ll SIZE = 1e6;
  SIZE--;

  vector<string> g;
  while (cin >> s)
    g.push_back(s);

  ll n = g.size();
  ll m = g[0].size();

  vector<ll> spr;
  for (ll i = 0; i < n; i++)
  {
    bool ok = true;
    for (ll j = 0; j < m; j++)
      ok = ok && g[i][j] == '.';
    if (ok)
      spr.push_back(i);
  }

  vector<ll> spc;
  for (ll i = 0; i < m; i++)
  {
    bool ok = true;
    for (ll j = 0; j < n; j++)
      ok = ok && g[j][i] == '.';
    if (ok)
      spc.push_back(i);
  }

  vector<pii> pos;
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      if (g[i][j] == '#')
      {
        ll si = lower_bound(spr.begin(), spr.end(), i) - spr.begin();
        ll sj = lower_bound(spc.begin(), spc.end(), j) - spc.begin();

        si *= SIZE;
        sj *= SIZE;

        pos.push_back({i + si, j + sj});
      }
    }
  }

  ll res = 0;
  for (ll i = 0; i < (ll)pos.size() - 1; i++)
  {
    for (ll j = i + 1; j < (ll)pos.size(); j++)
    {
      res += abs(pos[i].first - pos[j].first) +
             abs(pos[i].second - pos[j].second);
    }
  }

  cout << res << nl;

  return 0;
}