#include <stdio.h>
#include <stdlib.h>
int max_val[5];
void main()
{
  int n, *ptr, i, y;
  int x;
  printf("Enter the limit: ");
  scanf("%d", &n);
  ptr = (int *)calloc(n, sizeof(int));
  printf("Enter the values to calculate mode:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &ptr[i]);
  }
  printf("\n====\nMODE\n====\n");
  mode(ptr, n);

  free(ptr);
}
int mode(int ptr[], int n)
{

  int i, j, k = 0;
  int max_count = 0;
  for (i = 0; i < n; i++)
  {
    int count = 0;
    for (j = i + 1; j < n; j++)
    {
      if (ptr[i] == ptr[j])
      {
        count = count + 1;
      }
    }
    if (count > max_count)
    {
      max_count = count;
    }
  }
  for (i = 0; i < n; i++)
  {
    int count = 0;
    for (j = i + 1; j < n; j++)
    {
      if (ptr[i] == ptr[j])
    {
        count = count + 1;
      }
    }
    if (count == max_count)
    {

      printf("\n%d", ptr[i]);
    }
  }

  return 0;
}

