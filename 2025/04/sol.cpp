#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

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

  auto cnt = [&](int i, int j)
  {
    int res = 0;
    for (int x = -1; x <= 1; x++)
    {
      for (int y = -1; y <= 1; y++)
      {
        int ni = i + x;
        int nj = j + y;

        if ((i == ni && j == nj) ||
            ni < 0 || ni >= n ||
            nj < 0 || nj >= m)
          continue;

        if (g[ni][nj] == '@')
          res++;
      }
    }
    return res;
  };

  auto execute = [&]()
  {
    vector<pair<int, int>> idx;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (g[i][j] == '@' && cnt(i, j) < 4)
        {
          res++;
          idx.push_back({i, j});
        }
      }
    }

    for (auto [i, j] : idx)
      g[i][j] = '.';

    return res;
  };

  bool first = true;

  int res = 0;
  for (;;)
  {
    int cur = execute();

    if (first)
    {
      cout << cur << nl;
      first = false;
    }

    res += cur;

    if (cur == 0)
      break;
  }

  cout << res << nl;

  return 0;
}