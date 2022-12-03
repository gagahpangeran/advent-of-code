#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

string s;
int res = 0;

void solve()
{
  int n = s.size();
  assert(n % 2 == 0);
  int half = n / 2;
  set<char> st(s.begin(), s.begin() + half);
  set<char> su(s.begin() + half, s.end());
  for (auto c : su)
  {
    if (st.find(c) != st.end())
    {
      if ((int)'a' <= (int)c && (int)c <= (int)'z')
        res += c - 'a' + 1;
      else
        res += c - 'A' + 27;
    }
  }
}

vector<string> v;
int res2 = 0;

void solve2()
{
  v.push_back(s);

  if (v.size() != 3)
    return;

  set<char> st(v[0].begin(), v[0].end());
  set<char> su;
  for (auto c : v[1])
  {
    if (st.find(c) != st.end())
      su.insert(c);
  }
  set<char> sv;
  for (auto c : v[2])
  {
    if (su.find(c) != su.end())
      sv.insert(c);
  }
  for (auto c : sv)
  {
    if ((int)'a' <= (int)c && (int)c <= (int)'z')
      res2 += c - 'a' + 1;
    else
      res2 += c - 'A' + 27;
  }
  v.clear();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> s)
  {
    solve();
    solve2();
  }
  cout << res << nl;
  cout << res2 << nl;

  return 0;
}
