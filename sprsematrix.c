#include <stdio.h>

#define MAX 10

// Structure to represent a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numElements;
    struct Element data[MAX];
};

// Function to input a sparse matrix
void inputSparseMatrix(struct SparseMatrix *matrix) {
	int i;
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &matrix->rows, &matrix->cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &matrix->numElements);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (i = 0; i < matrix->numElements; ++i) {
        scanf("%d %d %d", &matrix->data[i].row, &matrix->data[i].col, &matrix->data[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrix matrix) {
	int i;
    printf("Sparse Matrix:\n");
    for ( i = 0; i < matrix.numElements; ++i) {
        printf("%d %d %d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].value);
    }
}

// Function to add two sparse matrices
void addSparseMatrices(struct SparseMatrix matrix1, struct SparseMatrix matrix2, struct SparseMatrix *result) {
    result->rows = matrix1.rows;
    result->cols = matrix1.cols;
    result->numElements = 0;

    int i = 0, j = 0;
    while (i < matrix1.numElements && j < matrix2.numElements) {
        if (matrix1.data[i].row < matrix2.data[j].row || (matrix1.data[i].row == matrix2.data[j].row && matrix1.data[i].col < matrix2.data[j].col)) {
            result->data[result->numElements++] = matrix1.data[i++];
        } else if (matrix1.data[i].row > matrix2.data[j].row || (matrix1.data[i].row == matrix2.data[j].row && matrix1.data[i].col > matrix2.data[j].col)) {
            result->data[result->numElements++] = matrix2.data[j++];
        } else {
            // Add the values if the positions match
            result->data[result->numElements].row = matrix1.data[i].row;
            result->data[result->numElements].col = matrix1.data[i].col;
            result->data[result->numElements++].value = matrix1.data[i++].value + matrix2.data[j++].value;
        }
    }

    // Copy any remaining elements from matrix1
    while (i < matrix1.numElements) {
        result->data[result->numElements++] = matrix1.data[i++];
    }

    // Copy any remaining elements from matrix2
    while (j < matrix2.numElements) {
        result->data[result->numElements++] = matrix2.data[j++];
    }
}

int main() {
    struct SparseMatrix matrix1, matrix2, result;

    printf("Enter details for the first sparse matrix:\n");
    inputSparseMatrix(&matrix1);

    printf("Enter details for the second sparse matrix:\n");
    inputSparseMatrix(&matrix2);

    // Display the input matrices
    printf("\nInput Matrices:\n");
    displaySparseMatrix(matrix1);
    displaySparseMatrix(matrix2);

    // Add the matrices
    addSparseMatrices(matrix1, matrix2, &result);

    // Display the result matrix
    printf("\nResult Matrix after addition:\n");
    displaySparseMatrix(result);

    return 0;
}

