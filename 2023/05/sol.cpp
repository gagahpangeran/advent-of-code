#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
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

template <typename T>
void pvec(T v)
{
  for (auto i : v)
    cout << i << nl;
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

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<ll> seeds;

  while (getline(cin, s))
  {
    if (s == "")
      continue;

    auto sp = split(s);

    string wat = sp.front();

    if (wat == "seeds:")
    {
      sp.erase(sp.begin());
      seeds = to_vi(sp);
    }
    else
    {
      vector<vi> mp;

      while (getline(cin, s))
      {
        if (s == "")
          break;

        auto vmp = to_vi(split(s));
        mp.push_back(vmp);
      }

      for (int i = 0; i < (int)seeds.size(); i++)
      {
        ll seed = seeds[i];

        for (auto vmp : mp)
        {
          ll dest_start = vmp[0];
          ll src_start = vmp[1];
          ll range = vmp[2];

          if (src_start <= seed && seed <= src_start + range - 1)
          {
            ll dest = dest_start + (seed - src_start);
            seeds[i] = dest;
            break;
          }
        }
      }
    }
  }

  ll res = *min_element(seeds.begin(), seeds.end());
  cout << res << nl;

  return 0;
}