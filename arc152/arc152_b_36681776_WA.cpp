/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc152/submissions/36681776
 * Submitted at: 2022-11-20 22:45:37
 * Problem URL: https://atcoder.jp/contests/arc152/tasks/arc152_b
 * Result: WA
 * Execution Time: 45 ms
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
    
    ll n,l; input(n,l);
    vector<ll> a(n+2,0),b,c;
    rep(i,n)input(a[i+1]);
    a[n+1] = l;
    rep(i,n+1)b.push_back((a[i+1]-a[i])*(i == 0 || i == n ? 2 : 1));
    for(int i=n-1;i>0;i--)b.push_back(b[i]);
    c = b;
    c.push_back(b.front());
    c.erase(c.begin());

    int s1 = b.size(),s2 = c.size();
    rep(i,s1)b.push_back(b[i]);
    rep(i,s2)c.push_back(c[i]);

    // for(auto g:b)cout << g << " ";
    // print();
    // for(auto g:c)cout << g << " ";
    // print();

    int l1 = 0,l2 = 0,lt1 = 0,lt2 = 0;
    ll ans = LLONG_MAX;
    rep(i,n){
        while(true){
            if(lt1 > l)break;
            lt1 += b[l1];
            l1++;
        }
        while(true){
            if(lt2 > l)break;
            lt2 += c[l2];
            l2++;
        }
        // cout << l1 << " : " << lt1 << endl;
        // cout << l2 << " : " << lt2 << endl;
        if(abs(lt1-b[l1-1]) == l && abs(lt2-c[l2-1]) == l){
            ans = 2*l;
        }
        else if(abs( lt1 - (lt2-c[l2-1]) ) <= abs( lt1-b[l1-1] - lt2 )){
            ans = min(ans,2*l+abs( lt1 - (lt2-c[l2-1]) ));
            // cout << 2*l+abs( lt1 - (lt2-c[l2-1]) ) << endl;
        }
        else{
            ans = min(ans,2*l+abs( lt1-b[l1-1] - lt2 ));
            // cout << 2*l+abs( lt1-b[l1-1] - lt2 ) << endl;
        }
        lt1 -= b[i];
        lt2 -= c[i];
    }
    print(ans);
    
    return 0;
}