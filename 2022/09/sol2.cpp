#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define x first
#define y second

typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  char dir;
  int step;

  int maxn = 10;
  vector<pii> pos(maxn, {0, 0});
  set<pii> vis;
  vis.insert(*pos.rbegin());

  while (cin >> dir >> step)
  {
    while (step--)
    {
      for (int i = 0; i < maxn; i++)
      {
        if (i == 0)
        {
          if (dir == 'R')
            pos[i].x++;
          else if (dir == 'L')
            pos[i].x--;
          else if (dir == 'U')
            pos[i].y++;
          else if (dir == 'D')
            pos[i].y--;
        }
        else
        {
          int dx = abs(pos[i].x - pos[i - 1].x);
          int dy = abs(pos[i].y - pos[i - 1].y);

          auto MoveX = [&]()
          {
            if (pos[i].x < pos[i - 1].x)
              pos[i].x++;
            else
              pos[i].x--;
          };

          auto MoveY = [&]()
          {
            if (pos[i].y < pos[i - 1].y)
              pos[i].y++;
            else
              pos[i].y--;
          };

          if (dx > 1)
          {
            MoveX();

            if (dy > 0)
              MoveY();
          }
          else if (dy > 1)
          {
            MoveY();

            if (dx > 0)
              MoveX();
          }
        }
      }

      vis.insert(*pos.rbegin());
    }
  }

  cout << vis.size() << nl;

  return 0;
}