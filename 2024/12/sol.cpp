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

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  map<pii, pii> mp;
  map<pii, map<pii, map<int, vector<int>>>> sides;

  vector<pii> nx = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  auto chk_bound = [&](int i, int j)
  {
    return 0 <= i && i < n && 0 <= j && j < m;
  };

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j])
        continue;

      queue<pii> q;
      q.push({i, j});

      char sym = g[i][j];
      pii par = {i, j};

      auto add_side = [&](pii dir, int i, int j)
      {
        if (dir == nx[0] || dir == nx[2])
          sides[dir][par][i].push_back(j);
        else
          sides[dir][par][j].push_back(i);
      };

      while (!q.empty())
      {
        auto [ci, cj] = q.front();
        q.pop();

        if (vis[ci][cj])
          continue;

        vis[ci][cj] = true;

        int fence = 0;
        for (auto [ni, nj] : nx)
        {
          int mi = ci + ni;
          int mj = cj + nj;

          if (chk_bound(mi, mj))
          {
            if (g[mi][mj] != sym)
            {
              fence++;
              add_side({ni, nj}, mi, mj);
            }

            if (g[mi][mj] == sym && !vis[mi][mj])
            {
              q.push({mi, mj});
            }
          }
          else
          {
            fence++;
            add_side({ni, nj}, mi, mj);
          }
        }

        mp[par].first++;
        mp[par].second += fence;
      }
    }
  }

  auto cnt_side = [](map<int, vector<int>> &sides)
  {
    int res = 0;
    for (auto &[k, s] : sides)
    {
      sort(s.begin(), s.end());

      int cnt = 1;
      int sz = s.size();
      if (sz > 1)
      {
        for (int i = 1; i < sz; i++)
        {
          if (s[i] - s[i - 1] > 1)
            cnt++;
        }
      }
      res += cnt;
    }

    return res;
  };

  int res = 0;
  int res2 = 0;
  for (auto [key, val] : mp)
  {
    auto [area, per] = val;
    res += area * per;

    int side = 0;
    for (auto &[k, s] : sides)
      side += cnt_side(s[key]);
    res2 += area * side;
  }
  cout << res << nl;
  cout << res2 << nl;

  return 0;
}
