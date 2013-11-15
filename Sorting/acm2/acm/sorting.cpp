

#include <sorting.h>
#include <time.h>
#include <iostream>

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

void swap( int * A, int q, int r ){ 
	if( q == r ){
		return ;
	}
	else{
		//int tmp = A[q]; 
		//A[q] = A[r]; 
		//A[r] = tmp; 
		A[q] = A[q] ^ A[r];
		A[r] = A[q] ^ A[r];
		A[q] = A[q] ^ A[r];
	}
	return ;
}

int partition( int * A, int p, int r ){ 
	int pivot = A[r];
	int i = p;
	int j = r-1;

	while( i < j ){
		while( A[i] <= pivot && ( i < j ) )
		{
			i++;
		}
		while( A[j] >= pivot && ( i < j ) )
		{
			j--;
		}
		if( i < j ){
			swap( A, i, j ); 
		}
	}

	swap( A, i, r );
	return i;
}

void quickSort( int * A, int p, int r ){ 
	if( p < r ){
		int q = partition( A, p, r );
		quickSort( A, p, q - 1 );
		quickSort( A, q + 1, r );

		//F( i, p, r ){
		//	cout << A[i] << " ";
		//}
	}

	cout << endl;
	return ;
} 


int randPartition( int * A, int p, int r ){ 
	srand( (unsigned)time(NULL) ); 
	int randR = (double)rand() / (RAND_MAX + 1) * (r + 1 - p) + p; 
	swap( A, r, randR ); 

	return partition( A, p, r ); 
}

void randQuickSort( int * A, int p, int r ){ 
	if( p < r ){
		int q = randPartition( A, p, r );
		randQuickSort( A, p, q - 1 );
		randQuickSort( A, q + 1, r );
	}

	cout << endl;
	return ;
} 

void selectionSort( int * A, int p, int r ){ 
	// denote p = 0, r = n-1
	int n = r - p + 1; //total number
	int minValue = 999999999; 
	int minIndex = p;
		
	int maxValue = -999999999;
	int maxIndex = r;

	F(i, 1, n/2){
		F(j, p + i - 1, r - i + 1 ){
			if( minValue > A[j] ){
				minValue = A[j];
				minIndex = j;
			}
			if( maxValue < A[j] ){
				maxValue = A[j];
				maxIndex = j;
			}
		}
		if( minIndex > p + i - 1 ){
			swap( A, p + i - 1, minIndex );
		}
		if( maxIndex < r - i + 1 ){
			swap( A, r - i + 1, maxIndex );
		}
		minValue = 999999999; 
		minIndex = p; 
		maxValue = -999999999; 
		maxIndex = r; 
	}
	return ;
} 

void bbSort( int * A, int p, int r ){
	// denote p = 0, r = n-1
	int times = 1;
	while(times > 0){
		times = 0;
		F( i, p, r-1 ){
			if( A[i] > A[i+1] ){
				swap( A, i, i+1 );
				times++;
			}
		}
	}

	return ;
}