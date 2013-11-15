

#include <sorting.h>
#include <time.h>
#include <iostream>
//#include <algorithm>

using namespace std;

int merge( int in_array [], int m, int begin, int end ){
	//smallest first
	int n = end - begin + 1;
	int * B = new int [n];
	int i = begin;
	int j = m+1;
	F( k, 0, n-1 ){
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
	F( k, 0, n-1 ){
		in_array[begin+k] = B[k]; 
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
	int i = p-1;

	F( j, p, r-1 ){
		if( A[j] <= pivot ){
			i++;
			//swap( A, i, j );
			swap( A[i], A[j] );
		}
	}

	//swap( A, i + 1, r );
	swap( A[i+1], A[r] );
	return i + 1;
}

int randPartition( int * A, int p, int r ){ 
	//srand( (unsigned)time(NULL) ); 
	int randR = rand() % (r - p + 1) + p; 
	//swap( A, r, randR ); 
	swap(A[r], A[randR]); 

	return partition( A, p, r ); 
} 

void randQuickSort( int * A, int p, int r ){
	if( p < r ){
		if( p + 11 < r ){ 
			int q = randPartition( A, p, r ); 
			//cout << "p, r: " << p << " " << r << endl;
			randQuickSort( A, p, q - 1 ); 
			randQuickSort( A, q + 1, r ); 
		}
		else {
			insertionSort( A, p, r );
		}
	}

	return ;
} 

void quickSort( int * A, int p, int r ){ 
	if( p + 11 < r  ){
		int q = partition( A, p, r );
		quickSort( A, p, q - 1 );
		quickSort( A, q + 1, r );

		//F( i, p, r ){
		//	cout << A[i] << " ";
		//}
	}
	else {
		insertionSort( A, p, r );
	}

	cout << endl;
	return ;
} 

void insertionSort( int * A, int p, int r ){ 
	F( i, p+1, r ){
		FB( j, i-1, p ){
			if( A[j] > A[j+1] ){
				swap( A[j], A[j+1] );
			}
			else{
				break; 
			}
		
		}
	}

	return ;
} 

void selectionSort( int * A, int p, int r ){ 
	// denote p = 0, r = n-1 
	int n = r - p + 1; //total number 
	int minValue = 999999999; 
	int minIndex = -1; 

	F( i, 1, n ){
		F( j, p + i - 1, r ){
			if( minValue > A[j] ){ 
				minValue = A[j]; 
				minIndex = j; 
			}
		}
		if( minIndex > - 1 ){
			swap( A, p + i - 1, minIndex );
		}
		minValue = 999999999; 
		minIndex = -1; 
	}
	return ;
} 

void selectionSort2Way( int * A, int p, int r ){ 
	// denote p = 0, r = n-1 
	int n = r - p + 1; //total number 
	int minValue = 999999999; 
	int minIndex = -1; 
	
	int maxValue = -999999999;
	int maxIndex = -1; 

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
		if( minIndex == maxIndex ){ 
			return ; 
		} else if( p + i - 1 == maxIndex || ( r - i + 1 == minIndex ) ){
			selectionSort( A, p + i - 1, r - i + 1 ); 
			return ;
		}
		else { 
			if( minIndex > - 1 ){ 
				swap( A, p + i - 1, minIndex );
			} 
			if( maxIndex > - 1 ){ 
				swap( A, r - i + 1, maxIndex );
			} 
		}
		minValue = 999999999; 
		minIndex = -1; 
		maxValue = -999999999; 
		maxIndex = -1; 
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





