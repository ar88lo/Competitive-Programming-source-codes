#include <iostream>
 
using namespace std;
 
const int max_n=110;
short a[max_n];
int dp[max_n][3];
int n;
 
int main(){
 
	cin>>n;
	for(int i=0;i<n;i++){
 
		cin>>a[i];
	}
 
	dp[0][0]=bool((a[0]&1));
	dp[0][1]=bool((a[0]&2));
	dp[0][2]=0;
	for(int i=1;i<n;i++){
 
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])*bool((a[i]&1))+bool((a[i]&1));
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])*bool((a[i]&2))+bool((a[i]&2));
		dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
	}
	cout<<n-max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	return 0;
}