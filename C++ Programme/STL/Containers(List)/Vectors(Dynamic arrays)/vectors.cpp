#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        arr[i] = i*2;
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr.at(i)<<endl;//or arr[i]
    }
    cout<<"total elements is:- "<<arr.size()<<endl;
}

///vector is like a dynamic arrays
int main()
{
    vector<int> arr;///int type arr
    arr.push_back(5);///insert elements at back;///in (...)bracket
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(0);
    display(arr);
    ///cout<<"how many elements in vector(vectorname.size):- "<<arr.size()<<endl;
    ///arr.pop_back();///delete last element.
    ///arr.assign(5,10);///(how many element, value of that many elements)
    ///arr.back();///last element show
    ///display(arr);
    ///arr.front();//first elements show;
    ///arr.capacity();size of arr
    ///arr.clear();///clear the array

        display(arr);
    return 0;
}
