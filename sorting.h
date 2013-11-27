

//#include <time.h>
//#include <stdlib.h>
//#include <iostream>
//#include <limits>
////#include <algorithm>
//
//int imin = numeric_limits<int>::min();
//int imax = numeric_limits<int>::max();
//
//float fmin = numeric_limits<float>::min();
//float fmax = numeric_limits<float>::max();

#include <common.h>

using namespace std;

template<class Type> 
class sorting{ 
public: 
	//
	typedef Type* iterator;
	//constructor
	sorting(){ 
		A = NULL;
	}

	sorting( int length ){ 
		A = new Type [length]; 

		F( i, 0, MAXArray ){ 
			A[i] = (Type)rand()/(RAND_MAX + 1) * (MAXArray-0) - (MAXArray/2); 
		} 
	} 

	int merge( iterator in_array, const int m, const int begin, const int end ){
		//smallest first
		int n = end - begin + 1;
		iterator B = new Type [n];
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

	void mergeSort( iterator in_array, const int begin, const int end ){
		int n = end - begin + 1;
		if( n > 1 ){
			mergeSort( in_array, begin, begin + n/2 - 1 ); 
			mergeSort( in_array, begin + n/2, end ); 
			merge( in_array, begin + n/2-1, begin, end ); 
		}
	}

	void mergeSort( const int begin, const int end ){
		int n = end - begin + 1;
		if( n > 1 ){
			mergeSort( A, begin, begin + n/2 - 1 ); 
			mergeSort( A, begin + n/2, end ); 
			merge( A, begin + n/2-1, begin, end ); 
		}
	}

	void swap( Type A [], int q, int r ){ 
		if( q == r ){
			return ;
		}
		else{
			Type tmp = A[q]; 
			A[q] = A[r]; 
			A[r] = tmp; 
			//A[q] = A[q] ^ A[r];
			//A[r] = A[q] ^ A[r];
			//A[q] = A[q] ^ A[r];
		}
		return ;
	}

	int randPartition( Type A [], int p, int r ){ 
		//srand( (unsigned)time(NULL) ); 
		int randR = rand() % (r - p + 1) + p; 
		//if( randR < p || (randR > r) ){ 
		//	cerr << "randR overflow" << endl; 
		//} 
		swap( A, r, randR ); 

		//partition
		Type pivot = A[r];
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

	void randQuickSort( Type A [], int p, int r ){ 
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

	void randQuickSort( int p, int r ){ 
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

	int partition( Type A [], int p, int r ){ 
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

	void quickSort( Type A [], int p, int r ){ 
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

	void insertionSort( Type A [], int p, int r ){ 
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

	void insertionSort( int p, int r ){ 
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

	void selectionSort( Type A [], int p, int r ){ 
		// denote p = 0, r = n-1 
		F( i, 1, r ){
			int begin = p + i - 1; 
			int minIndex = begin; 
			Type minValue = A[begin]; 
			F( j, begin, r ){
				if( minValue > A[j] ){ 
					minValue = A[j]; 
					minIndex = j; 
				} 
			} 
			swap( A, begin, minIndex );
		}
		return ;
	} 

	void selectionSort( int p, int r ){ 
		// denote p = 0, r = n-1 
		F( i, 1, r ){
			int begin = p + i - 1; 
			int minIndex = begin; 
			Type minValue = A[begin]; 
			F( j, begin, r ){
				if( minValue > A[j] ){ 
					minValue = A[j]; 
					minIndex = j; 
				} 
			} 
			swap( A, begin, minIndex );
		}
		return ;
	} 

	void selectionSort2Way( Type A [], int p, int r ){ 
		// denote p = 0, r = n-1 
		int n = r - p + 1; //total number 

		F(i, 1, n/2){
			int begin = p + i - 1;
			int end = r - i + 1;

			Type minValue = A[begin]; 
			int minIndex = begin; 

			Type maxValue = A[begin]; 
			int maxIndex = begin; 

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
				swap( A, begin, minIndex );
				swap( A, end, minIndex ); 
			} 
			else{
				swap( A, begin, minIndex );
				swap( A, end, maxIndex ); 
			}
		}
		return ;
	} 

	void selectionSort2Way( int p, int r ){ 
		// denote p = 0, r = n-1 
		int n = r - p + 1; //total number 

		F(i, 1, n/2){
			int begin = p + i - 1;
			int end = r - i + 1;

			Type minValue = A[begin]; 
			int minIndex = begin; 

			Type maxValue = A[begin]; 
			int maxIndex = begin; 

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
				swap( A, begin, minIndex );
				swap( A, end, minIndex ); 
			} 
			else{
				swap( A, begin, minIndex );
				swap( A, end, maxIndex ); 
			}
		}
		return ;
	} 

	void selectionSort2WayV2( Type A [], int p, int r ){ 
		// denote p = 0, r = n-1 
		int n = r - p + 1; //total number 

		if( p + 14 < r ){ 
			selectionSort2Way( A, p, r ); 
			return ; 
		} 
		F(i, 1, n/2){
			//testing
			//F( k, p, r ){ 
			//	cout << A[k] << ' '; 
			//} 
			//cout << endl; 

			int begin = p + i - 1;
			int end = r - i + 1;

			Type minValue = A[begin]; 
			int minIndex = begin; 

			Type maxValue = A[begin]; 
			int maxIndex = begin; 

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
				swap( A, begin, minIndex );
				swap( A, end, minIndex ); 
			} 
			else{
				swap( A, begin, minIndex );
				swap( A, end, maxIndex ); 
			}
		}
		return ;
	} 

	void selectionSort2WayV2( int p, int r ){ 
		// denote p = 0, r = n-1 
		int n = r - p + 1; //total number 

		if( p + 14 < r ){
			selectionSort2Way( A, p, r );
			return ; 
		} 
		F(i, 1, n/2){
			//testing
			//F( k, p, r ){ 
			//	cout << A[k] << ' '; 
			//} 
			//cout << endl; 

			int begin = p + i - 1;
			int end = r - i + 1;

			Type minValue = A[begin]; 
			int minIndex = begin; 

			Type maxValue = A[begin]; 
			int maxIndex = begin; 

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
				swap( A, begin, minIndex );
				swap( A, end, minIndex ); 
			} 
			else{
				swap( A, begin, minIndex );
				swap( A, end, maxIndex ); 
			}
		}
		return ;
	} 

	void bbSort( Type A [], int p, int r ){
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

	bool doneYet( Type A [], int p, int r ){
		// denote p = 0, r = n-1
		F( i, p, r-1 ){ 
			if( A[i] > A[i+1] ){ 
				return false; 
			}
		}

		return true;
	}

	bool doneYet( int p, int r ){
		// denote p = 0, r = n-1
		F( i, p, r-1 ){ 
			if( A[i] > A[i+1] ){ 
				return false; 
			}
		}

		return true;
	}

	void printArray( int length ){
		cout << length << endl ;
		F( i, 0, length - 1 ){ 
			cout << A[i] << ' '; 
		} 
		cout << endl; 
	} 

private:
	iterator A;
};