#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> adj[456976];
int val[456976];
char op[456976];

int dfs(int v){
    if(val[v])return val[v];
    if(op[v]=='+'){
        val[v]=dfs(adj[v][0])+dfs(adj[v][1]);
    }
    else if(op[v]=='-'){
        val[v]=dfs(adj[v][0])-dfs(adj[v][1]);
    } 
    else if(op[v]=='*'){
        val[v]=dfs(adj[v][0])*dfs(adj[v][1]);
    }
    else if(op[v]=='/'){
        val[v]=dfs(adj[v][0])/dfs(adj[v][1]);
    }
    return val[v];
}

int strToInt(string s){
    int res = 0;
    for(int i=0, mul=1;i<s.size();i++,mul*=26){
        int d = s[i]-'a';
        res+=d*mul;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int curr = -1;
    for(;cin >> s;){
        //cout << curr << '\n';
        if(s.back()==':'){
            curr = strToInt(s.substr(0,s.size()-1));
        }
        else if(s[0]<='9' && s[0]>='0'){
            // if(curr==strToInt("dbpl")){
            //     cout << s;
            // }
            val[curr]=stoi(s);
        }
        else if(s[0]<='z'&&s[0]>='a'){
            adj[curr].push_back(strToInt(s));
        }
        else{
            op[curr]=s[0];
        }
    }
    cout << dfs(strToInt("root")) << '\n';
   // cout << strToInt("dvpt") << ' ' << strToInt("dbpl");
    return 0;
}
