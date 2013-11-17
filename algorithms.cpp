
#include <algorithms.h> 
#include <iomanip>
#include <sorting.h> 
#include <binarySearchTrees.h>

//typedef int entry_type;

using namespace std;

void printArray( int in_array [], int length ){
	cout << length << endl ;
	F( i, 0, length - 1 ){ 
		cout << in_array[i] << ' '; 
	} 
	cout << endl; 
} 

//int in_array1 [MAXArray+1]; 
////int in_array2 [MAXArray+1];
//int in_array3 [MAXArray+1]; 

//sorting
int main()
{
	//MergeSort
		//generate data as input 
	srand( (unsigned)time(NULL) ); 
	sorting<int> st = sorting<int>(MAXArray+1);
	sorting<int> st3 = sorting<int>(MAXArray+1);

		//operations
	clock_t c1, c1e, c2, c2e, c3, c3e;  
	c1 = clock();
	st.mergeSort( 0, MAXArray ); 
	c1e = clock();

	////QuickSort
	//	//operations 
	//c2 = clock(); 
	//quickSort( in_array2, 0, MAXArray );
	//c2e = clock();

	//randQuickSort 
		//operations
	c3 = clock(); 
	st3.randQuickSort( 0, MAXArray ); 
	c3e = clock(); 

	///output 
	//st.printArray( MAXArray + 1 ); 

	//st2.printArray( MAXArray + 1 ); 

	//st3.printArray( MAXArray + 1 ); 

	cout << MAXArray << " uniformly random numbers!" << endl; 

	bool ret = false; 
	ret = st.doneYet( 0, MAXArray );
	if( ret ){
		cout << "array1: IS done! " << endl;
	}else{
		cout << "array1: NOT done! " << endl;
	}

	ret = st3.doneYet( 0, MAXArray ); 
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

////binarySearchTrees 
//int main() 
//{ 
//	node<int> newNode = node<int>(4); 
//	tree<int> tree( &node<int>(3) ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &newNode ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &node<int>(1) ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &node<int>(2) ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &node<int>(9) ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &node<int>(2) ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &node<int>(4) ); 
//	tree.printTreeIn( ); 
//
//	tree.insertNode( &node<int>(8) ); 
//	tree.printTreeIn( ); 
//
//	cout << (* tree.searchTree( 3 ) ).getValue() << endl; 
//
//	cout << (* tree.minimum()).getValue() << endl; 
//
//	cout << (* tree.maximum()).getValue() << endl; 
//
//	node<int> * tmp = tree.suc( tree.minimum()); 
//	if(tmp != NULL){
//		cout << (* tmp).getValue() << endl; 
//	}else{
//		cerr << "error NO SUC !" << endl; 
//	}
//
//	tmp = tree.suc( tree.maximum());
//	if(tmp != NULL){
//		cout << (* tmp).getValue() << endl;
//	}else{
//		cerr << "error NO SUC !" << endl;
//	}
//
//	tmp = tree.pre( tree.minimum());
//	if(tmp != NULL){
//		cout << (* tmp).getValue() << endl;
//	}else{
//		cerr << "error NO PRE !" << endl;
//	}
//
//	tmp = tree.pre( tree.maximum());
//	if(tmp != NULL){
//		cout << (* tmp).getValue() << endl;
//	}else{
//		cerr << "error NO PRE !" << endl;
//	}
//
//
//	tmp = NULL; 
//
//	system("pause"); 
//	return 0; 
//} 
//
