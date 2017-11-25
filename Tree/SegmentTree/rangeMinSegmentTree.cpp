#include<bits/stdc++.h>
using namespace std;
int findNextPowOfTwo(int x)
{
    while(x&(x-1))
        x++;
    return x;
}
void buildTree(int input[], int tree[], int low, int high, int pos)
{
    if(low==high)
    {
        tree[pos] = input[low];
        return;
    }
    int mid = (low+high)/2;
    buildTree(input, tree, low, mid, 2*pos+1);
    buildTree(input, tree, mid+1, high, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}
void update(int tree[], int x, int qLow, int qHigh, int low, int high, int pos)
{
	if(low>high||qHigh<low||qLow>high)
	{
		return;
	}
	if(low==high)
	{
		tree[pos] = x;
		return;
	}
	int mid =(low+high)/2;
	update(tree, x, qLow, qHigh, low, mid, 2*pos+1);
	update(tree, x, qLow, qHigh, mid+1, high, 2*pos+2);
	tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int query(int tree[],int qLow,int qHigh,int low,int high,int pos)
{
    if(qLow<=low&&qHigh>=high)
    {
        return tree[pos];
    }
    if(qLow>high||qHigh<low)
    {
        return INT_MAX;
    }
    int mid =(low+high)/2;
    int x = query(tree, qLow, qHigh, low, mid, 2*pos+1);
    int y = query(tree, qLow, qHigh, mid+1, high, 2*pos+2);
    return min(x,y);
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
    int s=2*findNextPowOfTwo(sizeof(a))-1;
    int tree[s];
    buildTree(a,tree,0,sizeof(a)-1,0);
    
    printf("%d\n", query(tree,1-1,10-1,0,sizeof(a)-1,0));
    
	update(tree,20,1-1,1-1,0,sizeof(a)-1,0);
	
	printf("%d\n", query(tree,1-1,10-1,0,sizeof(a)-1,0));
	
	update(tree,20,2-1,2-1,0,sizeof(a)-1,0);
	
	printf("%d\n", query(tree,1-1,10-1,0,sizeof(a)-1,0));
	
	update(tree,20,3-1,3-1,0,sizeof(a)-1,0);

	printf("%d\n", query(tree,1-1,10-1,0,sizeof(a)-1,0));
	return 0;
}
