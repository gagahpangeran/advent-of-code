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

  pii curh, curt;
  curh = curt = {0, 0};

  auto Dist = [&](pii a, pii b)
  {
    return abs(a.x - b.x) + abs(a.y - b.y);
  };

  auto Gap = [&](pii a, pii b)
  {
    int d = Dist(a, b);
    if ((a.x == b.x || a.y == b.y) && d > 1)
      return true;

    if ((a.x != b.x && a.y != b.y) && d != 2)
      return true;

    return false;
  };

  set<pii>
      vis;
  vis.insert(curt);

  while (cin >> dir >> step)
  {
    while (step--)
    {
      switch (dir)
      {
      case 'R':
        curh.x++;
        if (Gap(curh, curt))
        {
          curt.y = curh.y;
          curt.x = curh.x - 1;
        }
        break;

      case 'L':
        curh.x--;
        if (Gap(curh, curt))
        {
          curt.y = curh.y;
          curt.x = curh.x + 1;
        }
        break;

      case 'U':
        curh.y++;
        if (Gap(curh, curt))
        {
          curt.x = curh.x;
          curt.y = curh.y - 1;
        }
        break;

      case 'D':
        curh.y--;
        if (Gap(curh, curt))
        {
          curt.x = curh.x;
          curt.y = curh.y + 1;
        }
        break;

      default:
        assert(false);
        break;
      }
      vis.insert(curt);
    }
  }

  cout << vis.size() << nl;

  return 0;
}