
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

	system("pause");
	return 0;
}



