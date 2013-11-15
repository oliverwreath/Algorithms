
#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)

//
int merge( int in_array [], int m, int begin, int end );

void mergeSort( int in_array [], int begin, int end );

//
int partition( int * A, int p, int r );

void quickSort( int * A, int p, int r );

//
int randPartition( int A [], int p, int r );

void randQuickSort( int A [], int p, int r );

//
void insertionSort( int * A, int p, int r );

void selectionSort( int * A, int p, int r );

void selectionSort2Way( int * A, int p, int r ); 

void bbSort( int * A, int p, int r );