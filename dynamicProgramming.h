
#include <iostream>
#include <common.h>
#include <string>
#include <unordered_map>

using namespace std;

template<class Type>
class DynaPro{
public:
	//iterator
	typedef Type* iterator;
	typedef int size_type;

	//constructors
	DynaPro(  ){
		DP = new int [99999]();
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



