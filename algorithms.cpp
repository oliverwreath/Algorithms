
#include <algorithms.h> 
#include <iomanip>

#include <sorting.h> 
#include <binarySearchTrees.h>
#include <staque.h>
#include <linkedList.h>
#include <vector.h>
#include <others.h>
#include <dynamicProgramming.h>

#include <vector>
#include <string>

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
// int main() 
// { 
// 	TreeNode<int> newNode = TreeNode<int>(4); 
// 	Tree<int> tree1( &TreeNode<int>(3) ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &newNode ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &TreeNode<int>(1) ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &TreeNode<int>(2) ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &TreeNode<int>(9) ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &TreeNode<int>(2) ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &TreeNode<int>(4) ); 
// 	tree1.printTreePre( ); 

// 	tree1.insertNode( &TreeNode<int>(8) ); 
// 	tree1.printTreePre( ); 

// 	cout << (* tree1.searchTree( 3 ) ).getValue() << endl; 

// 	cout << (* tree1.minimum()).getValue() << endl; 

// 	cout << (* tree1.maximum()).getValue() << endl; 

// 	TreeNode<int> * tmp = tree1.suc( tree1.minimum()); 
// 	if(tmp != NULL){
// 		cout << (* tmp).getValue() << endl; 
// 	}else{
// 		cerr << "error NO SUC !" << endl; 
// 	}

// 	tmp = tree1.suc( tree1.maximum());
// 	if(tmp != NULL){
// 		cout << (* tmp).getValue() << endl;
// 	}else{
// 		cerr << "error NO SUC !" << endl;
// 	}

// 	tmp = tree1.pre( tree1.minimum());
// 	if(tmp != NULL){
// 		cout << (* tmp).getValue() << endl;
// 	}else{
// 		cerr << "error NO PRE !" << endl;
// 	}

// 	tmp = tree1.pre( tree1.maximum());
// 	if(tmp != NULL){
// 		cout << (* tmp).getValue() << endl;
// 	}else{
// 		cerr << "error NO PRE !" << endl;
// 	}

// 	tree1.deleteEntry( 8 ); cout << "delete 8 :" << endl;
// 	tree1.printTreePre( ); 

// 	tree1.deleteEntry( 3 ); cout << "delete 3 :" << endl;
// 	tree1.printTreePre( ); 

// 	tree1.deleteEntry( 4 ); cout << "delete 4 :" << endl;
// 	tree1.printTreePre( ); 

// 	tree1.deleteEntry( 9 ); cout << "delete 9 :" << endl;
// 	tree1.printTreePre( ); 

// 	tree1.deleteEntry( 2 ); cout << "delete 2 :" << endl;
// 	tree1.printTreePre( ); 

// 	tree1.deleteEntry( 8 ); cout << "delete 8 :" << endl;
// 	tree1.printTreePre( ); 

// 	tmp = NULL; 

// 	system("pause"); 
// 	return 0; 
// } 

////staque
//int main()
//{
//	Stack<int> st = Stack<int>();
//	int tmp = 0;
//
//	if( !st.top(&tmp) ){
//		cout << "top: " << tmp << endl;
//	}
//	if( !st.pop() ){
//		cout << "pop " << endl;
//	}
//	if( !st.push(3) ){
//		cout << "push: " << 3 << endl;
//	}
//	if( !st.top(&tmp) ){
//		cout << "top: " << tmp << endl;
//	}
//	if( !st.push(5) ){
//		cout << "push: " << 5 << endl;
//	}
//	if( !st.top(&tmp) ){
//		cout << "top: " << tmp << endl;
//	}
//	if( !st.clear() ){
//		cout << "clear: " << endl;
//	}
//	if( !st.top(&tmp) ){
//		cout << "top: " << tmp << endl;
//	}
//
//	cout << endl;
//	Queue<int> qt = Queue<int>();
//
//	if( !qt.retrieve(&tmp) ){
//		cout << "retrieve: " << tmp << endl;
//	}
//	if( !qt.serve() ){
//		cout << "serve " << endl;
//	}
//	if( !qt.append(3) ){
//		cout << "append: " << 3 << endl;
//	}
//	if( !qt.retrieve(&tmp) ){
//		cout << "retrieve: " << tmp << endl;
//	}
//	if( !qt.append(5) ){
//		cout << "append: " << 5 << endl;
//	}
//	if( !qt.retrieve(&tmp) ){
//		cout << "retrieve: " << tmp << endl;
//	}
//	if( !qt.serve() ){
//		cout << "serve " << endl;
//	}
//	if( !qt.retrieve(&tmp) ){
//		cout << "retrieve: " << tmp << endl;
//	}
//	if( !qt.clear() ){
//		cout << "clear: " << endl;
//	}
//	if( !qt.retrieve(&tmp) ){
//		cout << "retrieve: " << tmp << endl;
//	}
//
//	cout << endl;
//	Staque<int> sq = Staque<int>();
//
//	if( !sq.dequeue(&tmp) ){
//		cout << "dequeue: " << tmp << endl;
//	}
//	if( !sq.enqueue(3) ){
//		cout << "enqueue: " << 3 << endl;
//	}
//	if( !sq.dequeue(&tmp) ){
//		cout << "dequeue: " << tmp << endl;
//	}
//	if( !sq.enqueue(3) ){
//		cout << "enqueue: " << 3 << endl;
//	}
//	if( !sq.enqueue(5) ){
//		cout << "enqueue: " << 5 << endl;
//	}
//	if( !sq.enqueue(99) ){
//		cout << "enqueue: " << 99 << endl;
//	}
//	if( !sq.dequeue(&tmp) ){
//		cout << "dequeue: " << tmp << endl;
//	}
//	if( !sq.dequeue(&tmp) ){
//		cout << "dequeue: " << tmp << endl;
//	}
//	if( !sq.clear() ){
//		cout << "clear: " << endl;
//	}
//	if( !sq.dequeue(&tmp) ){
//		cout << "dequeue: " << tmp << endl;
//	}
//
//	system("pause");
//	return 0;
//}

////dLinkedList
//int main()
//{
//	//Stack<int> st = Stack<int>();
//	//int tmp = 0;
//
//	dLinkedList<int> ll = dLinkedList<int>();
//
//	bool ret = ll.contains(3);
//	if(ret){ cout << "contains: 3!" << endl; }else{ cout << "contains: NOT ANY 3!" << endl; }
//	
//	ll.addLast(3);
//	ll.print();
//
//	ret = ll.contains(3);
//	if(ret){ cout << "contains: 3!" << endl; }else{ cout << "contains: NOT ANY 3!" << endl; }
//
//	ll.addLast(1);
//	ll.print();
//
//	ll.addFirst(9);
//	ll.print();
//
//	ll.addFirst(6);
//	ll.print();
//
//	ll.addFirst(13);
//	ll.print();
//
//	ll.addBefore( ll.find(3), 6 );
//	ll.print();
//	
//	ll.addAfter( ll.findLast(6), 7 );
//	ll.print();
//
//	system("pause");
//	return 0;
//}

////Vector
//int main()
//{ 
//   Vector <int> v1;
//   Vector <int>::iterator Iter;
//   
//   v1.push_back( 10 );
//   v1.push_back( 20 );
//   v1.push_back( 30 );
//   v1.push_back( 40 );
//   v1.push_back( 50 );
//
//   cout << "v1 =" ;
//   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
//      cout << " " << *Iter;
//   cout << endl;
//
//   v1.erase( v1.begin( ) );
//   cout << "v1 =";
//   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
//      cout << " " << *Iter;
//   cout << endl;
//
//   v1.erase( v1.begin( ) + 1, v1.begin( ) + 3 );
//   cout << "v1 =";
//   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
//      cout << " " << *Iter;
//   cout << endl;
//
//   v1.clear();
//   cout << "v1 =";
//   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
//      cout << " " << *Iter;
//   cout << endl;
//
//   v1.push_back( 40 );
//   v1.push_back( 50 );
//   v1.pop_back();
//   v1.push_back( 60 );
//   cout << "v1 =";
//   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
//      cout << " " << *Iter;
//   cout << endl;
//
//	system("pause");
//	return 0;
//}

////searching
//int main(){
//	Others<int>* ot = new Others<int>();
//	int array [] = {-5, -2, 0, 1, 2, 3, 4, 5, 6};
//	int size = sizeof(array)/ sizeof(* array);
//
//	////hasDuplication
//	//bool retb = (*ot).hasDuplication( array, &size );
//	//if( retb ){cout << "has" << endl;}
//	//else{cout << "NOT has" << endl;}
//
//	//binarySearch
//	F( target, -6, 8 ){
//		int ret = (*ot).binarySearchIter( array, 0, size-1, &target );
//		if( ret == (*ot).binarySearchValidator( array, 0, size-1, &target ) ){
//			cout << "binSearch: IS Done!" << endl;
//		}
//		else{
//			cout << "binSearch: NOT Done!" << endl;
//		}
//	}
//	cout << "min: " <<  (*ot).min( array, size ) << endl;
//	cout << "max: " <<  (*ot).max( array, size ) << endl;
//	int* min = new int();
//	int* max = new int();
//	if( (*ot).minMax( array, size, min, max ) == 0 ){
//		cout << "min: " <<  (*min) << endl;
//		cout << "max: " <<  (*max) << endl;
//	}
//
//	system("pause");
//	return 0;
//}

////getFirstNonRepIndex
//int main(){
//	Others<int>* ot = new Others<int>();
//	int array [] = {-5, -2, 0, 1, 2, 3, 4, 5, 6};
//	int size = sizeof(array)/ sizeof(* array);
//
//	string st1 = "aaaccccccttdlkjjkljlk";
//
//	cout << "fstNonRep: " << (*ot).getFirstNonRepIndex( st1 ) << endl;
//
//	system("pause");
//	return 0;
//}


////dLinkedList
//int main()
//{
//	//Stack<int> st = Stack<int>();
//	//int tmp = 0;
//
//	int array1 [] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//
//	int array2 [] = {1, 2, 8, 9, 10, 17, 17, 20};
//
//	int size1 = sizeof( array1 )/ sizeof( array1[0] );
//	int size2 = sizeof( array2 )/ sizeof( array2[0] );
//
//	DynaPro<int> dp = DynaPro<int>(  );
//	DynaPro<int> dp2 = DynaPro<int>(  );
//
//	cout << dp.rodDP(array1, size1 ) << endl;
//
//	cout << dp2.rodDP(array2, size2 ) << endl;
//
//	//F( i, 0, 70 ){
//	//	cout << dp2.hopCutting( i ) << endl;
//	//}
//
//	F( i, 0, 20){
//		cout << dp2.robotPathDP( i-1, i+3 ) << endl;
//	}
//
//	system("pause");
//	return 0;
//}

////lcs series
//int main(){
//    //input
//    int ii;
//    string a;
//    string b;
//	DynaPro<int> DP = DynaPro<int>();
//
//    while( cin >> ii >> a ){
//        b = a;
//        DP.reverseString(b);
//        cout << ii - DP.lcs( a, b ) << endl;
//    }
//
//    //output
//    system("pause");
//    return 0;
//}

////maximum subarray sum
//int main(){
//    int nn;
//    int** arr;
//	DynaPro<int> DP = DynaPro<int>();
//    while( scanf_s("%d", &nn) != EOF ){
//        //scan
//        arr = new int* [nn];
//        for( int i = 0; i <= nn-1; i++ ){
//            arr[i] = new int [nn];
//            for( int j = 0; j <= nn-1; j++ ){
//                scanf_s("%d", &arr[i][j]);
//            }  
//        }
//
//        //process
//        cout << DP.D2MSS( arr, nn ) << endl;
//        for( int i = 0; i <= nn-1; i++ ){
//            delete [] arr[i];
//        }
//        delete [] arr;
//    }
//
//    //output
//    system("pause");
//    return 0;
//}

