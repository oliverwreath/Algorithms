

#include <sorting.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <limits>
//#include <algorithm>

using namespace std;

int imin = numeric_limits<int>::min();
int imax = numeric_limits<int>::max();

float fmin = numeric_limits<float>::min();
float fmax = numeric_limits<float>::max();

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

void swap( int A [], int q, int r ){ 
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

int randPartition( int A [], int p, int r ){ 
	//srand( (unsigned)time(NULL) ); 
	int randR = rand() % (r - p + 1) + p; 
	//if( randR < p || (randR > r) ){ 
	//	cerr << "randR overflow" << endl; 
	//} 
	swap( A, r, randR ); 

	//partition
	int pivot = A[r];
	int i = p; 
	int j = r; 

	while( i < j ){ 
		while( A[i] <= pivot && (i < j) ){ 
			i++; 
		}
		while( A[j] >= pivot && (i < j) ){ 
			j--; 
		}
		if( i < j ){ 
			swap( A, i, j ); 
		} 
	} 

	swap( A, i, r ); 

	return i; 
} 

void randQuickSort( int A [], int p, int r ){ 
	while( p + 7 < r ){ 
		int q = randPartition( A, p, r ); 
		//cout << "p, r: " << p << " " << r << endl; 
		randQuickSort( A, p, q - 1 ); 
		//randQuickSort( A, q + 1, r ); 
		p = q + 1; 
	} 
	if( p < r ){ 
		insertionSort( A, p, r ); 
	} 

	return ; 
} 

int partition( int A [], int p, int r ){ 
	int pivot = A[r];
	int i = p-1;

	F( j, p, r-1 ){
		if( A[j] < pivot ){
			i++;
			//swap( A, i, j );
			swap( A, i, j );
		}
	}

	//swap( A, i + 1, r );
	swap( A, i+1, r );
	return i + 1;
}

void quickSort( int A [], int p, int r ){ 
	if( p + 7 < r  ){
		int q = partition( A, p, r );
		quickSort( A, p, q - 1 );
		quickSort( A, q + 1, r );

		//F( i, p, r ){
		//	cout << A[i] << " ";
		//}
	} 
	else if( p < r ){  
		insertionSort( A, p, r ); 
	}

	return ;
} 

void insertionSort( int A [], int p, int r ){ 
	F( i, p+1, r ){
		FB( j, i, p + 1 ){
			if( A[j] < A[j - 1] ){
				swap( A, j, j-1 );
			}
			else{
				break; 
			}
		}
	}

	return ;
} 

void selectionSort( int A [], int p, int r ){ 
	// denote p = 0, r = n-1 
	int n = r - p + 1; //total number 

	F( i, 1, n ){
		int minIndex = p + i - 1; 
		int minValue = A[p + i - 1]; 
		F( j, p + i - 1, r ){
			if( minValue > A[j] ){ 
				minValue = A[j]; 
				minIndex = j; 
			} 
		} 
		swap( A, p + i - 1, minIndex );
	}
	return ;
} 

void selectionSort2Way( int A [], int p, int r ){ 
	// denote p = 0, r = n-1 
	int n = r - p + 1; //total number 

	F(i, 1, n/2){
		//testing
		//F( k, p, r ){ 
		//	cout << A[k] << ' '; 
		//} 
		//cout << endl; 

		int minValue = A[p + i - 1]; 
		int minIndex = p + i - 1; 

		int maxValue = A[p + i - 1]; 
		int maxIndex = p + i - 1; 

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
			//all the same, flat array
			return ; 
		} 
		else if( p + i - 1 == maxIndex ){ //A = C 
			swap( A, p + i - 1, minIndex );
			swap( A, r - i + 1, minIndex ); 
		} 
		else{
			swap( A, p + i - 1, minIndex );
			swap( A, r - i + 1, maxIndex ); 
		}
	}
	return ;
} 

void selectionSort2WayV2( int A [], int p, int r ){ 
	// denote p = 0, r = n-1 
	int n = r - p + 1; //total number 

	if( p + 15 < r ){
		selectionSort2Way( A, p, r );
		return ;
	}
	F(i, 1, n/2){
		//testing
		//F( k, p, r ){ 
		//	cout << A[k] << ' '; 
		//} 
		//cout << endl; 

		int minValue = A[p + i - 1]; 
		int minIndex = p + i - 1; 

		int maxValue = A[p + i - 1]; 
		int maxIndex = p + i - 1; 

		int begin = p + i - 1;
		int end = r - i + 1;
		int j = begin; 
		if( (end - begin + 1) %2 != 0 ){ 
			j++; 
		}
		while(1){
			if( j > (end) ){
				break;	
			}
			if( A[j] < A[j+1] ){
				if( minValue > A[j] ){
					minValue = A[j];
					minIndex = j; 
				} 
				if( maxValue < A[j+1] ){ 
					maxValue = A[j+1];
					maxIndex = j+1; 
				} 
			} 
			else{ 
				if( minValue > A[j+1] ){
					minValue = A[j+1];
					minIndex = j+1; 
				} 
				if( maxValue < A[j] ){ 
					maxValue = A[j];
					maxIndex = j; 
				} 
			} 
			j+=2; 
		} 

		if( minIndex == maxIndex ){ 
			//all the same, flat array
			return ; 
		} 
		else if( p + i - 1 == maxIndex ){ //A = C 
			swap( A, p + i - 1, minIndex );
			swap( A, r - i + 1, minIndex ); 
		} 
		else{
			swap( A, p + i - 1, minIndex );
			swap( A, r - i + 1, maxIndex ); 
		}
	}
	return ;
} 

void bbSort( int A [], int p, int r ){
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

bool doneYet( int A [], int p, int r ){
	// denote p = 0, r = n-1
	F( i, p, r-1 ){ 
		if( A[i] > A[i+1] ){ 
			return false; 
		}
	}

	return true;
}






