#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int g,b;
	cin>>g>>b;
	while(g!=-1 && b!= -1){
		int ans = ceil((double)max(g,b)/(double)(min(g,b) + 1.0));
		cout<<ans<<endl;
		cin>>g>>b;
	}
	return 0;
}
