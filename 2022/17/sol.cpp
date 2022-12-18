#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef vector<string> vs;
typedef vector<vs> vvs;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string moves;
  cin >> moves;

  int msz = moves.size();

  int maxh = 5000;
  const int width = 9;
  vs grid(maxh, string(width, '.'));

  for (int i = 0; i < maxh; i++)
  {
    grid[i][0] = grid[i][width - 1] = '*';

    if (i == maxh - 1)
      grid[i] = string(width, '*');
  }

  auto PG = [&](int height)
  {
    for (int i = maxh - height; i < maxh; i++)
      cout << grid[i] << nl;
  };

  vvs shapes = {
      {"####"},
      {".#.",
       "###",
       ".#."},
      {"..#",
       "..#",
       "###"},
      {"#",
       "#",
       "#",
       "#"},
      {"##",
       "##"},
  };

  int ssz = shapes.size();

  auto Next = [&](int i, int j, char move)
  {
    if (move == 'v')
      i++;
    else if (move == '>')
      j++;
    else if (move == '<')
      j--;

    return make_pair(i, j);
  };

  auto CanMove = [&](int i, int j, int sp, char move)
  {
    vs shape = shapes[sp];
    int sz = shape.size();

    int gi = i - sz + 1;
    int gj = j;

    auto next = Next(gi, gj, move);
    gi = next.first;
    gj = next.second;

    for (int i = 0; i < sz; i++)
    {
      for (int j = 0; j < shape[i].size(); j++)
      {
        if (shape[i][j] == '#' && grid[gi + i][gj + j] != '.')
          return false;
      }
    }

    return true;
  };

  auto Rest = [&](int i, int j, int sp)
  {
    vs shape = shapes[sp];
    int sz = shape.size();

    int gi = i - sz + 1;
    int gj = j;

    for (int i = 0; i < sz; i++)
    {
      for (int j = 0; j < shape[i].size(); j++)
      {
        if (shape[i][j] != '.' && grid[gi + i][gj + j] != '.')
          assert(false);

        if (grid[gi + i][gj + j] == '.')
          grid[gi + i][gj + j] = shape[i][j];
      }
    }
  };

  int maxr = 2022;
  int top = maxh - 1;
  int midx = 0;

  for (int idx = 0; idx < maxr; idx++)
  {
    int spi = idx % ssz;

    int i = top - 4;
    int j = 3;

    bool down = false;

    for (;;)
    {
      char move = 'v';
      if (!down)
      {
        move = moves[midx];
        midx = (midx + 1) % msz;
      }
      down = !down;

      bool canmove = CanMove(i, j, spi, move);

      if (move == 'v' && !canmove)
      {
        top = min(i - (int)shapes[spi].size() + 1, top);
        Rest(i, j, spi);
        break;
      }
      else if (canmove)
      {
        auto next = Next(i, j, move);
        i = next.first;
        j = next.second;
      }
    }
  }

  cout << maxh - top - 1 << nl;

  return 0;
}