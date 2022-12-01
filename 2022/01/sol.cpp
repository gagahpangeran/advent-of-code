#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  vector<ll> cal;
  ll cur = 0;
  while (getline(cin, s))
  {
    if (s.size() == 0)
    {
      cal.push_back(cur);
      cur = 0LL;
    }
    else
    {
      cur += stoll(s);
    }
  }
  cal.push_back(cur);

  sort(cal.begin(), cal.end(), greater<ll>());

  cout << cal[0] << nl;
  cout << cal[0] + cal[1] + cal[2] << nl;

  return 0;
}