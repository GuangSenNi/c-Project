#include <iostream>
#include"Sort.h"

#include"stdlib.h"
#include <time.h>
using namespace std;

int data[20];

void Create()
{
    srand(time(0));
    for(int i=0;i<20;i++)
    {
        data[i]=rand()%100;
    }
}

void Show()
{
    for(int i=0;i<20;i++)
    {
        cout << data[i] << ",";
    }
}

int main()
{
    Sort m;
    Create();
    int c;
    while(1)
    {
        cout<<"\n0,exit\n1,InsertSort\n2,BubbleSort\n21,BubbleSort\n3,SelectionSort\n4,QuickSort\n41,QuickSort2\n5,MergeSort\n6,Show\n";
        cin>>c;
        cout<<endl;
        switch(c)
        {
        case 0:exit(0);
        case 1:m.InsertSort(data,8);Show();break;
        case 2:m.BubbleSort(data,8);Show();break;
        case 21:m.BubbleSort2(data,10);Show();break;
        case 3:m.SelectionSort(data,8);Show();break;
        case 4:m.QuickSort(data,0,19);Show();break;
        case 41:m.QuickSort2(data,0,19);Show();break;
        case 5:m.MergeSort(data,0,19);Show();break;
        case 6:Show();break;
        default:break;
        }
    }


    return 0;
}
