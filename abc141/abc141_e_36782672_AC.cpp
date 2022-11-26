/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc141/submissions/36782672
 * Submitted at: 2022-11-26 12:51:27
 * Problem URL: https://atcoder.jp/contests/abc141/tasks/abc141_e
 * Result: AC
 * Execution Time: 114 ms
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

vector<int> Zalgo(string str){
    // z-algorithm : 連続文字列&文頭のLCP(Longest Common Prefix)
    int n = str.size();
    vector<int> a(n,0);

    // from : 一番右端まで来てる時の左端
    // last : 一番右端まで来てる時の右端
    int from = -1,last = -1;

    for(int i=1;i<n;i++){
        int &same = a[i];
        if(from != -1){
            // from が -1 でない時、i > from
            // => a[i-from]の時と同じ状況 | last-iと同じ状況
            same = min(a[i-from],last-i);
            same = max(same,0);
        }
        while(i+same < n && str[i+same] == str[same])same++;
        if(i+same > last){
            from = i;
            last = i+same;
        }
    }
    a[0] = n;
    return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // z-algorithm
    ll n; string str; input(n,str);
    ll ans = 0;
    rep(i,n){
        vector<int> tmp = Zalgo(str.substr(i,n));
        rep(j,tmp.size())ans = max(ans,min((ll)tmp[j],j));
    }
    print(ans);
    
    return 0;
}