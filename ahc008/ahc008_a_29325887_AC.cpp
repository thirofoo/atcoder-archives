/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29325887
 * Submitted at: 2022-02-14 09:59:01
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 52 ms
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

string move_up = "U",move_down = "D",move_right="R",move_left = "L";
string place_up = "u",place_down = "d",place_right="r",place_left = "l";

// 4*4 75876759点
// string p1do = "uRuRuRurDrDrDrdLdLdLdlUlUlUl";
// 7*7 129030061点
// string p1do = "uRuRuRuRuRuRurDrDrDrDrDrdLdLdLdLdLdlUlUlUlUlUl";
// 9*9 190289684点
// string p1do = "uRuRuRuRuRuRuRuRurDrDrDrDrDrDrDrdLdLdLdLdLdLdLdlUlUlUlUlUlUlUl";
// 11*11 
// string p1do = "uRuRuRuRuRuRuRuRuRuRurDrDrDrDrDrDrDrDrDrdLdLdLdLdLdLdLdLdLdlUlUlUlUlUlUlUlUlUl";
// 12*12
// string p1do = "rDrDrDrDrDrDrDrDrDrDrDrdLdLdLdLdLdLdLdLdLdLdLdlUlUlUlUlUlUlUlUlUlUlUluRuRuRuRuRuRuRuRuRuRuRu";
// 10*10(左上端っこ専用)
// string p1do = "rDrDrDrDrDrDrDrDrDrdLdLdLdLdLdLdLdLdRdRdRdRdRdRdRdRdrUrUrUrUrUrUrUrUrUrU";
// string p2do = "dRdRdRdRdRdRdRdRdrUrUrUrUrUrUrUrUrUrUrDrDrDrDrDrDrDrDrDrdLdLdLdLdLdLdLdL";
//横一列並べ用
string p1do = "dRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdRdR";


vector<vector<int>> field(32,vector<int>(32,0));
vector<string> player_action;
vector<vector<int>> pet_cnt(305,vector<int>(5,0));
vector<bool> player_bif(10,true);
vector<T> pet;
vector<P> people;
int n,m,cnt;
vector<int> mx = {0,0,1,-1};
vector<int> my = {1,-1,0,0};


//petのfield-update(人は行動するときに別で更新)
void pet_field_update(int x,int y,int dx,int dy){
    field[x][y]--;
    rep(i,4)if(field[x+mx[i]][y+my[i]] != -2)field[x+mx[i]][y+my[i]]--;
    field[x+dx][y+dy]++;
    rep(i,4)if(field[x+dx+mx[i]][y+dy+my[i]] != -2)field[x+dx+mx[i]][y+dy+my[i]]++;
}

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
    //petが5分割中のどこいるか
    if(x <= 5)pet_cnt[cnt][0]++;
    else if(x <= 11)pet_cnt[cnt][1]++;
    else if(x <= 17)pet_cnt[cnt][2]++;
    else if(x <= 23)pet_cnt[cnt][3]++;
    else pet_cnt[cnt][4]++;
}

//人の行動決定
void people_action_deciding(){
    rep(i,m){
        string tmp = "";
        auto[x,y] = people[i];
        if(i%4 == 0){
            rep(i,y-1)tmp += move_left;
            if(x >= 5)rep(i,x-5)tmp += move_up;
            else rep(i,5-x)tmp += move_down;
            while(tmp.size() <= 60)tmp += ".";
            tmp += p1do;
            tmp += move_down;
            while(tmp.size() <= 300)tmp += ".";
        }
        else if(i%4 == 1){
            rep(i,y-1)tmp += move_left;
            if(x >= 11)rep(i,x-11)tmp += move_up;
            else rep(i,11-x)tmp += move_down;
            while(tmp.size() <= 60)tmp += ".";
            tmp += p1do;
            tmp += move_down;
            while(tmp.size() <= 300)tmp += ".";           
        }
        else if(i%4 == 2){
            rep(i,y-1)tmp += move_left;
            if(x >= 17)rep(i,x-17)tmp += move_up;
            else rep(i,17-x)tmp += move_down;
            while(tmp.size() <= 60)tmp += ".";
            tmp += p1do;
            tmp += move_down;
            while(tmp.size() <= 300)tmp += ".";
        }
        else if(i%4 == 3){
            rep(i,y-1)tmp += move_left;
            if(x >= 23)rep(i,x-23)tmp += move_up;
            else rep(i,23-x)tmp += move_down;
            while(tmp.size() <= 60)tmp += ".";
            tmp += p1do;
            tmp += move_down;
            while(tmp.size() <= 300)tmp += ".";
        }
        player_action.push_back(tmp);
    }
}

//人の行動処理
string people_do(){
    string todo = "";
    vector<P> tmp(m,P(0,0));
    rep(i,m){
        int dx = 0,dy = 0;
        char action = player_action[i][cnt-1];
        if     (action == 'U' || action == 'u') dx--; 
        else if(action == 'D' || action == 'd') dx++;
        else if(action == 'L' || action == 'l') dy--;
        else if(action == 'R' || action == 'r') dy++;

        auto [x,y] = people[i];
        //操作先が柵もしくは操作がない時。
        if(field[x+dx][y+dy] == -2 || (dx == 0 && dy == 0)){todo += '.'; continue;}
        if('a' <= action && action <= 'z'){
            if(field[x+dx][y+dy] == 0){field[x+dx][y+dy] = -2; todo += action;}
            //操作先が何かある時に次の行動も置くに変更。
            else{
                string a = ""; a += action;
                player_action[i].insert(cnt,a);
                todo += '.'; continue;
            }
        }
        else{
            if(cnt >= 90 && action == 'D' && player_bif[i]){
                if(pet_cnt[cnt-1][i%4] >= pet_cnt[cnt-1][i%4+1])player_action[i].insert(cnt,place_up);
                else player_action[i].insert(cnt,place_down);
                player_bif[i] = false;
            }
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
        char action = player_action[i][cnt-1];
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
    people_action_deciding();

    //移動処理
    vector<string> ans(300);
    for(cnt=0;cnt<300;cnt++){
        //人間の行動出力部分
        string person = people_do();
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