/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc147/submissions/34613306
 * Submitted at: 2022-09-04 21:59:41
 * Problem URL: https://atcoder.jp/contests/arc147/tasks/arc147_b
 * Result: AC
 * Execution Time: 14 ms
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
typedef pair<char, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> p(n),place(n+1);
    rep(i,n)input(p[i]);
    rep(i,n)place[p[i]] = i;

    //数の偶奇と場所のidxの偶奇が一致してないものがAをする必要あり。
    queue<P> ans;
    ll c1 = 0,c2 = 0;
    rep(i,n){
        if((i%2 == 0 && p[i]%2 == 0) || (i%2 == 1 && p[i]%2 == 1)){
            ll tmp = i;
            while(tmp >= 2){
                swap(place[p[tmp]],place[p[tmp-2]]);
                swap(p[tmp],p[tmp-2]);
                ans.push(P('B',tmp-2+1));
                tmp -= 2;
            }
        }
    }
    //Aを最小で抑えるpart
    for(ll i=0;i<n;i += 2){
        if(i == n-1)break;
        if((i%2 == 0 && p[i]%2 == 0) || (i%2 == 1 && p[i]%2 == 1) || ((i+1)%2 == 0 && p[i+1]%2 == 0) || ((i+1)%2 == 1 && p[i+1]%2 == 1)){
            swap(place[p[i]],place[p[i+1]]);
            swap(p[i],p[i+1]);
            ans.push(P('A',i+1));
        }
        else break;
    }

    
    //そろえるpart
    rep(i,n){
        ll tmp = place[i+1];
        while(tmp-i >= 2){
            ans.push(P('B',tmp-2+1));
            swap(place[p[tmp]],place[p[tmp-2]]);
            swap(p[tmp],p[tmp-2]);
            tmp -= 2;
        }
    }

    //答え出力part
    print(ans.size());
    while(!ans.empty()){
        print(ans.front().first,ans.front().second);
        ans.pop();
    }
    
    return 0;
}