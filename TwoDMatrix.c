#include<stdio.h>

int arr1[10][10],arr2[10][10],arr3[10][10],i,j,k;

void read(int r1,int c1,int r2,int c2)
{
    printf("Enter the elements of 1st matrix: ");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter the elements of 2nd matrix: ");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
}

void disp(int r1,int c1,int r2,int c2)
{
    	printf("The elements of 1st matrix are: \n");
    	for(i=0;i<r1;i++)
    	{
       	 	for(j=0;j<c1;j++)
       	 	{
            	printf("%d ",arr1[i][j]);
        	}
        	printf("\n");
    	}
	
   	 	printf("The elements of 2nd matrix are: \n");
    	for(i=0;i<r2;i++)
    	{
       	 	for(j=0;j<c2;j++)
        	{
          	  printf("%d ",arr2[i][j]);
        	}
        	printf("\n");
    	}
}

void add(int r1,int c1,int r2,int c2)
{
    printf("Addition: \n");
    if(r1==r2 && c1==c2)
    {
    	{
    		for(i=0;i<r1;i++)
    		{
        		for(j=0;j<c1;j++)
        		{
            		arr3[i][j]=arr1[i][j]+arr2[i][j];
            		printf("%d\t",arr3[i][j]);
        		}
        	printf("\n");
    		}
    	}
	}
	else
	{
		printf("For addition matrix should be of same size");
	}
}


void sub(int r1,int c1,int r2,int c2)
{
    
    printf("Subtraction: \n");
    if(r1==r2 && c1==c2)
    {
    	for(i=0;i<r1;i++)
    	{
        	for(j=0;j<c1;j++)
        	{
            	arr3[i][j]=arr1[i][j]-arr2[i][j];
            	printf("%d\t",arr3[i][j]);
        	}
        	printf("\n");
    	}
	}
	else
	{
		printf("For subtraction matrix should be of same size");
	}
}

void mul(int r1,int c1,int r2,int c2)
{
    printf("Multiplication: \n");
    if(c1==r2)
    {
    	for(i=0;i<r1;i++)
    	{
        	for(j=0;j<c2;j++)
        	{
            	arr3[i][j]=0;
            	for(k=0;k<c2;k++)
            	{
               		arr3[i][j]=arr3[i][j]+ arr1[i][k] * arr2[k][j]; 
             
            	}
              	printf("%d\t",arr3[i][j]);
        	}
        printf("\n");
    	}
	}
	else
	{
		printf("Multiplication not possible the size should be of the form((axb)(bxc))");
	}
}

void tran(int r1,int c1,int r2,int c2)
{
    printf("Transponse of 1st matrix: \n");
    for(i=0;i<c1;i++)
    {
        for(j=0;j<r1;j++)
        {
            printf("%d ",arr1[j][i]);
        }
        printf("\n");
    }
    printf("\nTransponse of 2nd matrix: \n");
    for(i=0;i<c2;i++)
    {
        for(j=0;j<r2;j++)
        {
            printf("%d ",arr2[j][i]);
        }
        printf("\n");
    }
}

int determinant(int n, int mat[10][10]) {
    int det = 0;
    int submat[10][10];
	int x;
    if (n == 2) {
        return (mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);
    } else {
        for (x = 0; x < n; x++) {
            int subi = 0;
            for (i = 1; i < n; i++) {
                int subj = 0;
                for (j = 0; j < n; j++) {
                    if (j == x) {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * mat[0][x] * determinant(n - 1, submat);
        }
    }
    return det;
}


int menu()
{
	int ch;
	printf("\nChoices:\n1.Display\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Transpose\n6.Determinant\n7.Exit\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

void process(int r1,int c1,int r2,int c2)
{
	int ch;
	for(ch=menu();ch!=7;ch=menu())
	{
		switch(ch)
		{
		
			case 1: disp(r1,c1,r2,c2);
					break;
			case 2: add(r1,c1,r2,c2);
					break;
			case 3: sub(r1,c1,r2,c2);
					break;
			case 4: mul(r1,c1,r2,c2);
					break;
			case 5: tran(r1,c1,r2,c2);
					break;
			case 6: 
	                if (r1 == c1 && r2 == c2) {
	                    int det1 = determinant(r1, arr1);
	                    int det2 = determinant(r2, arr2);
	                    printf("Determinant of the 1st matrix: %d\n", det1);
	                    printf("Determinant of the 2nd matrix: %d\n", det2);
	                } else {
	                    printf("For determinant, matrices should be square (same number of rows and columns).\n");
	                }
	                break;
			default:printf("Invalid Choice");
			break;
					
		}
	}
}
int main()
{
    int r1,c1,r2,c2;
    printf("Enter the row size and column size of the 1st array: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the row size and column size of the 2nd array: ");
    scanf("%d %d",&r2,&c2);
    read(r1,c1,r2,c2);
    process(r1,c1,r2,c2);
	
}

