#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a,b,c,d,e,f;
    if(!(cin>>a>>b>>c>>d>>e>>f)) return 0;
    long long ab=a*b;
    long long day=ab*c;
    long long Tcur = f*ab + e*a + d;
    long long limit = min({a,b,c});
    long long best = day; // strictly positive and < day
    for(long long x=0;x<limit;++x){
        long long base = x*(a+1);
        long long q = base / ab; // floor(base/(ab))
        long long k0 = (x - q) % c; if(k0<0) k0 += c;
        long long Tx = base + ab * k0; // earliest time-of-day reaching hour=minute=second=x
        long long diff = (Tx - Tcur) % day; if(diff<0) diff += day; if(diff==0) diff = day;
        if(diff < best) best = diff;
    }
    cout << best << '\n';
    return 0;
}
