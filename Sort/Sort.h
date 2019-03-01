#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<iostream>
using namespace std;

class Sort
{
private:
    void Swap(int array[],int i,int j)
    {
        int tmp=array[i];
        array[i]=array[j];
        array[j]=tmp;
    }
public:
    Sort(){};
    ~Sort(){};

    void InsertSort(int array[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(array[j]<array[j-1])
                Swap(array,j,j-1);
            else
                break;
        }
    }
}

   void BubbleSort(int array[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
                Swap(array,j,j+1);
        }
    }
}

void BubbleSort2(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(array[j]>array[j-1])
            {
                Swap(array,j,j-1);
            }
        }
    }

}

void SelectionSort(int array[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int smallest=i;
        for(int j=i+1;j<n;j++)
        {
            if(array[smallest]>array[j])
                smallest=j;
        }
        Swap(array,i,smallest);
    }
}

void QuickSort(int array[], int left, int right)
{
    if(left < right)
    {
        int i = left -1, j = right + 1;
        int mid = array[(left + right) / 2];
        while(true)
        {
            while(array[++i] < mid);
            while(array[--j] > mid);
            if(i >= j)
            {
                break;
            }
            Swap(array, i, j);
        }
        QuickSort(array, left, i - 1);
        QuickSort(array, j + 1, right);
    }
}

int QuickSort2(int array[], int left, int right)
{
    if(left<right)
    {
    int key=array[left];
    while(left<right)
    {
        while(left<right&&key<array[right])
        {
            right--;
        }
        while(left<right&&key>array[left])
        {
            left++;
        }
        if(left<right)
        {Swap(array,left,right); }

    }
     cout<<right;
     return right;
    }
}

void QuickSort3(int array[], int left, int right)
{

    int i=
}


//归并排序

void MergeSort(int array[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);
        Merge(array, left, mid, right);
    }
}
//合并两个已排好序的子链

void Merge(int array[], int left, int mid, int right)
{
    int temp[right - left + 1];
    int i = left, j = mid + 1, m = 0;
    while(i <= mid && j <= right)
    {
        if(array[i] < array[j])
        {
            temp[m++] = array[i++];
        }
        else
        {
            temp[m++] = array[j++];
        }
    }
    while(i <= mid)
    {
        temp[m++] = array[i++];
    }
    while(j <= right)
    {
        temp[m++] = array[j++];
    }
    for(int n = left, m = 0; n <= right; n++, m++)
    {
        array[n] = temp[m];
    }
    delete temp;
}
};

#endif // SORT_H_INCLUDED
