#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long double epsilon=1e-6;
const int max_n=1e5+10;
int a[max_n];
long double dp[max_n],pd[max_n];
int t,n,l;

int main(){

    cin>>t;
    while(t){

        cin>>n>>l;

        a[0]=0;
        for(int i=1;i<=n;i++){

            cin>>a[i];
        }
        a[n+1]=l;

        dp[0]=0.0;
        for(int i=1;i<=n+1;i++){

            dp[i]=dp[i-1]+(long double)(a[i]-a[i-1])/i;
        }

        pd[n+1]=0.0;
        for(int i=n;i>=0;i--){

            pd[i]=pd[i+1]+(long double)(a[i+1]-a[i])/(n-i+1);
        }

        for(int i=0;i<=n;i++){

            long double x=a[i];
            long double y=a[i+1];

            if(dp[i]<=pd[i+1]+epsilon){

                x+=(pd[i+1]-dp[i])*(long double)(i+1);
            }
            else{

                y-=(dp[i]-pd[i+1])*(long double)(n-i+1);
            }

            if(x<=y+epsilon){

                cout<<fixed<<setprecision(15)<<max(dp[i],pd[i+1])+(y-x)/(n+2)<<'\n';
                break;
            }
        }

        t--;
    }
}