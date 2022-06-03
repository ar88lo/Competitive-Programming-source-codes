#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int max_n=2e5+10;
int t,n;
int a[max_n];
vector<int> v;

bool check(int i,vector<int> u){

    int sum=0;
    for(auto x:u){

        x-=i;
        if(x>0) sum+=x;
    }
    if(sum>i) return 1;
    return 0;
}
int main(){

    cin>>t;
    while(t){

        cin>>n;
        n--;
        for(int i=0;i<n;i++){

            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){

            int x=a[i];
            int temp=0;
            while(a[i]==x){

                temp++;
                i++;
            }
            i--;
            v.push_back(temp);
        }
        v.push_back(1);
        int m=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<m;i++){

            v[i]-=i+1;
        }
        int sum=0;
        for(int i=0;i<m;i++){

            if(v[i]>0) sum+=v[i];
        }
        int l=-1;
        for(int k=sum;k>0;k/=2){

            while(l+k<=sum&&check(l+k,v)) l+=k;
        }
        l++;
        cout<<m+l<<'\n';
        
        for(int i=0;i<=n;i++){

            a[i]=0;
        }
        int j=0;
        v.clear();
        t--;
    }
    return 0;
}
//moral of the story : binary search is very powerfull and can be used very often 
// when implementing binary search in the modern way always remember to set l=-1 at the start