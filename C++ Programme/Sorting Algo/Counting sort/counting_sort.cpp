/*
    counting sort:- elements are between n,so set by freq array and do counting sort.
                    TC:- O(n)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n = 7;
    int arr[n] = {6,4,2,5,6,4,1};
    int freq[10] = {0};
    int ans[n] = {0};
    for(int i = 0;i < n;i++)
    {
        freq[arr[i]]++;
    }
    int index = 0;
    for(int i = 0;i < 10;i++)
    {
        while(freq[i] != 0)
        {
            ans[index++] = i;
            freq[i]--;
        }
    }
    for(int i = 0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
