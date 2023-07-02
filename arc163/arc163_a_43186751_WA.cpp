/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc163/submissions/43186751
 * Submitted at: 2023-07-02 21:12:39
 * Problem URL: https://atcoder.jp/contests/arc163/tasks/arc163_a
 * Result: WA
 * Execution Time: 13 ms
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
typedef pair<string, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n; string s; input(n,s);

        bool f = false;
        rep(i,s.size()){
            if( s[0] < s[i] && s[i] <= 'z' ){
                print("Yes");
                f = true;
                break;
            }
        }
        if(f) continue;

        vector<P> str;
        string tmp = "";
        ll cnt = 0;
        tmp += s[0];
        for(ll i=1;i<s.size();i++){
            if( s[i] == s[0] ){
                str.push_back(P(tmp,cnt));
                tmp = s[i];
                cnt++;
            }
            else tmp += s[i];
        }
        str.push_back(P(tmp,cnt));
        sort(str.begin(),str.end(), [](P &s1, P &s2){
            if( s1.first == s2.first ) return s1.second > s2.second;
            return s1.first > s2.first;
        });
        print( (str[0].second == 0 ? "No" : "Yes") );
    }
    
    return 0;
}