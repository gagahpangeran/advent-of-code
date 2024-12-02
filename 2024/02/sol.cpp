#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

vector<string> split(string s)
{
  istringstream iss(s);
  vector<string> v;
  string ss;

  while (iss >> ss)
    v.push_back(ss);

  return v;
}

vector<int> to_vi(vector<string> v)
{
  vector<int> res;
  for (auto i : v)
    res.push_back(stoll(i));
  return res;
}

bool check(vector<int> &v)
{
  int n = v.size();
  vector<int> diff;
  bool is_pos;

  for (int i = 1; i < n; i++)
  {
    int d = v[i] - v[i - 1];

    if (abs(d) < 1 || abs(d) > 3)
      return false;

    if (i == 1)
      is_pos = d > 0;
    else if ((d > 0) != is_pos)
      return false;
  }

  return true;
}

bool check2(vector<int> &v)
{
  if (check(v))
    return true;

  int n = v.size();

  for (int i = 0; i < n; i++)
  {
    vector<int> v_now;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
        v_now.push_back(v[j]);
    }

    if (check(v_now))
      return true;
  }

  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int res = 0, res2 = 0;

  while (getline(cin, s))
  {
    auto vi = to_vi(split(s));
    res += check(vi);
    res2 += check2(vi);
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}