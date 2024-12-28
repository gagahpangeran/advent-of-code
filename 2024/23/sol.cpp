#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef pair<string, string> pss;
typedef tuple<string, string, string> triple;

map<string, set<string>> g;
vector<string> max_cliq;

void bron_kerbosch(set<string> cur_cliq, set<string> cand, set<string> proc_vert)
{
  if (cand.empty() && proc_vert.empty())
  {
    if (cur_cliq.size() > 2 && cur_cliq.size() > max_cliq.size())
    {
      max_cliq = vector(cur_cliq.begin(), cur_cliq.end());
    }
    return;
  }

  auto uni = cand;
  uni.insert(cand.begin(), cand.end());

  string pivot = "";
  for (auto node : uni)
  {
    if (g[node].size() > pivot.size())
      pivot = node;
  }

  assert(pivot != "");

  auto poss = cand;
  for (auto neig : g[pivot])
  {
    auto p = poss.find(neig);
    if (p != poss.end())
      poss.erase(p);
  }

  for (auto node : poss)
  {
    auto new_cliq = cur_cliq;
    new_cliq.insert(node);

    set<string> new_cand, new_proc_vert;
    for (auto neig : g[node])
    {
      if (cand.find(neig) != cand.end())
        new_cand.insert(neig);

      if (proc_vert.find(neig) != proc_vert.end())
        new_proc_vert.insert(neig);
    }

    bron_kerbosch(new_cliq, new_cand, new_proc_vert);

    cand.erase(node);
    proc_vert.erase(node);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  while (cin >> s)
  {
    string u = s.substr(0, 2);
    string v = s.substr(3, 2);

    g[u].insert(v);
    g[v].insert(u);
  }

  set<triple> tri;
  map<string, set<string>> ms;

  for (auto [node, neig] : g)
  {
    if (node[0] != 't')
      continue;

    for (auto n1 : neig)
    {
      for (auto n2 : neig)
      {
        if (n1 == n2)
          continue;

        if (g[n1].find(n2) != g[n1].end() && g[n2].find(n1) != g[n2].end())
        {
          vector<string> tr = {node, n1, n2};
          sort(tr.begin(), tr.end());
          tri.insert({tr[0], tr[1], tr[2]});
        }
      }
    }
  }

  cout << tri.size() << nl;

  set<string> cand;
  for (auto [k, _] : g)
    cand.insert(k);

  bron_kerbosch(set<string>(), cand, set<string>());

  int sz = max_cliq.size();
  for (int i = 0; i < sz; i++)
    cout << max_cliq[i] << ",\n"[i == sz - 1];

  return 0;
}
