/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past202004-open/submissions/36188237
 * Submitted at: 2022-11-04 11:03:40
 * Problem URL: https://atcoder.jp/contests/past202004-open/tasks/past202004_j
 * Result: AC
 * Execution Time: 11 ms
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

// 構文解析template
struct Parser{
    using State = string::const_iterator;
    string data;
    State s;
    Parser(string d){
        data = d;
        s = data.begin();
    }

    string term(){
        string res = "";
        while(true){
            if('a' <= *s && *s <= 'z'){
                res += *s;
                s++;
                continue;
            }
            break;
        }
        return res;
    }

    string formula(){
        string res = "",tmp = "";
        while(true){
            if(*s == '('){
                s++;
                res += formula();
                continue;
            }
            if(*s == ')'){
                s++;
                string t = res;
                reverse(t.begin(),t.end());
                res += t;
                break;
            }
            if('a' <= *s && *s <= 'z'){
                res += term();
                continue;
            }
            break;
        }
        return res;
    }



    string parse(){
        return formula();
    }

};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    Parser p(s);
    print(p.parse());
    
    return 0;
}