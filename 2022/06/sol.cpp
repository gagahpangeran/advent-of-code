#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();
  for (int i = 0; i < n - 3; i++)
  {
    set<char> st(s.begin() + i, s.begin() + i + 4);
    if (st.size() == 4)
    {
      cout << i + 4 << nl;
      break;
    }
  }

  for (int i = 0; i < n - 13; i++)
  {
    set<char> st(s.begin() + i, s.begin() + i + 14);
    if (st.size() == 14)
    {
      cout << i + 14 << nl;
      break;
    }
  }

  return 0;
}