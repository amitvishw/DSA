#include<bits/stdc++.h>
using namespace std;
#define MAX 100019
//2 1
//3 1
//4 0
//5 1
//6 0
int p[MAX];
void sieveOfEratosthenes()
{
    for(int i=0;i<MAX;i++)
    {
        p[i]=1;
    }
    for(int i=2;i<MAX;i++)
    {
        if(p[i])
        {
            for(int j=2;i*j<MAX;j++)
            {
                p[i*j]=0;
            }
        }
    }
}
int main()
{
    sieveOfEratosthenes();
    for(int i=0;i<20;i++)
    {
        cout<<i<<" "<<p[i]<<" "<<endl;
    }
    return 0;
}

