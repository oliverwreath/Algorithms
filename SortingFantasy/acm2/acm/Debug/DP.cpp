

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[101][101];
int cnt[101][101];

int R = 0 ;
int C = 0 ;

int DP(int i, int j)
{
	if( cnt[i][j] > 0 )
		return cnt[i][j];

	int max = 0;

	if( i + 1 <= R )
	{
		if( matrix[i][j] > matrix[i+1][j] )
		{
			if( max < DP(i+1, j) )
				max = DP(i+1, j);
		}
	}

	if( i - 1 >= 1 )
	{
		if( matrix[i][j] > matrix[i-1][j] )
		{
			if( max < DP(i-1, j) )
				max = DP(i-1, j);
		}
	}

	if( j + 1 <= C )
	{
		if( matrix[i][j] > matrix[i][j+1] )
		{
			if( max < DP(i, j+1) )
				max = DP(i, j+1);
		}
	}

	if( j - 1 >= 1 )
	{
		if( matrix[i][j] > matrix[i][j-1] )
		{
			if( max < DP(i, j-1) )
				max = DP(i, j-1);
		}
	}

	return cnt[i][j] = max + 1;

	
}

int main() {
	//read R & C
	cin >> R >> C;

	//read Matrix
	for( int i = 1; i <= R ; i++ )
	{
		for( int j = 1; j <= C ; j++ )
		{
			cin >> matrix[i][j];
		}
	}

	//run DP
	for( int i = 1; i <= R ; i++ )
	{
		for( int j = 1; j <= C ; j++ )
		{
			DP(i, j);
		}
	}
	
	//get maximum
	int max = 0;
	for( int i = 1; i <= R ; i++ )
	{
		for( int j = 1; j <= C ; j++ )
		{
			if( max < cnt[i][j])
				max = cnt[i][j];
		}
	}

	//print
	cout << max << endl;

	//system("pause");
    return 0;
}

