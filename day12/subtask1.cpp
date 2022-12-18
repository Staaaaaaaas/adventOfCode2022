#include <bits/stdc++.h>

using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    pair<int,int> st = {0,0}, fi = {0,0};
    string s;
    for(int i=0;cin>>s;i++){
        n = i+1;
        m=s.size();
        for(int j=0;j<m;j++){
            grid[i][j]=s[j]-'a';
            if(s[j]=='S'){
                grid[i][j]=0;
            }
            else if(s[j]=='E'){
                grid[i][j]=25;
                fi={i,j};
            }
        }
    }
    //cout << fi.first << fi.second;
    int ans = n*m;
    for(int ii=0;ii<n;ii++)for(int jj=0;jj<m;jj++)if(grid[ii][jj]==0){
        st = {ii,jj};
    
        queue<pair<pair<int,int>,int>> q;
        q.push({st, 0});
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            vis[i][j]=0;
        }
        for(;!q.empty();){
            auto pos = q.front().first;
            //cout << pos.first << ' ' << pos.second << '\n';
            int tm = q.front().second;
            q.pop();
            if(pos==fi){
                ans=min(ans,tm);
                break;
            }
            int i = pos.first, j=pos.second;
            if(vis[i][j])continue;
            vis[i][j]=1;
            if(i>0 && grid[i-1][j]-grid[i][j]<2){
                q.push({{i-1,j}, tm+1});
            }  
            if(j>0 && grid[i][j-1]-grid[i][j]<2){
                q.push({{i,j-1}, tm+1});
            }  
            if(i<n-1 && grid[i+1][j]-grid[i][j]<2){
                q.push({{i+1,j}, tm+1});
            }  
            if(j<m-1 && grid[i][j+1]-grid[i][j]<2){
                q.push({{i,j+1}, tm+1});
            }   
        }
    }
    cout << ans;
    //cout << m <<' '<< n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << vis[i][j];
    //     }
    //     cout << '\n';
    // }
    return 0;
}
