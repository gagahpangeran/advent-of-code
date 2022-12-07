#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
typedef long long ll;

struct Node
{
  string name;
  vector<Node *> children;
  ll size;
};

stack<Node *> dirs;

ll res = 0LL;
ll maxsize = 100000;

vector<ll> sz;

ll dfs(Node *cur)
{
  if (cur->children.empty())
    return cur->size;

  ll dsize = 0LL;
  for (auto c : cur->children)
    dsize += dfs(c);
  cur->size = dsize;

  if (dsize <= maxsize)
    res += dsize;

  sz.push_back(dsize);

  return dsize;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  Node *root = NULL;
  string pref, com;
  while (cin >> pref >> com)
  {
    if (pref == "$")
    {
    here:
      if (com == "cd")
      {
        string dir;
        cin >> dir;
        if (dir == "/")
        {
          Node *curnode = new Node();
          curnode->name = dir;
          root = curnode;
          dirs.push(curnode);
        }
        else if (dir == "..")
          dirs.pop();
        else
        {
          Node *curnode = dirs.top();
          Node *cnode;
          for (auto c : curnode->children)
          {
            if (c->name == dir)
              cnode = c;
          }
          assert(cnode != NULL);
          dirs.push(cnode);
        }
      }
      else if (com == "ls")
      {
        string aw, name;
        Node *curdir = dirs.top();
        while (cin >> aw >> name)
        {
          if (aw == "$")
          {
            pref = aw;
            com = name;
            goto here;
          }
          else
          {
            Node *cnode = new Node();
            cnode->name = name;
            curdir->children.push_back(cnode);

            if (aw != "dir")
              cnode->size = stoll(aw);
          }
        }
      }
    }
  }

  dfs(root);
  cout << res << nl;

  sort(sz.begin(), sz.end());
  ll avail = 70000000, minunused = 30000000;
  ll free = avail - *sz.rbegin();

  for (auto i : sz)
  {
    if (free + i >= minunused)
    {
      cout << i << nl;
      break;
    }
  }

  return 0;
}