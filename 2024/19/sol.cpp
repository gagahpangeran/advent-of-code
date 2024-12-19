#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

vector<string> split(string s)
{
  istringstream iss(s);
  vector<string> v;
  string ss;

  while (getline(iss, ss, ','))
  {
    ss.erase(0, ss.find_first_not_of(" "));
    v.push_back(ss);
  }

  return v;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);

  auto base = split(s);

  auto solve = [&](string tar)
  {
    int n = tar.size();
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
      for (auto b : base)
      {
        int m = b.size();
        if (i >= m && equal(tar.begin() + i - m, tar.begin() + i, b.begin()))
          dp[i] += dp[i - m];
      }
    }

    return dp[n];
  };

  ll res1 = 0;
  ll res2 = 0;
  while (cin >> s)
  {
    ll cur = solve(s);
    res1 += (cur > 0);
    res2 += cur;
  }

  cout << res1 << nl;
  cout << res2 << nl;

  return 0;
}
