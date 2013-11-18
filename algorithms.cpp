
#include <algorithms.h> 
#include <iomanip>
#include <sorting.h> 
#include <binarySearchTrees.h>

//typedef int entry_type;

using namespace std;

////sorting
//int main()
//{
//	//MergeSort
//		//generate data as input 
//	srand( (unsigned)time(NULL) ); 
//	sorting<double> st = sorting<double>(MAXArray+1); 
//	sorting<double> st3 = sorting<double>(MAXArray+1); 
//
//		//operations
//	clock_t c1, c1e, c3, c3e;  
//	c1 = clock();
//	st.selectionSort( 0, MAXArray ); 
//	c1e = clock();
//
//	////QuickSort
//	//	//operations 
//	//c2 = clock(); 
//	//quickSort( in_array2, 0, MAXArray );
//	//c2e = clock();
//
//	//randQuickSort 
//		//operations
//	c3 = clock(); 
//	st3.selectionSort2WayV2( 0, MAXArray ); 
//	c3e = clock(); 
//
//	///output 
//	//st.printArray( MAXArray + 1 ); 
//
//	//st2.printArray( MAXArray + 1 ); 
//
//	//st3.printArray( MAXArray + 1 ); 
//
//	cout << MAXArray << " uniformly random numbers!" << endl; 
//
//	bool ret = false; 
//	ret = st.doneYet( 0, MAXArray );
//	if( ret ){
//		cout << "array1: IS done! " << endl;
//	}else{
//		cout << "array1: NOT done! " << endl;
//	}
//
//	ret = st3.doneYet( 0, MAXArray ); 
//	if( ret ){
//		cout << "array3: IS done! " << endl;
//	}else{
//		cout << "array3: NOT done! " << endl;
//	}
//
//	//output Timer
//	cout << "MergeS : " << setprecision(9) << (double)(c1e - c1)/CLOCKS_PER_SEC << endl;
//	//cout << setprecision(9) << "QuickSort : " << (double)(c2e - c2)/CLOCKS_PER_SEC << endl;
//	cout << "randQuickSort : " << setprecision(9) << (double)(c3e - c3)/CLOCKS_PER_SEC << endl;
//
//	system("pause");
//	return 0;
//}

//binarySearchTrees 
int main() 
{ 
	node<int> newNode = node<int>(4); 
	tree<int> tree1( &node<int>(3) ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &newNode ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &node<int>(1) ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &node<int>(2) ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &node<int>(9) ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &node<int>(2) ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &node<int>(4) ); 
	tree1.printTreePre( ); 

	tree1.insertNode( &node<int>(8) ); 
	tree1.printTreePre( ); 

	cout << (* tree1.searchTree( 3 ) ).getValue() << endl; 

	cout << (* tree1.minimum()).getValue() << endl; 

	cout << (* tree1.maximum()).getValue() << endl; 

	node<int> * tmp = tree1.suc( tree1.minimum()); 
	if(tmp != NULL){
		cout << (* tmp).getValue() << endl; 
	}else{
		cerr << "error NO SUC !" << endl; 
	}

	tmp = tree1.suc( tree1.maximum());
	if(tmp != NULL){
		cout << (* tmp).getValue() << endl;
	}else{
		cerr << "error NO SUC !" << endl;
	}

	tmp = tree1.pre( tree1.minimum());
	if(tmp != NULL){
		cout << (* tmp).getValue() << endl;
	}else{
		cerr << "error NO PRE !" << endl;
	}

	tmp = tree1.pre( tree1.maximum());
	if(tmp != NULL){
		cout << (* tmp).getValue() << endl;
	}else{
		cerr << "error NO PRE !" << endl;
	}

	tree1.deleteEntry( 8 ); cout << "delete 8 :" << endl;
	tree1.printTreePre( ); 

	tree1.deleteEntry( 3 ); cout << "delete 3 :" << endl;
	tree1.printTreePre( ); 

	tree1.deleteEntry( 4 ); cout << "delete 4 :" << endl;
	tree1.printTreePre( ); 

	tree1.deleteEntry( 9 ); cout << "delete 9 :" << endl;
	tree1.printTreePre( ); 

	tree1.deleteEntry( 2 ); cout << "delete 2 :" << endl;
	tree1.printTreePre( ); 

	tree1.deleteEntry( 8 ); cout << "delete 8 :" << endl;
	tree1.printTreePre( ); 

	tmp = NULL; 

	system("pause"); 
	return 0; 
} 

