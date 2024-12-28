#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vector<string> pattern;
  vector<vector<int>> locks, schema;

  auto add_pattern = [&](vector<string> &pat)
  {
    vector<int> nums(5, 0);
    for (int i = 1; i <= 5; i++)
    {
      for (int j = 0; j < 5; j++)
        nums[j] += (pat[i][j] == '#');
    }

    if (pat[0] == string(5, '#'))
      locks.push_back(nums);
    else if (pat[0] == string(5, '.'))
      schema.push_back(nums);
    else
      assert(false);
  };

  while (getline(cin, s))
  {
    if (s.size() != 0)
    {
      pattern.push_back(s);
    }
    else
    {
      add_pattern(pattern);
      pattern.clear();
    }
  }
  add_pattern(pattern);

  auto chk = [&](vector<int> &lock, vector<int> &sch)
  {
    assert(lock.size() == sch.size());
    int n = lock.size();

    for (int i = 0; i < n; i++)
    {
      if (lock[i] + sch[i] > 5)
        return false;
    }

    return true;
  };

  int res = 0;

  for (auto lock : locks)
    for (auto sch : schema)
      res += chk(lock, sch);

  cout << res << nl;

  return 0;
}
