#include <bits/stdc++.h>

using namespace std;
#define int long long 
vector<pair<pair<int,int>,int>> snsr;
//set<int> hasb;
int maxVal = 4000000;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int x, y, x1,y1;
    bool f = 0;
    for(;cin>>s;){
        int n=s.size();
        if(s[0]=='x'){
            if(!f)x = stoi(s.substr(2,n-3));
            else x1 = stoi(s.substr(2,n-3));
        }
        else if(s[0]=='y'){
            if(!f){
                y = stoi(s.substr(2,n-3));
                f=1;
            }
            else{
                y1 = stoi(s.substr(2,n-2));
                snsr.push_back({{x,y}, abs(x-x1)+abs(y-y1)});
                f=0;
            }
        }
    }
    int ans = 0;
    
    for(int i=0;i<=maxVal;i++){
        set<pair<int, int>> rng;
        int id = 1;
        for(auto sn:snsr){
            if(sn.second-abs(sn.first.second-i)>=0){
                
                rng.insert({sn.first.first-(sn.second-abs(sn.first.second-i)), id});
                rng.insert({sn.first.first+(sn.second-abs(sn.first.second-i)+1), id}); 
            }
            id++;
        }
        //cout << i << '\n';
        //cout << rng.size() << '\n';
        set<int> st;
        for(auto it = rng.begin(); it!=rng.end(); it++){
            if(st.count(it->second)){
                st.erase(it->second);
            }
            else{
                st.insert(it->second);
            }
            if(st.size()==0 && (it->first) >=0 && (it->first) <= maxVal){
                cout << (it->first)*maxVal+i << ' ' << i << '\n';
                return 0;
            }

        }
        //cout << '\n';
    }
    return 0;
}
