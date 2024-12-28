#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const ll INF = 1e18;

vector<string> numpad = {
    "789",
    "456",
    "123",
    "x0A",
};

vector<string> dpad = {
    "x^A",
    "<v>",
};

map<char, pii> dirs = {
    {'^', {-1, 0}},
    {'v', {1, 0}},
    {'<', {0, -1}},
    {'>', {0, 1}},
};

map<pcc, set<string>> all_paths;

void gen_path(vector<string> &keypad)
{
  int n = keypad.size();
  int m = keypad[0].size();

  auto chk_path = [&](pii spos, pii epos, string path)
  {
    auto [ci, cj] = spos;
    assert(keypad[ci][cj] != 'x');

    for (auto arr : path)
    {
      auto [di, dj] = dirs[arr];
      int ni = ci + di;
      int nj = cj + dj;

      if (keypad[ni][nj] == 'x')
        return false;

      ci = ni;
      cj = nj;
    }

    assert(epos == pii(ci, cj));
    return true;
  };

  auto insert_path = [&](int ai, int aj, int bi, int bj)
  {
    char start = keypad[ai][aj];
    char end = keypad[bi][bj];

    if (start == 'x' || end == 'x')
      return;

    int di = ai - bi;
    int dj = aj - bj;

    char ver_arr = di >= 0 ? '^' : 'v';
    char hor_arr = dj >= 0 ? '<' : '>';

    string ver_path = string(abs(di), ver_arr);
    string hor_path = string(abs(dj), hor_arr);

    string path1 = ver_path + hor_path;
    string path2 = hor_path + ver_path;

    if (chk_path({ai, aj}, {bi, bj}, path1))
      all_paths[{start, end}].insert(path1 + 'A');

    if (chk_path({ai, aj}, {bi, bj}, path2))
      all_paths[{start, end}].insert(path2 + 'A');
  };

  for (int ai = 0; ai < n; ai++)
    for (int aj = 0; aj < m; aj++)
      for (int bi = 0; bi < n; bi++)
        for (int bj = 0; bj < m; bj++)
          insert_path(ai, aj, bi, bj);
}

void gen_all_paths()
{
  gen_path(numpad);
  gen_path(dpad);
}

map<tuple<char, char, ll>, ll> memo;

int def_depth = 22;

ll get_path_size(string s, int depth = 0)
{
  auto get_min_path = [&](char start, char end)
  {
    if (memo.find({start, end, depth}) != memo.end())
      return memo[{start, end, depth}];

    ll sz = INF;
    for (auto path : all_paths[{start, end}])
    {
      ll cur = depth == 0 ? path.size() : get_path_size(path, depth - 1);
      sz = min(sz, cur);
    }

    memo[{start, end, depth}] = sz;
    return sz;
  };

  ll res = 0;
  for (int i = 0; i < (int)s.size(); i++)
  {
    char prev = i == 0 ? 'A' : s[i - 1];
    res += get_min_path(prev, s[i]);
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  gen_all_paths();

  string s;

  ll res = 0;
  ll res2 = 0;
  while (cin >> s)
  {
    ll pz = get_path_size(s, 2);
    ll pz2 = get_path_size(s, 25);
    ll num = stoll(s.substr(0, 3));
    res += pz * num;
    res2 += pz2 * num;
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}
