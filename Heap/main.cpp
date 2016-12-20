/*********************************************************************************
/ Here's an implementation of a heap using an array. The code below includes
/ functionality for creating, inserting and deleting. But what if the tree is out
/ of order?
/
/ Write the functions for ReHeapUp and ReHeapDown. When do these functions have
/ to be called?
/
/ Test the function using the main function provided. Does it work? How is the
/ heap stored in the array?
/*********************************************************************************/


#include <iostream>

using namespace std;

#define max 20

class Heap
{
	private:
        int A[max];
        int n;
		void ReHeapUp(int root, int bottom);        //create this function
		void ReHeapDown(int root, int bottom);      //create this function
	public:
		Heap()
		{
		    n=0;
			for(int i=0; i<max; i++)
				A[i]=0;
		}
		void Create();
		void Insert(int i);
		void DeleteMaxVal();
		void write_out();
};

void Heap::DeleteMaxVal()
{
    int temp=A[0];
    A[0]=A[n-1];
    A[n-1]=temp;
    n--;
    ReHeapDown(0,n-1);
    //Is the heap in order?
}

void Heap::Insert(int x)
{
	A[n]=x;
	//Is the heap in order?
	n++;
	ReHeapUp(0,n-1);
}

void Heap::write_out()
{
    int i;
    for(i=0; i<n; i++)
        cout << A[i] << "\t";
    cout << endl;
}

void Heap::Create()
{
    int i,data,size;
    cout << "Enter number of elements: ";
    cin >> size;//n;
    cout << "\nEnter data: ";
    for(i=0; i<size; i++)
    {
        cin>> data;
        Insert(data);
    }
}

void Heap::ReHeapUp(int root, int bottom){

 while(A[bottom] > A[(bottom-1)/2] && bottom > root){
        int temp = A[bottom];
        A[bottom] = A[(bottom-1)/2];
        A[(bottom-1)/2] = temp;
        bottom = (bottom-1)/2;

 }


}
void Heap::ReHeapDown(int root, int bottom){
    while((A[root] < A[(2*root)+1] && (2*root +1) < bottom) || (A[root] < A[(2*root+2)] && 2*root+2 < bottom)){
            if(A[2*root + 2] > A[2*root+1]){
                int temp = A[root];
                A[root] = A[2*root+2];
                A[2*root+2] = temp;
                root = 2*root + 2;

            }
            else{
                int temp = A[root];
                A[root] = A[2*root+1];
                A[2*root+1] = temp;
                root = 2*root + 1;
            }


    }
}
int main()
{
    Heap h;
    h.Create();
    cout << "Writing out the heap: ";
    h.write_out();
    cout << "\nDeleting the max value. Here's what's left: ";
    h.DeleteMaxVal();
    cout << endl;
    h.write_out();
    cout << "\nDeleting the max value. Here's what's left: ";
    h.DeleteMaxVal();
    cout << endl;
    h.write_out();
    cout << endl;
    cout << "Final heap: ";
    h.write_out();
    return 0;
}
