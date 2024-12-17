#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;
typedef pair<pii, char> pos_dir;
typedef pair<int, pos_dir> dist_pos_dir;

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

  pii spos, epos;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == 'S')
        spos = {i, j};
      else if (g[i][j] == 'E')
        epos = {i, j};

  map<char, pii> dirs = {
      {'v', {1, 0}},
      {'^', {-1, 0}},
      {'>', {0, 1}},
      {'<', {0, -1}},
  };

  priority_queue<dist_pos_dir, vector<dist_pos_dir>, greater<dist_pos_dir>> pq;
  map<pos_dir, int> dist;
  map<pos_dir, pos_dir> parent;

  auto get_dist = [&](pii pos, char dir)
  {
    if (dist.find({pos, dir}) == dist.end())
      return INF;

    return dist[{pos, dir}];
  };

  char sdir = '>';
  pq.push({0, {spos, sdir}});
  dist[{spos, sdir}] = 0;

  while (!pq.empty())
  {
    auto [cdist, cposdir] = pq.top();
    pq.pop();

    auto [cpos, cdir] = cposdir;
    auto [ci, cj] = cpos;

    for (auto [ndir, ndirpos] : dirs)
    {
      auto [di, dj] = ndirpos;
      int ni = ci + di;
      int nj = cj + dj;
      pii npos = {ni, nj};

      if (g[ni][nj] != '#')
      {
        int weight = 1;
        if (ndir != cdir)
          weight += 1000;

        if (get_dist(npos, ndir) >= get_dist(cpos, cdir) + weight)
        {
          dist[{npos, ndir}] = get_dist(cpos, cdir) + weight;
          pq.push({dist[{npos, ndir}], {npos, ndir}});
          parent[{npos, ndir}] = {cpos, cdir};
        }
      }
    }
  }

  int min_dist = INF;
  for (auto [k, v] : dist)
  {
    auto [dpos, _] = k;
    if (dpos == epos)
      min_dist = min(min_dist, v);
  }

  cout << min_dist << nl;

  set<pii> vis;

  function<void(pii, char)> backtrack = [&](pii cpos, char cdir)
  {
    vis.insert(cpos);

    if (cpos == spos)
      return;

    auto [ci, cj] = cpos;
    int cdist = get_dist(cpos, cdir);

    for (auto [_, ndirpos] : dirs)
    {
      auto [di, dj] = ndirpos;
      int ni = ci + di;
      int nj = cj + dj;
      pii npos = {ni, nj};

      for (auto [ndir, _] : dirs)
      {
        int ndist = get_dist(npos, ndir);
        int weight = cdist - 1;
        if (ndir != cdir)
          weight -= 1000;

        if (weight == ndist)
          backtrack(npos, ndir);
      }
    }
  };

  char edir = 0;
  for (auto [k, v] : dist)
  {
    auto [dpos, ddir] = k;
    if (dpos == epos && v == min_dist)
      edir = ddir;
  }

  assert(edir != 0);

  backtrack(epos, edir);
  cout << vis.size() << nl;

  return 0;
}
