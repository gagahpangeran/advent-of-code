#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef tuple<ll, ll, ll> lll;
typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x, y, z;
  vector<lll> coor;

  while (scanf("%lld,%lld,%lld", &x, &y, &z) != EOF)
    coor.push_back({x, y, z});

  int n = coor.size();

  vector<pair<pii, ll>> dist;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      auto [x1, y1, z1] = coor[i];
      auto [x2, y2, z2] = coor[j];

      ll dx = x1 - x2;
      ll dy = y1 - y2;
      ll dz = z1 - z2;
      ll d = dx * dx + dy * dy + dz * dz;

      dist.push_back({{i, j}, d});
    }
  }

  auto compare = [&](pair<pii, ll> d1, pair<pii, ll> d2)
  {
    return d1.second < d2.second;
  };

  sort(dist.begin(), dist.end(), compare);

  // int max_len = 10;
  int max_len = 1000;
  auto s_dist = vector(dist.begin(), dist.begin() + max_len);

  vector<vector<int>> g(n);

  for (auto [p, d] : s_dist)
  {
    auto [u, v] = p;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  map<int, set<int>> mp;
  vector<bool> vis(n, false);

  for (int i = 0; i < n; i++)
  {
    if (vis[i])
      continue;

    queue<int> q;
    q.push(i);

    mp[i].insert(i);

    while (!q.empty())
    {
      int cur = q.front();
      q.pop();

      vis[cur] = true;
      mp[i].insert(cur);

      for (auto nx : g[cur])
      {
        if (!vis[nx])
        {
          vis[nx] = true;
          q.push(nx);
        }
      }
    }
  }

  vector<ll> box;

  for (auto [par, nx] : mp)
  {
    box.push_back(nx.size());
  }

  sort(box.begin(), box.end(), greater<ll>());

  ll res = box[0] * box[1] * box[2];
  cout << res << nl;

  vector<int> p(n), sz(n, 1);
  int cnt = n;

  iota(p.begin(), p.end(), 0);

  function<int(int)> find = [&](int x)
  {
    if (p[x] == x)
      return x;

    return p[x] = find(p[x]);
  };

  auto join = [&](int x, int y)
  {
    x = find(x);
    y = find(y);

    if (x == y)
      return;

    if (sz[x] < sz[y])
      swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
    cnt--;
  };

  lll a, b;

  for (auto [edge, dis] : dist)
  {
    auto [u, v] = edge;
    join(u, v);

    if (cnt == 1)
    {
      a = coor[u];
      b = coor[v];
      break;
    }
  }

  auto [xa, ya, za] = a;
  auto [xb, yb, zb] = b;

  ll res2 = xa * xb;
  cout << res2 << nl;

  return 0;
}