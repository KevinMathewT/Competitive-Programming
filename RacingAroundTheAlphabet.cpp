#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
# define M_PI           3.14159265358979323846  /* pi */
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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//start_clock();

	std::map<char, float> mp;
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['E']=5;
	mp['F']=6;
	mp['G']=7;
	mp['H']=8;
	mp['I']=9;
	mp['J']=10;
	mp['K']=11;
	mp['L']=12;
	mp['M']=13;
	mp['N']=14;
	mp['O']=15;
	mp['P']=16;
	mp['Q']=17;
	mp['R']=18;
	mp['S']=19;
	mp['T']=20;
	mp['U']=21;
	mp['V']=22;
	mp['W']=23;
	mp['X']=24;
	mp['Y']=25;
	mp['Z']=26;
	mp[' ']=27;
	mp['\'']=28;
	ll n;
	read(n);
	char c;
	scanf("%c", &c);
	while(n--){
		string s="";
		getline(cin, s);
		double t = M_PI/7;
		double tot = 0;
		for(ll i=0;i<s.length()-1;i++){
			tot += min(abs(mp[s[i]]-mp[s[i+1]]), (28-abs(mp[s[i]]-mp[s[i+1]])))*t+1;
		}
		printf("%0.10lf\n", tot+1);
	}

	//end_clock();
	return 0;
}