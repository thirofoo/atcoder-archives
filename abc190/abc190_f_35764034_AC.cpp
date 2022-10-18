/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/35764034
 * Submitted at: 2022-10-18 13:35:19
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_f
 * Result: AC
 * Execution Time: 229 ms
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
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

typedef pair<ll,vector<ll>> P;
P invNum(ll n,vector<ll> &a){
    if(n == 1)return P(0,a);

    vector<ll> left(a.begin(),a.begin()+n/2);
    vector<ll> right(a.begin()+n/2,a.end());
    P l = invNum(n/2,left);
    P r = invNum(n-n/2,right);

    // score : 転倒数, v : sort済み配列
    vector<ll> v;
    ll score = l.first + r.first, i1 = 0,i2 = 0;
    while(i1 < n/2 || i2 < n-n/2){
        if(i1 == n/2){
            v.push_back(r.second[i2]);
            i2++;
        }
        else if(i2 == n-n/2){
            v.push_back(l.second[i1]);
            i1++;
        }
        else{
            if(l.second[i1] <= r.second[i2]){
                v.push_back(l.second[i1]);
                i1++;
            }
            else{
                score += n/2-i1;
                v.push_back(r.second[i2]);
                // leftの中でright[i2]より大きいものだけ転倒数↑
                i2++;
            }
        }
    }
    return P(score,v);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n),b;
    rep(i,n)input(a[i]);
    b = a;
    sort(b.begin(),b.end());

    ll ans = invNum(n,a).first;
    print(ans);
    stack<ll> num;
    for(int i=n-1;i>0;i--){
        auto itr1 = lower_bound(b.begin(),b.end(),a[i]);
        auto itr2 = upper_bound(b.begin(),b.end(),a[i]);
        ans += n-(b.end()-itr1);
        ans -= b.end()-itr2;
        num.push(ans);
    }
    while(!num.empty()){
        print(num.top());
        num.pop();
    }
    
    return 0;
}