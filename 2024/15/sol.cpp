#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

map<char, pii> dirs = {
    {'^', {-1, 0}},
    {'v', {1, 0}},
    {'<', {0, -1}},
    {'>', {0, 1}},
};

pii get_spos(vector<string> &g, int n, int m)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '@')
        return {i, j};
  assert(false);
}

int get_res(vector<string> &g, int n, int m, char target)
{
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == target)
        res += 100 * i + j;
  return res;
}

void solve1(vector<string> g, string moves)
{
  function<char(pii &, char)> do_move = [&](pii &pos, char dir)
  {
    auto [ci, cj] = pos;

    if (g[ci][cj] == '#' || g[ci][cj] == '.')
      return g[ci][cj];

    auto [di, dj] = dirs[dir];
    int ni = ci + di;
    int nj = cj + dj;
    pii npos = {ni, nj};

    char nblock = do_move(npos, dir);

    if (nblock == '.')
    {
      if (g[ci][cj] == '@')
        pos = {ni, nj};
      swap(g[ci][cj], g[ni][nj]);
    }

    return g[ci][cj];
  };

  int n = g.size();
  int m = g[0].size();

  pii cpos = get_spos(g, n, m);

  for (auto move : moves)
    do_move(cpos, move);

  cout << get_res(g, n, m, 'O') << nl;
}

void solve2(vector<string> g, string moves)
{
  vector<string> ng;
  for (auto s : g)
  {
    string ns = "";
    for (auto c : s)
    {
      if (c == '#')
        ns += "##";
      else if (c == 'O')
        ns += "[]";
      else if (c == '.')
        ns += "..";
      else if (c == '@')
        ns += "@.";
    }
    ng.push_back(ns);
  }
  g = ng;

  function<bool(pii, char)> can_move = [&](pii pos, char dir)
  {
    auto [ci, cj] = pos;

    if (g[ci][cj] == '#')
      return false;

    if (g[ci][cj] == '.')
      return true;

    auto [di, dj] = dirs[dir];
    int ni = ci + di;
    int nj = cj + dj;

    if (g[ci][cj] == '@' || dir == '<' || dir == '>')
      return can_move({ni, nj}, dir);

    int sj = g[ci][cj] == '[' ? 1 : -1;
    int mi = ci + di;
    int mj = cj + dj + sj;

    return can_move({ni, nj}, dir) && can_move({mi, mj}, dir);
  };

  function<void(pii &, char)> do_move = [&](pii &pos, char dir)
  {
    auto [ci, cj] = pos;

    if (g[ci][cj] == '#' || g[ci][cj] == '.')
      return;

    if (can_move(pos, dir))
    {
      auto [di, dj] = dirs[dir];
      int ni = ci + di;
      int nj = cj + dj;

      pii npos = {ni, nj};
      do_move(npos, dir);

      if (g[ci][cj] == '@')
      {
        pos = {ni, nj};
        swap(g[ci][cj], g[ni][nj]);
      }
      else if (dir == '<' || dir == '>')
      {
        swap(g[ci][cj], g[ni][nj]);
      }
      else
      {
        int sj = g[ci][cj] == '[' ? 1 : -1;
        int mi = ci + di;
        int mj = cj + dj + sj;

        pii mpos = {mi, mj};
        do_move(mpos, dir);

        swap(g[ci][cj], g[ni][nj]);
        swap(g[ci][cj + sj], g[mi][mj]);
      }
    }
  };

  int n = g.size();
  int m = g[0].size();

  pii cpos = get_spos(g, n, m);
  for (auto move : moves)
    do_move(cpos, move);

  cout << get_res(g, n, m, '[') << nl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<string> g;
  string moves = "";
  bool get_map = true;

  while (getline(cin, s))
  {
    if (s.size() == 0)
    {
      get_map = false;
      continue;
    }

    if (get_map)
      g.push_back(s);
    else
      moves += s;
  }

  solve1(g, moves);
  solve2(g, moves);

  return 0;
}
