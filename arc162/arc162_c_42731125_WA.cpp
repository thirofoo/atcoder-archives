/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc162/submissions/42731125
 * Submitted at: 2023-06-19 00:59:16
 * Problem URL: https://atcoder.jp/contests/arc162/tasks/arc162_c
 * Result: WA
 * Execution Time: 15 ms
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
    
    // 解説AC
    // Aliceが1手で仕留めないとBobの勝利
    // → bfsで部分木を調べる
    // → O(N^2)が通るので全paternやってok
    ll t; input(t);
    queue<ll> todo;

    while(t--){
        ll n,k; input(n,k);
        vector<ll> p(n,-1),a(n);
        vector<vector<ll>> Graph(n);
        rep(i,n-1){
            input(p[i+1]);
            p[i+1]--;
            Graph[i+1].push_back(p[i+1]);
            Graph[p[i+1]].push_back(i+1);
        }
        bool k_used = false;
        rep(i,n){
            input(a[i]);
            k_used |= (a[i] == k);
        }
        
        bool ans = false;
        rep(i,n){
            todo.push(i);
            ll empty_cnt = 0;
            vector<ll> cand;
            vector<bool> visited(n,false);
            while(!todo.empty()){
                ll now = todo.front(); todo.pop();
                if(visited[now])continue;
                
                visited[now] = true;
                if(a[now] != -1)cand.push_back(a[i]);
                else empty_cnt++;

                for(auto to:Graph[now]){
                    if(p[now] == to || visited[to])continue;
                    todo.push(to);
                }
            }
            ll cnt = 0, k_exist = 0;
            rep(j,cand.size()){
                if(cand[j] < k)cnt++;
                if(cand[j] == k)k_exist++;
            }
            if(!k_used){
                if(cnt == k && k_exist == 0 && empty_cnt <= 1)ans = true;
                if(cnt == k-1 && k_exist == 0 && empty_cnt == 1)ans = true;
                if(ans)break;
            }
            else{
                if(cnt + (empty_cnt+1)/2 >= k && k_exist == 0)ans = true;
                if(ans)break;
            }
        }
        print( (ans ? "Alice" : "Bob") );
    }
    
    return 0;
}