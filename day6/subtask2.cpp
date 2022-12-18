#include <bits/stdc++.h>

using namespace std;
int cnt[100]; 
int main(){
    string s;
    set<char> st;
    while(cin >> s){
        int n = s.size();
        for(int i=0;i<n;i++){
            cnt[s[i]]++;
            st.insert(s[i]);
            if(i-14>=0){
                cnt[s[i-14]]--;
                if(!cnt[s[i-14]]){
                    st.erase(st.find(s[i-14]));
                }
            }
            if(st.size()==14){
                cout << i+1 << '\n';
                return 0;
            }
        }
    }
    return 0;
}
