

#include <iostream>

using namespace std; 

template <class T>
class node{
private: 
	T value;
	node * left; 
	node * right;
	node * parent; 

public:
	node(){
		value = 0;
		left = NULL; 
		right = NULL;
		parent = NULL; 
	}

	node( T entry){
		value = entry;
		left = NULL; 
		right = NULL;
		parent = NULL; 
	}

	T getValue(){
		return value;
	}

	node * getLeft(){
		return left;
	}

	node * getRight(){
		return right;
	}

	node * getParent(){
		return parent;
	}

	void setLeft( node * y ){
		left = y;
	}

	void setRight( node * y ){
		right = y;
	}

	void setParent( node * y ){
		parent = y;
	}

};

template <class T>
class tree{
private:
	node<T> * root;

public: 
	tree(){ 
		root = NULL;
	}
	tree( node<T> * rt ){ 
		root = rt;
	}

	node<T> * getRoot(){
		return root; 
	}

	node<T> * minimum( node<T> * original ){
		node<T> * tmp = original;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getLeft() != NULL )
		{
			tmp = (* tmp).getLeft();
		}

		return tmp; 
	}

	node<T> * maximum( node<T> * original ){
		node<T> * tmp = original;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getRight() != NULL )
		{
			tmp = (* tmp).getRight();
		}

		return tmp; 
	}

	node<T> * minimum(){
		node<T> * tmp = root;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getLeft() != NULL )
		{
			tmp = (* tmp).getLeft();
		}

		return tmp; 
	}

	node<T> * maximum(){
		node<T> * tmp = root;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getRight() != NULL )
		{
			tmp = (* tmp).getRight();
		}

		return tmp; 
	}

	node<T> * pre( node<T> * original ){
		if( original == NULL ){
			return original;
		}
		node<T> * tmp = original;
		if( (* tmp).getLeft() != NULL ){
			return maximum( (* tmp).getLeft() );
		}
		node<T> * y = (* tmp).getParent(); 
		while( y != NULL && (* y).getLeft() == tmp ){
			tmp = y; 
			y = (* y).getParent();
		}
		tmp = NULL; 
		return y; 
	}

	node<T> * suc( node<T> * original ){
		if( original == NULL ){
			return original;
		}
		node<T> * tmp = original;
		if( (* tmp).getRight() != NULL ){
			return minimum( (* tmp).getRight() );
		}
		node<T> * y = (* tmp).getParent(); 
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
		return printTreePreRec( root );
	}

	void printTreePos(){ 
		//pos-order
		return printTreePosRec( root );
	}

	node<T> * searchTree( T entry ){ 
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

	bool insertNode( node<T> * z ){ 
		node<T> * y = root ; 

		if( root == NULL ){ 
			root = z; 
			return true; 
		} 

		node<T> * tmp = root;
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

	bool deleteNode( T z ){
	

		return false;
	}

private:
	void printTreeInRec( node<T> * root ){ 
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

	void printTreePreRec( node<T> * root ){ 
		//pre-order
		if( (* root).getValue() != NULL ){ 
			cout << (* root).getValue(); 
		} 
		if( (* root).getLeft() != NULL ){
			printTreePreRec( (* root).getLeft() );
		}
		if( (* root).getRight() != NULL ){
			printTreePreRec( (* root).getRight() );
		}
	}

	void printTreePosRec( node<T> * root ){ 
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

	node<T> * searchTreeRec( node<T> * root, T entry ){
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





