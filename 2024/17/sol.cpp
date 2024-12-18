#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef long long ll;

vector<string> split(string s, char delim)
{
  istringstream iss(s);
  vector<string> v;
  string ss;

  while (getline(iss, ss, delim))
    v.push_back(ss);

  return v;
}

vector<ll> to_vi(vector<string> v)
{
  vector<ll> res;
  for (auto i : v)
  {
    res.push_back(stoll(i));
  }
  return res;
}

void pvec(vector<ll> &v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
    cout << v[i] << ",\n"[i == n - 1];
}

vector<ll> solve(ll a, ll b, ll c, vector<ll> &ins)
{
  ll sz = ins.size();
  ll pointer = 0;
  vector<ll> out;

  auto combo = [&](ll operand)
  {
    switch (operand)
    {
    case 0:
    case 1:
    case 2:
    case 3:
      return operand;

    case 4:
      return a;

    case 5:
      return b;

    case 6:
      return c;

    default:
      assert(false);
    }
  };

  while (0 <= pointer && pointer < sz)
  {
    ll opcode = ins[pointer];
    ll operand = ins[pointer + 1];

    switch (opcode)
    {
    case 0:
      a = a / pow(2, combo(operand));
      break;

    case 1:
      b = b ^ operand;
      break;

    case 2:
      b = combo(operand) % 8;
      break;

    case 3:
      if (a != 0)
      {
        pointer = operand;
        continue;
      }
      break;

    case 4:
      b = b ^ c;
      break;

    case 5:
      out.push_back(combo(operand) % 8);
      break;

    case 6:
      b = a / pow(2, combo(operand));
      break;

    case 7:
      c = a / pow(2, combo(operand));
      break;

    default:
      assert(false);
    }

    pointer += 2;
  }

  return out;
}

bool find_num(ll depth, ll cur, ll b, ll c, vector<ll> &ins)
{
  ll base = 8;
  ll max_bit = 16;
  ll dbit = 4;

  if (depth * dbit > max_bit)
  {
    cout << cur << nl;
    return true;
  }

  for (ll i = 0; i < pow(base, dbit); i++)
  {
    ll num = cur + i * pow(base, max_bit - (dbit * depth));
    auto out = solve(num, b, c, ins);
    if (equal(ins.end() - (dbit * depth), ins.end(), out.end() - (dbit * depth)))
    {
      if (find_num(depth + 1, num, b, c, ins))
        break;
    }
  }

  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string __, aa, bb, cc, pp;

  cin >> __ >> __ >> aa;
  cin >> __ >> __ >> bb;
  cin >> __ >> __ >> cc;
  cin >> __ >> pp;

  ll a = stoll(aa);
  ll b = stoll(bb);
  ll c = stoll(cc);
  vector<ll> ins = to_vi(split(pp, ','));

  vector<ll> out = solve(a, b, c, ins);
  pvec(out);

  find_num(1, 0, b, c, ins);

  return 0;
}
