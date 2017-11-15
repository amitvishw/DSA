#include <bits/stdc++.h>

using namespace std;

// An recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(vector<int> arr, int l, int r, int x)
{
    int mid = (l+r)/2;
    if(r >= l)
    {
        if(x == arr[mid])
        {
            return mid;
        }
        if(x < arr[mid])
        {
            return binarySearch(arr, l, mid-1, x);
        }
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(7);
    for(int i=-1;i<10;i++)
    cout<<i<<" "<<binarySearch(arr,0,arr.size()-1,i)<<endl;
    return 0;
}
