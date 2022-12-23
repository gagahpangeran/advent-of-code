#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define fi first
#define se second

typedef pair<int, int> pii;

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

  vector<pii> boundrow(n, {0, m - 1});

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

  vector<pii> boundcol(m, {0, n - 1});

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

  vector<char> faces = {'>', 'v', '<', '^'};

  auto FaceVal = [&](char fa)
  {
    return (int)(find(faces.begin(), faces.end(), fa) - faces.begin());
  };

  auto Turn = [&](char tu, char fa)
  {
    int idx = FaceVal(fa);
    int fsz = faces.size();

    auto Mod = [&](int a, int b)
    {
      return (a % b + b) % b;
    };

    if (tu == 'R')
      return faces[Mod(idx + 1, fsz)];

    if (tu == 'L')
      return faces[Mod(idx - 1, fsz)];

    assert(false);
  };

  int i = 0;
  int j = boundrow[0].fi;

  char face = faces[0];

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

    face = Turn(tu, face);
  }

  int res = (i + 1) * 1000 + (j + 1) * 4 + FaceVal(face);
  cout << res << nl;

  // solution bellow only works for input file only (does not works for sample file)

  int len = 50;

  vector<pii> sarea = {
      {0, len},
      {0, 2 * len},
      {len, len},
      {2 * len, 0},
      {2 * len, len},
      {3 * len, 0},
  };

  vector<vector<int>> garea(n, vector<int>(m, 0));

  for (int iarea = 0; iarea < sarea.size(); iarea++)
  {
    auto [u, v] = sarea[iarea];
    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        garea[u + i][v + j] = iarea + 1;
  }

  i = 0;
  j = boundrow[0].fi;

  face = faces[0];

  ist = 0, itu = 0;

  for (;;)
  {
    if (ist >= step.size())
      break;

    int st = step[ist];
    ist++;

    while (st--)
    {
      map<char, pii> nx = {
          {'>', {0, 1}},
          {'<', {0, -1}},
          {'v', {1, 0}},
          {'^', {-1, 0}},
      };

      int nexti = i + nx[face].fi, nextj = j + nx[face].se;
      char nextface = face;

      auto [l, r] = boundrow[i];
      auto [u, d] = boundcol[j];

      if (nextj < l || nextj > r || nexti > d || nexti < u)
      {
        int narea = garea[i][j];

        if (narea == 1 && face == '<')
        {
          assert(j == len);
          nextj = 0;
          nexti = 2 * len + (len - i - 1);
          assert(garea[nexti][nextj] == 4);
          nextface = '>';
        }
        else if (narea == 1 && face == '^')
        {
          assert(i == 0);
          nextj = 0;
          nexti = 3 * len + (j - len);
          assert(garea[nexti][nextj] == 6);
          nextface = '>';
        }
        else if (narea == 2 && face == '^')
        {
          assert(i == 0);
          nexti = 4 * len - 1;
          nextj = j - (2 * len);
          assert(garea[nexti][nextj] == 6);
          nextface = '^';
        }
        else if (narea == 2 && face == '>')
        {
          assert(j == 3 * len - 1);
          nextj = 2 * len - 1;
          nexti = 2 * len + (len - i - 1);
          assert(garea[nexti][nextj] == 5);
          nextface = '<';
        }
        else if (narea == 2 && face == 'v')
        {
          assert(i == len - 1);
          nextj = 2 * len - 1;
          nexti = len + (j - 2 * len);
          assert(garea[nexti][nextj] == 3);
          nextface = '<';
        }
        else if (narea == 3 && face == '<')
        {
          assert(j == len);
          nexti = 2 * len;
          nextj = i - len;
          assert(garea[nexti][nextj] == 4);
          nextface = 'v';
        }
        else if (narea == 3 && face == '>')
        {
          assert(j == 2 * len - 1);
          nexti = len - 1;
          nextj = 2 * len + (i - len);
          assert(garea[nexti][nextj] == 2);
          nextface = '^';
        }
        else if (narea == 4 && face == '^')
        {
          assert(i == 2 * len);
          nextj = len;
          nexti = len + j;
          assert(garea[nexti][nextj] == 3);
          nextface = '>';
        }
        else if (narea == 4 && face == '<')
        {
          assert(j == 0);
          nextj = len;
          nexti = 3 * len - 1 - i;
          assert(garea[nexti][nextj] == 1);
          nextface = '>';
        }
        else if (narea == 5 && face == '>')
        {
          assert(j == 2 * len - 1);
          nextj = 3 * len - 1;
          nexti = 3 * len - 1 - i;
          assert(garea[nexti][nextj] == 2);
          nextface = '<';
        }
        else if (narea == 5 && face == 'v')
        {
          assert(i == 3 * len - 1);
          nextj = len - 1;
          nexti = 3 * len + (j - len);
          assert(garea[nexti][nextj] == 6);
          nextface = '<';
        }
        else if (narea == 6 && face == '<')
        {
          assert(j == 0);
          nexti = 0;
          nextj = len + (i - 3 * len);
          assert(garea[nexti][nextj] == 1);
          nextface = 'v';
        }
        else if (narea == 6 && face == '>')
        {
          assert(j == len - 1);
          nexti = 3 * len - 1;
          nextj = len + (i - 3 * len);
          assert(garea[nexti][nextj] == 5);
          nextface = '^';
        }
        else if (narea == 6 && face == 'v')
        {
          assert(i == 4 * len - 1);
          nexti = 0;
          nextj = 2 * len + j;
          assert(garea[nexti][nextj] == 2);
          nextface = 'v';
        }
        else
          assert(false);
      }

      if (grid[nexti][nextj] == '#')
        break;

      i = nexti;
      j = nextj;
      face = nextface;
    }

    if (itu >= turn.size())
      break;

    char tu = turn[itu];
    itu++;

    face = Turn(tu, face);
  }

  int res2 = (i + 1) * 1000 + (j + 1) * 4 + FaceVal(face);
  cout << res2 << nl;

  return 0;
}