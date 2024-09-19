#include <stdio.h>

#define MAX 100

void read(int A[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void display(int A[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void ptrip(int B[MAX][3], int tr) {
    printf("\nRows--- Columns--- Values\n");
    for (int i = 0; i < tr; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
}

int trip(int A[MAX][MAX], int r, int c, int B[MAX][3]) {
    int cnz = 0;
    int tr;

    // Traverse the matrix to find non-zero elements
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A[i][j] != 0) {
                cnz++;
                B[cnz][0] = i;
                B[cnz][1] = j;
                B[cnz][2] = A[i][j];
                
            }
        }
    }

    // Store dimensions and count in the first row
    B[0][0] = r;
    B[0][1] = c;
    B[0][2] = cnz;
    tr=cnz+1;
    return tr;

    // Include the first row for dimensions and count
}

void transpose(int B[100][3]){
	int temp[100],i,j;
	int tr=B[0][2];
	for(i=0;i<=tr;i++)
   	 {
         temp[i]= B[i][0];
         B[i][0]= B[i][1];
         B[i][1]=temp[i];
    	}
    	
    	 printf("\nThe Transpose is\n");
   	 for(i=0;i<tr+1;i++)
    	{
       	printf("\n");
        	for(j=0;j<3;j++)
        	{
              	printf("%d  ",B[i][j]);
        	}
    }
}

void sum(int mat1[100][3],int mat2[100][3])
{
    int tr1,tr2,n=0,mat[100][3],i,j,k;
    
    if((mat1[0][0]==mat2[0][0]) && (mat1[0][1]==mat2[0][1]))
    {
        
        tr1=mat1[0][2];
        tr2=mat2[0][2];
        i=1;
        j=1;
        k=1;
        n=tr1+tr2;
        while((i<=tr1) &&(j<=tr2))
        {
            if((mat1[i][0]==mat2[j][0]) &&(mat1[i][1]==mat2[j][1]))
            {
                mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2]+mat2[j][2];
                i++;j++;k++;
            }
            
               else if(mat1[i][0]<mat2[j][0])
                {
                    mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2];
                i++;k++;
                }
                else
                {
                     mat[k][0]=mat2[j][0];
                mat[k][1]=mat2[j][1];
                mat[k][2]=mat2[j][2];
                j++;k++;
                }
                       
                   }
        while(i<=tr1)
        {
           mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2];
                i++;k++; 
        }
        while(j<=tr2)
        {
             mat[k][0]=mat2[j][0];
                mat[k][1]=mat2[j][1];
                mat[k][2]=mat2[j][2];
                j++;k++;
        }
        mat[0][0]=mat1[0][0];
        mat[0][1]=mat1[0][1];
        mat[0][2]=k-1;
        printf("\nThe sum is:\n");
         for(i=0;i<k;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            
            printf("%d  ",mat[i][j]);
        }
    }
    }
    else
    {
        printf("The matrix is incompatible for addition\n");
    }
}
int main() {
    

    int A[MAX][MAX];
    int B[MAX][3];

    
    int mat1[100][100],r1,c1,mat2[100][100],r2,c2;
    int mat1tup[100][3],mat2tup[100][3];
    printf("\nFirst matrix:");
    printf("\nEnter the no. of rows:");
    scanf("%d",&r1);
    printf("\nEnter the no. of columns:");
    scanf("%d",&c1);
    printf("Enter the elements\n");
    read(mat1,r1,c1);
    printf("\nSecond matrix:");
    printf("\nEnter the no. of rows:");
    scanf("%d",&r2);
    printf("\nEnter the no. of columns:");
    scanf("%d",&c2);
    printf("Enter the elements\n");
    read(mat2,r2,c2);
    printf("\nThe first matrix is : \n");
    display(mat1,r1,c1);
    printf("\nThe second matrix is : \n ");
    display(mat2,r2,c2);
    printf("\nFirst Matrix in tuple form:\n");
    int tr1=trip(mat1,r1,c1,mat1tup);
    ptrip(mat1tup,tr1);
    printf("\nSecond Matrix in tuple form:\n");
    int tr2=trip(mat2,r2,c2,mat2tup);
    ptrip(mat2tup,tr2);
    printf("\nSum\n");
    sum(mat1tup,mat2tup);
    transpose(mat2tup); 
    
    
    
}

























