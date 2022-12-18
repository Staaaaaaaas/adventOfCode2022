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
    for(int i = 0;i<240;i++){
        //cout << cyc[i] << ' ';
        int myX = i%40;
        if(myX>=cyc[i]-1 && myX<=cyc[i]+1){
           cout << '#';
        }
        else cout << '.';
        if(myX==39)cout << '\n';
    }
    return 0;
}
