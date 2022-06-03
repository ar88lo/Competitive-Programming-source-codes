#include <iostream>

using namespace std;

const int max_n=400;
int ans[max_n][max_n];
int t;

void solve(int n,int k){

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            ans[i][j]=0;
        }
    }

    int x=k/n;
    int m=k%n;

    for(int i=0;i<n;i++){

        int temp=x;
        int j=i;
        while(temp){

            ans[i][j]=1;
            j++;
            j%=n;
            temp--;
        }
        ans[i][n]=x;
        ans[n][i]=x;
    }

    for(int i=0;i<n;i++){

        if(m==0) break;

        for(int j=0;j<n;j++){

            if(ans[i][j]==0&&ans[n][j]==x){

                ans[i][j]=1;
                ans[n][j]++;
                ans[i][n]++;
                m--;
                break;
            }
        }
    }
    int a,b;
    a=0;
    b=max_n;
    for(int i=0;i<n;i++){

        a=max(ans[i][n],a);
        b=min(ans[i][n],b);
    }
    int c,d;
    c=0;
    d=max_n;
    for(int i=0;i<n;i++){

        c=max(ans[n][i],c);
        d=min(ans[n][i],d);
    }

    cout<<(a-b)*(a-b)+(c-d)*(c-d)<<'\n';
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}
int main(){

    cin>>t;
    while(t){

        int n,k;
        cin>>n>>k;
        solve(n,k);
        t--;
    }
    return 0;
}