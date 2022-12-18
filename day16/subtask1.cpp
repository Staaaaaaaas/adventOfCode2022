#include <bits/stdc++.h>

using namespace std;

int flow[26*26];
//int dp[26*26][2][31];
vector<int> adj[26*26];
int vis[26*26];
int d[26*26][26*26];
vector<int> good;

void parseIn(){
    bool f = 1;
    int curr;
    string s;
    while(cin >> s){
        int n = s.size();
        if(s=="Valve")f=1;
        else if(s[0]>='A' && s[0]<='Z'){
            int vl = (s[0]-'A')*26+(s[1]-'A');
            if(f){
                curr = vl;
                f=0;
            }
            else{
                adj[curr].push_back(vl);
            }
        }
        else if(s.substr(0,5)=="rate="){
            int vl = stoi(s.substr(5,n-6));
            flow[curr]=vl;
            if(vl)good.push_back(curr);
        }
    }
}

void calcD(int u){
    queue<pair<int,int>> q;
    q.push({u, 0});
    for(int i=0;i<26*26;i++){
        vis[i]=0;
    }
    for(;!q.empty();){
        int v = q.front().first;
        int ds = q.front().second;
        q.pop();
        if(vis[v])continue;
        vis[v]=1;
        d[u][v]=ds;
        for(int vv:adj[v]){
            q.push({vv, ds+1});
        }
    }
}

int dfs(int u, int t){
    int ret = 0;
    for(int v:good){
        if(t>d[u][v]+1 && !vis[v]){
            vis[v]=1;
            ret = max(ret, flow[v]*(t-d[u][v]-1)+dfs(v,t-d[u][v]-1));
            vis[v]=0;
        }
    }
    return ret;
}

int main(){
    parseIn();
    for(int i=0;i<26*26;i++){
        if(adj[i].size())calcD(i);
    }
    for(int i=0;i<26*26;i++)vis[i]=0;
    //cout << good.size();
    cout << dfs(0, 30) << '\n';
    return 0;
}
