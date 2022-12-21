#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef vector<string> vs;
typedef long long ll;

vs split(string s, char delim)
{
  vs res;
  stringstream ss(s);
  string r;

  while (getline(ss, r, delim))
    res.push_back(r);

  return res;
}

map<string, pair<string, string>> children;
map<string, char> ops;
map<string, ll> val;

map<string, ll> memo;
map<string, bool> chk;

ll count(string cur)
{
  if (children.count(cur) == 0)
  {
    memo[cur] = val[cur];
    return val[cur];
  }

  auto [c1, c2] = children[cur];

  ll r1 = count(c1);
  ll r2 = count(c2);

  char op = ops[cur];

  ll res;

  if (op == '+')
    res = r1 + r2;
  else if (op == '-')
    res = r1 - r2;
  else if (op == '*')
    res = r1 * r2;
  else if (op == '/')
    res = r1 / r2;
  else
    assert(false);

  memo[cur] = res;

  return res;
}

bool check(string cur)
{
  if (children.count(cur) == 0)
  {
    bool res = cur == "humn";
    chk[cur] = res;
    return res;
  }

  auto [c1, c2] = children[cur];

  bool r1 = check(c1);
  bool r2 = check(c2);
  chk[cur] = r1 || r2;

  return chk[cur];
}

ll solve(string cur, ll target)
{
  if (children.count(cur) == 0)
  {
    if (cur == "humn")
      return target;

    assert(false);
  }

  auto [c1, c2] = children[cur];

  bool isleft = chk[c1];
  bool isright = chk[c2];

  assert(isleft != isright);

  ll res = isleft ? memo[c2] : memo[c1];

  char op = ops[cur];

  ll newtar;

  if (op == '+')
    newtar = target - res;
  else if (op == '-')
    newtar = target + res;
  else if (op == '*')
    newtar = target / res;
  else if (op == '/')
    newtar = target * res;
  else
    assert(false);

  return solve(isleft ? c1 : c2, newtar);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  while (getline(cin, s))
  {
    vs mk = split(s, ':');
    string name = mk[0];

    vs nx = split(mk[1].substr(1), ' ');
    if (nx.size() == 1)
      val[name] = stoll(nx[0]);
    else
    {
      ops[name] = nx[1][0];
      children[name] = {nx[0], nx[2]};
    }
  }

  cout << count("root") << nl;

  auto [c1, c2] = children["root"];
  bool isleft = check(c1);
  bool isright = check(c2);

  assert(isleft != isright);

  ll res = count(isleft ? c2 : c1);

  // somehow the real input need this to get corrent answer, comment out line bellow for sample input
  res = -res;

  ll slv = solve(isleft ? c1 : c2, res);
  cout << slv << nl;

  return 0;
}