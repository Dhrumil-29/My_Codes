#include <iostream>
#include <bits/stdc++.h>

//1<=a<b<=n
// ((m mod a)mod b) = ((m mod b)mod a)
/*
1≤T≤100
2≤N≤10^5
1≤M≤10^5
*/


using namespace std;
#define ll long long

int main() {
	int t = 1;
	cin>>t;
	while(t--)
	{
	    ll n = 7,m = 5;
	    cin>>n>>m;
	    ll count = 0;
	    if(n==2)
        {
            cout<<n-1<<endl;;
        }
	    else if(n > m)
        {
            count = n-1;
            count += (n-m)*(n-m+1)/2;
            count += (m-2)*(n-m);
            for(ll i = 2;i<m;i++)
            {
                for(ll j = i+1;j<=m;j++)
                {
                    if((m%i)%j == (m%j)%i)
	                {
	                    count++;
	                    cout<<"("<<i<<","<<j<<")";
	                }
                }
                cout<<endl;
            }
            cout<<count<<endl;
        }
        else{

	        count = n-1;
	        for(ll i = 2;i<n;i++)
	        {
	            for(ll j = i+1;j<=n;j++)
	            {
	                if((m%i)%j == (m%j)%i)
	                {
	                    count++;
	                    cout<<"("<<i<<","<<j<<")";
	                }
	            }
	            cout<<endl;
	        }
            cout<<count<<endl;
        }
	}
	return 0;
}
