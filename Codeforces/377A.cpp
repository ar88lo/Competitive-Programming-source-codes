#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
const int max_n=1000;
string t[max_n];
int cnt,e;
int n,m,k;
 
void tabledfs(int i,int j){
 
    if(cnt==e-k) return;
    if(i>=n||i<0||j>=m||j<0||t[i][j]!='.') return;
 
    t[i][j]='X';
    cnt++;
 
    tabledfs(i+1,j);
    tabledfs(i,j+1);
    tabledfs(i-1,j);
    tabledfs(i,j-1);
}
int main(){
 
    cin>>n>>m>>k;
    pair<int,int> st;
    for(int i=0;i<n;i++){
 
        cin>>t[i];
        for(int j=0;j<m;j++){
 
            if(t[i][j]=='.'){
                st={i,j};
                e++;
            }
        }
    }
    tabledfs(st.first,st.second);
    for(int i=0;i<n;i++){
 
        for(int j=0;j<m;j++){
 
            if(t[i][j]=='X'){
                t[i][j]='.';
            }
            else if(t[i][j]=='.'){ t[i][j]='X';}
        }
        cout<<t[i]<<'\n';
    }
    return 0;
}