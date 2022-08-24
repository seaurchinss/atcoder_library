//マンハッタン距離からチェビシェフ距離に変換する関数
//マンハッタン距離の最大値をO(1)で求められる

#include<cmath>
#include<algorithm>
struct point{
    long long x,y;
};
point manhattan_to_chebyshev(point x){
    point new_p;
    new_p.x=x.x+x.y;
    new_p.y=x.x-x.y;
    return new_p;
}
long long calculate_ChebyshevDistance(point x,point y){
    return std::max(abs(x.x-y.x),abs(x.y-y.y));
}
