/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43397656
 * Submitted at: 2023-07-09 01:00:40
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_c
 * Result: AC
 * Execution Time: 382 ms
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

    // ~~~ 削除 ~~~ //
    // sort(med.begin(),med.end(),[](pair<int,ll> &e1, pair<int,ll> &e2){
    //     auto [a1,b1] = e1;
    //     auto [a2,b2] = e2;
    //     return a1 > a2;
    // });
    //
    // int cnt=0;
    // rep(i,n-1){
    //     if(med[i-cnt].first==med[i-cnt+1].first){
    //         med[i-cnt].second+=med[i-cnt+1].second;
    //         med.erase(med.begin()+i-cnt+1);
    //         cnt++;
    //     }
    // }
    // ~~~ 削除 ~~~ //

    // ~~~ 追加 ~~~ //
    vector<pair<int,ll>> sum_med;
    ll pre = med[0].first, sum = 0;
    rep(i,n){
        auto [a, b] = med[i];
        if( pre == a ) sum += b;
        else{
            sum_med.push_back( pair(pre,sum) );
            sum = b;
        }
        pre = a;
    }
    if(sum != 0) sum_med.push_back( pair(pre,sum) );
    swap( med, sum_med );
    sort(med.begin(),med.end(),[](pair<int,ll> &e1, pair<int,ll> &e2){
        auto [a1,b1] = e1;
        auto [a2,b2] = e2;
        return a1 > a2;
    });
    // ~~~ 追加 ~~~ //

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