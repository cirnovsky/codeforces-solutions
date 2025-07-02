#include <stdio.h>

#define N 5000

int max(int i, int j)
{
  return i > j ? i : j;
}

int find(int *arr, int n, int lb, int i, int j)
{
  int l = j + 1, r = n - 2, pos = n - 1; // aa[pos] >= lb

  while (l <= r)
  {
    int m = (l + r) / 2;

    if (arr[m] > lb)
      pos = m, r = m - 1;
    else
      l = m + 1;
  }
  l = j + 1, r = n - 2;
  int pos2 = j;

  while (l <= r)
  {
    int m = (l + r) / 2;

    if (arr[m] < arr[n - 1] - lb)
      pos2 = m, l = m + 1;
    else
      r = m - 1;
  }

  return max(0, pos2 - pos + 1);
}

int main()
{
  int t;

  scanf("%d", &t);
  while (t--)
  {
    int n;
    int i, j;
    static int aa[N];

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
      scanf("%d", aa + i);
    int ans = 0;

    for (i = 0; i + 1 < n; ++i)
      for (j = i + 1; j + 1 < n; ++j)
        ans += aa[i] + aa[j] > aa[n - 1];
    for (i = 0; i + 1 < n; ++i)
      for (j = i + 1; j + 1 < n; ++j)
        ans += find(aa, n, aa[n - 1] - aa[i] - aa[j], i, j);

    printf("%d\n", ans);
  }
}
