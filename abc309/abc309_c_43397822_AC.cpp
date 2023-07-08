/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43397822
 * Submitted at: 2023-07-09 01:10:26
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_c
 * Result: AC
 * Execution Time: 318 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int n,k; cin >> n >> k;
    vector<pair<int,ll>> med(n);
    set<int> st;
    rep(i,n){
        int a,b; cin >> a >> b;
        med[i]=make_pair(a,b);
        st.insert(a);
    }

    sort(med.begin(),med.end(),[](pair<int,ll> &e1, pair<int,ll> &e2){
        auto [a1,b1] = e1;
        auto [a2,b2] = e2;
        return a1 > a2;
    });

    vector<ll> s(st.size()+1,0);
    rep(i,st.size()){
        s[i+1]=s[i]+med[i].second;
    }

    for(int i=st.size(); i>=0; i--){
        if(s[i]<=k){
            if(i==st.size()){
                cout << 1 << endl;
                return 0;
            }else{
                cout << med[i].first+1 << endl;
                return 0;
            }    
        }
    }
    return 0;
}