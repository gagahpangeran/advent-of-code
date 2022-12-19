#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

map<string, vector<string>> gr;
map<string, int> rt;
map<pair<string, string>, int> apsp;
vector<string> nozero;

int BFS(string start, string end)
{
  queue<string> q;
  set<string> vis;
  map<string, int> dist;

  vis.insert(start);
  q.push(start);
  dist[start] = 0;

  while (!q.empty())
  {
    string cur = q.front();
    q.pop();

    for (auto next : gr[cur])
    {
      if (vis.find(next) == vis.end())
      {
        vis.insert(next);
        dist[next] = dist[cur] + 1;
        q.push(next);

        if (next == end)
          return dist[end];
      }
    }
  }

  return dist[end];
};

int dist(string x, string y)
{
  if (apsp.count({x, y}) > 0)
    return apsp[{x, y}];

  return apsp[{y, x}];
};

map<tuple<string, int, set<string>>, int> memo;

int solve(string cur, int time, set<string> next)
{
  next.erase(cur);

  if (next.empty())
    return 0;

  if (memo.count({cur, time, next}) > 0)
    return memo[{cur, time, next}];

  int res = 0;

  for (auto nx : next)
  {
    int tm = dist(cur, nx) + 1;
    int tleft = time - tm;
    if (tleft <= 0)
      continue;

    int nr = (tleft * rt[nx]) + solve(nx, tleft, next);
    res = max(nr, res);
  }

  memo[{cur, time, next}] = res;

  return res;
}

void solve1()
{
  int res = solve("AA", 30, set<string>(nozero.begin(), nozero.end()));
  cout << res << nl;
}

void solve2()
{
  int n = nozero.size();
  int all = pow(2, n);

  int mx = -1;

  for (int i = 0; i < all; i++)
  {
    string bs = bitset<16>(i).to_string().substr(16 - n, n);

    assert(n == bs.size());

    vector<string> seta, setb;
    for (int j = 0; j < n; j++)
    {
      if (bs[j] == '1')
        seta.push_back(nozero[j]);
      else
        setb.push_back(nozero[j]);
    }

    int res1 = solve("AA", 26, set(seta.begin(), seta.end()));
    int res2 = solve("AA", 26, set(setb.begin(), setb.end()));
    mx = max(mx, res1 + res2);
  }

  cout << mx << nl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  while (getline(cin, s))
  {
    stringstream ss(s);

    string v;
    int r;
    vector<string> ng;

    for (auto [sp, i] = tuple{string{""}, 0}; ss >> sp; i++)
    {
      if (i == 1)
        v = sp;
      else if (i == 4)
        r = stoi(sp.substr(5, sp.size() - 6));
      else if (i >= 9)
        ng.push_back(sp.substr(0, 2));
    }

    rt[v] = r;
    gr[v] = ng;
  }

  vector<string> vl;
  for (auto &[k, v] : gr)
    vl.push_back(k);

  for (int i = 0; i < vl.size() - 1; i++)
  {
    for (int j = i + 1; j < vl.size(); j++)
      apsp[{vl[i], vl[j]}] = BFS(vl[i], vl[j]);
  }

  for (auto v : vl)
  {
    if (rt[v] > 0)
      nozero.push_back(v);
  }

  solve1();
  solve2();

  return 0;
}