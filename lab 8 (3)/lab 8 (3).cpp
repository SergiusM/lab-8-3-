//3.	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
//Найти столбец с наименьшей суммой элементов и увеличить все элементы этого столбца на 3
#include <iostream>

#define N 100
#define M 100
int main()
{
	//int matrix[N][M];
	int n, m;
	std::cin >> n >> m;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];
	int sum = 0;
	int minsum = INT_MAX;
	int save = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> matrix[i][j];
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum = sum + matrix[i][j];
		}
		if (sum < minsum)
		{
			minsum = sum;
			save = j;
		}
		sum = 0;
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum = sum + matrix[i][j];
		}
		if (sum == minsum)
		{
			for (int y = 0; y < m; y++)
			{
				matrix[y][save] = matrix[y][save] + 3;
			}
		}
		sum = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
	for (int i; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}