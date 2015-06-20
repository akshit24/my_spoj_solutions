/*--------------------- Author - Akshit ----------------------*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<cstdlib>
#include<numeric>
#include<set>
#include<map>
#include<deque>
#include<climits>
#include<cassert>
#include<cctype>
#include<ctime>
#include<iterator>
#include<iomanip>
#include<functional>
#include<fstream>
#include<ostream>
#include<istream>
#include<sstream>
using namespace std;

#define sf(n)                scanf("%d",&n) 
#define pf(n)                printf("%d",n)          
#define pfln(n)              printf("%d\n",n)         

#define vi                   vector <int > 
#define pb                   push_back()
#define debug(n)             printf("n = %d\n",n)
#define PI 3.14159265358979
#define LL 1000000007

struct node{
	int closerem;
	int openrem;
} tree[65536];
char st[30001];
void init (char *st,int idx, int lo, int hi){
	if(lo == hi){
//		cout<<"leaf\n";
		if(st[lo] == '(')
		{
			tree[idx].openrem = 1;tree[idx].closerem = 0;
		}
		if(st[lo] == ')')
		{
			tree[idx].closerem = 1;tree[idx].openrem = 0;
		}
		return;
	}
	else{
	//	cout<<"hello\n";
		int mid = (lo+hi)/2;
		int leftidx = 2*idx+1;
		int rightidx = 2*idx+2;
		init(st,leftidx,lo,mid);
		init(st,rightidx,mid+1,hi);
		int matched = min (tree[leftidx].openrem,tree[rightidx].closerem);
		tree[idx].openrem = tree[leftidx].openrem+tree[rightidx].openrem-matched;
		tree[idx].closerem = tree[leftidx].closerem+tree[rightidx].closerem-matched;
	}
}
void update(char *st, int idx,int uidx,int lo,int hi){
	if(lo==hi){
		if(st[lo] == '('){
			tree[idx].openrem = 1;tree[idx].closerem = 0;
		}
		if(st[lo] == ')'){
			tree[idx].openrem = 0;tree[idx].closerem = 1;
		}
		return;
	}
	int mid = (lo+hi)/2;
	int leftidx = 2*idx+1;int rightidx = 2*idx+2;
	if(uidx <=mid){
		update(st,leftidx,uidx,lo,mid);
	}
	else {
		update(st,rightidx,uidx,mid+1,hi);
	}
	int matched = min (tree[leftidx].openrem,tree[rightidx].closerem);
	tree[idx].openrem = tree[leftidx].openrem+tree[rightidx].openrem-matched;
	tree[idx].closerem = tree[leftidx].closerem+tree[rightidx].closerem-matched;
	
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n,m,k;
	int t = 1;
	while(t<=10){
		scanf("%d",&n);
		scanf("%s",st);
		scanf("%d",&m);
		//node tree[2*n];
		init(st,0,0,n-1);
		printf("Test %d:\n", t);
		for(int i = 0 ; i < m ; i++){
			scanf("%d",&k);
			if(k!=0)
			{
				st[k-1] = (st[k-1] == ')')?'(':')';
				update(st,0,k-1,0,n-1);
			}
			else{
				if(tree[0].openrem == 0 && tree[0].closerem == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}

		}
		t++;
	}
	return 0;
}









































