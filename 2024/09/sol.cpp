#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef pair<int, int> pii;

void solve1(string &s)
{
  deque<int> b;
  int tsz = 0;

  for (int i = 0; i < (int)s.size(); i++)
  {
    for (int j = 0; j < (s[i] - '0'); j++)
    {
      if (i % 2 == 0)
      {
        b.push_back(i / 2);
        tsz++;
      }
    }
  }

  vector<int> r;
  for (int i = 0; i < (int)s.size(); i++)
  {
    for (int j = 0; j < (s[i] - '0'); j++)
    {
      if (b.size() <= 0 || (int)r.size() == tsz)
        break;

      int cur;
      if (i % 2 == 0)
      {
        cur = b.front();
        b.pop_front();
      }
      else
      {
        cur = b.back();
        b.pop_back();
      }
      r.push_back(cur);
    }
  }

  ll res = 0;
  for (int i = 0; i < (int)r.size(); i++)
    res += i * r[i];

  cout << res << nl;
}

void solve2(string &s)
{
  vector<pii> files, empty;
  int pos = 0;

  for (int i = 0; i < (int)s.size(); i++)
  {
    int cur = s[i] - '0';

    if (i % 2 == 0)
      files.push_back({pos, cur});
    else
      empty.push_back({pos, cur});

    pos += cur;
  }

  int sz = files.size();
  map<int, pii> r;

  for (int i = sz - 1; i >= 0; i--)
  {
    auto [cpos, csize] = files[i];
    int kpos = cpos;

    for (int j = 0; j < (int)empty.size(); j++)
    {
      auto [epos, esize] = empty[j];
      if (esize >= csize && epos < cpos)
      {
        kpos = epos;
        empty[j] = {epos + csize, esize - csize};
        break;
      }
    }

    r[kpos] = {i, csize};
  }

  ll res = 0;
  for (auto [pos, file] : r)
  {
    auto [id, size] = file;
    for (int i = 0; i < size; i++)
      res += id * (pos + i);
  }

  cout << res << nl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  solve1(s);
  solve2(s);

  return 0;
}
