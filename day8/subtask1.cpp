#include <bits/stdc++.h>

using namespace std;
bool vis[300][300];
int row[300];
int col[300];
int a[300][300];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; 
    for(int i=0;i<300;i++){
        row[i]=col[i]=-1;
    }
    int n=0;
    int m=-1;
    for(int i=0;cin>>s;i++, n++){
        if(m==-1){
            m = s.size();
            if(s.back()=='\n')m--;
        }
        for(int j=0;j<m;j++){
            if(s[j]=='\n')continue;
            a[i][j]=s[j]-'0';
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] > row[i]){
                row[i]=a[i][j];
                if(!vis[i][j]){
                    ans++;
                }
                vis[i][j]=1;
            }
            if(a[i][j] > col[j]){
                
                col[j]=a[i][j];
                if(!vis[i][j]){
                    ans++;
                }
                vis[i][j]=1; 
            }
        }  
    }
    for(int i=0;i<300;i++){
        row[i]=col[i]=-1;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i][j] > row[i]){
                row[i]=a[i][j];
                if(!vis[i][j])ans++;
                vis[i][j]=1;
            }
            if(a[i][j] > col[j]){
                col[j]=a[i][j];
                if(!vis[i][j])ans++;
                vis[i][j]=1; 
            }
        }  
    }
    cout << ans;
    return 0;
}
