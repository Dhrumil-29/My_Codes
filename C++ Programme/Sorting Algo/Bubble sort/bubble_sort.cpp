/*
bubble sort:-   compare elements by their next elements,stable(same order for same elements)

time complexity:- O(n^2)

suppose : - 7 6 2 4 3 5 1
so by 1st iteration 6 2 4 3 5 1 7
      2   iteration 2 4 3 5 1 6 7
      3   iteration 2 4 3 1 5 6 7
      4   iteration 2 3 1 4 5 6 7
      5   iteration 2 1 3 4 5 6 7
      6   iteration 1 2 3 4 5 6 7

      so we can see that by ith iteration ith maximum element place by their place.

*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 7,flag = 0;//flag is for check that arr is sorted?if yes than break the for loop and return else continue the for loop
    int arr[n] = {1,2,3,4,5,6,7};
    for(int i = 0;i < n;i++)
    {
        cout<<"i = "<<i+1<<endl;
        flag = 0;
        for(int j = 0;j < n-i-1;j++)
        {
            if(arr[j] > arr[j+1])//if next element is greater than that than swap the element
            {
                flag = 1;
                swap(arr[j],arr[j+1]);
            }
        }
        for(int k = 0;k < n;k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        if(flag == 0)
        {
            break;
        }
    }

    cout<<"So sorted array .....\n";
    for(int k = 0;k < n;k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    return 0;
}
