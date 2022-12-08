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
  vvi g;
  while (getline(cin, s))
  {
    vi v;
    for (auto c : s)
      v.push_back(c - '0');
    g.push_back(v);
  }

  int n = g.size(), m = g[0].size();
  vvi max_left(n, vi(m)), max_right(n, vi(m)), max_top(n, vi(m)), max_bottom(n, vi(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      max_left[i][j] = g[i][j];
      max_right[i][m - j - 1] = g[i][m - j - 1];
      if (j != 0)
      {
        max_left[i][j] = max(max_left[i][j], max_left[i][j - 1]);
        max_right[i][m - j - 1] = max(max_right[i][m - j - 1], max_right[i][m - j]);
      }

      max_top[i][j] = g[i][j];
      max_bottom[n - i - 1][j] = g[n - i - 1][j];
      if (i != 0)
      {
        max_top[i][j] = max(max_top[i][j], max_top[i - 1][j]);
        max_bottom[n - i - 1][j] = max(max_bottom[n - i - 1][j], max_bottom[n - i][j]);
      }
    }
  }

  int res = (n + m - 2) * 2;
  for (int i = 1; i < n - 1; i++)
  {
    for (int j = 1; j < m - 1; j++)
    {
      int cur = g[i][j];
      bool ok = cur > max_left[i][j - 1] ||
                cur > max_right[i][j + 1] ||
                cur > max_top[i - 1][j] ||
                cur > max_bottom[i + 1][j];
      res += ok;
    }
  }

  cout << res << nl;

  int mx = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int cur = g[i][j];
      int c1 = 0;
      for (int x = j + 1; x < m; x++)
      {
        c1++;
        if (g[i][x] >= cur)
          break;
      }
      int c2 = 0;
      for (int x = j - 1; x >= 0; x--)
      {
        c2++;
        if (g[i][x] >= cur)
          break;
      }
      int c3 = 0;
      for (int x = i + 1; x < n; x++)
      {
        c3++;
        if (g[x][j] >= cur)
          break;
      }
      int c4 = 0;
      for (int x = i - 1; x >= 0; x--)
      {
        c4++;
        if (g[x][j] >= cur)
          break;
      }
      mx = max(mx, c1 * c2 * c3 * c4);
    }
  }
  cout << mx << nl;

  return 0;
}