#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

template <typename T>
struct RMQ{
    //RMQ:range maximum query 
    //セグメント木を使い区間内の最大値をO(logn)で求める

    vector<T> tree;
    int datasize;
    //datasize:葉の数,searchのnrに入れる
    int leaf;
    //leaf:葉の一番左の添え字

    RMQ(int n,vector<int> &a){
        int index = 1;
        //index:tree配列の要素数(完全二分木になるように)
        //2*n-1は最低限ほしい要素数
        int tmp = 2;
        while(index<2*n-1){
            index+=tmp;
            tmp*=2;
        }
        datasize = tmp/2;
        tree.resize(index,0);
        leaf = index-(tmp/2);
        queue<int> q;
        //q:木を作る際、次に注目するものを入れる
        //葉にデータを格納
        for(int i=0;i<(tmp/2);++i){
            if(i<n) tree[leaf+i] = a[i];
            q.push(leaf+i);
        }
        //木を構築
        while(q.size()!=1){
            int l = q.front(); q.pop();
            int r = q.front(); q.pop();
            if(tree[l]<=tree[r]) tree[(l-1)/2] = tree[r];
            else tree[(r-1)/2] = tree[l];
            //親をqueueに入れる
            q.push((l-1)/2);
        }
    }

    //l,r:queryで求める範囲 nl,nr:現在調査中の範囲
    T ans=0;
    void search(int now,int l,int r,int nl,int nr){
        //nl=1 nr = datasize を入力(再起関数使うからやむを得ない)
        if(l>nr||r<nl) return;
        //l,rが範囲と全くかぶらない場合の処理
        if(l<nl) l = nl;
        if(r>nr) r = nr;
        //一部nl,nrと被っている時にはみ出ている部分を切り捨てる
        if(l==nl&&r==nr){
            //範囲が等しい時
            if(ans<tree[now]) ans = tree[now];
            return;
        }
        //それ以外は範囲縮小
        search(2*now+1,l,r,nl,(nl+nr)/2);
        search(2*now+2,l,r,(nl+nr)/2+1,nr);
    }

    //配列aの添え字iのデータがxにされたとき木のデータを更新する関数
    void update(int i,int x){
        int now = leaf+i;
        tree[now] = x;
        int parent = (now-1)/2;
        while(parent>0){
            if(tree[2*parent+1]<=tree[2*parent+2]) tree[parent] = tree[2*parent+2];
            else tree[parent] = tree[2*parent+1];
            now = parent;
            parent = (now-1)/2;
        }
        tree[0] = max(tree[1],tree[2]);
    }
};
