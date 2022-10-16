//aCbの値をmodで割ったあまりを出力する

#include<iostream>
#define mod 1000000007
long long power_mod(long long n, long long m){
    if(m==0) return 1;
    if(m==1) return n;
    if(m%2==1) return (power_mod(n,m-1)*(n%mod))%mod;
    long long tmp = power_mod(n,m/2);
    return (tmp*tmp)%mod;
}
long long aCb(long long a,long long b){
    long long numer=1,denom=1;
    for(int i = 1;i<=a;i++){
        numer*=i;
        numer%=mod;
    }
    for(int i = 1;i<=b;i++){
        denom*=i;
        denom%=mod;
    }
    for(int i = 1;i<=a-b;i++){
        denom*=i;
        denom%=mod;
    }
    denom=power_mod(denom,mod-2);
    return (numer*denom)%mod;
}

int main(){
    int a,b;
    std::cin >> a >> b;
    std::cout << aCb(a,b) << std::endl;
}