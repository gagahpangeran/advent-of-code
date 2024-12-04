#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

vector<string> g;
int n, m;

void solve1()
{
  auto Count = [&](int cur_i, int cur_j)
  {
    int cnt = 0;
    vector<string> ss(4);

    for (int x = 0; x < 4; x++)
    {
      if (cur_i + x < n)
        ss[0] += g[cur_i + x][cur_j];
      if (cur_j + x < m)
        ss[1] += g[cur_i][cur_j + x];
      if (cur_i + x < n && cur_j + x < m)
        ss[2] += g[cur_i + x][cur_j + x];
      if (cur_i + x < n && cur_j - x >= 0)
        ss[3] += g[cur_i + x][cur_j - x];
    }

    for (auto sc : ss)
    {
      cnt += sc == "XMAS";
      cnt += sc == "SAMX";
    }

    return cnt;
  };

  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      res += Count(i, j);

  cout << res << nl;
}

void solve2()
{
  auto Check = [&](int cur_i, int cur_j)
  {
    if (g[cur_i][cur_j] != 'A')
      return false;

    vector<pair<int, int>> nx = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    string ss = "";
    for (auto &[ni, nj] : nx)
      ss += g[cur_i + ni][cur_j + nj];

    vector<string> tg = {"MMSS", "SSMM", "SMSM", "MSMS"};

    for (auto t : tg)
    {
      if (ss == t)
        return true;
    }

    return false;
  };

  int res = 0;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++)
      res += Check(i, j);

  cout << res << nl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  while (cin >> s)
    g.push_back(s);

  n = g.size();
  m = g[0].size();

  solve1();
  solve2();

  return 0;
}
