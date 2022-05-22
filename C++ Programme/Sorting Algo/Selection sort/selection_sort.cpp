/*
selection sort:-   select the max/min element in array and then replace it,stable(same order for same elements)

time complexity:- O(n^2)

suppose : - 7 6 2 4 3 5 1
so by 1st iteration 1 6 2 4 3 5 7
      2   iteration 1 5 2 4 3 6 7
      3   iteration 1 3 2 4 5 6 7
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
    int arr[n] = {7,6,2,4,3,5,1};
    int mx;
    for(int i = 0;i<n;i++)
    {
        int index = 0;
        flag = 0;
        mx = arr[0];
        cout<<"i = "<<i+1<<endl;
        for(int j = 1;j < n-i;j++)
        {
            if(arr[j] > mx)
            {
                flag = 1;
                mx = max(mx,arr[j]);
                index = j;
            }
        }
        swap(arr[index],arr[n-i-1]);
        for(int k = 0;k < n;k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        if(index == -1)
        {
            break;
        }
    }

    cout<<"\n\n\nSo sorted array .....\n";
    for(int k = 0;k < n;k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    return 0;
}
