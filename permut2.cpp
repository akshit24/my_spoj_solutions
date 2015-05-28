#include <iostream>
#include <cstdio>

using namespace std;

int a[100001];
int b[100001];
int main()
{	
	int n;
	cin>>n;
	while(n!=0){
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			cin>>a[i];
		}
		for(int i = 1 ; i <= n ; i++){
			b[a[i]] = i;
		}
		for(int i = 1 ; i <= n ; i++){
			if(a[i] == b[i])
				cnt++;
		}
		if(cnt == n)
			cout<<"ambiguous\n";
		else
			cout<<"not ambiguous\n";
		cin>>n;
	}

	return 0;
}
