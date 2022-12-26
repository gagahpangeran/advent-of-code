#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  map<vvi, int> side_cnt;
  set<vi> points;

  while (getline(cin, s))
  {
    int csz = 8;
    vvi corners(csz);
    stringstream ss(s);

    for (int i; ss >> i;)
    {
      corners[0].push_back(i);
      if (ss.peek() == ',')
        ss.ignore();
    }

    points.insert(corners[0]);

    for (int i = 1; i < csz; i++)
    {
      bitset<3> bs(i);
      for (int j = 0; j < bs.size(); j++)
        corners[i].push_back(corners[0][j] + bs[j]);
    }

    sort(corners.begin(), corners.end());

    vector<vvi> sides = {
        {corners[0], corners[1], corners[2], corners[3]},
        {corners[4], corners[5], corners[6], corners[7]},
        {corners[0], corners[2], corners[4], corners[6]},
        {corners[1], corners[3], corners[5], corners[7]},
        {corners[0], corners[1], corners[4], corners[5]},
        {corners[2], corners[3], corners[6], corners[7]},
    };

    for (auto side : sides)
    {
      sort(side.begin(), side.end());
      side_cnt[side]++;
    }
  }

  int res = 0;
  for (auto &[k, c] : side_cnt)
  {
    if (c == 1)
      res++;
  }

  cout << res << nl;

  vector<int> minp(3, INT_MAX), maxp(3, INT_MIN);

  for (auto pt : points)
  {
    assert(pt.size() == 3);
    for (int i = 0; i < 3; i++)
    {
      minp[i] = min(minp[i], pt[i] - 1);
      maxp[i] = max(maxp[i], pt[i] + 1);
    }
  }

  int res2 = 0;

  set<vi> vis;
  deque<vi> q;
  q.push_back({minp[0], minp[1], minp[2]});

  while (!q.empty())
  {
    vi cur = q.front();
    q.pop_front();
    vis.insert(cur);

    vector<vi> neig = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, -1},
    };

    for (auto ng : neig)
    {
      vi next(3);
      bool in_bound = true;
      for (int i = 0; i < 3; i++)
      {
        next[i] = cur[i] + ng[i];
        in_bound = in_bound && minp[i] <= next[i] && next[i] <= maxp[i];
      }

      bool is_visited = vis.find(next) != vis.end();
      bool in_queue = find(q.begin(), q.end(), next) != q.end();
      bool valid_point = points.find(next) != points.end();

      if (in_bound && !is_visited && !in_queue)
      {
        if (valid_point)
          res2++;
        else
          q.push_back(next);
      }
    }
  }

  cout << res2 << nl;

  return 0;
}