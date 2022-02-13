/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29249753
 * Submitted at: 2022-02-13 10:45:03
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 56 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 4*4 75876759点
// vector<char> pdo = {'u','R','u','R','u','R','u','r','D','r','D','r','D','r','d','L','d','L','d','L','d','l','U','l','U','l','U','l'};
// 7*7 129030061点
// vector<char> pdo = {'u','R','u','R','u','R','u','R','u','R','u','R','u','r','D','r','D','r','D','r','D','r','D','r','d','L','d','L','d','L','d','L','d','L','d','l','U','l','U','l','U','l','U','l','U','l'};
// 9*9 190289684点
// vector<char> pdo = {'u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l'};
// 11*11 
vector<char> pdo = {'u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l'};
// 12*12
// vector<char> pdo = {'u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','R','u','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','D','r','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','L','d','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l','U','l'};


//ヒトpet問わず、その場or周辺にいる生物の数 外側は-2で、柵は-1になってる。
vector<vector<int>> field(32,vector<int>(32,0));
vector<T> pet;
vector<P> people;
int n,m,cnt,time_dif;
vector<int> mx = {0,0,1,-1};
vector<int> my = {1,-1,0,0};


//petのfield-update
void pet_field_update(int x,int y,int dx,int dy){
    field[x][y]--;
    rep(i,4)if(field[x+mx[i]][y+my[i]] != -2)field[x+mx[i]][y+my[i]]--;
    field[x+dx][y+dy]++;
    rep(i,4)if(field[x+dx+mx[i]][y+dy+my[i]] != -2)field[x+dx+mx[i]][y+dy+my[i]]++;
}

//人のfield-update
// void people_field_update(int x,int y,int dx,int dy){
//     field[x][y]--;
//     field[x+dx][y+dy]++;
// }


//petの位置情報更新
void pet_do(string m,int i){
    int dx = 0,dy = 0;
    rep(i,m.size()){
        if(m[i] == '.')continue;
        else if(m[i] == 'U') dx--;
        else if(m[i] == 'D') dx++;
        else if(m[i] == 'L') dy--;
        else dy++;
    }
    auto [x,y,t] = pet[i];
    pet[i] = {x+dx,y+dy,t};
    //field更新
    if(dx || dy)pet_field_update(x,y,dx,dy);
}

//ヒトの行動決定
string per_todo(){
    string todo = "";
    vector<P> tmp(m,P(0,0));
    rep(i,m){
        int dx = 0,dy = 0;
        char action = pdo[cnt%pdo.size()];
        if     (action == 'U' || action == 'u') dx--; 
        else if(action == 'D' || action == 'd') dx++;
        else if(action == 'L' || action == 'l') dy--;
        else if(action == 'R' || action == 'r') dy++;

        auto [x,y] = people[i];
        //操作先が柵もしくは操作がない時。
        if(field[x+dx][y+dy] == -2 || (dx == 0 && dy == 0)){todo += '.'; continue;}
        if('a' <= action && action <= 'z'){
            if(field[x+dx][y+dy] == 0){field[x+dx][y+dy] = -2; todo += action;}
            //操作先が何かある時。
            else{todo += '.'; continue;}
        }
        else{
            people[i] = {x+dx,y+dy};
            field[x+dx][y+dy]++;
            tmp[i] = P(dx,dy);
            todo += action;
        }
    }
    //そのターン開始に操作出来ないところ
    //(人がいて置けなかったけどその人が先に行動していなくなったkらおけたとか)は×。
    //だからfieldの削除更新は最後。
    rep(i,m){
        auto [x,y] = people[i];
        auto [dx,dy] = tmp[i];
        char action = pdo[cnt%pdo.size()];
        if('A' <= action && action <= 'Z' && (dx || dy))field[x-dx][y-dy]--;
    }
    return todo;
}


int main(){
    rep(i,32)rep(j,32)if(i == 0 || j == 0 || i == 31 || j == 31)field[i][j] = -2;
    //初期入力
    cin >> n;
    rep(i,n){
        int x,y,t; cin >> x >> y >> t;
        pet.push_back(T(x,y,t));
        field[x][y]++;
        rep(j,4)if(field[x+mx[j]][y+my[j]] != -2)field[x+mx[j]][y+my[j]]++;
    }
    cin >> m;
    rep(i,m){
        int x,y; cin >> x >> y;
        people.push_back(P(x,y));
        field[x][y]++;
    }
    time_dif = 300/m;

    //移動処理
    vector<string> ans(300);
    for(cnt=0;cnt<300;cnt++){
        //今のfield状況
        // rep(i,32){
        //     rep(j,32){
        //         cout << field[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        //人間の行動出力部分
        string person = per_todo();
        ans[cnt] = person;
        cout << person << endl;
        fflush(stdout);

        //人間の行動後のペットの行動処理
        rep(i,n){
            string tmp; cin >> tmp;
            pet_do(tmp,i);
        }
    }
}