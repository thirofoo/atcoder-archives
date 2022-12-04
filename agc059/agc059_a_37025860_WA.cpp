/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc059/submissions/37025860
 * Submitted at: 2022-12-04 23:03:24
 * Problem URL: https://atcoder.jp/contests/agc059/tasks/agc059_a
 * Result: WA
 * Execution Time: 1174 ms
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

vector<char> ch = {'A','B','C'};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // Mo's
    ll n,q; string s; input(n,q,s);
    vector<ll> l(q),r(q);
    rep(i,q){
        input(l[i],r[i]);
        l[i]--; r[i]--;
    }
    ll sq = sqrt(q);
 
    // queryを実行する順番を決めるpart
    vector<ll> query(q);
    iota(query.begin(),query.end(),0);
    sort(query.begin(),query.end(),[&](ll a,ll b){
        if(l[a]/sq != l[b]/sq){
            return l[a] < l[b];
        }
        if(l[a]/sq %2 == 1){
            return r[a] > r[b];
        }
        return r[a] < r[b];
    });
 
    // クエリ処理part
    vector<ll> ans(q,LLONG_MAX),cnt_l,cnt_r;
    
    rep(j,3){
        cnt_l.assign(3,0);
        cnt_r.assign(3,0);
        ll nl = 0,nr = 0,now_ans = (s[0] == ch[j] ? 0 : 1);
        cnt_l[s[0]-'A']++; cnt_r[s[0]-'A']++; // この初期値忘れがち
        deque<vector<ll>> v_r,v_l;
        rep(i,q){
            // 次のクエリの点まで移動
            while(nr < r[query[i]]){
                // rが大きい方に進む時
                // => [l,r]は広がる
                nr++;
                if(s[nr] == ch[j]){
                    if(cnt_r[0] || cnt_r[1] || cnt_r[2]){
                        v_l.push_back(cnt_r);
                        cnt_r[0] = 0;
                        cnt_r[1] = 0;
                        cnt_r[2] = 0;
                    }
                }
                else{
                    if(cnt_r[s[nr]-'A'] == 0)now_ans++;
                    cnt_r[s[nr]-'A']++;
                }
            }
            // print(nl,nr," : ",now_ans);
            // cout << flush;
            while(nl > l[query[i]]){
                // lが小さい方に進む時
                // => [l,r]は広がる
                nl--;
                if(s[nl] == ch[j]){
                    if(cnt_l[0] || cnt_l[1] || cnt_l[2]){
                        v_r.push_front(cnt_l);
                        cnt_l[0] = 0;
                        cnt_l[1] = 0;
                        cnt_l[2] = 0;
                    }
                }
                else{
                    if(cnt_l[s[nr]-'A'] == 0)now_ans++;
                    cnt_l[s[nl]-'A']++;
                }
            }
            // print(nl,nr," : ",now_ans);
            // cout << flush;
            while(nl < l[query[i]]){
                // lが大きい方に進む時
                // => [l,r]は狭まる
                if(s[nl] == ch[j]){
                    if(!(cnt_l[0] || cnt_l[1] || cnt_l[2])){
                        if(!v_l.empty()){
                            cnt_l = v_l.front();
                            v_l.pop_front();
                        }
                        else{
                            cnt_l[0] = 0;
                            cnt_l[1] = 0;
                            cnt_l[2] = 0;
                        }
                    }
                }
                else{
                    cnt_l[s[nl]-'A']--;
                    if(cnt_l[s[nr]-'A'] == 0)now_ans--;
                }
                nl++;
            }
            // print(nl,nr," : ",now_ans);
            // cout << flush;
            while(nr > r[query[i]]){
                // rが小さい方に進む時
                // => [l,r]は狭まる
                if(s[nr] == ch[j]){
                    if(!(cnt_r[0] || cnt_r[1] || cnt_r[2])){
                        if(!v_r.empty()){
                            cnt_r = v_r.back();
                            v_r.pop_back();
                        }
                        else{
                            cnt_r[0] = 0;
                            cnt_r[1] = 0;
                            cnt_r[2] = 0;
                        }
                    }
                }
                else{
                    cnt_r[s[nr]-'A']--;
                    if(cnt_r[s[nr]-'A'] == 0)now_ans--;
                }
                nr--;
            }
            // print(nl,nr," : ",now_ans);
            // print("query",query[i]);
            // print("ans = ",now_ans);
            // print();
            // cout << flush;
            ans[query[i]] = min(ans[query[i]],now_ans);
        }
    }
    
    rep(i,q)print(ans[i]);
    
    return 0;
}