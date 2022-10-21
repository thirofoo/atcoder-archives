/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/35837540
 * Submitted at: 2022-10-21 22:32:41
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ay
 * Result: AC
 * Execution Time: 272 ms
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
    
    // 半分全列挙復習
    ll n,k,p; input(n,k,p);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<vector<ll>> cand1(50),cand2(50);
    rep(i,(1LL << n/2)){
        ll sum = 0,num = 0;
        rep(j,n/2){
            if(i & (1LL << j)){
                sum += a[j];
                num++;
            }
        }
        cand1[num].push_back(sum);
    }
    rep(i,(1LL << (n-n/2))){
        ll sum = 0,num = 0;
        rep(j,n-n/2){
            if(i & (1LL << j)){
                sum += a[j+n/2];
                num++;
            }
        }
        cand2[num].push_back(sum);
    }
    ll ans = 0;
    rep(i,k+1){
        sort(cand1[i].begin(),cand1[i].end());
        sort(cand2[k-i].begin(),cand2[k-i].end());
        for(auto num:cand1[i]){
            auto itr = upper_bound(cand2[k-i].begin(),cand2[k-i].end(),p-num);
            ans += cand2[k-i].size() - (cand2[k-i].end()-itr);
        }
    }
    print(ans);
    
    return 0;
}