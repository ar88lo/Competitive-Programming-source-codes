#include <iostream>
#include <string>
#include <map>

using namespace std;

const double INF=1e9+10;
const int max_n=5e5+10;

map<long double,int> m;
long double d,k;
int dp[max_n];
int n,t;
string s;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t;
	while(t){

		cin>>n>>s;

		for(int i=0;i<n;i++){

			(s[i]=='D')?d+=1L:k+=1L;

			long double r;
			if(d==0){
				r=INF;
			}
			else{
				r=k/d;
			}
			dp[i]=m[r]+1L;
			m[r]=dp[i];
		}
		for(int i=0;i<n;i++){

			cout<<dp[i]<<" ";
		}
		cout<<'\n';
		m.clear();
		d=k=0;
		t--;
	}
}