
#include <acm.h> 
#include <sorting.h> 
#include <iomanip>

#define MAXArray 99999

typedef int entry_type;

using namespace std;

void printArray( int in_array [], int length ){
	cout << length << endl ;
	F( i, 0, length - 1 ){ 
		cout << in_array[i] << ' '; 
	} 
	cout << endl; 
}

int main()
{
	//MergeSort
		//generate data as input
	srand( (unsigned)time(NULL) ); 
	int in_array1 [MAXArray+1]; 
	F( i, 0, MAXArray ){ 
		in_array1[i] = rand() % (MAXArray-0+1); 
	} 
		//operations
	clock_t c1, c1e, c2, c2e, c3, c3e;  
	c1 = clock();
	mergeSort( in_array1, 0, MAXArray ); 
	c1e = clock();

	////QuickSort
	//	//generate data as input
	//int in_array2 [MAXArray+1]; 
	//F( i, 0, sizeof(in_array2)/ sizeof(* in_array2) - 1 ){ 
	//	in_array2[i] = (double)rand() / (RAND_MAX + 1) * (MAXArray-1); 
	//} 
	//	//operations
	//c2 = clock();
	//quickSort( in_array2, 0, sizeof(in_array2) / sizeof( * in_array2 ) - 1 );
	//c2e = clock();

	//randQuickSort
		//generate data as input
	int in_array3 [MAXArray+1]; 
	F( i, 0, MAXArray ){ 
		in_array3[i] = rand() % (MAXArray-0+1); 
	} 
		//operations
	c3 = clock(); 
	randQuickSort( in_array3, 0, MAXArray ); 
	c3e = clock(); 

	///output 
	//printArray( in_array1, sizeof(in_array1) / sizeof(* in_array1) );

	//printArray( in_array2, sizeof(in_array2) / sizeof(* in_array2) );

	//printArray( in_array3, sizeof(in_array3) / sizeof(* in_array3) );

	cout << MAXArray << " uniformly random numbers!" << endl;

	bool ret = false; 
	ret = doneYet( in_array1, 0, MAXArray );
	if( ret ){
		cout << "array1: IS done! " << endl;
	}else{
		cout << "array1: NOT done! " << endl;
	}

	ret = doneYet( in_array3, 0, MAXArray ); 
	if( ret ){
		cout << "array3: IS done! " << endl;
	}else{
		cout << "array3: NOT done! " << endl;
	}


	//output Timer
	cout << "MergeS : " << setprecision(9) << (double)(c1e - c1)/CLOCKS_PER_SEC << endl;
	//cout << setprecision(9) << "QuickSort : " << (double)(c2e - c2)/CLOCKS_PER_SEC << endl;
	cout << "randQuickSort : " << setprecision(9) << (double)(c3e - c3)/CLOCKS_PER_SEC << endl;

	system("pause");
	return 0;
}



