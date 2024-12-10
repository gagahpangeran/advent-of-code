#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  vector<vector<int>> g;

  while (cin >> s)
  {
    vector<int> v;
    for (auto c : s)
      v.push_back(c - '0');
    g.push_back(v);
  }

  int n = g.size();
  int m = g[0].size();

  vector<pii> nx = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  auto chk_bound = [&](int i, int j)
  {
    return 0 <= i && i < n && 0 <= j && j < m;
  };

  function<int(int, int, set<pii> &)> dfs = [&](int i, int j, set<pii> &st)
  {
    if (g[i][j] == 9)
    {
      st.insert({i, j});
      return 1;
    }

    int res = 0;

    for (auto [ni, nj] : nx)
    {
      int mi = i + ni;
      int mj = j + nj;

      if (chk_bound(mi, mj) && g[mi][mj] - g[i][j] == 1)
        res += dfs(mi, mj, st);
    }

    return res;
  };

  int res = 0;
  int res2 = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (g[i][j] == 0)
      {
        set<pii> st;
        res2 += dfs(i, j, st);
        res += st.size();
      }
    }
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}
