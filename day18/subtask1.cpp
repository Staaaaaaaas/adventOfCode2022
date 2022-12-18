#include <bits/stdc++.h>

using namespace std;

int a[23][23][23];


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
    int tot = 0;
    for(int i=0;i<23;i++)for(int j=0;j<23;j++)for(int k=0;k<23;k++)if(a[i][j][k]){
        tot+=check(i,j,k);
    }   
    cout << tot;
    return 0;
}
