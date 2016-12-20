#ifndef SORTS_H
#define SORTS_H


class Sorts
{
    public:
        int comparision;
        int exchange;
        int length;
        Sorts(int sizeOfArray);
        void BubbleSort(int array1[]);
        void InsertionSort(int array1[]);
        void QuickSort(int array1[]);
        void MergeSort(int array1[]);
        void ShellSort(int array1[]);

    private:
        void MergeSort(int array1[],int temp[], int low, int high);
        void QuickSort(int array1[], int low, int high);
        void Merge(int arrray1[],int temp[], int low, int mid, int high);

};

#endif // SORTS_H
