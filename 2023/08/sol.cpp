#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  getline(cin, s);
  string ins = s;

  getline(cin, s);

  map<string, pair<string, string>> mp;

  while (getline(cin, s))
  {
    regex r(R"((\w+) = \((\w+), (\w+)\))");
    smatch m;
    regex_match(s, m, r);
    mp[m[1]] = {m[2], m[3]};
  }

  int pos = 0;
  int step = 0;
  string cur = "AAA";
  int sz = ins.size();

  // input sample 3 not working with this while loop
  while (cur != "ZZZ")
  {
    step++;
    int dir = ins[pos];
    cur = dir == 'L' ? mp[cur].first : mp[cur].second;
    pos = (pos + 1) % sz;
  }

  cout << step << nl;

  vector<string> curs;
  vector<string> goals;

  for (auto [k, v] : mp)
  {
    if (k[2] == 'A')
      curs.push_back(k);
    else if (k[2] == 'Z')
      goals.push_back(k);
  }

  vector<int> steps;
  ll res = 1;

  for (auto cur : curs)
  {
    ll step = 0;
    int pos = 0;

    while (cur[2] != 'Z')
    {
      step++;
      char dir = ins[pos];
      cur = dir == 'L' ? mp[cur].first : mp[cur].second;
      pos = (pos + 1) % sz;
    }
    // cout << step << nl;
    // steps.push_back(step);
    res = lcm(res, step);
  }

  cout << res << nl;

  return 0;
}