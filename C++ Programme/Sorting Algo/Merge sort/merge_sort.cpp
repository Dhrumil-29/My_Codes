/*
    Merge sort:- Divide and conqure technique,TC :- O(n log n)
                procedure:-
                {2, 3, 12, 2, 4, 1, 17, 28}
                divide {2,3,12,2} , {4,1,17,28}
                divide {2,3} , {12,2} , {4,1} , {17,28}
                divide {2} , {3} , {12} , {2} , {4} , {1} , {17} , {28}
                sort   {2,3} , {2,12} , {1,4} , {17,28}
                sort   {2,2,3,12} , {1,4,17,28}
                sort   {1,2,2,3,4,12,17,28}
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void display(int arr[],int n)
{
    cout<<"\n\n\nSo sorted array...\n";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n\n"<<endl;
}

void merge_ele(int arr[],int start,int mid,int e)
{
    int len1 = mid-start;
    int len2 = e-mid+1;
    int arr1[len1] = {0};
    int arr2[len2] = {0};

    for(int i = 0;i< len1;i++)
    {
        arr1[i] = arr[i+start];
    }
    for(int i = 0;i< len2;i++)
    {
        arr2[i] = arr[i+mid];
    }

    int idx1 = 0,idx2 = 0,index = start;

    while(idx1 < len1 && idx2 < len2)
    {
        if(arr1[idx1] <= arr2[idx2])
        {
            arr[index] = arr1[idx1];
            idx1++;
            index++;
        }
        else if(arr2[idx2] <= arr1[idx1])
        {
            arr[index] = arr2[idx2];
            idx2++;
            index++;
        }
    }
    if(idx1 < len1)
    {
        while(idx1 < len1)
        {
            arr[index] = arr1[idx1];
            idx1++;
            index++;
        }
    }
    if(idx2 < len2)
    {
        while(idx2 < len2)
        {
            arr[index] = arr2[idx2];
            idx2++;
            index++;
        }
    }
    cout<<"\nmerge_ele func complete...\n";
    display(arr,8);
}

void merge_sort(int arr[],int start,int e)
{
    int len = e - start + 1;
    int mid = start + (len/2);

    if(len <= 1)
    {
        return ;
    }

    merge_sort(arr,start,mid-1);
    cout<<"\nsuccessful dividing left part...\n";
    merge_sort(arr,mid,e);
    cout<<"\nsuccessful dividing right part...\n";
    merge_ele(arr,start,mid,e);
    cout<<"\nsuccessful merging left and right part...\n";
}

int main()
{
    int n = 8;
    int arr[n] = {2,3,12,2,4,1,17,28};

    merge_sort(arr,0,n-1);

    display(arr,n-1);
    return 0;
}
