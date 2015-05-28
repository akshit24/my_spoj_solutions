#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){

	int x,y,t;
	cin>>t;
	while(t--){
		cin>>x>>y;
		if (x == y && x%2 == 0)
			cout<<x+y<<endl;
		else if (x == y && x%2 != 0)
			cout<<x+y-1<<endl;
		else if ((x == y+2) && x%2 == 0)
			cout<<x+y<<endl;
		else if ((x == y+2) && x%2 != 0)
			cout<<x+y-1<<endl;
		else
			cout<<"No Number\n";
	}
	return 0;
}
