#include <stdio.h>
#include <math.h>
using namespace std;
const int _ = 1000, __ = 1e9 + 7;
typedef long long ll;
ll f[_ + 1], d[_ + 1];
int main()
{f[0]=1;for (int i=1; i<=_; i++){f[i]=(f[i-1]*i)%__;d[i]=(((i*d[i - 1])%__)+(((i/2)*f[i-1])%__))%__;}int a; scanf("%d",&a);for(int b=1; b<=a; b++){ll n;scanf("%lld",&n);printf("#%d %lld\n",b,d[n]);}return 0;}