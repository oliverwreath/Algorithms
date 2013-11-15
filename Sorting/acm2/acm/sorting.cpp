

#include <sorting.h>
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

void swap( int A [], int q, int r ){
	int tmp = A[q];
	A[q] = A[r];
	A[r] = tmp; 
	return ;
}

int partition( int A [], int p, int r ){
	int q = p;
	int i = p - 1;
	int j = p; 
	F( j, p, r - 1 ){
		if( A[j] <= A[r] ){
			i++;
			swap( A, i, j );
		}
	}

	q = i + 1;
	swap( A, q, r );
	return q;
}

void quickSort( int A [], int p, int r ){
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


int randPartition( int A [], int p, int r ){
	int randR = (double)rand() / (RAND_MAX + 1) * (r + 1 - p) + p; 
	swap( A, r, randR );

	int q = p;
	int i = p - 1;
	int j = p; 
	F( j, p, r - 1 ){
		if( A[j] <= A[r] ){
			i++;
			swap( A, i, j );
		}
	}

	q = i + 1;
	swap( A, q, r );
	return q;
}

void randQuickSort( int A [], int p, int r ){
	if( p < r ){
		int q = randPartition( A, p, r );
		randQuickSort( A, p, q - 1 );
		randQuickSort( A, q + 1, r );

		//F( i, p, r ){
		//	cout << A[i] << " ";
		//}
	}

	cout << endl;
	return ;
} 