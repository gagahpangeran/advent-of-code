#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

const int INF = 1e9;

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

  auto chk_bound = [&](pii pos)
  {
    auto [i, j] = pos;
    return 0 <= i && i < n && 0 <= j && j < m;
  };

  vector<pii> dirs = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1},
  };

  pii spos, epos;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == 'S')
        spos = {i, j};
      else if (g[i][j] == 'E')
        epos = {i, j};

  queue<pii> q;
  map<pii, int> dist;
  map<pii, pii> parent;

  dist[epos] = 0;
  q.push(epos);

  auto get_dist = [&](pii pos)
  {
    auto [i, j] = pos;
    if (dist.find({i, j}) == dist.end())
      return INF;

    return dist[{i, j}];
  };

  while (!q.empty())
  {
    pii cpos = q.front();
    q.pop();

    auto [ci, cj] = cpos;

    for (auto [di, dj] : dirs)
    {
      int ni = ci + di;
      int nj = cj + dj;
      pii npos = {ni, nj};

      if (chk_bound(npos) && g[ni][nj] != '#' && get_dist(npos) == INF)
      {
        dist[npos] = dist[cpos] + 1;
        parent[npos] = cpos;
        q.push(npos);
      }
    };
  }

  int tar_dist = get_dist(spos);

  function<int(pii, int)> break_wall = [&](pii cpos, int cnt)
  {
    if (cnt <= 0)
      return get_dist(cpos);

    auto [ci, cj] = cpos;

    int res = INF;
    for (auto [di, dj] : dirs)
    {
      int ni = ci + di;
      int nj = cj + dj;
      pii npos = {ni, nj};

      if (chk_bound(npos))
      {
        res = min(res, 1 + get_dist(npos));
        res = min(res, 1 + break_wall(npos, cnt - 1));
      }
    }

    return res;
  };

  pii cpos = spos;
  int step = 0;

  map<int, int> saves;

  while (cpos != epos)
  {
    auto [ci, cj] = cpos;
    for (auto [di, dj] : dirs)
    {
      int ni = ci + di;
      int nj = cj + dj;
      pii npos = {ni, nj};

      if (chk_bound(npos) && g[ni][nj] == '#')
      {
        int bdist = step + break_wall(npos, 1);
        int diff = tar_dist - bdist - 1;
        if (diff > 0)
        {
          saves[diff]++;
        }
      }
    }

    step++;
    cpos = parent[cpos];
  }

  int min_save = 100;
  int res = 0;

  for (auto [k, v] : saves)
  {
    if (k >= min_save)
      res += v;
  }

  cout << res << nl;

  cpos = spos;
  step = 0;
  saves.clear();

  int max_cheat = 20;
  while (cpos != epos)
  {
    auto [ci, cj] = cpos;
    for (auto [tar, tdist] : dist)
    {
      auto [ti, tj] = tar;
      int manh_dist = abs(ti - ci) + abs(tj - cj);

      if (manh_dist <= max_cheat)
      {
        int bdist = step + manh_dist + tdist;
        int diff = tar_dist - bdist;
        saves[diff]++;
      }
    }

    step++;
    cpos = parent[cpos];
  }

  min_save = 100;
  int res2 = 0;
  for (auto [k, v] : saves)
  {
    if (k >= min_save)
      res2 += v;
  }

  cout << res2 << nl;

  return 0;
}
