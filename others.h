
#include <iostream>
#include <common.h>

using namespace std;

class Others{
public:
	//constructors
	Others(){
	}

	//methods
	bool hasDuplication( int array [], int* size ){
		F( i, 0, (* size)-1 ){
			F( j, 0, (* size)-1 ){
				if( array[i] == array[j] && i!=j ){
					return true;
				}
			}
		}
		return false;
	}

	int binarySearchValidator( int array [], int begin, int end, int * target ){
		//brute force
		F( i, begin, end ){
			if( array[i] == (*target) ){
				return i;
			}
		} 
		return -1;
	}

	int binarySearchRec( int array [], int begin, int end, int * target ){
		//recursivly
		if( begin > end ){
			return -1;
		}
		int middle = (begin + end)/2;
		if( array[middle] == (*target) ){
			return middle;
		}
		else if( (*target) < array[middle] ){
			//left
			return binarySearchRec( array, begin, middle-1, target );
		}else{
			//right
			return binarySearchRec( array, middle+1, end, target );
		}
	}

	int binarySearchIter( int array [], int begin, int end, int * target ){
		//iteratively
		while(1){
			if( begin > end ){
				return -1;
			}
			int middle = (begin + end)/2;
			if( array[middle] == (*target) ){
				return middle;
			}
			else if( (*target) < array[middle] ){
				//left
				end = middle-1;
				continue;
			}else{
				//right
				begin = middle+1; 
				continue;
			}
		}
	}

};