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
using namespace std;
using ll = long long;
//狭義最長増加部分列の値を求める
struct lis{
    ll LEN = 0;
    vector<ll> dp, L;
    //dp:iまでで作られるlisの値
    //L:長さiのisの最後尾の数の最小値
    lis(ll n){
        dp = vector<ll>(n);
        L = vector<ll>(n+1, 1LL<<60);
    }

    int binary_search(int left,int right,ll target){
        if(left+1>=right) return left;
        int middle = (left+right)/2;
        if(L[middle]<target) left = middle;
        else right = middle;
        return binary_search(left,right,target);
    }

    void make_lis(vector<ll> &a){
        for(int i=0;i<a.size();++i){
            if(i==0) {
                dp[i] = 1;
                L[1] = a[i];
                L[0] = 0;
            }
            else{
                int target = a[i];
                int max_id = binary_search(-1,i+1,target);
                dp[i] = max_id+1;
                if(L[dp[i]]==(1LL<<60)||L[dp[i]]>a[i]) L[dp[i]] = a[i];
            }
            LEN = max(LEN,dp[i]);
            // cout << dp[i] << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    lis l(n);
    vector<ll> a(n);
    for(int i = 0;i<a.size();i++){
        cin >> a[i];
    }
    l.make_lis(a);
    cout << l.LEN << endl;
}