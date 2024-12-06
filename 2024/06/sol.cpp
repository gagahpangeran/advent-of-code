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

  int n = g.size();
  int m = g[0].size();

  pii spos;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '^')
        spos = {i, j};

  vector<pii> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int cdir = 0;
  pii cpos = spos;

  map<pii, map<int, set<pii>>> mp;
  for (auto d : dirs)
    mp[d] = map<int, set<pii>>();

  set<pii> vis;
  vis.insert(cpos);

  for (;;)
  {
    auto [ci, cj] = cpos;
    auto [di, dj] = dirs[cdir];

    int ni = ci + di;
    int nj = cj + dj;

    if (!(0 <= ni && ni < n && 0 <= nj && nj < m))
      break;

    if (g[ni][nj] == '#')
      cdir = (cdir + 1) % 4;
    else
      cpos = {ni, nj};

    vis.insert(cpos);
  }

  cout << vis.size() << nl;

  vis.erase(spos);

  int inf = n * m;
  int cnt = 0;

  for (auto [mi, mj] : vis)
  {
    auto newg = g;
    newg[mi][mj] = '#';

    cdir = 0;
    cpos = spos;

    int step = 0;

    for (;;)
    {
      auto [ci, cj] = cpos;
      auto [di, dj] = dirs[cdir];

      int ni = ci + di;
      int nj = cj + dj;

      step++;

      if (step > inf)
      {
        cnt++;
        break;
      }

      if (!(0 <= ni && ni < n && 0 <= nj && nj < m))
        break;

      if (newg[ni][nj] == '#')
        cdir = (cdir + 1) % 4;
      else
        cpos = {ni, nj};
    }
  }

  cout << cnt << nl;

  return 0;
}
