

#include <iostream>

using namespace std; 

template <class Type>
class TreeNode{
public:
	//constructor
	TreeNode(){
		value = 0;
		left = NULL; 
		right = NULL;
		parent = NULL; 
	}

	TreeNode( Type entry){
		value = entry;
		left = NULL; 
		right = NULL;
		parent = NULL; 
	}

	//destructor
	~TreeNode(){
	}

	//methods
	Type getValue(){
		return value;
	}

	TreeNode* getLeft(){
		return left;
	}

	TreeNode* getRight(){
		return right;
	}

	TreeNode* getParent(){
		return parent;
	}

	void setLeft( TreeNode* y ){
		left = y;
	}

	void setRight( TreeNode* y ){
		right = y;
	}

	void setParent( TreeNode* y ){
		parent = y;
	}

private: 
	Type value;
	TreeNode* left; 
	TreeNode* right;
	TreeNode* parent; 
};

template <class Type>
class Tree{
public: 
	//typedef
	typedef TreeNode<Type>* iterator;

	//constructor
	Tree(){ 
		root = NULL;
	}
	
	Tree( iterator rt ){ 
		root = rt;
	}

	//destructor
	~Tree(){ 
		//TBD
		root = NULL;
	}

	//methods
	iterator getRoot(){
		return root; 
	}

	iterator minimum( iterator original ){
		iterator tmp = original;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getLeft() != NULL )
		{
			tmp = (* tmp).getLeft();
		}

		return tmp; 
	}

	iterator maximum( iterator original ){
		iterator tmp = original;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getRight() != NULL )
		{
			tmp = (* tmp).getRight();
		}

		return tmp; 
	}

	iterator minimum(){
		iterator tmp = root;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getLeft() != NULL )
		{
			tmp = (* tmp).getLeft();
		}

		return tmp; 
	}

	iterator maximum(){
		iterator tmp = root;
		if( tmp == NULL ){
			return NULL; 
		}
		while( (* tmp).getRight() != NULL )
		{
			tmp = (* tmp).getRight();
		}

		return tmp; 
	}

	iterator pre( iterator original ){
		if( original == NULL ){
			return original;
		}
		iterator tmp = original;
		if( (* tmp).getLeft() != NULL ){
			return maximum( (* tmp).getLeft() );
		}
		iterator y = (* tmp).getParent(); 
		while( y != NULL && (* y).getLeft() == tmp ){
			tmp = y; 
			y = (* y).getParent();
		}
		tmp = NULL; 
		return y; 
	}

	iterator suc( iterator original ){
		if( original == NULL ){
			return original;
		}
		iterator tmp = original;
		if( (* tmp).getRight() != NULL ){
			return minimum( (* tmp).getRight() );
		}
		iterator y = (* tmp).getParent(); 
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

	iterator searchTree( Type entry ){ 
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

	bool insertNode( iterator z ){ 
		iterator y = root ; 

		if( root == NULL ){ 
			root = z; 
			return true; 
		} 

		iterator tmp = root;
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

	bool deleteNode( iterator z ){
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
			iterator y = minimum( (* z).getRight() );
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

	bool deleteEntry( Type entry ){ 
		return deleteNode( searchTree( entry ) ); 
	}

private:
	iterator root;

	void transPlant( iterator u, iterator v ){
		iterator p = (* u).getParent(); 
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

	void printTreeInRec( iterator root ){ 
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

	void printTreePreRec( iterator root ){ 
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

	void printTreePosRec( iterator root ){ 
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

	iterator searchTreeRec( iterator root, Type entry ){
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





