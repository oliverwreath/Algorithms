
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <math.h>

#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c
#define MAXDP 100001
#define maxLen 100001

typedef int entry_type;

using namespace std;


class Queue{
public:
	Queue(){
		begin = 0;
		end = 0;
		length = 0;
		entry_array = new entry_type [maxLen];
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

	int append( entry_type entry ){
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

	int retrieve( entry_type *ret ){
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
	entry_type * entry_array ;
	int length;
	int begin;
	int end;
};

class Stack{
public:
	Stack(){
		length = 0;
		entry_array = new entry_type [maxLen];
	}

	int push( entry_type entry ){
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

	int top( entry_type *ret ){
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
	entry_type * entry_array ;
	int length;
};

class Staque{
public: 
	Staque(){
		st1 = Stack();
		st2 = Stack();
	}

	int enqueue( entry_type in ){
		int ret = st1.push( in );
		return ret;
	}

	int dequeue( entry_type * out ){
		if( st2.empty() ){
			while( !st1.empty() ){
				entry_type tmp;
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
	Stack st1;
	Stack st2;
};


int main()
{
	Stack st = Stack();
	int tmp = 0;

	if( !st.top(&tmp) ){
		cout << "top: " << tmp << endl;
	}
	if( !st.pop() ){
		cout << "pop " << endl;
	}
	if( !st.push(3) ){
		cout << "push: " << 3 << endl;
	}
	if( !st.top(&tmp) ){
		cout << "top: " << tmp << endl;
	}
	if( !st.push(5) ){
		cout << "push: " << 5 << endl;
	}
	if( !st.top(&tmp) ){
		cout << "top: " << tmp << endl;
	}
	if( !st.clear() ){
		cout << "clear: " << endl;
	}
	if( !st.top(&tmp) ){
		cout << "top: " << tmp << endl;
	}

	cout << endl;
	Queue qt = Queue();

	if( !qt.retrieve(&tmp) ){
		cout << "retrieve: " << tmp << endl;
	}
	if( !qt.serve() ){
		cout << "serve " << endl;
	}
	if( !qt.append(3) ){
		cout << "append: " << 3 << endl;
	}
	if( !qt.retrieve(&tmp) ){
		cout << "retrieve: " << tmp << endl;
	}
	if( !qt.append(5) ){
		cout << "append: " << 5 << endl;
	}
	if( !qt.retrieve(&tmp) ){
		cout << "retrieve: " << tmp << endl;
	}
	if( !qt.serve() ){
		cout << "serve " << endl;
	}
	if( !qt.retrieve(&tmp) ){
		cout << "retrieve: " << tmp << endl;
	}
	if( !qt.clear() ){
		cout << "clear: " << endl;
	}
	if( !qt.retrieve(&tmp) ){
		cout << "retrieve: " << tmp << endl;
	}

	cout << endl;
	Staque sq = Staque();

	if( !sq.dequeue(&tmp) ){
		cout << "dequeue: " << tmp << endl;
	}
	if( !sq.enqueue(3) ){
		cout << "enqueue: " << 3 << endl;
	}
	if( !sq.dequeue(&tmp) ){
		cout << "dequeue: " << tmp << endl;
	}
	if( !sq.enqueue(3) ){
		cout << "enqueue: " << 3 << endl;
	}
	if( !sq.enqueue(5) ){
		cout << "enqueue: " << 5 << endl;
	}
	if( !sq.enqueue(99) ){
		cout << "enqueue: " << 99 << endl;
	}
	if( !sq.dequeue(&tmp) ){
		cout << "dequeue: " << tmp << endl;
	}
	if( !sq.dequeue(&tmp) ){
		cout << "dequeue: " << tmp << endl;
	}
	if( !sq.clear() ){
		cout << "clear: " << endl;
	}
	if( !sq.dequeue(&tmp) ){
		cout << "dequeue: " << tmp << endl;
	}

	system("pause");
	return 0;
}



