/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/43336332
 * Submitted at: 2023-07-08 20:34:15
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_g
 * Result: AC
 * Execution Time: 754 ms
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

template <typename T0, typename T1, typename F0, typename F1, typename F2, typename F3>
struct Mo{
    Mo( vector<T0> &x ,F0 f0, F1 f1, F2 f2, F3 f3 ) : addL( f0 ), delL( f1 ), addR( f2 ), delR( f3 ), v( x ), n( x.size() ) {}

    vector<T1> get( vector<pair<int,int>> &queries ){
        vector<T1> ret( queries.size() );
        vector<int> q_idx( queries.size() );
        long long sq = sqrt( n );
        iota( q_idx.begin(), q_idx.end(), 0 );
        sort( q_idx.begin(), q_idx.end(), [&]( int &i1, int &i2 ){
            auto &&[ l1, r1 ] = queries[i1];
            auto &&[ l2, r2 ] = queries[i2];
            if( l1/sq != l2/sq ) return l1 < l2;
            if( l1/sq %2 == 1 )  return r1 > r2;
            return r1 < r2;
        });
        
        // [l,r) での運用想定
        long long l = 0, r = 0, now = 0;
        for(int i = 0; i < queries.size(); i++){
            auto &&[ L, R ] = queries[ q_idx[i] ];
            while( r < R ) addR( now, v[r++] );
            while( l > L ) delL( now, v[--l] );
            while( l < L ) addL( now, v[l++] );
            while( r > R ) delR( now, v[--r] );
            ret[ q_idx[i] ] = now;
        }
        return ret;
    }

private :
    F0 addL;
    F1 delL;
    F2 addR;
    F3 delR;
    int n;
    vector<T0> v;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, q; input(n,q);
    vector<long long> a(n);
    vector<pair<int, int>> query;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < q; i++){
        // ~~~ [l,r) に変換 ~~~ //
        int l, r; cin >> l >> r; l--;
        query.push_back( pair<int, int>(l, r) );
    }

    auto nCr = [&](ll n,ll r){
        ll res = 1;
        rep(i,r) res *= (n-i);
        rep(i,r) res /= (i+1);
        return res;
    };

    // Mo's algorithm
    // ~~ 半開区間に注意 ~~ //
    vector<ll> cnt(200005,0);
    // now : 現在の答え , next : 拡張・縮小後の要素
    auto delL = [&]( ll &now, ll next ){
        if( cnt[next] >= 3 )now -= nCr(cnt[next],3);
        if( ++cnt[next] >= 3 )now += nCr(cnt[next],3);
    };
    auto addL = [&]( ll &now, ll next ){
        if( cnt[next] >= 3 )now -= nCr(cnt[next],3);
        if( --cnt[next] >= 3 )now += nCr(cnt[next],3);
    };
    auto delR = [&]( ll &now, ll next ){
        if( cnt[next] >= 3 )now -= nCr(cnt[next],3);
        if( --cnt[next] >= 3 )now += nCr(cnt[next],3);
    };
    auto addR = [&]( ll &now, ll next ){
        if( cnt[next] >= 3 )now -= nCr(cnt[next],3);
        if( ++cnt[next] >= 3 )now += nCr(cnt[next],3);
    };

    // Mo< (要素型), (返り値型), ... >
    Mo<ll, ll, decltype( addL ), decltype( delL ), decltype( addR ), decltype( delR )> mo( a, addL, delL, addR, delR );
    vector ans = mo.get( query );
    
    rep(i,q)cout << ans[i] << endl;
    
    return 0;
}