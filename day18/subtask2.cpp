#include <bits/stdc++.h>

using namespace std;

int a[23][23][23];
bool vis[23][23][23];
int tot;

int check(int x, int y, int z){
    int ret = 0;
    if(a[x+1][y][z]==0)ret++;
    if(a[x][y+1][z]==0)ret++;
    if(a[x][y][z+1]==0)ret++;
    if(a[x-1][y][z]==0)ret++;
    if(a[x][y-1][z]==0)ret++;
    if(a[x][y][z-1]==0)ret++;
    return ret;
}

int dfs(int x, int y, int z){
    if(x<0 || y<0 || z<0 || x>22 || y>22 || z>22)return 0;
    if(a[x][y][z])return 1;
    if(vis[x][y][z])return 0;
    vis[x][y][z]=1;
    int ret = 0;
    ret += dfs(x+1,y,z);
    ret += dfs(x,y+1,z);
    ret += dfs(x,y,z+1);
    ret += dfs(x-1,y,z);
    ret += dfs(x,y-1,z);
    ret += dfs(x,y,z-1);
    return ret;
}

int main(){
    string s; 
    int mx = 0;
    for(;cin >> s;){
        int p1 = s.find(',');
        int x = stoi(s.substr(0,p1));
        s = s.substr(p1+1);
        p1 = s.find(',');
        int y = stoi(s.substr(0,p1));
        int z = stoi(s.substr(p1+1));
        x++, y++, z++;
        a[x][y][z]=1;
    }
    //dfs(0,0,0);
    cout << dfs(0,0,0);
    return 0;
}
