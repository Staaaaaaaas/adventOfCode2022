#include <bits/stdc++.h>

using namespace std;

bool taken[7][100000];

int ans =0;
class Fig{
    public:
        vector<pair<int,int>> v;
        int lf = 2;
        int rt;
        Fig(int type, int yL){
            if(type == 0){
                for(int i=0;i<4;i++){
                    v.push_back({2+i,yL});
                }
                rt = 5;
            }
            else if(type ==1){
                v.push_back({3, yL});
                for(int i=0;i<3;i++){
                    v.push_back({2+i,yL+1});
                } 
                v.push_back({3,yL+2});
                rt = 4;
            }
            else if(type ==2){
                for(int i=0;i<3;i++){
                    v.push_back({2+i,yL});
                }
                for(int i=0;i<2;i++){
                    v.push_back({4,yL+1+i});
                } 
                rt = 4;
            }
            else if(type == 3){
                for(int i=0;i<4;i++){
                    v.push_back({2,yL+i});
                }
                rt = 2;
            }
            else{
                for(int i=0;i<2;i++){
                    v.push_back({2+i,yL});
                    v.push_back({2+i,yL+1});
                } 
                rt=3;   
            }
        }
        bool move(bool dir){
            if(dir && rt<6){
                bool ok = 1;
                for(int i=0;i<v.size();i++){
                    if(taken[v[i].first+1][v[i].second]){
                        ok=0;
                        break;
                    }
                    
                }
                if(ok){
                    for(int i=0;i<v.size();i++){
                        v[i].first++;
                    }
                    rt++;
                    lf++;
                }
            }
            else if(!dir && lf>0){
                bool ok = 1;
                for(int i=0;i<v.size();i++){
                    if(taken[v[i].first-1][v[i].second]){
                        ok=0;
                        break;
                    }
                    
                }
                if(ok){
                    for(int i=0;i<v.size();i++){
                        v[i].first--;
                    }
                    rt--;
                    lf--;
                } 
            }
            bool out = false;
            for(int i=0;i<v.size();i++){
                if(taken[v[i].first][v[i].second-1]){
                    out = 1;
                    break;
                }
            }
            if(out){
                for(int i=0;i<v.size();i++){
                    taken[v[i].first][v[i].second]=1;
                    ans = max(ans, v[i].second);
                } 
                return false;
            }
            for(int i=0;i<v.size();i++){
                v[i].second--;
            } 
            return true;

        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    for(int i =0;i<7;i++){
        taken[i][0]=1;
    }
    int mv = -1;
    for(int i=0;i<2022;i++){
        Fig f = Fig(i%5, ans+4);
        for(;;){
            mv++;
            int dr = (s[mv%s.size()]=='>');
            if(!f.move(dr))break;
        }
        //cout << ans<<'\n';
        // for(int ii=ans+3;ii>=0 && i<5;ii--){
        //     for(int j=0;j<7;j++){
        //         cout << ".#"[taken[j][ii]];
        //     }
        //     cout << '\n';
        // }
    }
    cout << ans;
    return 0;
}
