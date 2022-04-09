#include <iostream>
#include <vector>

using namespace std;

const int max_n=5e3+1;
int n;
vector<int> ans;
vector<int> g[max_n];
bool ch[max_n],tmp[max_n];

int dfs(int u,int p){

    int s=1;
    vector<int> si;
    for(int v:g[u]){

        if(v==p) continue;

        si.push_back(dfs(v,u));
        s+=si[si.size()-1];
    }
    si.push_back(n-s);
    
    for(int i=0;i<n;i++) tmp[i]=0;
   
    tmp[0]=1;
    for(int x:si){

        for(int i=n-1;i>=0;i--){

            if(tmp[i]) tmp[i+x]=1;
        }
    }
    for(int i=0;i<n;i++){

        if(tmp[i]) ch[i]=1;
    }
    return s;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++){

        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);

    for(int i=1;i<n-1;i++){

        if(ch[i]){

            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(int i:ans) cout<<i<<" "<<n-1-i<<'\n';
    return 0;
}
/*wrong asymptotic analysis of dfs led to hours of thinking on this problem.