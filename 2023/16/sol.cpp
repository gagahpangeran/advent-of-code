#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define fi first
#define se second

typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<char, pii> pcp;

vs g;
int n, m;

map<char, pii> mv = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}},
};

map<pcc, string> nx = {
    {{'R', '|'}, "UD"},
    {{'L', '|'}, "UD"},
    {{'U', '-'}, "LR"},
    {{'D', '-'}, "LR"},
    {{'R', '/'}, "U"},
    {{'L', '/'}, "D"},
    {{'U', '/'}, "R"},
    {{'D', '/'}, "L"},
    {{'R', '\\'}, "D"},
    {{'L', '\\'}, "U"},
    {{'U', '\\'}, "L"},
    {{'D', '\\'}, "R"},
};

int solve(char dir, pii pos)
{
  vector<pcp> st;
  set<pcp> vis;
  set<pii> vpos;

  st.push_back({dir, pos});

  while (!st.empty())
  {
    auto cur = *st.rbegin();
    st.pop_back();

    if (vis.find(cur) != vis.end())
      continue;

    vis.insert(cur);

    auto &[cdir, cpos] = cur;
    vpos.insert(cpos);

    auto &[i, j] = cpos;

    char cb = g[i][j];

    string ndir = "";

    if (nx.find({cdir, cb}) != nx.end())
      ndir += nx[{cdir, cb}];
    else
      ndir += cdir;

    for (auto nd : ndir)
    {
      auto &[mi, mj] = mv[nd];
      int ni = i + mi;
      int nj = j + mj;

      if (0 <= ni && ni < n && 0 <= nj && nj < m)
      {
        pcp nxt = {nd, {ni, nj}};
        if (vis.find(nxt) == vis.end())
          st.push_back(nxt);
      }
    }
  }

  return vpos.size();
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

  cout << solve('R', {0, 0}) << nl;

  int res = 0;

  for (int i = 0; i < m; i++)
  {
    res = max(res, solve('D', {0, i}));
    res = max(res, solve('U', {n - 1, i}));
  }

  for (int i = 0; i < n; i++)
  {
    res = max(res, solve('R', {i, 0}));
    res = max(res, solve('L', {i, m - 1}));
  }

  cout << res << nl;

  return 0;
}