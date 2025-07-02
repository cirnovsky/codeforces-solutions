#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <vector>

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

#define rng(l, r) std::uniform_int_distribution<int>(l, r - 1)(rnd)


int main()
{
  puts("1");
  int n = 600;
  printf("%d\n", n);
  std::vector<int> vec(n);
  for (int &x : vec)
    x = rng(1, 100000);
  std::sort(vec.begin(), vec.end());
  for (int x : vec)
    printf("%d ", x);
}
