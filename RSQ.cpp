#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<utility>
#include<stack>

//RSQ:RangeSumQuery
template <typename T>
struct RSQ{
    vector<T> tree;
    int datasize,leaf;
    //コンストラクタはデータ数とデータのvectorを引数に取る
    RSQ(int n,vector<T>& a){
        int index = 1;
        datasize = 1;
        while(index<2*n-1){
            datasize*=2;
            index+=datasize;
        }
        tree.resize(index,0);
        leaf = index - datasize;
        queue<int> que;
        for(int i = 0;i < datasize; i++){
            if(i<n) tree[leaf+i] = a[i];
            que.push(leaf+i);
        }
        while(que.size()!=1){
            int l = que.front(); que.pop();
            int r = que.front(); que.pop();
            int p_v = tree[l]+tree[r];
            int p_id = l/2;
            tree[p_id] = p_v;
            que.push(p_id);
        }
    }
    //pos:変更の場所,0origin
    void update(int pos,T after){
        int now = leaf+pos;
        T before = tree[now];
        tree[now] = after;
        while(now!=0){
            now = (now-1)/2;
            tree[now] += (after-before);
        }
    }
    //l,r:queryで求める範囲 nl,nr:現在調査中の範囲
    T ans=0;
    void search(int now,int l,int r,int nl,int nr){
        //nl=0 nr = datasize-1 を入力(再起関数使うからやむを得ない)
        //範囲も葉の添え字と一致させるべき
        if(l>nr||r<nl) return;
        //l,rが範囲と全くかぶらない場合の処理
        if(l<nl) l = nl;
        if(r>nr) r = nr;
        //一部nl,nrと被っている時にはみ出ている部分を切り捨てる
        if(l==nl&&r==nr){
            //範囲が等しい時
            ans+=tree[now];
            return;
        }
        //それ以外は範囲縮小
        search(2*now+1,l,r,nl,(nl+nr)/2);
        search(2*now+2,l,r,(nl+nr)/2+1,nr);
    }
};
