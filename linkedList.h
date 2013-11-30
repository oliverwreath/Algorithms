
#include <iostream>

using namespace std; 

template<class Type>
class dLinkedListNode{
public: 
	//typedef
	typedef dLinkedListNode<Type>* iterator;
	//constructor
	dLinkedListNode( Type in ){
		value = in; 
		prev = NULL;
		next = NULL; 
	}

	//destructor
	~dLinkedListNode(){
	}

	//methods
	Type getValue(){
		return value;
	}

	iterator getPrev(){
		return prev;
	}

	iterator getNext(){
		return next;
	}

	bool setValue( Type invalue ){
		value = invalue;
		return true;
	}

	bool setPrev( iterator inprev ){
		prev = inprev;
		return true;
	}

	bool setNext( iterator innext ){
		next = innext; 
		return true;
	}

private: 
	Type value;
	iterator prev;
	iterator next;
};

template<class Type> 
class dLinkedList{ 
public: 
	//typedef
	typedef dLinkedListNode<Type>* iterator;

	//constructor
	dLinkedList(){
		first = NULL;
		last = NULL;
		count = 0;
	}

	dLinkedList( iterator in ){ 
		if( in == NULL ){
			first = NULL;
			last = NULL;
			count = 0;
		}
		else{
			first = in;
			last = in;
			count = 1;
		}
	}

	//destructor
	~dLinkedList(){
		clear();
	}

	//methods
	iterator getNext(){
		return (* first).getNext();
	}

	iterator getNext( iterator in ){
		return (* in).getNext();
	}

	iterator getPrev(){
		return (* first).getPrev();
	}

	iterator getPrev( iterator in ){
		return (* in).getPrev();
	}

	bool addFirst( Type value ){
		iterator newNode = new dLinkedListNode<Type>( value );
		if( first != NULL ){
			(* first).setPrev( newNode );
			(* newNode).setNext( first );
			first = newNode; 
			count ++; 
		}
		else{
			first = newNode; 
			last = newNode;
			count ++; 
		}
		return true;
 	}

	bool addFirst( iterator newNode ){
		if( first != NULL ){
			(* first).setPrev( newNode );
			(* newNode).setNext( first );
			first = newNode; 
			count ++; 
		}
		else{
			first = newNode; 
			last = newNode;
			count ++; 
		}
		return true;
 	}

	bool addLast( Type value ){
		iterator newNode = new dLinkedListNode<Type>( value );
		if( last != NULL ){
			(* last).setNext( newNode );
			(* newNode).setPrev( last );
			last = newNode; 
			count ++; 
		}
		else{
			first = newNode; 
			last = newNode; 
			count ++; 
		}
		return true;
 	}

	bool addLast( iterator newNode ){
		if( last != NULL ){
			(* last).setNext( newNode );
			(* newNode).setPrev( last );
			last = newNode; 
			count ++; 
		}
		else{
			first = newNode; 
			last = newNode; 
			count ++; 
		}
		return true;
 	}

	bool addAfter( iterator in, iterator newNode ){
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		iterator tmp = first;
		while( tmp != NULL && (* tmp).getValue() != (* indexNode).getValue() ){
			tmp = (* tmp).getNext();
		}
		if( tmp != NULL ){
			if( indexNode == last ){
				(* indexNode).setNext( newNode );
				(* newNode).setPrev( indexNode );
				last = newNode; 
			}
			else{
				iterator n = (* indexNode).getNext();
				(* newNode).setNext( n );
				(* n).setPrev( newNode );
				(* indexNode).setNext( newNode );
				(* newNode).setPrev( indexNode );
			}
			count ++;
		}
		return true;
	}

	bool addAfter( iterator indexNode, Type value ){ 
		iterator newNode = new dLinkedListNode<Type>( value );
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		iterator tmp = first;
		while( tmp != NULL && (* tmp).getValue() != (* indexNode).getValue() ){
			tmp = (* tmp).getNext();
		}
		if( tmp != NULL ){
			if( indexNode == last ){
				(* indexNode).setNext( newNode );
				(* newNode).setPrev( indexNode );
				last = newNode; 
			}
			else{
				iterator n = (* indexNode).getNext();
				(* newNode).setNext( n );
				(* n).setPrev( newNode );
				(* indexNode).setNext( newNode );
				(* newNode).setPrev( indexNode );
			}
			count ++;
		}
		return true;
	}

	bool addBefore( iterator indexNode, iterator newNode ){
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		iterator tmp = first;
		while( tmp != NULL && (* tmp).getValue() != (* indexNode).getValue() ){
			tmp = (* tmp).getNext();
		}
		if( tmp != NULL ){
			if( indexNode == first ){
				(* indexNode).setPrev( newNode );
				(* newNode).setNext( indexNode );
				first = newNode; 
			}
			else{
				iterator p = (* indexNode).getPrev();
				(* newNode).setPrev( p );
				(* p).setNext( newNode );
				(* indexNode).setPrev( newNode );
				(* newNode).setNext( indexNode );
			}
			count ++;
		}
		return true;
	}

	bool addBefore( iterator indexNode, Type value ){
		iterator newNode = new dLinkedListNode<Type>( value );
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		iterator tmp = first;
		while( tmp != NULL && (* tmp).getValue() != (* indexNode).getValue() ){
			tmp = (* tmp).getNext();
		}
		if( tmp != NULL ){
			if( indexNode == first ){
				(* indexNode).setPrev( newNode );
				(* newNode).setNext( indexNode );
				first = newNode; 
			}
			else{
				iterator p = (* indexNode).getPrev();
				(* newNode).setPrev( p );
				(* p).setNext( newNode );
				(* indexNode).setPrev( newNode );
				(* newNode).setNext( indexNode );
			}
			count ++;
		}
		return true;
	}

	void clear(){
		iterator tmp; 
		while( first != NULL ){
			tmp = first; 
			first = (* first).getNext(); 
			delete tmp; 
		}
		last = NULL;
		count = 0;
	}

	iterator find( Type valueToFind ){
		iterator tmp = first; 
		while( tmp != NULL ){
			if( (* tmp).getValue() == valueToFind ){
				break; 
			}
			else{
				tmp = (* tmp).getNext(); 
			}
		}
		return tmp; 
	}
	
	iterator findLast( Type valueToFind ){
		iterator tmp = first; 
		iterator tmpMarker = NULL; 
		while( tmp != NULL ){
			if( (* tmp).getValue() == valueToFind ){
				tmpMarker = tmp; 
			}
			tmp = (* tmp).getNext(); 
		} 
		return tmpMarker; 
	} 

	bool contains( Type valueToFind ){ 
		iterator tmp = first; 
		while( tmp != NULL ){ 
			if( (* tmp).getValue() == valueToFind ){ 
				return true;  
			} 
			else{ 
				tmp = (* tmp).getNext(); 
			}
		}
		return false; 
	}

	bool remove( Type valueToFind ){ 
		iterator tmp = first; 
		while( tmp != NULL ){ 
			if( (* tmp).getValue() == valueToFind ){ 
				if( (* tmp).getPrev() != NULL ){ 
					(* (* tmp).getPrev()).setNext( (* tmp).getNext() );
				}
				else{
					first = (* tmp).getNext();
				}
				if( (* tmp).getNext() != NULL ){
					(* (* tmp).getNext()).setPrev( (* tmp).getPrev() );
				}
				else{
					last = (* tmp).getPrev();
				}
				delete tmp;
				count--;
				return true;
			} 
			else{ 
				tmp = (* tmp).getNext();
			} 
		} 
		return false; 
	} 

	bool remove( iterator node ){ 
		Type valueToFind = (* node).getValue();
		iterator tmp = first; 
		while( tmp != NULL ){ 
			if( (* tmp).getValue() == valueToFind ){ 
				if( (* tmp).getPrev() != NULL ){ 
					(* (* tmp).getPrev()).setNext( (* tmp).getNext() );
				}
				else{
					first = (* tmp).getNext();
				}
				if( (* tmp).getNext() != NULL ){
					(* (* tmp).getNext()).setPrev( (* tmp).getPrev() );
				}
				else{
					last = (* tmp).getPrev();
				}
				delete tmp;
				count--;
				return true;
			} 
			else{ 
				tmp = (* tmp).getNext();
			} 
		} 
		return false; 
	} 

	bool removeFirst(){
		iterator tmp = (* first).getNext(); 

		if( tmp == NULL ){
			delete first;
			first = tmp;
			(* first).setPrev( NULL );
		}
		count--;

		return true;
	}

	bool removeLast(){
		iterator tmp = (* last).getPrev(); 

		if( tmp == NULL ){
			delete last;
			last = tmp;
			(* last).setNext( NULL );
		}
		count--;

		return true;
	}

	bool print(){
		iterator tmp = first;
		while( tmp != NULL ){
			cout << (* tmp).getValue() << " "; 
			tmp = (* tmp).getNext(); 
		}
		cout << endl; 
		return true;
	}

private: 
	dLinkedListNode<Type>* first;
	dLinkedListNode<Type>* last;
	int count;
};