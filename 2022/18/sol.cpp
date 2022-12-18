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

  return 0;
}