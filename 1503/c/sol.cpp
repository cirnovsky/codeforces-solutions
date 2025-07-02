#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> arr(n);
  long long ans = 0;
  for (auto &[a, c] : arr)
  {
    std::cin >> a >> c;
    ans += c;
    c += a;
  }
  std::sort(arr.begin(), arr.end());
  long long mx = arr[0].second;
  for (int i = 1; i < n; ++i)
  {
    ans += std::max(0ll, arr[i].first - mx);
    mx = std::max(mx, 1ll * arr[i].second);
  }
  std::cout << ans << "\n";
}
