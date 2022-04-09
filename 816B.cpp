#include <iostream>

using namespace std;

const int max_n=2e6;
long long k;
int n,q;
int l,r;
long long m[max_n];
long long cnt[max_n];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k>>q;
    for(int i=0;i<n;i++){

        cin>>l>>r;
        l--; r--;
        m[l]++;
        m[r+1]--;
    }
    
    cnt[0]=m[0];
    for(int i=1;i<max_n;i++){

        cnt[i]=cnt[i-1]+m[i];
    }
    cnt[0]=(cnt[0]<k)?0:1;
    for(int i=1;i<max_n;i++){

        cnt[i]=(cnt[i]<k)?0:1;
        cnt[i]=cnt[i-1]+cnt[i];
    }
    while(q){

        cin>>l>>r;
        l--; r--;
        cout<<cnt[r]-cnt[l-1]<<'\n';
        q--;
    }
    return 0;
}