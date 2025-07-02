#include <ios>
#include <iostream>
#include <utility>
#include <vector>

const int kMaxN = 2e5;

std::vector<int> adj[kMaxN];
std::vector<std::pair<int, int>> ans;

void dfs(int u, int parent, int depth)
{
  bool flag = 0;

  for (int v : adj[u])
    if (v != parent)
      dfs(v, u, depth + 1), flag = 1;

  if (depth == 0)
    return;
  else if (depth & 1)
    ans.emplace_back(u, parent);
  else
    ans.emplace_back(parent, u);
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;

  std::cin >> t;
  while (t--)
  {
    int n;

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
      int u, v;

      std::cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    std::vector<std::pair<int, int>>().swap(ans);
    dfs(0, n, 0);
    std::swap(ans[0].first, ans[0].second);

    if (n > 2)
    {
      std::cout << "YES\n";
      for (auto &[f, s] : ans)
        std::cout << f + 1 << " " << s + 1 << "\n";
    }
    else
      std::cout << "NO\n";

    for (int i = 0; i < n; ++i)
      std::vector<int>().swap(adj[i]);
  }
}
