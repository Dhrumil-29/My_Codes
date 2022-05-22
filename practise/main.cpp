#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sb(int arr[], int n, int x)
{
    /*int i = n-1,count = 0,start = n-1,sum = 0,ans= INT_MAX,flag = 0;
    //sort(arr,arr+n);
    if(*max_element(arr,arr+n) > x)
    {
        return 1;
    }
    while(i >= 0)
    {
        if(i == n)
        {
            i--;
        }
        cout<<"i = "<<i;
        cout<<"\tstart = "<<start<<endl;
        if(sum <= x && i < n)
        {
            sum += arr[i--];
            count++;
            //cout<<"sum = "<<sum<<endl;
            //cout<<"count = "<<count<<endl;
        }
        else
        {
            //cout<<"@@"<<endl;
            if(sum - arr[start] > x)
            {
                cout<<"@@"<<endl;
                sum -= arr[start--];
                //cout<<"sum = "<<sum<<endl;
                //start++;
                //cout<<"start = "<<start<<endl;
                count--;
                cout<<"@@count = "<<count<<endl;
                cout<<"@@start = "<<start<<endl;
                //ans = min(count,ans);
                flag = 1;
            }
            else{
                if(flag == 1)
                {
                    start = i;
                    sum = 0;
                    //ans = min(count,ans);
                    count = 0;
                    //flag = 0;
                }
                else
                {
                    sum -= arr[start--];
                    ans = min(count,ans);
                    count--;
                }
            }
        }
        cout<<"sum = "<<sum<<endl;
    }
    return ans;*/
    int curr_sum = 0, min_len = n+1;

    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n)
    {
        cout<<"end = "<<end<<endl;
        // Keep adding array elements while current sum
        // is smaller than x
        while (curr_sum <= x && end < n){
            curr_sum += arr[end++];
            cout<<"sum = "<<curr_sum<<endl;}

        // If current sum becomes greater than x.
        while (curr_sum > x && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;

            curr_sum -= arr[start++];
            cout<<"sum = "<<curr_sum<<endl;
            cout<<"start = "<<start<<endl;
        }
    }
    if(min_len > n)
        return 0;
    return min_len;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //int n = 20,k = 14;
    int n = 6,k = 51;
    //cin>>n;
    int arr[n] = {1,6,4,45,0,19};//{6,3,4,5,4,3,7,9} ;//= {4,11,6,5,11,20,19,14,14,2,9,20,11,11,15,1,7,12,19,9} ;///= {0};
    /*for(int i= 0;i<n;i++)
    {
        cin>>arr[i];
    }*/
    //cin>>k;
    cout<<"answer = "<< sb(arr,n,k)<<endl;
    return 0;
}
