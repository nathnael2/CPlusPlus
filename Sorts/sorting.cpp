#include <iostream>
#include <cstring>
#include <fstream>
#include<include/"Sorts.h">

using namespace std;
int* get_from_file(char* filename);

int main()
{
    char* Random = "Random.txt";
    char* Reversed = "Reversed.txt";
    char* NearlySorted = "NearlySorted.txt";
    char* FewUnique = "FewUnique.txt";

    int* random = get_from_file(Random);
    int* reversed = get_from_file(Reversed);
    int* nearlysorted = get_from_file(NearlySorted);
    int* fewunique = get_from_file(FewUnique);

    Sorts* s = new Sorts(10000);

    //sorting using bubblesort
    cout<<"Sorting random, reversed, nearly sorted and few unique data using Bubble Sort"<<endl;
    s->BubbleSort(random);
    s->BubbleSort(reversed);
    s->BubbleSort(nearlysorted);
    s->BubbleSort(fewunique);


    //sorting using insertionsort
    cout<<"Sorting random, reversed, nearly sorted and few unique data using Insertion Sort"<<endl;
    s->InsertionSort(random);
    s->InsertionSort(reversed);
    s->InsertionSort(nearlysorted);
    s->InsertionSort(fewunique);

    //sorting using mergesort
    cout<<"Sorting random, reversed, nearly sorted and few unique data using Merge Sort"<<endl;
    s->MergeSort(random);
    s->MergeSort(reversed);
    s->MergeSort(nearlysorted);
    s->MergeSort(fewunique);

    //sorting using shellsort
    cout<<"Sorting random, reversed, nearly sorted and few unique data using Shell Sort"<<endl;
    s->ShellSort(random);
    s->ShellSort(reversed);
    s->ShellSort(nearlysorted);
    s->ShellSort(fewunique);

    //sorting using quicksort
    cout<<"Sorting random, reversed, nearly sorted and few unique data using Quick Sort"<<endl;
    s->QuickSort(random);
    s->QuickSort(reversed);
    s->QuickSort(nearlysorted);
    s->QuickSort(fewunique);


    delete s;
    return 0;

}
int* get_from_file(char* filename)
{
    int arr[10000];
    ifstream in;
    in.open(filename);
    int i=0;
    while(in.eof() || i >= 10000){
        int readnum;
        in>>readnum;
        arr[i] = readnum;
        i++;
    }
    return arr;


}

