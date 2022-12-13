#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define fi first
#define se second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vvi g;

  int i = 0;

  pii start, end;
  vp lowest;

  while (getline(cin, s))
  {
    vi vg;
    for (int j = 0; j < s.size(); j++)
    {
      int num = s[j] - 'a';
      if (s[j] == 'S')
      {
        start = {i, j};
        num = 0;
      }
      else if (s[j] == 'E')
      {
        end = {i, j};
        num = 'z' - 'a';
      }
      if (num == 0)
        lowest.push_back({i, j});
      vg.push_back(num);
    }
    g.push_back(vg);
    i++;
  }

  int n = g.size(), m = g[0].size();

  vp adj = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  auto BFS = [&](pii st)
  {
    queue<pii> q;
    set<pii> vis;
    vvi dist(n, vi(m, INT_MAX));

    vis.insert(st);
    q.push(st);
    dist[st.fi][st.se] = 0;

    while (!q.empty())
    {
      pii cur = q.front();
      q.pop();

      for (auto &[x, y] : adj)
      {
        pii next = {cur.fi + x, cur.se + y};
        if (next.fi >= 0 && next.fi < n && next.se >= 0 && next.se < m &&
            g[next.fi][next.se] - g[cur.fi][cur.se] <= 1 &&
            vis.find(next) == vis.end())
        {
          vis.insert(next);
          dist[next.fi][next.se] = dist[cur.fi][cur.se] + 1;
          q.push(next);

          if (next == end)
            return dist[end.fi][end.se];
        }
      }
    }

    return dist[end.fi][end.se];
  };

  cout << BFS(start) << nl;

  int res = INT_MAX;

  for (auto low : lowest)
    res = min(res, BFS(low));

  cout << res << nl;

  return 0;
}