#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
typedef long long ll;

void process_input(string &s, vector<ll> &nums)
{
  regex re("\\d+");
  smatch match;
  while (regex_search(s, match, re))
  {
    nums.push_back(stoll(match.str()));
    s = match.suffix();
  }
}

ll solve(vector<ll> &nums, int part)
{
  assert(nums.size() == 6);

  ll a1 = nums[0];
  ll a2 = nums[1];
  ll b1 = nums[2];
  ll b2 = nums[3];
  ll c1 = nums[4];
  ll c2 = nums[5];

  if (part == 2)
  {
    ll pad = 10000000000000;
    c1 += pad;
    c2 += pad;
  }

  ll d = a1 * b2 - a2 * b1;
  ll dx = c1 * b2 - b1 * c2;
  ll dy = a1 * c2 - c1 * a2;

  if (dx % d != 0 || dy % d != 0)
    return 0LL;

  ll x = dx / d;
  ll y = dy / d;

  return 3LL * x + y;
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  vector<ll> nums;
  ll res = 0, res2 = 0;
  while (getline(cin, s))
  {
    process_input(s, nums);

    if (nums.size() == 6)
    {
      res += solve(nums, 1);
      res2 += solve(nums, 2);
      nums.clear();
    }
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}
