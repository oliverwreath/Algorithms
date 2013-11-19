

#include <iostream>

using namespace std; 

template <class T>
class TreeNode{
private: 
	T value;
	TreeNode * left; 
	TreeNode * right;
	TreeNode * parent; 

public:
	TreeNode(){
		value = 0;
		left = NULL; 
		right = NULL;
		parent = NULL; 
	}

	TreeNode( T entry){
		value = entry;
		left = NULL; 
		right = NULL;
		parent = NULL; 
	}

	T getValue(){
		return value;
	}

	TreeNode * getLeft(){
		return left;
	}

	TreeNode * getRight(){
		return right;
	}

	TreeNode * getParent(){
		return parent;
	}

	void setLeft( TreeNode * y ){
		left = y;
	}

	void setRight( TreeNode * y ){
		right = y;
	}

	void setParent( TreeNode * y ){
		parent = y;
	}

};

template <class T>
class Tree{
private:
	TreeNode<T> * root;

public: 
	Tree(){ 
		root = NULL;
	}
	Tree( TreeNode<T> * rt ){ 
		root = rt;
	}

	TreeNode<T> * getRoot(){
		return root; 
	}

	TreeNode<T> * minimum( TreeNode<T> * original ){
		TreeNode<T> * tmp = original;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getLeft() != NULL )
		{
			tmp = (* tmp).getLeft();
		}

		return tmp; 
	}

	TreeNode<T> * maximum( TreeNode<T> * original ){
		TreeNode<T> * tmp = original;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getRight() != NULL )
		{
			tmp = (* tmp).getRight();
		}

		return tmp; 
	}

	TreeNode<T> * minimum(){
		TreeNode<T> * tmp = root;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getLeft() != NULL )
		{
			tmp = (* tmp).getLeft();
		}

		return tmp; 
	}

	TreeNode<T> * maximum(){
		TreeNode<T> * tmp = root;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getRight() != NULL )
		{
			tmp = (* tmp).getRight();
		}

		return tmp; 
	}

	TreeNode<T> * pre( TreeNode<T> * original ){
		if( original == NULL ){
			return original;
		}
		TreeNode<T> * tmp = original;
		if( (* tmp).getLeft() != NULL ){
			return maximum( (* tmp).getLeft() );
		}
		TreeNode<T> * y = (* tmp).getParent(); 
		while( y != NULL && (* y).getLeft() == tmp ){
			tmp = y; 
			y = (* y).getParent();
		}
		tmp = NULL; 
		return y; 
	}

	TreeNode<T> * suc( TreeNode<T> * original ){
		if( original == NULL ){
			return original;
		}
		TreeNode<T> * tmp = original;
		if( (* tmp).getRight() != NULL ){
			return minimum( (* tmp).getRight() );
		}
		TreeNode<T> * y = (* tmp).getParent(); 
		while( y != NULL && (* y).getRight() == tmp ){
			tmp = y; 
			y = (* y).getParent();
		}
		tmp = NULL; 
		return y; 
	}

	void printTreeIn(){ 
		//in-order
		printTreeInRec( root );
		cout << endl;
	}

	void printTreePre(){ 
		//pre-order
		printTreePreRec( root );
		cout << endl;
	}

	void printTreePos(){ 
		//pos-order
		return printTreePosRec( root );
	}

	TreeNode<T> * searchTree( T entry ){ 
		if( root == NULL || ((* root).getValue() == entry) ){ 
			return root;
		} 
		if( entry < (* root).getValue() ){
			return searchTreeRec( (* root).getLeft(), entry );
		}
		else{
			return searchTreeRec( (* root).getRight(), entry );
		}
	}

	bool insertNode( TreeNode<T> * z ){ 
		TreeNode<T> * y = root ; 

		if( root == NULL ){ 
			root = z; 
			return true; 
		} 

		TreeNode<T> * tmp = root;
		while( tmp != NULL ){ 
			if( (* z).getValue() < (* tmp).getValue() ){
				y = tmp;
				tmp = (* tmp).getLeft(); 
			}
			else{
				y = tmp;
				tmp = (* tmp).getRight(); 
			}
		} 
		(* z).setParent(y); 
		if( (* z).getValue() < (* y).getValue() ){
			(* y).setLeft(z);
		}
		else {
			(* y).setRight(z);
		} 

		y = NULL;
		return true; 
	}

	bool deleteNode( TreeNode<T> * z ){
		if( z == NULL ){
			cerr << "error: InValid Input: no such TreeNode or entry !" << endl;
			return false;
		}
		if( (* z).getLeft() == NULL ){
			transPlant( z, (* z).getRight() );
		}
		else if( (* z).getRight() == NULL ){
			transPlant( z, (* z).getLeft() );
		}
		else{
			TreeNode<T> * y = minimum( (* z).getRight() );
			if( (* y).getParent() != z ){
				transPlant( y, (* y).getRight() );
				(* y).setRight( (* z).getRight() );
				(* (* y).getRight()).setParent( y );
			}
			(* y).setLeft( (* z).getLeft() );
			(* (* y).getLeft()).setParent( y );
			transPlant( z, y );
		}
		return true;
	}

	bool deleteEntry( T entry ){ 
		return deleteNode( searchTree( entry ) ); 
	}

private:
	void transPlant( TreeNode<T> * u, TreeNode<T> * v ){
		TreeNode<T> * p = (* u).getParent(); 
		if( p == NULL ){
			root = v;
		}
		else{
			if( (* p).getLeft() == u ){
				(* p).setLeft( v );
			}
			else{
				(* p).setRight( v );
			}
		} 
		if( v != NULL ){ 
			(* v).setParent( p ); 
		} 
	}

	void printTreeInRec( TreeNode<T> * root ){ 
		//in-order
		if( (* root).getLeft() != NULL ){
			printTreeInRec( (* root).getLeft() );
		}
		if( (* root).getValue() != NULL ){ 
			cout << (* root).getValue() << " "; 
		} 
		if( (* root).getRight() != NULL ){
			printTreeInRec( (* root).getRight() );
		}
	}

	void printTreePreRec( TreeNode<T> * root ){ 
		//pre-order
		if( (* root).getValue() != NULL ){ 
			cout << (* root).getValue() << " "; 
		} 
		if( (* root).getLeft() != NULL ){
			printTreePreRec( (* root).getLeft() );
		}
		if( (* root).getRight() != NULL ){
			printTreePreRec( (* root).getRight() );
		}
	}

	void printTreePosRec( TreeNode<T> * root ){ 
		//pos-order
		if( (* root).getLeft() != NULL ){
			printTreePosRec( (* root).getLeft() );
		}
		if( (* root).getRight() != NULL ){
			printTreePosRec( (* root).getRight() );
		}
		if( (* root).getValue() != NULL ){ 
			cout << (* root).getValue(); 
		} 
	} 

	TreeNode<T> * searchTreeRec( TreeNode<T> * root, T entry ){
		if( root == NULL || ((* root).getValue() == entry) ){ 
			return root;
		} 
		if( entry < (* root).getValue() ){
			return searchTreeRec( (* root).getLeft(), entry );
		}
		else{
			return searchTreeRec( (* root).getRight(), entry );
		}
	}
};





