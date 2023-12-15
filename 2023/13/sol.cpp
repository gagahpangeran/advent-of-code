#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

template <typename T>
void pvec(T v, string sep = " ")
{
  for (auto i : v)
    cout << i << sep;
  cout << nl;
}

vs transpose(vs v)
{
  int n = v.size();
  int m = v[0].size();

  vs vres(m, string(n, '.'));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      vres[j][i] = v[i][j];
    }
  }

  return vres;
}

int check(vs v)
{
  int sz = v.size();

  for (int i = 0; i < sz - 1; i++)
  {
    if (v[i] == v[i + 1])
    {
      vs st(v.begin(), v.begin() + i + 1);
      int j = i + 1;
      bool ok = true;

      while (!st.empty() && j < sz)
      {
        ok = ok && (*st.rbegin() == v[j]);
        st.pop_back();
        j++;
      }

      if (ok)
        return i + 1;
    }
  }

  return -1;
}

int solve1(vs pt)
{
  vs tp = transpose(pt);

  int tres = check(tp);

  if (tres != -1)
    return tres;

  int pres = check(pt);

  assert(pres != -1);

  return 100 * pres;
}

bool almost_eq(string s, string t)
{
  assert(s.size() == t.size());
  int n = s.size();
  vi dif;

  for (int i = 0; i < n; i++)
  {
    if (s[i] != t[i])
      dif.push_back(i);
  }

  return dif.size() == 1;
}

vi check2(vs v)
{
  int sz = v.size();
  vi res;

  for (int i = 0; i < sz - 1; i++)
  {
    bool can_smudge = true;
    if (v[i] == v[i + 1] || almost_eq(v[i], v[i + 1]))
    {
      vs st(v.begin(), v.begin() + i + 1);
      int j = i + 1;
      bool ok = true;

      while (!st.empty() && j < sz)
      {
        string cur = *st.rbegin();
        bool same = cur == v[j];
        if (!same && can_smudge && almost_eq(cur, v[j]))
        {
          same = true;
          can_smudge = false;
        }

        ok = ok && same;
        st.pop_back();
        j++;
      }

      if (ok)
      {
        res.push_back(i + 1);
      }
    }
  }

  return res;
}

int solve2(vs pt, int prev)
{
  vs tp = transpose(pt);

  vi tres = check2(tp);

  for (auto r : tres)
  {
    if (r != prev)
      return r;
  }

  vi pres = check2(pt);

  for (auto r : pres)
  {
    if (100 * r != prev)
      return 100 * r;
  }

  assert(false);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  vs pat;

  int res = 0;
  int res2 = 0;

  while (getline(cin, s))
  {
    if (s.size() != 0)
    {
      pat.push_back(s);
      continue;
    }

    int s1 = solve1(pat);
    res += s1;
    int s2 = solve2(pat, s1);
    res2 += s2;
    pat.clear();
  }

  cout << res << nl;
  cout << res2 << nl;

  return 0;
}