/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc150/submissions/35550268
 * Submitted at: 2022-10-09 23:00:00
 * Problem URL: https://atcoder.jp/contests/arc150/tasks/arc150_b
 * Result: WA
 * Execution Time: 6 ms
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

//拡張ユークリッドの互除法
//x,yは再起の帰りがけ以降に得られる解であるから、初期化はいらない。
// ll a,b,x,y; cin >> a >> b; でok。
//また逆元の存在条件は、「aとpが互いに素」であるから、
//if(a%b == 0 || b%a == 0)cout << 0 << endl; とすべき。
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    //ax + by = gcd(a,b)のa,bの次の部分はそれぞれb,a%bに対応。
    //そしてx,yを反転させて再起に潜り、あとは再起に任せる感じ。
    ll d = extGCD(b, a%b, y, x);
    //ここでのx,y,は再起後であるからそれぞれが実質s,tの値になっている。
    //そのためy -= a/b * x して、x = d,y = s - qt より元のx,yを復元している。
    y -= a/b * x;
    //x,yはax+by = gcd(x,y)の解となっている。
    //また、逆元を求めるときはax + py = gcd(a,p)の正の解xが欲しい為、
    //cout << (x%p + p)%p << endl;　で得られる。
    return d;
}

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll a,b,ans = LLONG_MAX; input(a,b);
        ll c,d,x,y,tmp;
        if(b/a != 0){
            c = b/a;
            d = -1;
            extGCD(c,d,x,y);
            tmp = ((b-c*a)%(b-a%b)+b-a%b)%(b-a%b);
            ans = min(ans,(x+y)*tmp);
        }
        c = b/a+1;
        d = -1;
        extGCD(c,d,x,y);
        tmp = ((b-c*a)%(b-a%b)+b-a%b)%(b-a%b);
        ans = min(ans,(x+y)*tmp);
        print(ans);
    }
    
    return 0;
}