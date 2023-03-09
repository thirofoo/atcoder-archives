/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/39549093
 * Submitted at: 2023-03-09 12:32:23
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_e
 * Result: AC
 * Execution Time: 154 ms
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
typedef pair<string, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<P> s(n);
    rep(i,n){
        input(s[i].first);
        s[i].second = i;
    }
    sort(s.begin(),s.end());
    vector<ll> ans(n);
    rep(i,n){
        ll answer = 0,cand;
        if(i != 0){
            cand = 0;
            rep(j,min(s[i].first.size(),s[i-1].first.size())){
                if(s[i].first[j] == s[i-1].first[j]){
                    cand++;
                    continue;
                }
                break;
            }
            answer = max(answer,cand);
        }
        if(i != n-1){
            cand = 0;
            rep(j,min(s[i].first.size(),s[i+1].first.size())){
                if(s[i].first[j] == s[i+1].first[j]){
                    cand++;
                    continue;
                }
                break;
            }
            answer = max(answer,cand);
        }
        ans[s[i].second] = answer;
    }
    rep(i,n)print(ans[i]);
    
    return 0;
}