#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int sz = s.size();
	int col = 1;
	for (int i = 1 ; i*i <= sz ; i++){
		if (sz % i == 0)
		{
			if (i > col)
				col = i;
		}
	}
	int row = sz/col;
	int j = 0;
	while (j<col){
		int i =0;
		while(i<sz){
			cout<<s[j];
			cout<<s[i+2*col-1]<<s[i+2*col];
			i=i+2*col;
			j+=1;
		}}
	return 0;
}

