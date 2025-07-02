#include <stdio.h>

#define N 1000

int check(int a, int b, int c)
{
  if (a > b)
    a ^= b ^= a ^= b;
  return (a-1 <= c && c <= b+1);
}

int main()
{
  int t;

  scanf("%d", &t);
  while (t--)
  {
    int n;
    int i;
    int flag = -1;
    static int aa[N];

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
      scanf("%d", aa + i);
    for (i = 0; i+1 < n; ++i)
    {
      if ((aa[i] > aa[i+1] ? aa[i] - aa[i+1] : aa[i+1] - aa[i]) <= 1)
      {
        flag = 0;
        break;
      }
      if ((i > 0 && check(aa[i], aa[i+1], aa[i-1])) || (i+2 < n && check(aa[i], aa[i+1], aa[i+2])))
        flag = 1;
    }
    printf("%d\n", flag);
  }
}
