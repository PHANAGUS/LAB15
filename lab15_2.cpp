#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double M[][N])
{
	for(int i=0 ; i<N ; i++)
	{
		cout << "Row " << i+1 << ": ";
		for(int j=0 ; j<N ; j++)
		{
			cin >> M[i][j];
		}
	}
}

void findLocalMax(const double M[][N], bool Lmx[][N])
{
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<N ; j++)
		{
			Lmx[i][j] = 0;
		}
	}

	for(int i=1 ; i<N-1 ; i++)
	{
		for(int j=1 ; j<N-1 ; j++)
		{
			if(M[i][j] >= M[i-1][j] && M[i][j] >= M[i+1][j] && M[i][j] >= M[i][j-1] && M[i][j] >= M[i][j+1])
			{
				Lmx[i][j] = 1;
			}
		}
	}
}

void showMatrix(const bool Lmx[][N])
{
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<N ; j++)
		{
			cout << Lmx[i][j] << " ";
		}
		cout << endl;
	}
}