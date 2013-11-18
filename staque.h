

template<class T>
class Queue{
public:
	Queue(){
		begin = 0;
		end = 0;
		length = 0;
		entry_array = new T [maxLen];
	}

	int next(int ret){
		if( ret <= maxLen-2 ){
			ret++;
		}
		else{
			ret = 0;
		}
		return ret;
	}

	int append( T entry ){
		if( !full() ){
			entry_array[end] = entry;
			end = next(end);
			length++;
			return 0;
		}
		else{
			cerr<<"error: appending: full Queue! can't append anymore!\n";
			return 1;
		}
	}

	int serve(){
		if( !empty() ){
			begin = next(begin);
			length--;
			return 0;
		}
		else{
			cerr<<"error: serving: empty Queue!\n";
			return 1;
		}
	}

	int retrieve( T *ret ){
		if( !empty() ){
			* ret = entry_array[begin];
			return 0;
		}
		else{
			cerr<<"error: retrieving: empty Queue!\n";
			return 1;
		}
	}

	bool full(){
		if( length >= maxLen ){
			return true;
		}
		else{
			return false;
		}
	}

	bool empty(){
		if( length <= 0 ){
			return true;
		}
		else{
			return false;
		}
	}

	int clear(){
		length = 0;
		begin = 0;
		end = 0;
		return 0;
	}

	int size(){
		return length;
	}

private:
	T * entry_array ;
	int length;
	int begin;
	int end;
};

template<class T>
class Stack{
public:
	Stack(){
		length = 0;
		entry_array = new T [maxLen];
	}

	int push( T entry ){
		if( !full() ){
			entry_array[length] = entry;
			length++;
			return 0;
		}
		else{
			cerr<<"error: pushing: full Stack! can't push anymore!\n";
			return 1;
		}
	}

	int pop(){
		if( !empty() ){
			length--;
			return 0;
		}
		else{
			cerr<<"error: popping: empty Stack!\n";
			return 1;
		}
	}

	int top( T *ret ){
		if( !empty() ){
			* ret = entry_array[length-1];
			return 0;
		}
		else{
			cerr<<"error: topping: empty Stack!\n";
			return 1;
		}
	}

	bool full(){
		if( length >= maxLen ){
			return true;
		}
		else{
			return false;
		}
	}

	bool empty(){
		if( length <= 0 ){
			return true;
		}
		else{
			return false;
		}
	}

	int clear(){
		length = 0;
		return 0;
	}

	int size(){
		return length;
	}

private:
	T * entry_array ;
	int length;
};

template<class T>
class Staque{
public: 
	Staque(){
		st1 = Stack<T>();
		st2 = Stack<T>();
	}

	int enqueue( T in ){
		int ret = st1.push( in );
		return ret;
	}

	int dequeue( T * out ){
		if( st2.empty() ){
			while( !st1.empty() ){
				T tmp;
				st1.top( &tmp );
				st2.push( tmp );
				st1.pop();
			}
		}
		if( st2.empty() ){
			cerr<<"error: dequeuing: empty Staque!\n";
			return 1;
		}
		st2.top( out );
		st2.pop();
		return 0;
	}

	bool empty(){
		return ( st1.empty() && st2.empty() );
	}

	int clear(){
		int ret = 0;
		ret += st1.clear();
		ret += st2.clear();
		return ret;
	}

private:
	Stack<T> st1;
	Stack<T> st2;
};

