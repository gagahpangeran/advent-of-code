#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<string> grid;

  while (getline(cin, s))
    grid.push_back(s);

  int n, m;
  n = grid.size();
  m = grid[0].size();

  vector<tuple<pii, char>> bliz;

  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++)
      if (grid[i][j] != '.')
        bliz.push_back({{i, j}, grid[i][j]});

  auto Solve = [&](pii st, pii en)
  {
    set<pii> spos;
    spos.insert(st);

    int res = 0;
    while (spos.find(en) == spos.end())
    {
      res++;

      set<pii> blizpos;
      for (int i = 0; i < bliz.size(); i++)
      {
        auto [pos, dir] = bliz[i];
        auto [ci, cj] = pos;

        int ni = ci, nj = cj;

        if (dir == '>')
          nj = (cj == m - 2) ? 1 : cj + 1;
        else if (dir == '<')
          nj = (cj == 1) ? m - 2 : cj - 1;
        else if (dir == 'v')
          ni = (ci == n - 2) ? 1 : ci + 1;
        else if (dir == '^')
          ni = (ci == 1) ? n - 2 : ci - 1;
        else
          assert(false);

        bliz[i] = {{ni, nj}, dir};
        blizpos.insert({ni, nj});
      }

      vector<pii> nx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0}};
      set<pii> nspos;

      for (auto [ci, cj] : spos)
      {
        for (auto [ni, nj] : nx)
        {
          int nexti = ci + ni, nextj = cj + nj;

          bool ok = 0 <= nexti && nexti < n && 0 <= nextj && nextj < m &&
                    grid[nexti][nextj] != '#' &&
                    blizpos.find({nexti, nextj}) == blizpos.end();

          if (ok)
            nspos.insert({nexti, nextj});
        }
      }
      spos = nspos;
    }

    return res;
  };

  pii start = {0, 1};
  pii end = {n - 1, m - 2};

  auto obliz = bliz;

  cout << Solve(start, end) << nl;

  bliz = obliz;
  cout << Solve(start, end) + Solve(end, start) + Solve(start, end) << nl;

  return 0;
}