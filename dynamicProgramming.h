
#include <iostream>
#include <common.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template<class Type>
class DynaPro{
public:
	//iterator
	typedef Type* iterator;
	typedef int size_type;

	//constructors
	DynaPro(  ){
		DP = NULL;
	}

	DynaPro( int size ){
		DP = new int [size]();//99999
	}

	//destructors
	~DynaPro(){
		delete [] DP;
	}

	//variables
	
	//methods
	int rodRec( int arr [], const int size ){
		if( size == 0 ){
			return 0;
		}
		int maxValue = INT_MIN;
		for( int i = 1; i <= size; i++ ){
			maxValue = MAX2( maxValue, (arr[i-1] + rodRec( arr, size-i )) );
		}
		return maxValue;
	}

	int rodMemoization( int arr [], const int size ){
		if( size == 0 ){
			return 0;
		}
		else if( DP[size] != 0 ){
			return DP[size];
		}
		int maxValue = INT_MIN;
		for( int i = 1; i <= size; i++ ){
			maxValue = MAX2( maxValue, (arr[i-1] + rodMemoization( arr, size-i )) );
		}
		DP[size] = maxValue;
		return DP[size];
	}

	int rodDP( int arr [], const int size ){
		F( i, 0, size -1 ){
			int maxValue = INT_MIN;
			F( j, 0, i ){
				maxValue = MAX2(maxValue, (arr[j] + DP[i-j]));
			}
			DP[i+1] = maxValue;
		}
		return DP[size];
	}

	int move( int* DPA, const int to, const int from, int* steps ){
		if( to > steps ){
			return -1;
		}
		else{
			DPA[to] += DPA[from]
		}
		return 0;
	}

	long long hopCutting( int steps ){
		if( steps < 0 ){
			return 0;
		}
		long long DPA[99999] = {0};
		DPA[0] = 1;
		F( i, 0, steps-1 ){
			if( i+1 > steps ){
				break;
			}
			else{
				DPA[i+1] += DPA[i];
			}
			if( i+2 > steps ){
				continue;
			}
			else{
				DPA[i+2] += DPA[i];
			}			
			if( i+3 > steps ){
				continue;
			}
			else{
				DPA[i+3] += DPA[i];
			}
		}
		return DPA[steps];
	}

	long long robotPathDP( const int X, const int Y ){ 
		if( X < 0 || (Y < 0) ){
			return -1;
		}
		long long DPA[99][99] = {0}; 
		F( i, 0, X ){
			DPA[i][0] = 1;
		} 
		F( i, 0, Y ){
			DPA[0][i] = 1;
		}
		F( i, 1, X ){
			F( j, 1, Y ){
				DPA[i][j] += (DPA[i-1][j] + DPA[i][j-1]);
			}
		}
		return DPA[X][Y];
	}


	//lcs series
	void reverseString( string& a ){
		int len = a.size();
		int end = len/2-1;
		len--;
		for( int i = 0; i <= end; i++ ){
			int tmp = a[i];
			a[i] = a[len-i];
			a[len-i] = tmp;
		}
	}

	//typedef ListNode* iterator;
	int lcs( string& a, string& b ) {
		//loop through
		int m = a.size();
		int n = b.size();
		if( m == 0 || n == 0 ){
			return 0;
		}
		vector<vector <int>> dp;
		if( n < m ){
			//dp = vector<vector <int>(n+1, 0)>(m+1, 0);
			vector<int> tmp = vector<int>(n+1, 0);
			for( int i = 0; i <= 1; i++ ){
				dp.push_back(tmp);
			}
			for( int i = 1; i <= m; i++ ){
				for( int j = 1; j <= n; j++ ){
					if( a[i-1] == b[j-1] ){
						dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
					}
					else{
						dp[i%2][j] = MAX2( dp[(i-1)%2][j], dp[i%2][j-1] );
					}
				}
			}
			return dp[m%2][n];
		}
		else{ // m < n
			//dp = vector<vector <int>(n+1, 0)>(m+1, 0);
			vector<int> tmp = vector<int>(2, 0);
			for( int i = 0; i <= n; i++ ){
				dp.push_back(tmp);
			}
			for( int j = 1; j <= n; j++ ){
				for( int i = 1; i <= m; i++ ){
					if( a[i-1] == b[j-1] ){
						dp[i][j%2] = dp[i-1][(j-1)%2] + 1;
					}
					else{
						dp[i][j%2] = MAX2( dp[i-1][j%2], dp[i][(j-1)%2] );
					}
				}
			}
			return dp[m][n%2];
		}
	}

	//typedef ListNode* iterator;
	int lcsOld( string a, string b ) {
		//loop through
		int m = a.size();
		int n = b.size();
		if( m == 0 || n == 0 ){
			return 0;
		}
		vector<vector <int>> dp;
		if( true ){
			//dp = vector<vector <int>(n+1, 0)>(m+1, 0);
			vector<int> tmp = vector<int>(n+1, 0);
			for( int i = 0; i <= m; i++ ){
				dp.push_back(tmp);
			}
			for( int i = 1; i <= m; i++ ){
				for( int j = 1; j <= n; j++ ){
					if( a[i-1] == b[j-1] ){
						dp[i][j] = dp[i-1][j-1] + 1;
					}
					else{
						dp[i][j] = MAX2( dp[i-1][j], dp[i][j-1] );
					}
				}
			}

		}

		return dp[m][n];
	}

	//typedef ListNode* iterator;
	int agtc( string& a, string& b ) {
		//loop through
		int m = a.size();
		int n = b.size();
		if( m == 0 ){
			return n;
		}
		if( n == 0 ){
			return m;
		}
		vector<vector <int>> dp;
		if( true ){
			//dp = vector<vector <int>(n+1, 0)>(m+1, 0);
			vector<int> tmp = vector<int>(n+1, 0);
			for( int i = 0; i <= m; i++ ){
				dp.push_back(tmp);
			}
			for( int i = 1; i <= m; i++ ){
				for( int j = 1; j <= n; j++ ){
					if( a[i-1] == b[j-1] ){
						dp[i][j] = dp[i-1][j-1] + 1;
					}
					else{
						dp[i][j] = MAX2( dp[i-1][j], dp[i][j-1] );
					}
				}
			}

		}

		if( m > n ){
			return m - dp[m][n];
		}
		else{
			return n - dp[m][n];
		}
	}

	//auxillary methods
	bool emptyString( string inputString ){
		if( inputString.length() == 0 ){
			return true;
		}
		return false;
	}
	
	bool nullOrEmpty( iterator array ){
		if( array == NULL || ( size < 1 ) ){
			return false;
		}
		return true;
	}

private:
	iterator DP;
};



