#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int findAnswer(int arr[],int n,int k)
{
    int cnt = 0;
   for (int i = 0; i < n; ++i) {
      if (arr[i] <= k) {
         ++cnt;
      }
   }
   cout<<"cnt = "<<cnt<<endl;
   int outOfRange = 0;
   for (int i = 0; i < cnt; ++i) {
      if (arr[i] > k) {
         ++outOfRange;
      }
   }
   int result = outOfRange;
   cout<<"result = "<<result<<endl;
   for (int i = 0, j = cnt; j < n; ++i, ++j) {
      if (arr[i] > k) {
         --outOfRange;
      }
      if (arr[j] > k) {
         ++outOfRange;
      }
      cout<<"outOfRange = "<<outOfRange<<endl;
      result = min(result, outOfRange);
      cout<<"result = "<<result<<endl;
   }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //int n = 20,k = 14;
    int n,k;
    cin>>n;
    int arr[n] = {0} ;//= {4,11,6,5,11,20,19,14,14,2,9,20,11,11,15,1,7,12,19,9} ;///= {0};
    for(int i= 0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    cout<<findAnswer(arr,n,k)<<endl;
    return 0;
}
