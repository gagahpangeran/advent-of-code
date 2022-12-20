#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define fi first
#define se second

typedef vector<int> vi;
typedef pair<int, int> pii;

void p(vi &v)
{
  for (auto i : v)
    cout << i << " ";
  cout << nl;
}

void p(vector<pii> &v)
{
  for (auto &[i, j] : v)
    cout << "(" << i << ", " << j << ") ";
  cout << nl;
}

int mod(int a, int b)
{
  return (a % b + b) % b;
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  vi v;

  while (cin >> x)
    v.push_back(x);

  int n = v.size();

  vector<pii> u;
  pii zero;

  for (int i = 0; i < n; i++)
  {
    if (v[i] == 0)
      zero = {v[i], i};

    u.push_back({v[i], i});
  }

  for (int i = 0; i < n; i++)
  {
    int pos = find(u.begin(), u.end(), pair{v[i], i}) - u.begin();
    int npos = mod(pos + u[pos].fi, n);

    int num = u[pos].fi;
    int nx = num > 0 ? 1 : -1;
    int step = abs(num);
    int cur = pos;

    while (step--)
    {
      int next = mod(cur + nx, n);
      swap(u[cur], u[next]);
      cur = next;
    }
  }

  int zpos = find(u.begin(), u.end(), zero) - u.begin();

  int res = 0;
  for (int i = 1; i <= 3; i++)
  {
    int t = mod(zpos + (i * 1e3), n);
    res += u[t].fi;
  }

  cout << res << nl;

  return 0;
}