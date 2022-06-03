#include <iostream>
#include <string>

using namespace std;

const int max_n=2e5+10;

int dp[max_n],pd[max_n];
string s;
int t,n;
int ans;

int solve(char a,char b){

	pd[0]=0;
	dp[0]=0;
	if(s[0]==a){
		dp[0]=1;
	}
	
	for(int i=1;i<n;i++){

		dp[i]=max(dp[i-1],bool(s[i]==a)*(pd[i-1]+1));
		pd[i]=max(pd[i-1],bool(s[i]==b&&dp[i-1]>0)*(dp[i-1]+1));
	}
	return max(pd[n-1],bool(a==b)*dp[n-1]);
}
int main(){

	cin>>t;
	while(t){

		cin>>s;
		n=s.size();

		for(int i=0;i<=9;i++){

			for(int j=0;j<=9;j++){

				ans=max(ans,solve((i+'0'),(j+'0')));
			}
		}
		cout<<n-ans<<'\n';
		ans=0;
		t--;
	}
	return 0;
}