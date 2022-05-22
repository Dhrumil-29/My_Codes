#include<bits/stdc++.h>
using namespace std;

int binary_start(int arr[],int start,int end,int x)
{
    int mid = (start + end) / 2;
    cout<<"start = "<<start<<"\tmid = "<<mid<<"\tend = "<<end<<endl;
    if(start == end)
    {
        if(arr[start] == x)
            return start;
        else
            return -1;
    }
    if(end == start + 1)
    {
        if(x > arr[start] && arr[start] < arr[end] && arr[end] == x)
        {
            return end;
        }
        else if(arr[end] != x && arr[start] != x)
        {
            return -1;
        }
        else
        {
            return start;
        }
    }
    if(arr[start] <= x && arr[end] >=x && arr[mid] >= x)
    {
        binary_start(arr,start,mid,x);
    }
    else
    {
        binary_start(arr,mid,end,x);
    }
}
int binary_end(int arr[],int start,int end,int x)
{
    int mid = (start + end) / 2;
    cout<<"start = "<<start<<"\tmid = "<<mid<<"\tend = "<<end<<endl;
    if(start == end)
    {
        if(arr[start] == x)
            return start;
        else
            return -1;
    }
    if(end == start + 1)
    {
        if(x > arr[start] && arr[start] < arr[end] && arr[end] == x)
        {
            return end;
        }
        else if(arr[end] != x && arr[start] != x)
        {
            return -1;
        }
        else
            return start;
    }
    if(arr[start] <= x && arr[end] >=x && arr[mid] <= x)
    {
        binary_end(arr,mid,end,x);
    }
    else
    {
        binary_end(arr,start,mid,x);
    }
}
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int start_index,end_index;
	    cout<<"first 2 element find----------"<<endl;
	    start_index = binary_start(arr,0,n-1,x);
	    cout<<"second 2 element find----------"<<endl;
	    end_index = binary_end(arr,0,n-1,x);
	    cout<<"start = "<<start_index<<"\tend = "<<end_index<<endl;
	    if(start_index == -1 && end_index == -1)
	    return 0;
	    else
	    return (end_index - start_index + 1);
	}
int main()
{
    int arr[21]={7, 7, 7, 7, 9, 11, 12, 14, 15, 16, 17, 18, 18, 18, 18, 18, 19, 19, 20, 21, 23};
    cout<<count(arr,21,7)<<endl;
    return 0;
}
