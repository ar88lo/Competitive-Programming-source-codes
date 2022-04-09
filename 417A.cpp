#include <iostream>

using namespace std;
#define INF 1000000000;

const int max_n=10000;
int dp[max_n];
int c,d,n,m,k;
int ans=INF;

int main(){

    cin>>c>>d;
    cin>>n>>m;
    cin>>k;
    for(int i=1;i<=n*m;i++){

        if(i<n){
            dp[i]=dp[i-1]+d;
        }
        else{
            dp[i]=min(dp[i-1]+d,dp[i-n]+c);
        }
    }
    for(int i=max(0,n*m-k);i<=n*m;i++){

        ans=min(ans,dp[i]);
    }
    cout<<ans<<'\n';
}