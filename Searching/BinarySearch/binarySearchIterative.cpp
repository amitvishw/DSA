#include <bits/stdc++.h>

using namespace std;

// An iterative binary search function. It returns location of x in
// given vector arr[l..r] if present, otherwise -1
int binarySearch(vector<int> arr, int l, int r, int x)
{
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(x == arr[mid])
        {
            return mid;
        }
        else
        {
            if(x < arr[mid])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
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