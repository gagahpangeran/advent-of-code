#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

ll count(vector<int> &a, int max_count)
{
  int n = a.size();
  int start = 0;
  ll res = 0;

  for (int i = max_count - 1; i >= 0; i--)
  {
    int end = n - i;
    int idx = max_element(a.begin() + start, a.begin() + end) - a.begin();
    start = idx + 1;
    res = (res * 10) + a[idx];
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  ll res1 = 0, res2 = 0;

  while (cin >> s)
  {
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      a[i] = s[i] - '0';

    res1 += count(a, 2);
    res2 += count(a, 12);
  }

  cout << res1 << nl;
  cout << res2 << nl;

  return 0;
}