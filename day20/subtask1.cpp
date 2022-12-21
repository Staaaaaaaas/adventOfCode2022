#include <bits/stdc++.h>

using namespace std;
pair<int,int> a[5001];
int b[5001];
pair<int,int> tmp[5001];

void shuffle( int pp, int n){
    int k = b[pp];
    if(k<0){
        reverse(a,a+n);
    }
    int pos;
    for(int i=0;i<n;i++){
        if(a[i].second==pp){
            pos=i;
            break;
        }
    }
    
    int newPos = (pos+abs(k))%(n-1);
    
    tmp[newPos]=a[pos];
    if(pos!=n-1)tmp[n-1]=a[n-1];
    else tmp[n-1]=a[n-2];
    int j = 0;
    for(int i=0;i<n-1;i++){
        if(i==newPos)continue;
        if(j==pos)j++;
        tmp[i]=a[j++];
    }
    for(int i=0;i<n;i++){
        a[i]=tmp[i];
    }
    if(k<0){
        reverse(a,a+n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x; 
    int n = 0;
    int zeroPos;
    for(int i=0;cin >> x;i++, n++){
        a[i]={x,i};
        b[i]=x;
    }
    for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++){
        //     cout << a[j].first<< ' ';
        // }
        // cout << '\n';
        shuffle(i,n);
        
    }
    // for(int j=0;j<n;j++){
    //     cout <<' ' << a[j].first<< ' ' << a[j].second<< " \n";
    // }
    // cout << '\n';
    int ans = 0;
    for(int i=0;i<n;i++)if(a[i].first==0){
        zeroPos=i;
        break;
    }
    
    for(int i=1;i<=3;i++){
        ans+=a[(zeroPos+(i*1000))%n].first;
    }
   // cout << zeroPos;
    cout << ans << '\n';
    return 0;
}
