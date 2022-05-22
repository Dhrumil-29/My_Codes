/*
    Bucket sort:- know that element is between n and also uniformly distributed
                TC:- O(n)
                Total element = n
                range of one bucket = max(max = max+1) - min / total element
(why max = max + 1 ? => when we store elements in bucket ((arr[i] - min) / (max - min)) * total element so when arr[i] = max then
                 that element go to total element index bucket so its not done in our code,bucket arr element are total element)

                [min , min+range),[min+range,min+range*2),...
                if (0 to n) than we can use
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
int main()
{
    int n = 10;
    float arr[n] = {0.5,2.3, 4.9, 3.6, 4.8, 5.7, 9.8, 7.2, 7.9,10};
    vector <float>bucket[n];
    float ans[n] = {0};
    int index = 0;

    float mx = *max_element(arr,arr+n);
    float mn = *min_element(arr,arr+n);
    mx = mx+1;
    int range = (mx-mn)/n;
    cout<<"range  = "<<range<<"    max = "<<mx<<endl;
    for(int i = 0;i < n;i++)
    {
        int idx = (arr[i]-mn)/range;
        //cout<<"i = "<<i<<"   idx = "<<idx<<endl;
        bucket[idx].push_back(arr[i]);
    }
    for(int i = 0;i < n;i++)
    {
        sort(bucket[i].begin(),bucket[i].end());
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < bucket[i].size();j++)
        {
            ans[index++] = bucket[i][j];
        }
    }
    cout<<"\n\n\nSo sorted array...\n";
    for(int i = 0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
