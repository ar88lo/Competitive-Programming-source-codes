#include <iostream>
using namespace std;

const int max_n=1e5+10;
int n;
long long a[max_n],t[max_n],cnt[max_n],rem[max_n],temp;

void calc(int x,long long f){
    int l=-1;
    for(int k=n;k>0;k/=2){

        while(l+k<n&&t[l+k]<=f) l+=k;
    }
    cnt[x]++;
    cnt[l+1]--;
    rem[l+1]+=f-t[l];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){

        cin>>a[i];
    }
    for(int i=0;i<n;i++){

        cin>>temp;
        t[i]=t[i-1]+temp;
    }
    for(int i=0;i<n;i++){

        calc(i,a[i]+t[i-1]);
    }
    for(int i=0;i<n;i++){

        cnt[i]=cnt[i-1]+cnt[i];
        cout<<cnt[i]*(t[i]-t[i-1])+rem[i]<<" ";
    }
    return 0;
}