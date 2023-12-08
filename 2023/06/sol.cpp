#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

vs split(string s)
{
  istringstream iss(s);
  vs v;
  string ss;

  while (iss >> ss)
    v.push_back(ss);

  return v;
}

vi to_vi(vs v)
{
  vi res;
  for (auto i : v)
  {
    res.push_back(stoll(i));
  }
  return res;
}

template <typename T>
void pvec(T v)
{
  for (auto i : v)
    cout << i << nl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  getline(cin, s);

  auto pt = split(s);
  pt.erase(pt.begin());

  string rt = "";
  for (auto t : pt)
    rt += t;
  ll rtime = stoll(rt);

  vi times = to_vi(pt);

  getline(cin, s);

  auto pd = split(s);
  pd.erase(pd.begin());

  string rd = "";
  for (auto d : pd)
    rd += d;
  ll rdist = stoll(rd);

  vi dists = to_vi(pd);

  assert(times.size() == dists.size());

  int sz = times.size();

  int res1 = 1;
  for (int i = 0; i < sz; i++)
  {
    int cnt = 0;
    for (int j = 1; j < times[i]; j++)
    {
      int dis = j * (times[i] - j);
      cnt += dis > dists[i];
    }
    res1 *= cnt;
  }

  cout << res1 << nl;

  int res2 = 0;
  for (int i = 1; i < rtime; i++)
  {
    bool ok = (rtime - i) > (rdist / i);
    res2 += ok;
  }

  cout << res2 << nl;

  return 0;
}