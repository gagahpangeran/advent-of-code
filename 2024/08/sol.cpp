#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  vector<string> g;

  while (cin >> s)
    g.push_back(s);

  map<char, vector<pii>> sig_pos;

  int n = g.size();
  int m = g[0].size();

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] != '.')
        sig_pos[g[i][j]].push_back({i, j});

  auto chk_bound = [&](int i, int j)
  {
    return 0 <= i && i < n && 0 <= j && j < m;
  };

  set<pii> vis, vis2;
  for (auto [sig, pos] : sig_pos)
  {
    int sz = pos.size();
    if (sz <= 1)
      continue;

    for (int a = 0; a < sz - 1; a++)
    {
      for (int b = a + 1; b < sz; b++)
      {
        auto [ai, aj] = min(pos[a], pos[b]);
        auto [bi, bj] = max(pos[a], pos[b]);

        int di = bi - ai;
        int dj = bj - aj;

        int pi = ai - di, pj = aj - dj;
        if (chk_bound(pi, pj))
          vis.insert({pi, pj});

        int ni = bi + di, nj = bj + dj;
        if (chk_bound(ni, nj))
          vis.insert({ni, nj});

        int ci = ai, cj = aj;
        while (chk_bound(ci, cj))
        {
          vis2.insert({ci, cj});
          ci += di;
          cj += dj;
        }

        ci = bi, cj = bj;
        while (chk_bound(ci, cj))
        {
          vis2.insert({ci, cj});
          ci -= di;
          cj -= dj;
        }
      }
    }
  }

  cout << vis.size() << nl;
  cout << vis2.size() << nl;

  return 0;
}
