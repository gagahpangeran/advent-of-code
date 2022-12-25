#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

ll convert(string s)
{
  reverse(s.begin(), s.end());

  map<char, ll> sym = {
      {'=', -2},
      {'-', -1},
      {'0', 0},
      {'1', 1},
      {'2', 2},
  };

  ll res = 0;

  for (ll i = 0; i < s.size(); i++)
    res += sym[s[i]] * (ll)pow(5LL, i);

  return res;
}

ll mod(ll a, ll b)
{
  return (a % b + b) % b;
};

string conback(ll n)
{
  vector<string> sym = {"=", "-", "0", "1", "2"};

  if (n <= 0)
    return sym[n + 2];

  string res = "";
  while (n > 0)
  {
    n += 2LL;
    res = sym[mod(n, 5LL)] + res;
    n = n / 5;
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<string> snafus;

  while (getline(cin, s))
    snafus.push_back(s);

  ll tot = 0;
  for (auto sn : snafus)
    tot += convert(sn);

  cout << conback(tot) << nl;

  return 0;
}