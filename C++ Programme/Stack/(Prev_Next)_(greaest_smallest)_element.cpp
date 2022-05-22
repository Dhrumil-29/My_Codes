#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    array :- 2   7   6  12  5   9  10
    ans:-    7  12  12  -1  9  10  -1


take a stack in that we store the index of arr
for continuous decreasing elements ,their next greater elements will be the same like in above arr 7 6 have same ans 12

so if stack is empty or s.top() value > arr[i] push into stack means decreasing elements
push that elements until their greater than elements was not found

after traversing all elements and stack is not empty which means that for that elements greater elements are not found and for that store ans -1.


*/

#define vi vector<int>



void display(int n,int arr[],int ans[])
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<"-> "<<ans[i]<<endl;
    }
    return;
}

void prevGreaterElement(int n,int arr[])
{
    stack<int> s;
    int ans[7] = {0};

    for(int i = n-1;i>-1;i--)
    {
        if(s.empty() or arr[s.top()] > arr[i])
            s.push(i);
        else{
            while(!s.empty() and arr[s.top()] <= arr[i])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    display(n,arr,ans);
}

void prevSmalledtElement(int n,int arr[])
{
    stack<int> s;
    int ans[7] = {0};
    for(int i = n-1;i > -1;i--)
    {
        if(s.empty() or arr[s.top()] < arr[i])
            s.push(i);
        else{
            while(!s.empty() and arr[s.top()] >= arr[i])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    display(n,arr,ans);
    return;
}

void nextSmalledtElement(int n,int arr[])
{
    stack<int> s;
    int ans[7] = {0};
    for(int i = 0;i < 7;i++)
    {
        if(s.empty() or arr[s.top()] < arr[i])
            s.push(i);
        else{
            while(!s.empty() and arr[s.top()] >= arr[i])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    display(n,arr,ans);
    return;
}

void nextGreaterElement(int n,int arr[])//,int &ans)
{
    stack<int> s;
    int ans[7] = {0};
    for(int i = 0;i < 7;i++)
    {
        if(s.empty() or arr[s.top()] > arr[i])
            s.push(i);
        else{
            while(!s.empty() and arr[s.top()] <= arr[i])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    display(n,arr,ans);
    return;
}
int main()
{
    int n = 7;
    int arr[7] = {2,7,6,12,5,9,10};
    //int ans[7] = {0};
    for(int i = 0;i < n;i++)
    {

        cout<<arr[i]<<"  ";
    }
    cout<<endl<<endl;
    nextGreaterElement(n,arr);//,ans);

    cout<<"\n\n";
    prevGreaterElement(n,arr);
    cout<<"\n\n";

    nextSmalledtElement(n,arr);
    cout<<"\n\n";

    prevSmalledtElement(n,arr);
    cout<<"\n\n";
    //display(n,arr,ans);

    return 0;
}
