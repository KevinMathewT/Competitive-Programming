#include<iostream>
#include<cmath>
#include<assert.h>
#include<cstdio>
using namespace std;

#define LL long long
#define MX 2000000
double fall;
LL n, t1, t2;
double dp  [2000006];

int main (){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	cin>>n>>fall;
	cin>>t1>>t2;

	if (n > MX) n = MX;

	dp [n] = pow (n, -fall);
	for (int i=n-1;i>0;--i){
		dp [i] = 0;
		if (i+t1+t2 <= MX) dp [i] += pow (i, -fall) * (1 + dp [i+t1+t2]);
		if (i+t1 <= MX) dp [i] += ((double)1 - pow (i, -fall)) * dp [i+t1];
	}
	printf ("%.10lf ", dp[1]);
	cin>>n;
	return 0;
}