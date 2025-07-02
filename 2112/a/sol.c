#include <stdio.h>

int abs(int x)
{
  return x < 0 ? -x : x;
}

int main()
{
  int t;

  scanf("%d", &t);
  while (t--)
  {
    int a, x, y;

    scanf("%d%d%d", &a, &x, &y);
    int l1 = x - abs(a - x) + 1, r1 = x + abs(a - x) - 1;
    int l2 = y - abs(a - y) + 1, r2 = y + abs(a - y) - 1;

    printf(" %d %d %d %d\n", l1, r1, l2, r2);
    if (l1 > l2)
    {
      l1 ^= l2 ^= l1 ^= l2;
      r1 ^= r2 ^= r1 ^= r2;
    }
    puts(r1 >= l2 ? "YES" : "NO");
  }
}
