#include <bits/stdc++.h>

using namespace std;

char grid[1000][1000];

int main(){
    for(int i=0;i<1000;i++)for(int j=0;j<1000;j++)grid[i][j]='.';
    string s;
    bool go = 0;
    pair<int,int> start;
    int maxy = 0;
    while(cin >> s){
        if(s=="->")go=1;
        else{

            int pos = s.find(',');
            int xc = stoi(s.substr(0,pos));
            int yc = stoi(s.substr(pos+1));
            maxy=max(maxy, yc);
            //cout <<s.substr(0,pos) << ' ' << s.substr(pos+1) << ' ' << go << '\n'; 
            if(go){
                
                if(start.first==xc){
                    int ys = start.second;
                    int ye = yc;
                    if(ye<ys)swap(ye,ys);
                    for(int i=ys;i<=ye;i++){
                        //cout << i << ' ' << ye << '\n';
                        grid[i][xc]='#';
                    }
                }
                else{
                    int xs = start.first;
                    int xe = xc;
                    if(xe<xs)swap(xe,xs);
                    for(int i=xs;i<=xe;i++)grid[yc][i]='#'; 
                }
                go = 0;
            }
            start = {xc,yc};
        }
    }
    int ans = 0;
    for(;true;ans++){
        pair<int,int> curr = {500,0};
        for(;curr.second <= maxy;){
            if(grid[curr.second+1][curr.first]=='.'){
                curr.second+=1;
            }
            else if(grid[curr.second+1][curr.first-1]=='.'){
                curr.second+=1;
                curr.first-=1;
            }
            else if(grid[curr.second+1][curr.first+1]=='.'){
                curr.second+=1;
                curr.first+=1;
            }
            else{
                grid[curr.second][curr.first]='O';
                break;
            }
        }
        if(curr.second>maxy)break;
    }
    cout << ans << '\n';
    // for(int i=0;i<10;i++){
    //     for(int j=494;j<=503;j++){
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }
    return 0;
}
