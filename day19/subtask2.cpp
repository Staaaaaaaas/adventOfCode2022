#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<array<int, 6>> bp;
int mat[4] = {0,0,0,0};
int rob[4] = {1,0,0,0};
// int q[4] = {0,0,0,0};
int calls = 0;
int mx = 0;
int id = 1;
int calc0(){
    int need = bp[id][0];
    int has = mat[0];
    int tm= (need-has+rob[0]-1)/rob[0];
    
    return max(tm,0LL)+1;
}
int calc1(){
    int need = bp[id][1];
    int has = mat[0];
    int tm = (need-has+rob[0]-1)/rob[0];

    return max(tm,0LL)+1;
}
int calc2(){
    int need0 = bp[id][2];
    int need1 = bp[id][3];
    int has0 = mat[0];
    int has1 = mat[1];
    int time0 = (need0-has0+rob[0]-1)/rob[0];
    int time1 = (need1-has1+rob[1]-1)/rob[1];
    
    return max({0LL,time0,time1})+1;
}
int calc3(){
    int need0 = bp[id][4];
    int need2 = bp[id][5];
    int has0 = mat[0];
    int has2 = mat[2];
    int time0 = (need0-has0+rob[0]-1)/rob[0];
    int time2 = (need2-has2+rob[2]-1)/rob[2];
    return max({0LL,time0,time2})+1;
}

void dfs(int t){

    mx = max(mx, mat[3]+rob[3]*t);
    if(t<=0)return;
    calls++;
    int t0 = calc0();
    int t1 = calc1();
    int t2 = (rob[1])?calc2():1000;
    int t3 = (rob[2])?calc3():1000;
    if(rob[0]>5 || rob[1]>11 || rob[2]>7)return;
    if(t-t0>0){
        for(int i=0;i<4;i++){
            mat[i]+=t0*rob[i];
        }
        mat[0]-=bp[id][0];
        rob[0]++;
        dfs(t-t0);
        rob[0]--;
        mat[0]+=bp[id][0];
        for(int i=0;i<4;i++){
            mat[i]-=t0*rob[i];
        }
    }
    if(t-t1>0){
        for(int i=0;i<4;i++){
            mat[i]+=t1*rob[i];
        }
        mat[0]-=bp[id][1];
        rob[1]++;
        dfs(t-t1);
        rob[1]--;
        mat[0]+=bp[id][1];
        for(int i=0;i<4;i++){
            mat[i]-=t1*rob[i];
        }
    }
    if(t-t2>0){
        for(int i=0;i<4;i++){
            mat[i]+=t2*rob[i];
        }
        mat[0]-=bp[id][2];
        mat[1]-=bp[id][3];
        rob[2]++;
        dfs(t-t2);
        rob[2]--;
        mat[1]+=bp[id][3];
        mat[0]+=bp[id][2];
        for(int i=0;i<4;i++){
            mat[i]-=t2*rob[i];
        }
    }
    if(t-t3>0){
        for(int i=0;i<4;i++){
            mat[i]+=t3*rob[i];
        }
        mat[0]-=bp[id][4];
        mat[2]-=bp[id][5];
        rob[3]++;
        dfs(t-t3);
        rob[3]--;
        mat[2]+=bp[id][5];
        mat[0]+=bp[id][4];
        for(int i=0;i<4;i++){
            mat[i]-=t3*rob[i];
        }
    }
    
   
}


int32_t main(){
    string s;
    int idl = 0;
    for(;cin >> s;){
        if(s.back()<='9' && s.back()>='0'){
            if(idl==0){
                array<int, 6> a;
                bp.push_back(a);
            }
            bp.back()[idl++]=stoi(s);
            if(idl==6){
                idl=0;
            }
        }
    }
    //runBp(0,1,4,2);
    int ans = 1;
    for(int blp=0;blp<min((int)bp.size(),3LL);blp++){
        calls=0;
        id = blp;
        mx = 0;
        mat[0]=mat[1]=mat[2]=mat[3]=0;
        rob[0]=rob[1]=rob[2]=rob[3]=0; 
        rob[0]=1;
        dfs(32);
        // cout << mx << '\n';
        ans*= (mx);
    }
    //dfs(24);
    //cout << bp.size();
    cout << ans << '\n';
    return 0;
}
