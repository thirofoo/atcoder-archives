/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41929931
 * Submitted at: 2023-06-03 18:11:32
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_i
 * Result: WA
 * Execution Time: 1554 ms
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
typedef pair<ld, ld> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    // 解説AC 偏角sort
    // 各頂点を原点と見なした時の偏角を前計算 → 二分探索
    ll n; input(n);
    vector<P> v;
    rep(i,n){
        ld x,y; input(x,y);
        v.push_back(P(x,y));
    }

    ld ans = 0;
    rep(i,n){
        auto &&[x1,y1] = v[i];
        vector<ld> angle;
        rep(j,n){
            if(i == j)continue;
            auto &&[x2,y2] = v[j];
            ld dx = x2-x1, dy = y2-y1;
            angle.push_back( atan2(dx,dy)*180 / M_PI );
        }
        sort(angle.begin(),angle.end());
        ld cand = 0;
        for(auto a:angle){
            ld ideal = a + 180;
            if(ideal >= 360)ideal -= 360;
            auto itr = upper_bound(angle.begin(),angle.end(),ideal);
            if(itr == angle.begin() || itr == angle.end()){
                ld c1 = abs(a-*angle.begin()), c2 = abs(a-*angle.rend());
                if(c1 >= 180)c1 = 360-c1;
                if(c2 >= 180)c2 = 360-c2;
                cand = max(cand,c1);
                cand = max(cand,c2);
            }
            else{
                ld c1 = abs(a-*itr), c2 = abs(a-*(itr-1));
                if(c1 >= 180)c1 = 360-c1;
                if(c2 >= 180)c2 = 360-c2;
                cand = max(cand,c1);
                cand = max(cand,c2);
            }
        }
        ans = max(ans,cand);
    }
    print(ans);
    
    return 0;
}