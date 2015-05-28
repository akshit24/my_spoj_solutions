#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
long long dp[5001];

long long ways(vector <int> &v){
	int sz = v.size();
	int tmp = 0;
	 tmp = (v[0]*10) + v[1];
//		cout<<"tmp = "<<tmp<<endl;
	dp[0] = 1;
	if(tmp <= 26 && tmp > 9 && tmp !=20 && tmp !=10)
		dp[1] = 2;
	else
		dp[1] = 1;
	for(int i = 2 ; i < sz ; i++){
		tmp = (v[i-1]*10)+v[i];
//		cout<<"tmp = "<<tmp<<endl;
		if(v[i] != 0){
			dp[i] = dp[i-1];
		}
		if(tmp<=26 && tmp>9)
			dp[i]+=dp[i-2];
	}
	return dp[sz-1];
}
int main(){
	string s;
	vector <int> v;
	cin>>s;
	int sz = s.size();
	while(1){
		if(s[0] == '0' && sz == 1)
			break;
		v.clear();
		memset(dp,0,sizeof(dp));
		for(int i = 0 ; i < sz ; i++){
			v.push_back(s[i]-'0');
		}
		long long ans = ways(v);
		cout<<ans<<endl;
		cin>>s;
		sz = s.size();
	}
	return 0;
}
