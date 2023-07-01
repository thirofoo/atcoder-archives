/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43167074
 * Submitted at: 2023-07-02 08:11:34
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_g
 * Result: AC
 * Execution Time: 1142 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // 実は xor の最小値の候補は隣接ノードのみを考慮すれば良い
    // → 候補が高々 N-1 個だから管理可能

    ll q; input(q);
    multiset<ll> st, ans;

    while(q--){
        ll t; input(t);
        if( t == 1 ){
            ll x; input(x);
            st.insert(x);

            bool f1 = false, f2 = false, f3 = false;
            auto itr1 = st.lower_bound(x);
            auto itr2 = itr1, itr3 = itr1;
            itr2--; itr3++;
            ll cand1, cand2, cand3;

            if(itr1 != st.begin()){
                cand1 = (*itr1)^(*itr2);
                f1 = true;
            }
            if(itr3 != st.end()){
                cand2 = (*itr1)^(*itr3);
                f2 = true;
                if(itr1 != st.begin()){
                    cand3 = (*itr2)^(*itr3);
                    f3 = true;
                }
            }

            if(f1)ans.insert(cand1);
            if(f2)ans.insert(cand2);
            if(f3)ans.erase(ans.find(cand3));
        }
        else if( t == 2 ){
            ll x; input(x);
            auto itr1 = st.lower_bound(x);
            auto itr2 = itr1, itr3 = itr1;
            itr2--; itr3++;
            bool f1 = false, f2 = false, f3 = false;
            ll cand1, cand2, cand3;

            if(itr1 != st.begin()){
                cand1 = (*itr1)^(*itr2);
                f1 = true;
            }
            if(itr3 != st.end()){
                cand2 = (*itr1)^(*itr3);
                f2 = true;
                if(itr1 != st.begin()){
                    cand3 = (*itr2)^(*itr3);
                    f3 = true;
                }
            }

            if(f1)ans.erase(ans.find(cand1));
            if(f2)ans.erase(ans.find(cand2));
            if(f3)ans.insert(cand3);
            st.erase(st.find(x));
        }
        else print( *ans.begin() );
    }
    
    return 0;
}