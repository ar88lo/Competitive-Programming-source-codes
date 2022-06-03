#include <iostream>

using namespace std;

const int INF=(1<<30);
const int max_n=2e5+10;

int dp[max_n][2];
int a[max_n];
int t,n;

int main(){

	cin>>t;
	while(t){

		cin>>n;
		for(int i=0;i<n;i++){

			cin>>a[i];
		}
		if(n==1){

			cout<<a[0]<<'\n';
		}
		else{

			dp[0][0]=a[0];
			dp[1][0]=a[1]+a[0];
			dp[0][1]=INF;
			dp[1][1]=dp[0][0];
			for(int i=2;i<n;i++){

				dp[i][0]=min(dp[i-1][1]+a[i],dp[i-2][1]+a[i]+a[i-1]);
				dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
			}
			cout<<min(dp[n-1][1],dp[n-1][0])<<'\n';
		}
		t--;
	}
	return 0;
}