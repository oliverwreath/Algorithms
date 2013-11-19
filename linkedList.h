
#include <iostream>

using namespace std; 

template<class T>
class dLinkedListNode{
public: 
	dLinkedListNode( T in ){
		value = in; 
		prev = NULL;
		next = NULL; 
	}

	T getValue(){
		return value;
	}

	dLinkedListNode<T> * getPrev(){
		return prev;
	}

	dLinkedListNode<T> * getNext(){
		return next;
	}

	bool setValue( T invalue ){
		value = invalue;
		return true;
	}

	bool setPrev( dLinkedListNode<T> * inprev ){
		prev = inprev;
		return true;
	}

	bool setNext( dLinkedListNode<T> * innext ){
		next = innext; 
		return true;
	}

private: 
	T value;
	dLinkedListNode<T> * prev;
	dLinkedListNode<T> * next;
};

template<class T> 
class dLinkedList{ 
public: 
	dLinkedList(){
		first = NULL;
		last = NULL;
		count = 0;
	}

	dLinkedList( dLinkedListNode<T> * in ){ 
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

	dLinkedListNode<T> * getNext(){
		return (* first).getNext();
	}

	dLinkedListNode<T> * getNext( dLinkedListNode<T> * in ){
		return (* in).getNext();
	}

	dLinkedListNode<T> * getPrev(){
		return (* first).getPrev();
	}

	dLinkedListNode<T> * getPrev( dLinkedListNode<T> * in ){
		return (* in).getPrev();
	}

	bool addFirst( T value ){
		dLinkedListNode<T> * newNode = new dLinkedListNode<T>( value );
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

	bool addFirst( dLinkedListNode<T> * newNode ){
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

	bool addLast( T value ){
		dLinkedListNode<T> * newNode = new dLinkedListNode<T>( value );
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

	bool addLast( dLinkedListNode<T> * newNode ){
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

	bool addAfter( dLinkedListNode<T> * in, dLinkedListNode<T> * newNode ){
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		dLinkedListNode<T> * tmp = first;
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
				dLinkedListNode<T> * n = (* indexNode).getNext();
				(* newNode).setNext( n );
				(* n).setPrev( newNode );
				(* indexNode).setNext( newNode );
				(* newNode).setPrev( indexNode );
			}
			count ++;
		}
		return true;
	}

	bool addAfter( dLinkedListNode<T> * indexNode, T value ){ 
		dLinkedListNode<T> * newNode = new dLinkedListNode<T>( value );
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		dLinkedListNode<T> * tmp = first;
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
				dLinkedListNode<T> * n = (* indexNode).getNext();
				(* newNode).setNext( n );
				(* n).setPrev( newNode );
				(* indexNode).setNext( newNode );
				(* newNode).setPrev( indexNode );
			}
			count ++;
		}
		return true;
	}

	bool addBefore( dLinkedListNode<T> * indexNode, dLinkedListNode<T> * newNode ){
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		dLinkedListNode<T> * tmp = first;
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
				dLinkedListNode<T> * p = (* indexNode).getPrev();
				(* newNode).setPrev( p );
				(* p).setNext( newNode );
				(* indexNode).setPrev( newNode );
				(* newNode).setNext( indexNode );
			}
			count ++;
		}
		return true;
	}

	bool addBefore( dLinkedListNode<T> * indexNode, T value ){
		dLinkedListNode<T> * newNode = new dLinkedListNode<T>( value );
		if( indexNode == NULL ){
			//error
			cerr << "error: Invalid argument: NULL! " << endl;
			return false; 
		}
		dLinkedListNode<T> * tmp = first;
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
				dLinkedListNode<T> * p = (* indexNode).getPrev();
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
		dLinkedListNode<T> * tmp; 
		while( first != NULL ){
			tmp = first; 
			first = (* first).getNext(); 
			delete tmp; 
		}
		last = NULL;
		count = 0;
	}

	dLinkedListNode<T> * find( T valueToFind ){
		dLinkedListNode<T> * tmp = first; 
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
	
	dLinkedListNode<T> * findLast( T valueToFind ){
		dLinkedListNode<T> * tmp = first; 
		dLinkedListNode<T> * tmpMarker = NULL; 
		while( tmp != NULL ){
			if( (* tmp).getValue() == valueToFind ){
				tmpMarker = tmp; 
			}
			tmp = (* tmp).getNext(); 
		}
		return tmpMarker; 
	}

	bool contains( T valueToFind ){ 
		dLinkedListNode<T> * tmp = first; 
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

	bool remove( T valueToFind ){ 
		dLinkedListNode<T> * tmp = first; 
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

	bool remove( dLinkedListNode<T> * node ){ 
		T valueToFind = (* node).getValue();
		dLinkedListNode<T> * tmp = first; 
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
		dLinkedListNode<T> * tmp = (* first).getNext(); 

		if( tmp == NULL ){
			delete first;
			first = tmp;
			(* first).setPrev( NULL );
		}
		count--;

		return true;
	}

	bool removeLast(){
		dLinkedListNode<T> * tmp = (* last).getPrev(); 

		if( tmp == NULL ){
			delete last;
			last = tmp;
			(* last).setNext( NULL );
		}
		count--;

		return true;
	}

	bool print(){
		dLinkedListNode<T> * tmp = first;
		while( tmp != NULL ){
			cout << (* tmp).getValue() << " "; 
			tmp = (* tmp).getNext(); 
		}
		cout << endl; 
		return true;
	}

private: 
	dLinkedListNode<T> * first;
	dLinkedListNode<T> * last;
	int count;
};