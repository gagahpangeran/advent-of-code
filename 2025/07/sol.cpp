#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  vector<string> g;

  while (cin >> s)
    g.push_back(s);

  int n = g.size();
  int m = g[0].size();

  set<int> pos;
  int start = -1;

  for (int i = 0; i < m; i++)
  {
    if (g[0][i] == 'S')
    {
      pos.insert(i);
      start = i;
    }
  }

  int res1 = 0;
  for (int i = 1; i < n; i++)
  {
    set<int> add_pos;
    set<int> remove_pos;
    for (int j = 0; j < m; j++)
    {
      if (g[i][j] == '^' && pos.find(j) != pos.end())
      {
        res1++;
        add_pos.insert(max(0, j - 1));
        add_pos.insert(min(m - 1, j + 1));
        remove_pos.insert(j);
      }
    }

    for (auto i : remove_pos)
      pos.erase(i);

    for (auto i : add_pos)
      pos.insert(i);
  }

  cout << res1 << nl;

  vector<vector<ll>> dp(n + 1, vector<ll>(m, 0));
  for (int j = 0; j < m; j++)
    dp[n][j] = 1;

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < m; j++)
    {
      ll res = 0;
      if (g[i][j] == '^')
      {
        if (j - 1 >= 0)
          res += dp[i + 1][j - 1];
        if (j + 1 < m)
          res += dp[i + 1][j + 1];
      }
      else
      {
        res += dp[i + 1][j];
      }
      dp[i][j] = res;
    }
  }

  assert(start != -1);

  ll res2 = dp[0][start];
  cout << res2 << nl;

  return 0;
}