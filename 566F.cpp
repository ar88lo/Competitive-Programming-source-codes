#include <iostream>

using namespace std;

const int max_n=1e6+10;
int dp[max_n];
int n,a,ans;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){

        cin>>a;
        dp[a]++;
        for(int j=2*a;j<=max_n;j+=a){

            dp[j]=max(dp[a],dp[j]);
        }
        ans=max(ans,dp[a]);
    }
    cout<<ans<<'\n';
    return 0;
}