#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int cy = 0;

  set<int> sig = {20, 60, 100, 140, 180, 220};
  int x = 1;
  int res = 0;

  while (getline(cin, s))
  {
    if (s == "noop")
    {
      cy++;

      int pos = cy % 40;
      if (pos == 0)
        pos = 40;
      if (x <= pos && pos <= x + 2)
        cout << "#";
      else
        cout << ".";
      if (cy % 40 == 0)
        cout << nl;

      if (sig.find(cy) != sig.end())
      {
        res += cy * x;
      }
    }
    else
    {
      int val = stoi(s.substr(5));
      cy++;

      int pos = cy % 40;
      if (pos == 0)
        pos = 40;
      if (x <= pos && pos <= x + 2)
        cout << "#";
      else
        cout << ".";
      if (cy % 40 == 0)
        cout << nl;
      if (sig.find(cy) != sig.end())
      {
        res += cy * x;
      }
      cy++;
      pos = cy % 40;
      if (pos == 0)
        pos = 40;
      if (x <= pos && pos <= x + 2)
        cout << "#";
      else
        cout << ".";
      if (cy % 40 == 0)
        cout << nl;
      if (sig.find(cy) != sig.end())
      {
        res += cy * x;
      }
      x += val;
    }
  }

  cout << res << nl;

  return 0;
}