#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
	int temp[200001];
	
	int arr[200001];
static long long ans;
void merge(int *arr, int lo, int mid, int hi){
		//cout <<"lo = "<<lo<<"  mid = "<<mid<<"  hi = "<<hi<<endl;
	//cout<<"Merging\n";
	int i = lo;
	int j = mid+1 ;
	int k = lo;
	while(i<=mid && j<=hi){
		if(arr[i] > arr[j])
		{
			temp[k++] = arr[j];
			j++;
			ans+=(mid-i+1);
		}
		else{
			temp[k++] = arr[i];
			i++;
		}
	}
	//cout <<"temp = "<<temp[0]<<endl;
	//cout<<"hello\n";
	while(i<=mid)
	{	temp[k++] =arr[i];
	i++;}
	while(j<=hi)
	{	temp[k++] = arr[j];
		j++;}
	for(int p = lo ; p<k ; p++)
		arr[p] = temp[p];
}

void merge_sort(int *arr, int lo, int hi){
	//	cout <<"lo = "<<lo<<"  hi = "<<hi<<endl;
	if(hi <= lo)
		return;
	else{
		//cout<<"hello\n";
		int mid = (hi+lo)/2;
		merge_sort(arr,lo,mid);
		merge_sort(arr,mid+1,hi);
		merge(arr,lo,mid,hi);
	}
}

int main(){
	int n,t;
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];
		merge_sort(arr,0,n-1);
	cout<<ans<<endl;
	}
	return 0;
}
