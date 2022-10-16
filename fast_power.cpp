//繰り返し二乗法によってnのm乗を高速に計算する
//適宜modを取る
//modを取るやつは10^18乗でも計算できる
#define mod 1000000007
long long power_mod(long long n, long long m){
    if(m==0) return 1;
    if(m==1) return n;
    if(m%2==1) return (power_mod(n,m-1)*(n%mod))%mod;
    long long tmp = power_mod(n,m/2);
    return (tmp*tmp)%mod;
}

double power_double(double n, int m){
    if(m==0) return 1;
    if(m==1) return n;
    if(m%2==1) return (power_double(n,m-1)*power_double(n,1));
    else return (power_double(n,m/2)*power_double(n,m/2));
}

long long power(long long n, long long m){
    if(m==0) return 1;
    if(m==1) return n;
    if(m%2==1) return (power(n,m-1)*power(n,1));
    else return (power(n,m/2)*power(n,m/2));
}