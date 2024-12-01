#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<ll> a, b;
  ll x, y;

  map<ll, ll> cnt;

  while (cin >> x >> y)
  {
    a.push_back(x);
    b.push_back(y);
    cnt[y]++;
  }

  assert(a.size() == b.size());

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll res = 0;
  ll res2 = 0;
  int sz = a.size();
  for (int i = 0; i < sz; i++)
  {
    res += abs(a[i] - b[i]);
    res2 += a[i] * cnt[a[i]];
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}