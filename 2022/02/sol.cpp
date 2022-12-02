#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

char op, me;
ll res = 0LL, res2 = 0LL;

void solve1()
{
  res += me - 'X' + 1;
  if (op - 'A' == me - 'X')
    res += 3;
  else if (me == 'X' && op == 'C' ||
           me == 'Y' && op == 'A' ||
           me == 'Z' && op == 'B')
    res += 6;
}

int mod(int a, int b)
{
  return (a % b + b) % b;
};

void solve2()
{
  int val = op - 'A';
  if (me == 'X')
    res2 += mod(val - 1, 3) + 1;
  else if (me == 'Y')
    res2 += val + 1 + 3;
  else if (me == 'Z')
    res2 += mod(val + 1, 3) + 1 + 6;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> op >> me)
  {
    solve1();
    solve2();
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}