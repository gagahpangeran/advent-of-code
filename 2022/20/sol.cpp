#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define fi first
#define se second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

void p(vll &v)
{
  for (auto i : v)
    cout << i << " ";
  cout << nl;
}

void p(vector<pll> &v)
{
  for (auto &[i, j] : v)
    cout << "(" << i << ", " << j << ") ";
  cout << nl;
}

ll mod(ll a, ll b)
{
  return (a % b + b) % b;
};

void mixing(vll &v, ll t)
{
  ll n = v.size();

  vector<pll> u;
  pll zero;

  for (ll i = 0; i < n; i++)
  {
    if (v[i] == 0)
      zero = {v[i], i};

    u.push_back({v[i], i});
  }

  while (t--)
  {

    for (ll i = 0; i < n; i++)
    {
      ll pos = find(u.begin(), u.end(), pair{v[i], i}) - u.begin();
      ll npos = mod(pos + u[pos].fi, n - 1);

      pll cur = u[pos];

      vector<pll> nextu;
      for (ll j = 0; j < n; j++)
      {
        if (nextu.size() == npos)
          nextu.push_back(cur);

        if (u[j] != cur)
          nextu.push_back(u[j]);
      }

      assert(u.size() == nextu.size());
      u = nextu;
    }
  }

  ll zpos = find(u.begin(), u.end(), zero) - u.begin();

  ll res = 0;
  for (ll i = 1; i <= 3; i++)
  {
    ll t = mod(zpos + (i * 1e3), n);
    res += u[t].fi;
  }

  cout << res << nl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x;
  vll v;

  while (cin >> x)
    v.push_back(x);

  mixing(v, 1);

  const ll key = 811589153;
  for (ll i = 0; i < v.size(); i++)
    v[i] *= key;

  mixing(v, 10);

  return 0;
}