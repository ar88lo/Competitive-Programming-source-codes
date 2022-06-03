#include <iostream>

using namespace std;

const int max_n=4*1e5;
const int INF=2*1e9+10;
int dp[max_n];
int pd[max_n];
int a[max_n];
int x[max_n];
int n,k,q;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>q;
	while(q){

		cin>>n>>k;

		for(int i=0;i<k;i++){

			cin>>x[i];
		}
		for(int i=0;i<k;i++){

			int t;
			cin>>t;
			a[x[i]-1]=t;
		}

		(a[0]==0)?dp[0]=INF:dp[0]=a[0];
		for(int i=1;i<n;i++){

			dp[i]=min(dp[i-1]+1,max(a[i],bool(a[i]==0)*INF));
		}

		(a[n-1]==0)?pd[n-1]=INF:pd[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--){

			pd[i]=min(pd[i+1]+1,max(a[i],bool(a[i]==0)*INF));
		}


		for(int i=0;i<n;i++){

			cout<<min(dp[i],pd[i])<<" ";
			a[i]=0;
		}
		cout<<'\n';
		q--;
	}
	return 0;
}