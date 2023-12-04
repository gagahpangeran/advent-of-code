#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<int, int> pii;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> schema;
  string s;

  while (cin >> s)
  {
    schema.push_back(s);
  }

  map<pii, string> nums;
  map<pii, char> sym;

  for (int i = 0; i < (int)schema.size(); i++)
  {
    string number = "";
    for (int j = 0; j < (int)schema[i].size(); j++)
    {
      char c = schema[i][j];

      if (isdigit(c))
      {
        number += c;

        if ((j + 1 < schema[i].size() && !isdigit(schema[i][j + 1])) ||
            (j + 1 >= schema[i].size()))
        {
          pii coor = {i, j + 1 - (int)number.size()};
          nums[coor] = number;
          number = "";
        }
      }
      else if (c != '.')
      {
        sym[{i, j}] = c;
      }
    }
  }

  int res1 = 0;
  int res2 = 0;

  map<pii, int> wut;

  for (auto [k, v] : nums)
  {
    auto [a, b] = k;

    for (int i = a - 1; i <= a + 1; i++)
    {
      for (int j = b - 1; j <= b + (int)v.size(); j++)
      {
        if (sym.find({i, j}) != sym.end())
        {
          res1 += stoi(v);

          if (sym[{i, j}] == '*')
          {
            if (wut.find({i, j}) != wut.end())
            {
              res2 += wut[{i, j}] * stoi(v);
            }
            else
            {
              wut[{i, j}] = stoi(v);
            }
          }

          break;
        }
      }
    }
  }

  cout << res1 << nl;
  cout << res2 << nl;

  return 0;
}
