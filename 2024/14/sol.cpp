#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

int mod(int a, int b)
{
  return (a % b + b) % b;
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<pii> pos;

  int t = 100;
  int w = 101;
  int h = 103;

  vector<pii> p, v;

  while (getline(cin, s))
  {
    regex re(R"(p=(-?\d+),(-?\d+) v=(-?\d+),(-?\d+))");
    smatch match;
    regex_match(s, match, re);

    int px = stoi(match[1]);
    int py = stoi(match[2]);
    int vx = stoi(match[3]);
    int vy = stoi(match[4]);

    p.push_back({px, py});
    v.push_back({vx, vy});

    int nx = mod(px + t * vx, w);
    int ny = mod(py + t * vy, h);

    pos.push_back({nx, ny});
  }

  int mx = w / 2;
  int my = h / 2;

  vector<int> q(4, 0);

  for (auto [x, y] : pos)
  {
    if (x < mx && y < my)
      q[0]++;
    else if (x > mx && y < my)
      q[1]++;
    else if (x < mx && y > my)
      q[2]++;
    else if (x > mx && y > my)
      q[3]++;
  }

  int res = 1;
  for (auto i : q)
    res *= i;
  cout << res << nl;

  assert(p.size() == v.size());
  int sz = p.size();

  for (int i = 0;; i++)
  {
    set<pii> st;
    for (int j = 0; j < sz; j++)
    {
      auto [px, py] = p[j];
      auto [vx, vy] = v[j];

      int cx = mod(px + i * vx, w);
      int cy = mod(py + i * vy, h);

      st.insert({cx, cy});
    }

    if ((int)st.size() == sz)
    {
      vector<vector<char>> g(h, vector<char>(w, '.'));
      for (auto [x, y] : st)
        g[y][x] = '*';

      cout << i << nl;
      for (auto u : g)
      {
        for (auto v : u)
          cout << v;
        cout << nl;
      }

      break;
    }
  }

  return 0;
}
