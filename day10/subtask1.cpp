#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> cyc;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int curr =1;
    cin.tie(NULL);
    string s; 
    while(cin>>s){
        if(s=="addx"){
            cyc.push_back(curr);
            cyc.push_back(curr);
            int v; cin >> v;
            curr+=v;
        }
        else{
            cyc.push_back(curr);
        }
    }
    int ans = 0;
    for(int i=19;i<220;i+=40){
        ans+=cyc[i]*(i+1);
    }
    cout << ans << '\n';
    return 0;
}
