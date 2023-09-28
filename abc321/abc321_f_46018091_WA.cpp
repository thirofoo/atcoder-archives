/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/46018091
 * Submitted at: 2023-09-29 02:23:47
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_f
 * Result: WA
 * Execution Time: 2211 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct FPS:vector<mint>{
    using vector<mint>::vector;
    FPS(const vector<mint> &x):vector<mint>(x){}

    FPS inv(int maxDegree = -1){
        if( maxDegree == -1 ) maxDegree = (*this).size() - 1;
        FPS ret(1,(*this)[0].inv());
        int m = 1;
        while( m < maxDegree+1 ){
            ret = ret*2 - ret*ret*(*this);
            m *= 2;
            while( ret.size() > m ) ret.pop_back();
        }
        while( ret.size() > maxDegree+1 ) ret.pop_back();
        return ret;
    }

    FPS &operator+=(mint another){
        *this += FPS(1,another);
        return (*this);
    }

    FPS operator+(mint another) const {
        return (FPS(*this) += another);
    }

    FPS &operator+=(const FPS &another){
        if( (*this).size() < another.size() ) (*this).resize(another.size(),0);
        for(int i=0; i<min((int)(*this).size(),(int)another.size()); i++) {
            (*this)[i] += another[i];
        }
        return (*this);
    }

    FPS operator+(const FPS &another)const{
        return (FPS(*this) += another);
    }

    FPS operator-(){
        return (FPS(*this) *= -1);
    }

    FPS &operator-=(mint another){
        *this -= FPS(1,another);
        return (*this);
    }

    FPS operator-(mint another)const{
        return (FPS(*this)-=another);
    }

    FPS &operator-=(const FPS &another){
        if( (*this).size() < another.size() ) (*this).resize(another.size(),0);
        for(int i=0; i<min((int)(*this).size(),(int)another.size()); i++) {
            (*this)[i] -= another[i];
        }
        return (*this);
    }

    FPS operator-(const FPS &another) const {
        return (FPS(*this) -= another);
    }
    
    FPS &operator*=(mint another){
        for(int i=0;i<(*this).size();i++) {
            (*this)[i] *= another;
        }
        return (*this);
    }

    FPS operator*(mint another)const{
        return (FPS(*this) *= another);
    }

    FPS &operator*=(const FPS &another){
        FPS temp(convolution((*this),another));
        (*this) = temp;
        return (*this);
    }

    FPS operator*(const FPS &another)const{
        return (FPS(*this) *= another);
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll q, k; cin >> q >> k;
    FPS x(k+1, 0);
    x[0] = 1;

    while( q-- ) {
        char c; ll v; cin >> c >> v;
        FPS tx(k+1, 0);
        tx[0] = 1, tx[min(v,k)] = 1;
        if( c == '-' ) tx = tx.inv();
        // rep(i,k+1) cout << tx[i].val() << " ";
        // cout << endl;
        x *= tx;
        // while( x.size() > k ) x.pop_back();
        // rep(i,k+1) cout << x[i].val() << " ";
        // cout << endl;
        cout << x[k].val() << endl;
    }

    return 0;
}