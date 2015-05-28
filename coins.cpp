#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<long long int , long long int> dp;
long long  maxcoins(long long  n){
	if (dp.count(n)){
		return dp[n];
	}
	else{
		dp[n] = max(n,maxcoins(n/2)+maxcoins(n/3)+maxcoins(n/4));
		return dp[n];
	}

}
int main()
{
	dp[0] = 0;
	dp[1] = 0;
	long long n;
	while(scanf("%lld",&n) != EOF){
		long long ans = maxcoins(n);
		cout<<ans<<endl;
	}
	return 0;

}
