/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/31486879
 * Submitted at: 2022-05-07 19:25:25
 * Problem URL: https://atcoder.jp/contests/abc112/tasks/abc112_c
 * Result: WA
 * Execution Time: 12 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    vector<T> hint;
    rep(i,n){
        ll x,y,h; cin >> x >> y >> h;
        hint.push_back(T(x,y,h));
    }

    for(ll x=0;x<=100;x++){
        for(ll y=0;y<=100;y++){
            ll xp = 0,yp = 0,hp = 0,z;
            rep(i,n){
                auto [a,b,c] = hint[i];
                xp += abs(x-a);
                yp += abs(y-b);
                hp += c;
                if(i == 0)z = c + abs(a-x) + abs(b-y);
            }
            
            bool frag = true;
            rep(i,n){
                auto [a,b,c] = hint[i];
                if(c != max(z - abs(x-a) - abs(y-b),0LL))frag = false;
            }
            if(frag){
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    return 0;
}