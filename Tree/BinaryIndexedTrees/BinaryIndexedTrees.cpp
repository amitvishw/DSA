#include<bits/stdc++.h>
using namespace std;
void update(int BIT[], int x, int n, int val)
{
    for(; x <= n; x += x&-x)
        BIT[x] += val;
}
int query(int BIT[], int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int BIT[sizeof(a)+5];
    memset(BIT, 0, sizeof(BIT));
    for(int i = 0; i < sizeof(a); i++)
    {
        update(BIT , i+1, sizeof(a), a[i]);
    }
    printf("[1:10] %d\n", query(BIT, 10));
    printf("[2:7] %d\n", query(BIT, 7) - query(BIT, 2-1));
    return 0;
}