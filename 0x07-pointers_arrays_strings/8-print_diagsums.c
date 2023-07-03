#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the main diagonal and secondary diagonal of a square matrix.
 * @a: Pointer to the first element of the matrix.
 * @size: Size of the square matrix.
 */
void print_diagsums(int *a, int size) 
{
	/*sum of the main diagonal*/
	int sumA = 0;  
	/*sum of the secondary diagonal*/
	int sumB = 0;  

	for (int i = 0; i < size; i++) 
	{
		/*getting the elements of main diagonal*/
		sumA += *(a + i * size + i);    
		/*getting elements of secondart diagonal*/                
		sumB += *(a + i * size + (size - 1 - i));  
	}

	printf("%d, %d\n", sumA, sumB);
}
