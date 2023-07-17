/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc166/submissions/43682726
 * Submitted at: 2023-07-17 11:05:47
 * Problem URL: https://atcoder.jp/contests/abc166/tasks/abc166_f
 * Result: AC
 * Execution Time: 158 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // A,B,C のうち 2つ以上が正 && その2つの少なくとも一方が1より大きい → Yes
    // 　　　〃     1つも無い → No
    // else → 場合による
    ll n,a,b,c; cin >> n >> a >> b >> c;
    ll zero_cnt = 0, one_cnt = 0;
    zero_cnt = (a == 0) + (b == 0) + (c == 0);
    one_cnt = (a == 1) + (b == 1) + (c == 1);
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    if( zero_cnt == 3 ){
        cout << "No" << endl;
        return 0;
    }

    queue<char> ans;
    rep(i,n){
        if( s[i] == "AB" ){
            if( a == 0 && b == 0 ){
                cout << "No" << endl;
                return 0;
            }

            if( a == 1 && b == 1 && i != n-1 ){
                if( s[i+1] == "AC" ){
                    ans.push('A');
                    a++; b--;
                }
                else{
                    ans.push('B');
                    a--; b++;
                }
            }
            else if( a > b ){
                ans.push('B');
                a--; b++;
            }
            else{
                ans.push('A');
                a++; b--;
            }
        }
        else if( s[i] == "AC" ){
            if( a == 0 && c == 0 ){
                cout << "No" << endl;
                return 0;
            }

            if( a == 1 && c == 1 && i != n-1 ){
                if( s[i+1] == "AB" ){
                    ans.push('A');
                    a++; c--;
                }
                else{
                    ans.push('C');
                    a--; c++;
                }
            }
            else if( a > c ){
                ans.push('C');
                a--; c++;
            }
            else{
                ans.push('A');
                a++; c--;
            }
        }
        else{
            if( b == 0 && c == 0 ){
                cout << "No" << endl;
                return 0;
            }

            if( b == 1 && c == 1 && i != n-1 ){
                if( s[i+1] == "AB" ){
                    ans.push('B');
                    b++; c--;
                }
                else{
                    ans.push('C');
                    b--; c++;
                }
            }
            else if( b > c ){
                ans.push('C');
                b--; c++;
            }
            else{
                ans.push('B');
                b++; c--;
            }
        }
    }

    cout << "Yes" << endl;
    while( !ans.empty() ){
        cout << ans.front() << endl;
        ans.pop();
    }
    
    return 0;
}