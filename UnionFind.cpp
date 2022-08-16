#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<deque>

#define rep(i,s,e) for(int i=s;i<e;i++)

#define mod 998244353

using namespace std;

using graph = vector<vector<int>>;

using ll = long long;

struct UnionFind{                   //structのアクセシビリティの初期設定はpublic

    vector<int> par;

    UnionFind(int n){               //コンストラクタ:構造体を呼び出すと自動で作動
        par = vector<int>(n,-1);    //根の親は負の要素数
    }

    int root(int n){
        if (par[n] <0) return n;
        return par[n] = root(par[n]);   //根の親に要素数を入れたいが正の値だとこの関数がうまいこと作れない
    }

    void unite(int x,int y){
        x=root(x);                  //親同士をくっつける
        y=root(y);
        if(x==y) return;
        if(par[x]>par[y]) swap(x,y);
        //深さが長いほうに短いほうをくっつける。
        //長いほうがもっと長くなって積もり積もって計算時間が爆発するから.
        //突出して長いものがなくなる
        //なぜなら常に大きいほうにくっつけていくから
        par[x]+=par[y];
        par[y]=x;
    }

    int size(int n){
        return -par[root(n)];
    }
};