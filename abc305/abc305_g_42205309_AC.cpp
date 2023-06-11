/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42205309
 * Submitted at: 2023-06-12 02:25:04
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_g
 * Result: AC
 * Execution Time: 429 ms
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

using Matrix = vector<vector<ll>>;
Matrix matrix_multi(Matrix A, Matrix B, ll mod){
    // A * B の行列積
    ll s1 = A.size(), s2 = B.size(), s3 = B[0].size();
    Matrix mul(s1,vector<ll>(s3,0));
    for(int i=0;i<s1;i++){
        for(int j=0;j<s3;j++){
            for(int k=0;k<s2;k++){
                mul[i][j] += A[i][k]*B[k][j] % mod;
                mul[i][j] %= mod;
            }
        }
    }
    return mul;
}

Matrix matrix_pow(Matrix A, ll x, ll mod){
    Matrix res(A.size(),vector<ll>(A.size(),0));
    rep(i,A.size())res[i][i] = 1;

    Matrix r = A; // 行列累乗
    for(int i=0;i<=62;i++){
        if(x & (1LL << i))res = matrix_multi(res, r, mod);
        r = matrix_multi(r, r, mod);
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // dp[i][s] : i文字 & 後ろ6文字がs の時の場合の数
    // とすると、dp[i+1][?] は dp[i] から導ける
    // → その遷移行列を A とすると、その遷移はiに寄らず一意
    // → A を作成・行列累乗すれば O( (2^6)^3logN ) で求まる！

    // 以下 'a' = 1 , 'b' = 0 とする
    ll mod = 998244353;
    ll n,m; input(n,m);
    vector<string> str(m);
    rep(i,m)input(str[i]);

    Matrix first((1LL << 6),vector<ll>(1));
    // 以下の処理は2重の意味がかかってる
    // n <= 6 → 全探索
    // n > 6 → 初期値設定
    ll ans = 0;
    rep(i,(1LL << min(n,6LL))){
        string now = "";
        for(ll j=5;j>=0;j--)now += ( (i & (1LL << j)) ? 'a' : 'b' );
        bool f = true;
        for(string ele:str){
            if(ele.size() > n)continue;
            rep(j,min(n,6LL)-ele.size()+1){
                bool same = true;
                rep(k,ele.size())same &= (now[max(6-n,0ll) + j+k] == ele[k]);
                if(same){
                    f = false;
                    break;
                }
            }
            if(!f)break;
        }
        ans += f;
        first[i][0] = f;
    }
    if(n <= 6){
        print(ans);
        return 0;
    }
    else ans = 0;

    Matrix A(1LL << 6,vector<ll>(1LL << 6,0));
    rep(i,1LL << 6){
        rep(j,1LL << 6){
            // i : 操作前, j : 操作後
            // f : i の末尾に 1文字加えて j に出来るか否か
            bool f = true;
            ll cand = 0;
            // iの後ろ5文字 + 加えるべき1文字(jの末尾)
            rep(k,5)cand += (i & (1LL << k));
            cand <<= 1;
            cand += (j & 1);
            rep(k,6)f &= ( (j & (1LL << k)) == (cand & (1LL << k)) );

            // 一致しないなら x
            if(!f)continue;

            // 一致 & sの要素を含まない なら i → j の遷移が発生！
            // sの要素を含むかどうか → 初期値以外は 末尾からの文字列で決まる！
            string cand_str = "";
            for(ll k=5;k>=0;k--)cand_str += ( (cand & (1LL << k)) ? 'a' : 'b' );
            reverse(cand_str.begin(),cand_str.end());
            for(string ele:str){
                // 末尾から見た方がやり易い為 reverse
                reverse(ele.begin(), ele.end());
                bool same = true;
                rep(l,ele.size())same &= (cand_str[l] == ele[l]);
                if(same){
                    f = false;
                    break;
                }
            }
            if(f)A[j][i]++;
        }
    }

    // Matrix tmp = matrix_pow(A,n-6,mod);
    // rep(i,10){
    //     rep(j,10){
    //         cout << tmp[i][j] << " ";
    //     }
    //     print();
    // }

    Matrix mat = matrix_multi( matrix_pow(A,n-6,mod),first,mod );
    rep(i,(1LL << 6)){
        ans += mat[i][0]%mod;
        ans %= mod;
    }
    print(ans);
    
    return 0;
}