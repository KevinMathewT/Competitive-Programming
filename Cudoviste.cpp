#include <bits/stdc++.h>
#include <iostream>
#include <vector>
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
void read(ll &x){
	scanf("%lld",&x);
}
void read(ll &x,ll &y){
	scanf("%lld%lld",&x,&y);
}
void read(ll &x,ll &y,ll &z){
	scanf("%lld%lld%lld",&x,&y,&z);
}
void read(ll &x,ll &y,ll &z,ll &w){
	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
}
clock_t t_start,t_end;
void start_clock(){
	t_start = clock();
}
void end_clock(){
	t_end = clock();
	ld timeis = t_end - t_start;
    printf("\n\nTime taken : %f s", ((float)timeis)/CLOCKS_PER_SEC);
}

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll r, c;
	read(r, c);
	char a[r][c];

	for(ll i=0;i<r;i++){
		char ch;
		scanf("%c", &ch);
		for(ll j=0;j<c;j++){
			scanf("%c", &a[i][j]);
		}
	}

	ll c1=0, c2=0, c3=0, c4=0, c5=0;
	for(ll i=0;i<r-1;i++)
		for(ll j=0;j<c-1;j++){
			ll hash=0, X=0, dot=0;
			for(ll k=0;k<2;k++)
				for(ll l=0;l<2;l++)
					if(a[i+k][j+l]=='#')
						hash++;
					else if(a[i+k][j+l]=='X')
						X++;
					else
						dot++;
			if(hash>0) continue;
			if(X==0)c1++;
			if(X==1)c2++;
			if(X==2)c3++;
			if(X==3)c4++;
			if(X==4)c5++;
		}

	printf("%lld\n", c1);
	printf("%lld\n", c2);
	printf("%lld\n", c3);
	printf("%lld\n", c4);
	printf("%lld\n", c5);

	end_clock();
	return 0;
}