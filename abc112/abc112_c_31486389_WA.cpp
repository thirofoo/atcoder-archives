/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/31486389
 * Submitted at: 2022-05-07 18:54:10
 * Problem URL: https://atcoder.jp/contests/abc112/tasks/abc112_c
 * Result: WA
 * Execution Time: 10 ms
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

    int n; cin >> n;
    vector<T> hint;
    rep(i,n){
        ll x,y,h; cin >> x >> y >> h;
        hint.push_back(T(x,y,h));
    }

    for(ll x=0;x<=100;x++){
        for(ll y=0;y<=100;y++){
            ll xp = 0,yp = 0,hp = 0;
            rep(i,n){
                auto [a,b,c] = hint[i];
                xp += abs(x-a);
                yp += abs(y-b);
                hp += c;
            }
            
            ll bottom = -5,top = 1000000005;
            while(top-bottom > 1){
                ll mid = (bottom+top)/2;
                ll point = mid*n - hp - xp - yp;
                if(point > 0)top = mid;
                else if(point < 0)bottom = mid;
                else{
                    rep(i,n){
                        auto [a,b,c] = hint[i];
                        if(c != mid - abs(x-a) - abs(y-b))goto loop_out;
                    }
                    cout << x << " " << y << " " << mid << endl;
                    return 0;
                }
            }
            loop_out:;
        }
    }
    return 0;
}