/*
insertion sort:-   after ith iteration i length array are sorted,in place,stable(same order for same elements)
this is best sorted algo in O(n^2) algos because when sorted arrays given than its best TC is O(n).
time complexity:- O(n^2)

suppose : - 7| 6 2 4 3 5 1
so by 1st iteration 6 7| 2 4 3 5 1
      2   iteration 2 6 7| 4 3 5 1
      3   iteration 2 4 6 7| 3 5 1
      4   iteration 2 3 4 6 7| 5 1
      5   iteration 2 3 4 5 6 7| 1
      6   iteration 1 2 3 4 5 6 7|

      so we can see that by ith iteration ith maximum element place by their place.

*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 7,flag = 0;//flag is for check that arr is sorted?if yes than break the for loop and return else continue the for loop
    int arr[n] = {1,2,3,4,5,6,7};
    for(int i = 1;i<n;i++)
    {
        //int digit = arr[i];
        cout<<"i = "<<i+1<<endl;
        if(arr[i] > arr[i-1])
        {
            continue;
        }
        else
        {
            for(int j = i;j >0;j--)
            {
                if(arr[j] < arr[j-1])
                {
                    swap(arr[j],arr[j-1]);
                }
            }
        }
        for(int k = 0;k < n;k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n\n\nSo sorted array .....\n";
    for(int k = 0;k < n;k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    return 0;
}
