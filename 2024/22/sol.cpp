#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef tuple<ll, ll, ll, ll> forple;

ll process(ll num)
{
  ll nx = num * 64;
  num = nx ^ num;
  num = num % 16777216;

  nx = num / 32;
  num = nx ^ num;
  num = num % 16777216;

  nx = num * 2048;
  num = nx ^ num;
  num = num % 16777216;

  return num;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x;
  ll res = 0;
  vector<vector<ll>> nums;

  while (cin >> x)
  {
    int cnt = 2000;
    vector<ll> seq = {x % 10};
    while (cnt--)
    {
      x = process(x);
      seq.push_back(x % 10);
    }
    res += x;
    nums.push_back(seq);
  }

  cout << res << nl;

  vector<vector<ll>> changes;

  for (auto seq : nums)
  {
    vector<ll> ch;
    for (int i = 1; i < (int)seq.size(); i++)
      ch.push_back(seq[i] - seq[i - 1]);
    changes.push_back(ch);
  }

  map<forple, ll> mp;

  for (int i = 0; i < (int)changes.size(); i++)
  {
    auto ch = changes[i];
    set<forple> seen;

    for (int j = 3; j < (int)ch.size(); j++)
    {
      forple k = {ch[j - 3], ch[j - 2], ch[j - 1], ch[j]};
      if (seen.find(k) == seen.end())
      {
        mp[k] += nums[i][j + 1];
        seen.insert(k);
      }
    }
  }

  ll res2 = 0;
  for (auto &[k, v] : mp)
    res2 = max(res2, v);

  cout << res2 << nl;

  return 0;
}
