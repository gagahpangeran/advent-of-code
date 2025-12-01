#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int mod(int a, int b)
{
  return (a % b + b) % b;
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  char rot;
  int num;

  int cur = 50;
  int MOD = 100;
  int res1 = 0, res2 = 0;

  while (scanf("%c%d\n", &rot, &num) != EOF)
  {
    int sign = rot == 'L' ? -1 : 1;

    while (num--)
    {
      cur = mod(cur + sign, MOD);
      res2 += cur == 0;
    }

    res1 += cur == 0;
  }

  cout << res1 << nl;
  cout << res2 << nl;

  return 0;
}