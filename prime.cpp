//数nの一番小さな素因数を返す関数
//エラトステネスのふるいで数n以下の数の素因数の種類数を配列に入れる関数

#include<cmath>

int prime[10000001];
long long smallest_prime_number(long long n){
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0) return i;
    }
    return n;
}

int erat[10000001];
void eratosthenes(long long n){
    for(int i=2;i<=n;++i){
        if(erat[i]) continue;
        int now=i;
        for(int j=1;j*now<=n;++j){
            ++erat[j*now];
        }
    }
}
