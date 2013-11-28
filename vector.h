

#include <iostream>
#include <common.h>

using namespace std; 

template<class Type>
class Vector{
public:
	//
	typedef Type* iterator;
	typedef int size_type;
	//constructors
	Vector(){
		buffer = new Type[10];
		size = 0;
		capacity = 10;
	}

	Vector( size_type newSize ){
		buffer = new Type[newSize];
		size = 0;
		capacity = newSize;
	}

	Vector( const Vector& anotherVector ){
		size = anotherVector.getSize();
		capacity = anotherVector.getCapacity();
		buffer = new Type[size];
		F( i, 0, size-1 ){
			buffer[i] = anotherVector.at(i);
		}
	}

	//methods
	Type& at( const size_type i ){
		if( !empty() ){
			return *buffer[i];
		}
	}

	Type& front(){
		if( !empty() ){
			return *buffer[0];
		}
	}

	Type& back(){
		if( !empty() ){
			return *buffer[size-1];
		}
	}

	iterator begin(){
		if( !empty() ){
			return &buffer[0];
		}
		return buffer;
	}

	iterator end(){
		if( !empty() ){
			return &buffer[size];
		}
		return buffer;
	}

	iterator erase( const iterator where ){
		if( where == NULL ){
			return NULL;
		}
		iterator tmpWhere = where;
		while( tmpWhere != end() ){
			*tmpWhere = *(tmpWhere+1);
			tmpWhere++;
		}
		size--;
		return begin();
	}
   
	iterator erase( const iterator first, const iterator last ){
		if( first == NULL || last == NULL ){
			return NULL;
		}
		iterator tmpFirst = first;
		iterator tmpLast = last;
		while( tmpLast != end() ){
			*tmpFirst = *tmpLast;
			tmpFirst++;
			tmpLast++;
		}
		size -= (tmpLast - tmpFirst);
		return begin();
	}

	void push_back( const Type& newElement ){
		if( size >= capacity ){
			//expand
			expand();
		}
		*end() = newElement;
		size++;
	}

	void pop_back(){
		if( size > 0 ){
			size--;
		}
	}

	void expand(){
		if( size == 0 ){
			buffer = new Type[10];
			size = 0;
			capacity = 10;
		}else{
			iterator newBuffer = new Type[size*resize_factor]; 
			F( i, 0, size-1 ){
				newBuffer[i] = buffer[i];
			}
			size *= resize_factor;
			capacity *= resize_factor;
			iterator oldBuffer = buffer;
			buffer = newBuffer;
			delete [] oldBuffer;
			delete newBuffer;
		}
	}

	void clear(){
		size = 0;
	}

	bool empty() const{
		return( size == 0 );
	}	

	//access the private variables. 
	size_type getSize(){
		return size;
	}

	bool setSize( size_type newSize ){
		size = newSize;
		return true;
	}

	size_type getCapacity() const{
		return capacity;
	}

	bool setCapacity( size_type newCapacity ){
		capacity = newCapacity;
		return true;
	}

	iterator getBuffer() const{
		return buffer;
	}

	bool setBuffer( iterator newBuffer ){
		buffer = newBuffer;
		return true;
	}
	
private: 
	iterator buffer;
	size_type size;
	size_type capacity;
	static const size_type resize_factor = 2;
};