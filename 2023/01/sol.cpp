#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

map<string, int> num;
vector<string> letters = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int parse1(string s)
{
  vector<int> val;

  for (auto c : s)
  {
    int dig = c - '0';

    if (0 <= dig && dig <= 9)
    {
      val.push_back(dig);
    }
  }

  assert(val.size() > 0);

  return val[0] * 10 + val[val.size() - 1];
}

int parse2(string s)
{

  vector<int> val;

  for (int i = 0; i < (int)s.size(); i++)
  {
    for (auto [k, v] : num)
    {
      if (s.substr(i, k.size()) == k)
      {
        val.push_back(v);
      }
    }
  }

  assert(val.size() > 0);

  return val[0] * 10 + val[val.size() - 1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int res1 = 0;
  int res2 = 0;

  for (int i = 0; i <= 9; i++)
  {
    num[to_string(i)] = i;
    num[letters[i]] = i;
  }

  while (cin >> s)
  {
    res1 += parse1(s);
    res2 += parse2(s);
  }

  cout << res1 << nl;
  cout << res2 << nl;

  return 0;
}