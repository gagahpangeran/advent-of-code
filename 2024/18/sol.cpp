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
  vector<pii> coor;

  while (cin >> s)
  {
    regex r(R"((\d+),(\d+))");
    smatch m;
    regex_match(s, m, r);
    int x = stoi(m[1]);
    int y = stoi(m[2]);
    coor.push_back({x, y});
  }

  int n = 71;
  int m = 71;
  int sz = 1024;

  auto chk_bound = [&](int i, int j)
  {
    return 0 <= i && i < n && 0 <= j && j < m;
  };

  vector<pii> dirs = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1},
  };

  auto solve = [&](set<pii> &opos)
  {
    pii spos = {0, 0};
    queue<pii> q;
    map<pii, int> dist;
    dist[spos] = 0;
    q.push(spos);

    auto get_dist = [&](int i, int j)
    {
      if (dist.find({i, j}) == dist.end())
        return INF;

      return dist[{i, j}];
    };

    auto chk_obs = [&](int i, int j)
    {
      return opos.find({i, j}) != opos.end();
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

        if (chk_bound(ni, nj) && !chk_obs(ni, nj) && get_dist(ni, nj) == INF)
        {
          dist[{ni, nj}] = dist[cpos] + 1;
          q.push({ni, nj});
        }
      };
    }

    return get_dist(n - 1, m - 1);
  };

  auto get_opos = [&](int sz)
  {
    set<pii> opos;
    for (int i = 0; i < sz; i++)
      opos.insert(coor[i]);
    return opos;
  };

  set<pii> opos = get_opos(sz);

  cout << solve(opos) << nl;

  int l = 0;
  int r = coor.size();

  while (l <= r)
  {
    int mid = (l + r) / 2;
    auto cur_opos = get_opos(mid);

    int cur = solve(cur_opos);

    if (cur == INF)
      r = mid - 1;
    else
      l = mid + 1;
  }

  auto [ax, ay] = coor[r];
  cout << ax << "," << ay << nl;

  return 0;
}
