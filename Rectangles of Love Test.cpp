#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <cmath>
using namespace std;
typedef unsigned int uint;

#define FOR(k,a,b) for(uint k(a); k < (b); ++k)
#define REP(k,a) for(uint k=0; k < (a); ++k)

int main (int argc, char** argv) {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	int T;
	long long N, M, K;
	long long a, r, c, NM;
	long double full, lr, lc;
	scanf("%d",&T);
	assert(T>0 && T<6);
	while(T--)
	{
		scanf("%lld %lld %lld",&M,&N,&K);
		assert(N>0 && N<=1e7);
		assert(M>0 && M<=1e7);
		assert(K>0 && K<=1e5);
		NM = N;
		NM *=M;
		full = 0;
		REP(i,K)
		{
			scanf("%lld",&a);
			assert(a>0 && a<=NM);
			--a;
			printf("%lld\n", a);
			c = a % N;
			r = a / N;
			printf("%lld %lld\n", r, c);
			lr = (r+1)*(M-r);
			lc = (c+1)*(N-c);
			printf("%lld %lld\n", lr, lc);
			full += lr * lc;
		}

		printf("%.10Lf\n",full);
		full /= N + 1;
		full /= N;
		full /= M + 1;
		full /= M;
		full *= 4;
		fprintf(stderr,"%.10Lf\n",full);
		printf("%.10Lf\n",full);
	}
	return 0;
}