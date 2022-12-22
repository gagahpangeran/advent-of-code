#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define fi first
#define se second

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<string> grid;

  int mxm = 0;

  while (getline(cin, s))
  {
    if (s.size() == 0)
      break;

    grid.push_back(s);
    mxm = max((int)s.size(), mxm);
  }

  string p;
  cin >> p;

  deque<int> step;
  deque<char> turn;

  stringstream ss(p);

  for (int i; ss >> i;)
  {
    step.push_back(i);
    if (ss.peek() == 'R' || ss.peek() == 'L')
    {
      turn.push_back(ss.peek());
      ss.ignore();
    }
  }

  for (int i = 0; i < grid.size(); i++)
  {
    if (grid[i].size() < mxm)
      grid[i] += string(mxm - grid[i].size(), ' ');
  }

  int n = grid.size(), m = grid[0].size();

  vector<pair<int, int>> boundrow(n, {0, m - 1});

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] != ' ')
      {
        boundrow[i].fi = j;
        break;
      }
    }

    for (int j = m - 1; j >= 0; j--)
    {
      if (grid[i][j] != ' ')
      {
        boundrow[i].se = j;
        break;
      }
    }
  }

  vector<pair<int, int>> boundcol(m, {0, n - 1});

  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      if (grid[i][j] != ' ')
      {
        boundcol[j].fi = i;
        break;
      }
    }

    for (int i = n - 1; i >= 0; i--)
    {
      if (grid[i][j] != ' ')
      {
        boundcol[j].se = i;
        break;
      }
    }
  }

  char face = '>';

  int i = 0;
  int j = boundrow[0].fi;

  int ist = 0, itu = 0;

  for (;;)
  {
    if (ist >= step.size())
      break;

    int st = step[ist];
    ist++;

    while (st--)
    {
      if (face == '>' || face == '<')
      {
        int nx = face == '>' ? 1 : -1;
        int nextj = j + nx;
        auto [l, r] = boundrow[i];

        if (face == '>' && nextj > r)
          nextj = l;
        else if (face == '<' && nextj < l)
          nextj = r;

        if (grid[i][nextj] == '#')
          break;

        j = nextj;
      }
      else if (face == 'v' || face == '^')
      {
        int nx = face == 'v' ? 1 : -1;
        int nexti = i + nx;
        auto [u, d] = boundcol[j];

        if (face == 'v' && nexti > d)
          nexti = u;
        else if (face == '^' && nexti < u)
          nexti = d;

        if (grid[nexti][j] == '#')
          break;

        i = nexti;
      }
    }

    if (itu >= turn.size())
      break;

    char tu = turn[itu];
    itu++;

    map<char, char> turnright = {
        {'>', 'v'},
        {'v', '<'},
        {'<', '^'},
        {'^', '>'},
    };

    map<char, char> turnleft = {
        {'>', '^'},
        {'^', '<'},
        {'<', 'v'},
        {'v', '>'},
    };

    if (tu == 'R')
      face = turnright[face];
    else if (tu == 'L')
      face = turnleft[face];
  }

  map<char, int> faceval = {
      {'>', 0},
      {'v', 1},
      {'<', 2},
      {'^', 3},
  };

  int res = (i + 1) * 1000 + (j + 1) * 4 + faceval[face];
  cout << res << nl;

  return 0;
}