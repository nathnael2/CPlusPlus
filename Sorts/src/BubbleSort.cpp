#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
    comparision = 0;
    exchange = 0;
}

void BubbleSort::Bsort(int[] array1)
{
    for(int i = 0; i < array1.length-1; i++){
        for(int j = 0; j < array1.length-1; j++){
            comparision++;
            if(array1[j] > array1[j+1]){
                exchange++;
                temp = array1[j];
                array1[j] = array1[j+1];
                array1[j+1] = temp;
            }
        }

    }


}
