/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/34749093
 * Submitted at: 2022-09-10 22:02:21
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_d
 * Result: WA
 * Execution Time: 1328 ms
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

ll n,m;
bool f = false;
string ans;
vector<string> s;
set<string> str;
void dfs(string now,ll idx){
    if(f)return;
    if(idx == n){
        if(!str.count(now) && now.size() >= 3 && now.size() <= 16){
            ans = now;
            f = true;
        }
    }
    else{
        while(true){
            if(f)break;
            now += "_";
            if(now.size()+s[idx].size() <= 16)dfs(now+s[idx],idx+1);
            else break;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,m);
    s.assign(n,"");
    rep(i,n)input(s[i]);
    rep(i,m){
        string t; input(t);
        str.insert(t);
    }
    
    do{
        dfs(s[0],1);
        if(f)break;
    }while(next_permutation(s.begin(),s.end()));

    print((f ? ans : "-1"));
    
    return 0;
}