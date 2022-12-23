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

  auto Solve = [&](int part)
  {
    set<pii> elves;

    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[i].size(); j++)
        if (grid[i][j] == '#')
          elves.insert({i, j});

    int esz = elves.size();

    vector<char> dirs = {'N', 'S', 'W', 'E'};

    int rounds = part == 1 ? 10 : 1e9;
    int cnt = 0;

    for (int r = 0; r < rounds; r++)
    {
      cnt++;
      set<pii> nextelves;

      map<pii, pii> moving;
      map<pii, int> nextmove;

      for (auto [ci, cj] : elves)
      {
        bool makemoves = false;

        for (int u = -1; u <= 1; u++)
        {
          for (int v = -1; v <= 1; v++)
          {
            if (u == 0 && v == 0)
              continue;

            int adi = ci + u, adj = cj + v;
            if (elves.find({adi, adj}) != elves.end())
              makemoves = true;
          }
        }

        if (!makemoves)
        {
          nextelves.insert({ci, cj});
          continue;
        }

        int fdirs = r % 4;

        for (int fi = 0; fi < 4; fi++)
        {
          char dir = dirs[(fdirs + fi) % 4];

          if (dir == 'N')
          {
            bool chk = true;
            for (int v = -1; v <= 1; v++)
              chk = chk && (elves.find({ci - 1, cj + v}) == elves.end());
            if (chk)
            {
              moving[{ci, cj}] = {ci - 1, cj};
              nextmove[{ci - 1, cj}]++;
              break;
            }
          }
          else if (dir == 'S')
          {
            bool chk = true;
            for (int v = -1; v <= 1; v++)
              chk = chk && (elves.find({ci + 1, cj + v}) == elves.end());
            if (chk)
            {
              moving[{ci, cj}] = {ci + 1, cj};
              nextmove[{ci + 1, cj}]++;
              break;
            }
          }
          else if (dir == 'W')
          {
            bool chk = true;
            for (int u = -1; u <= 1; u++)
              chk = chk && (elves.find({ci + u, cj - 1}) == elves.end());
            if (chk)
            {
              moving[{ci, cj}] = {ci, cj - 1};
              nextmove[{ci, cj - 1}]++;
              break;
            }
          }
          else if (dir == 'E')
          {
            bool chk = true;
            for (int u = -1; u <= 1; u++)
              chk = chk && (elves.find({ci + u, cj + 1}) == elves.end());
            if (chk)
            {
              moving[{ci, cj}] = {ci, cj + 1};
              nextmove[{ci, cj + 1}]++;
              break;
            }
          }
        }

        if (moving.count({ci, cj}) == 0)
          nextelves.insert({ci, cj});
      }

      for (auto [from, to] : moving)
      {
        if (nextmove[to] == 1)
          nextelves.insert(to);
        else
          nextelves.insert(from);
      }

      assert((int)nextelves.size() == esz);

      if (part == 2 && elves == nextelves)
        break;

      elves = nextelves;
    }

    if (part == 1)
    {
      int mini = INT_MAX;
      int maxi = INT_MIN;
      int minj = INT_MAX;
      int maxj = INT_MIN;

      for (auto [i, j] : elves)
      {
        mini = min(mini, i);
        maxi = max(maxi, i);
        minj = min(minj, j);
        maxj = max(maxj, j);
      }

      int h = maxi - mini + 1;
      int w = maxj - minj + 1;
      int res = (h * w) - esz;

      return res;
    }
    else if (part == 2)
    {
      return cnt;
    }

    assert(false);
  };

  cout << Solve(1) << nl;
  cout << Solve(2) << nl;

  return 0;
}