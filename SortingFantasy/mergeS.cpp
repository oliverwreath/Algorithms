
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c
#define MAXDP 100001
#define MAXArray 31
#define maxLen 100001

typedef int entry_type;

using namespace std;

int merge( int in_array [], int m, int begin, int end ){
	//smallest first
	int n = end - begin + 1;
	int * B = new int [n+1];
	int i = begin;
	int j = m+1;
	F( k, 1, n ){
		if( j > end ){
			B[k] = in_array[i++];
		}else if( i > m ){
			B[k] = in_array[j++];
		}else if( in_array[i] < in_array[j] ){
			B[k] = in_array[i++];
		}else{
			B[k] = in_array[j++];
		}
	}
	F( k, 1, n ){
		in_array[begin+k-1] = B[k]; 
	}
	return 0;
}

void mergeSort( int in_array [], int begin, int end ){
	int n = end - begin + 1;
	if( n > 1 ){
		mergeSort( in_array, begin, begin + n/2 - 1 ); 
		mergeSort( in_array, begin + n/2, end ); 
		merge( in_array, begin + n/2-1, begin, end ); 
	}
}

int main()
{
	//generate data as input
	srand( (unsigned)time(NULL) ); 
	int in_array [MAXArray+1]; 
	F( i, 1, sizeof(in_array)/ sizeof(* in_array) - 1 ){ 
		in_array[i] = (double)rand() / (RAND_MAX + 1) * (100); 
	} 

	//operations
	mergeSort( in_array, 1, sizeof(in_array) / sizeof(* in_array) - 1 ); 

	//output
	F( i, 1, sizeof(in_array) / sizeof(* in_array) - 1 ){
		cout << in_array[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}



