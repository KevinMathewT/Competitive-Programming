#include <bits/stdc++.h>
#include <iostream>
#include <string>
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

ll a[32][32], b[32][32];

void blacken(ll x1, ll y1, ll x2, ll y2, ll aob){
	printf("Reached here to blacken %lld %lld %lld %lld\n", x1, y1, x2, y2);
	for(ll x=x1-1;x<=x2-1;x++)
		for(ll y=y1-1;y<=y2-1;y++)
			if(aob == 0)
				a[x][y]=1;
			else
				b[x][y]=1;

}

void generate(string& s, ll x1, ll y1, ll x2, ll y2, ll aob){
	std::cout << s << "\n";
	printf("Reached here for %lld %lld %lld %lld\n", x1, y1, x2, y2);
	if(s[0] == 'p'){
		s.erase(0, 1);
		generate(s, (x1+x2)/2, (y1+y2)/2, x2, y2, aob);
		generate(s, x1, (y1+y2)/2 , (x1+x2)/2, y2, aob);
		generate(s, x1, y1, (x1+x2)/2, (y1+y2)/2, aob);
		generate(s, (x1+x2)/2, y1, x2, (y1+y2)/2, aob);
		return;
	}
	else if(s[0] == 'f'){
		printf("Reached here to full %lld %lld %lld %lld\n", x1, y1, x2, y2);
		s.erase(0, 1);
		blacken(x1, y1, x2, y2, aob);
		return;
	}
	else{
		s.erase(0, 1);
		return;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	start_clock();

	ll n;
	read(n);
	char x;
	scanf("%c", &x);
	while(n--){
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		for(ll i=0;i<32;i++)
			for(ll j=0;j<32;j++){
				a[i][j]=0;
				b[i][j]=0;
			}
		generate(s1, 1, 1, 32, 32, 0);
		generate(s2, 1, 1, 32, 32, 1);
		for(ll i=31;i>0;i--){
			for(ll j=0;j<32;j++)
				printf("%lld ", a[i][j]);
			printf("\n");
		}
		printf("\n");
		printf("\n");
		printf("\n");
		for(ll i=31;i>0;i--){
			for(ll j=0;j<32;j++)
				printf("%lld ", b[i][j]);
			printf("\n");
		}
		ll c=0;
		for(ll i=31;i>0;i--){
			for(ll j=0;j<32;j++)
				if(a[i][j] == 1 || b[i][j] == 1)
					c++;
		}
		printf("\n%lld\n", c);
	}

	end_clock();
	return 0;
}