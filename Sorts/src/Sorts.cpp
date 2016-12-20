#include "Sorts.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;
Sorts::Sorts(int sizeOfArray)
{
    length = sizeOfArray;
}

void Sorts::BubbleSort(int array1[])
{
    comparision =0;
    exchange = 0;
    for(int i = 0; i < length-1; i++){
        for(int j = 0; j < length-1; j++){
            comparision++;
            if(array1[j] > array1[j+1]){
                exchange++;
                int temp = array1[j];
                array1[j] = array1[j+1];
                array1[j+1] = temp;
            }
        }

    }
    cout<<"Comparisions:" + comparision<<" Exchange: " + exchange<<endl;

}
void Sorts::InsertionSort(int array1[])
{
    comparision = 0;
    exchange = 0;

    for(int i = 1; i < length; i++){
        int currentIndex = i;
        for(int j = currentIndex-1; j >=0;j--){
                comparision++;
                if(array1[currentIndex] < array1[j]){
                    int temp = array1[currentIndex];
                    array1[currentIndex] = array1[j];
                    array1[j] = temp;
                    exchange++;
                    currentIndex = j;

                }
                else{
                    break;
                }

        }

    }
    cout<<"Comparisions:" + comparision<<" Exchange: " + exchange<<endl;


}
void Sorts::MergeSort(int array1[])
{
  comparision = 0;
  exchange = 0;
  int temp[length];
  MergeSort(array1,temp,0,length-1);
  cout<<"Comparisions:" + comparision<<" Exchange: " + exchange<<endl;

}
void Sorts::MergeSort(int array1[], int temp[], int low, int high)
{
    if(high <= low){
        return;
    }
    else{
        int mid = low + (high - 2)/2;
        MergeSort(array1,temp,low,mid);
        MergeSort(array1,temp,mid+1,high);
        Merge(array1,temp,low,mid,high);
    }

}
void Sorts::Merge(int array1[], int temp[], int low, int mid, int high)
{
    for(int i = low; i <=high; i++)
    {
        temp[i] = array1[i];

    }

    //set starting pointers to the two halves of the arrays to be joined
    int i = low;
    int j = mid +1;
    for(int k = low; k<=high;k++)
    {
        exchange++;
        comparision++;
        if(i > mid){
            array1[k] = temp[j];
            j++;
        }
        else if(j > high){
            array1[k] = temp[i];
            i++;

        }
        else if(temp[j] < temp[i])
        {
            array1[k] = temp[j];
            j++;
        }
        else{
            array1[k] = temp[i];
            i++;
        }
    }


}
void Sorts::QuickSort(int array1[])
{
    comparision = 0;
    exchange = 0;
    QuickSort(array1,0,length-1);
    cout<<"Comparisions:" + comparision<<" Exchange: " + exchange<<endl;

}
void Sorts::QuickSort(int array1[], int low, int high)
{

    if(low == high){
        srand(time(NULL));
        int pivotIndex = rand()%high;
        int pivot = array1[pivotIndex];
        exchange++;
        array1[pivotIndex] = array1[high];
        array1[high] = pivot;
        int i = low -1;
        int j = high;
        do{
            do{i++; comparision++;} while(array1[i] < pivot);
            do{j--;comparision++;} while(array1[j] > pivot && j > low);
            comparision++;
            if(i<j){
                exchange++;
                int temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
            }
        }while(i<j);
        array1[high] = array1[i];
        array1[i] = pivot;
        exchange++;
        QuickSort(array1,low,i-1);
        QuickSort(array1,i+1,high);
    }

}
void Sorts::ShellSort(int array1[])
{
   comparision = 0;
   exchange = 0;
   int temp;
   int difference = length/2;
   int i;
   int swapped;
    do{
        do
        {
            swapped = 0;
            for(i = 0; i < length - difference; i++)
            {
                if(array1[i] > array1[i + difference])
                {
                    temp = array1[i];
                    array1[i] = array1[i + difference];
                    array1[i + difference] = temp;
                    swapped = 1;
                }
            }
        }
        while(swapped == 1);
    }
    while((difference = difference/2) >= 1);
    cout<<"Everything works"<<end;
    //cout<<"Comparisions:" + comparision<<" Exchange: " + exchange<<endl;
}

