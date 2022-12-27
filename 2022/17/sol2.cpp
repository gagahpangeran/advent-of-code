#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef vector<string> vs;
typedef vector<vs> vvs;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string moves;
  cin >> moves;

  ll msz = moves.size();

  ll maxh = 5000;
  const int width = 9;
  vs grid(maxh, string(width, '.'));

  for (ll i = 0; i < maxh; i++)
  {
    grid[i][0] = grid[i][width - 1] = '*';

    if (i == maxh - 1)
      grid[i] = string(width, '*');
  }

  auto PG = [&](ll height)
  {
    for (ll i = maxh - height; i < maxh; i++)
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

  ll ssz = shapes.size();

  auto Next = [&](ll i, ll j, ll move)
  {
    if (move == 'v')
      i++;
    else if (move == '>')
      j++;
    else if (move == '<')
      j--;

    return make_pair(i, j);
  };

  auto CanMove = [&](ll i, ll j, ll sp, char move)
  {
    vs shape = shapes[sp];
    ll sz = shape.size();

    ll gi = i - sz + 1;
    ll gj = j;

    auto next = Next(gi, gj, move);
    gi = next.first;
    gj = next.second;

    for (ll i = 0; i < sz; i++)
    {
      for (ll j = 0; j < shape[i].size(); j++)
      {
        if (shape[i][j] == '#' && grid[gi + i][gj + j] != '.')
          return false;
      }
    }

    return true;
  };

  auto Rest = [&](ll i, ll j, ll sp)
  {
    vs shape = shapes[sp];
    ll sz = shape.size();

    ll gi = i - sz + 1;
    ll gj = j;

    for (ll i = 0; i < sz; i++)
    {
      for (ll j = 0; j < shape[i].size(); j++)
      {
        if (shape[i][j] != '.' && grid[gi + i][gj + j] != '.')
          assert(false);

        if (grid[gi + i][gj + j] == '.')
          grid[gi + i][gj + j] = shape[i][j];
      }
    }
  };

  ll maxr = 1000000000000;
  ll top = maxh - 1;
  ll midx = 0;

  map<tuple<ll, ll, vs>, ll> tops;
  vector<ll> heights;

  for (ll idx = 0; idx < maxr; idx++)
  {
    ll spi = idx % ssz;

    ll i = top - 4;
    ll j = 3;

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
        top = min(i - (ll)shapes[spi].size() + 1, top);
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

    ll hg = maxh - top - 1;
    heights.push_back(hg);

    const ll minhg = 5;
    if (hg >= minhg)
    {
      vs tp = vector(grid.begin() + top, grid.begin() + top + minhg);
      tuple<ll, ll, vs> key = {spi, midx, tp};

      if (tops.count(key) > 0)
      {
        ll pidx = tops[key];
        ll phg = heights[pidx];

        ll dhg = hg - phg;
        ll cycle = idx - pidx;

        ll sisa = maxr - pidx;
        ll cnt = sisa / cycle;

        ll kurang = sisa % cycle;
        ll hkurang = heights[pidx + kurang] - phg;

        ll tothg = (cnt * dhg) + (phg - 1) + hkurang;
        cout << tothg << nl;

        return 0;
      }

      tops[key] = idx;
    }
  }

  assert(false);

  return 0;
}