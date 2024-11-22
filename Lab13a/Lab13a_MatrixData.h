//
// Written by TheAidenS2014
// Last modified 11/21/2024
// Header file for Lab13a
//

#pragma once
#include <iostream>
#include <iomanip>

class Matrix
{
	int size = 2;
	double contents[2][2]{ 0 };

public:
	// functions
	void replace(int spot_x, int spot_y, double data) { contents[spot_x][spot_y] = data; }
	friend void printMatrix(const Matrix& matrixObject);

	// operators
	Matrix operator + (Matrix other_matrix)
	{
		Matrix results(0, 0, 0, 0);

		for (int index_x = 0; index_x < size; index_x++)
		{
			for (int index_y = 0; index_y < size; index_y++)
			{
				results.contents[index_x][index_y] = this->contents[index_x][index_y] + other_matrix.contents[index_x][index_y];
			}
		}

		return results;
	}
	Matrix operator - (Matrix other_matrix)
	{
		Matrix results(0, 0, 0, 0);

		for (int index_x = 0; index_x < size; index_x++)
		{
			for (int index_y = 0; index_y < size; index_y++)
			{
				results.contents[index_x][index_y] = this->contents[index_x][index_y] - other_matrix.contents[index_x][index_y];
			}
		}

		return results;
	}
	Matrix operator * (Matrix other_matrix)
	{
		Matrix results(0, 0, 0, 0);

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++)
				{
					// matrix-matrix multiplication is done via the dot product
					// more info: https://www.calculator.net/matrix-calculator.html
					results.contents[i][j] += this->contents[i][k] * other_matrix.contents[k][j];
				}
			}
		}

		return results;
	}

	// constructors
	Matrix() = delete;
	Matrix (double data_one, double data_two, double data_three, double data_four)
	{
		//		 x  y
		contents[0][0] = data_one;
		contents[0][1] = data_two;
		contents[1][0] = data_three;
		contents[1][1] = data_four;
	}
};

void printMatrix(const Matrix& in_matrix)
{
	for (int index_x = 0; index_x < in_matrix.size; index_x++)
	{
		for (int index_y = 0; index_y < in_matrix.size; index_y++)
		{
			std::cout << std::setw(2) << in_matrix.contents[index_x][index_y] << " ";
		}
		std::cout << "\n";
	}
}