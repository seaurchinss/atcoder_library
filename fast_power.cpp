//最小二乗法によってnのm乗を高速に計算する
//適宜modを取る
#define mod 1000000007
long long power(long long n, long long m){
    if(m==1) return n;
    if(m%2==1) return (power(n,m-1)*power(n,1))%mod;
    else return (power(n,m/2)*power(n,m/2))%mod;
}