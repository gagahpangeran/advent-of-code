#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;
typedef vector<string> vs;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  ll x;

  vs hands;
  map<string, ll> bids;

  while (cin >> s >> x)
  {
    hands.push_back(s);
    bids[s] = x;
  }

  string sym = "23456789TJQKA";
  map<char, int> str;
  for (int i = 0; i < (int)sym.size(); i++)
  {
    str[sym[i]] = i;
  }

  auto Check = [&](string s, bool with_joker = false)
  {
    map<char, int> cnt;
    for (auto c : s)
      cnt[c]++;

    int joker = 0;
    if (with_joker)
    {
      if (cnt.find('J') != cnt.end())
      {
        joker = cnt['J'];
        cnt.erase('J');
      }
    }

    vector<int> wut;
    for (auto [k, v] : cnt)
      wut.push_back(v);

    // assert(wut.size() > 0);

    if (wut.size() > 0)
    {
      sort(wut.begin(), wut.end(), greater<int>());

      wut[0] += joker;
    }
    else
    {
      wut.push_back(joker);
    }

    if (wut[0] == 5)
      return 6;

    if (wut[0] == 4)
      return 5;

    if (wut[0] == 3 && wut[1] == 2)
      return 4;

    if (wut[0] == 3 && wut[1] == 1)
      return 3;

    if (wut[0] == 2 && wut[1] == 2)
      return 2;

    if (wut[0] == 2 && wut[1] == 1)
      return 1;

    return 0;
  };

  auto TieBreak = [&](string h1, string h2, bool with_joker = false)
  {
    assert(h1.size() == h2.size());

    if (with_joker)
    {
      str['J'] = -1;
    }

    for (int i = 0; i < (int)h1.size(); i++)
    {
      if (h1[i] != h2[i])
      {
        return str[h1[i]] < str[h2[i]];
      }
    }

    assert(false);
  };

  auto Compare = [&](string h1, string h2, bool with_joker = false)
  {
    assert(h1.size() == h2.size());

    int c1 = Check(h1, with_joker);
    int c2 = Check(h2, with_joker);

    if (c1 == c2)
      return TieBreak(h1, h2, with_joker);

    return c1 < c2;
  };

  sort(hands.begin(), hands.end(), Compare);

  ll res = 0;
  for (int i = 0; i < (int)hands.size(); i++)
  {
    res += (i + 1) * bids[hands[i]];
  }

  cout << res << nl;

  sort(hands.begin(), hands.end(), [&](string h1, string h2)
       { return Compare(h1, h2, true); });

  ll res2 = 0;
  for (int i = 0; i < (int)hands.size(); i++)
  {
    res2 += (i + 1) * bids[hands[i]];
  }

  cout << res2 << nl;

  return 0;
}