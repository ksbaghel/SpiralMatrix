// SpiralMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A)
{
	//start filling the data in the rings...starting from outer layer
	//int layer = (n-1)/2;

	vector<vector<int> > res(A, vector<int>(A));
	if (A == 0) return res;
	int num = 1;
	for (int layer = 0; layer<(A + 1) / 2; layer++)
	{
		//start cordinates
		//1st row
		for (int col = layer; col<A - layer; col++)
		{
			res[layer][col] = num++;
		}
		//last col
		for (int row = layer + 1; row<A - layer; row++)
		{
			res[row][A - layer-1] = num++;
		}
		//bot col
		for (int col = A - layer - 2; col >= layer; col--)
		{
			res[A - layer-1][col] = num++;
		}
		//1st col
		for (int row = A - layer - 2; row>layer; row--)
		{
			res[row][layer] = num++;
		}
	}
	return res;
}



int main()
{
	int n;
	cin >> n;

	vector < vector<int> > mat = generateMatrix(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}

