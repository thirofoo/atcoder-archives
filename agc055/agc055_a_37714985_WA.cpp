/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc055/submissions/37714985
 * Submitted at: 2023-01-03 21:05:14
 * Problem URL: https://atcoder.jp/contests/agc055/tasks/agc055_a
 * Result: WA
 * Execution Time: 146 ms
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
    
    ll n; string s; input(n,s);

    vector<ll> used(3*n,-1);
    ll rest = 3*n,time = 1;

    while(time <= 6){
        vector<ll> p = {0,1,2};
        ll ok = (rest/3+1)/2;

        // print(ok);
        // cout << flush;
        
        do{
            ll idx = 0,cnt = 0;
            rep(i,3*n){
                if(used[i] >= 1)continue;

                if(s[i]-'A' == p[idx])cnt++;
                if(cnt >= ok){
                    cnt = 0;
                    idx++;
                }
                if(idx == 3)break;
            }
            // print(idx,cnt);
            if(idx == 3)break;

        }while(next_permutation(p.begin(),p.end()));

        // rep(i,3*n){
        //     if(used[i] >= 1)continue;
        //     cout << s[i];
        // }
        // print();
        // rep(i,3*n)cout << used[i] << " ";
        // print();

        ll now = 0,cnt = 0;
        rep(i,3*n){
            if(used[i] >= 1)continue;
            if(s[i]-'A' == p[now]){
                used[i] = time;
                rest--;
                cnt++;
            }
            if(cnt >= ok){
                now++;
                cnt = 0;
            }
            if(now == 3)break;
        }
        time++;

        // check part
        bool f = true;
        rep(i,3*n)f &= (used[i] >= 1);
        if(f)break;
    }
    rep(i,3*n)cout << used[i];
    print();
    
    return 0;
}