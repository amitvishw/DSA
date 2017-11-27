#include<bits/stdc++.h>
using namespace std;
#define MAX 100019
//least prime factor
//2 2 
//3 3
//4 2
//5 5
//6 2
int f[MAX];
int p[MAX];
void lPF()
{
    for(int i=0;i<MAX;i++)
    {
        p[i]=1;
        f[i]=-1;
    }
    f[0]=1;
    f[1]=1;
    for(int i=2;i<MAX;i++)
    {
        if(p[i])
        {
            f[i]=i;
            for(int j=2;i*j<MAX;j++)
            {
                p[i*j]=0;
                if(f[i*j]==-1)
                    f[i*j]=i;
            }
        }
    }
}
int main()
{
    lPF();
    for(int i=0;i<20;i++)
    {
        cout<<i<<" "<<f[i]<<" "<<endl;
    }
    return 0;
}