#include <stdio.h>
struct poly
{
  int coeff;
  int exp;
};
int main()
{
  struct poly poly1[10], poly2[10], product[100];
  int NoOfTerms1, NoOfTerms2, count = -1;
  int i, j;
  printf("\nEnter Number Of Terms Of 1st Polynomial: ");
  scanf("%d", &NoOfTerms1);
  for (i = 0; i < NoOfTerms1; i++)
  {
    printf("\nEnter Coefficient: ");
    scanf("%d", &poly1[i].coeff);
    printf("\nEnter Exponent: ");
    scanf("%d", &poly1[i].exp);
  }
  printf("\nEnter Number Of Terms Of 2nd Polynomial: ");
  scanf("%d", &NoOfTerms2);
  for (i = 0; i < NoOfTerms2; i++)
  {
    printf("\nEnter Coefficient: ");
    scanf("%d", &poly2[i].coeff);
    printf("\nEnter Exponent: ");
    scanf("%d", &poly2[i].exp);
  }
  for (i = 0; i < NoOfTerms1; i++)
  {
    for (j = 0; j < NoOfTerms2; j++)
    {
      product[++count].exp = poly1[i].exp + poly2[j].exp;
      product[count].coeff = poly1[i].coeff * poly2[j].coeff;
    }
  }
  printf("\nThe Product Of Two Polynomials Is: \n");
  for (i = 0; i <= count; i++)
  {
    if (product[i].exp == 0)
      printf("%d ", product[i].coeff);
    else if (product[i].exp == 1)
      printf("%dx ", product[i].coeff);
    else
      printf("%dx^%d ", product[i].coeff, product[i].exp);
    if (i != count)
      printf("+ ");
  }
  return 0;
}

