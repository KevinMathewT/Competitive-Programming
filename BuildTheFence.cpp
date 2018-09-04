#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())

void read(ll &x){
	cin >> x;
}
void read(ll &x,ll &y){
	cin >> x >> y;
}
void read(ll &x,ll &y,ll &z){
	cin >> x >> y >> z;
}
void read(ll &x,ll &y,ll &z,ll &w){
	cin >> x >> y >> z >> w;
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

bool IsOdd(ll n){ return n % 2 == 1; }

struct Point{
	ll x;
	ll y;
};

Point p0;

ll dist(Point a, Point b){
	return abs((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

ll orientation(Point p, Point q, Point r){
	ll val = (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);
	if(val == 0) return 0;
	if(val > 0) return 1;
	return 2;
}

int compare(Point a, Point b){
	ll o = orientation(p0, a, b);
	if(o == 0) return dist(a, p0) > dist(b, p0) ? 1 : -1;
	return (o == 2) ? -1 : 1;
}

void te(){

	ll n;
	read(n);
	Point p[n];
	for(ll i=0;i<n;i++)
		read(p[i].x, p[i].y);

	// for(ll i=0;i<n;i++)
	// 	cout << p[i].x << " " << p[i].y << "\n";
	
	if(n == 1){
		cout << "Woah0.00\n1\n\n";
		return;
	}


	map<ll, map<ll, ll> > mp;
	Point min;
	min.x = p[0].x;
	min.y = p[0].y;
	ll minpos = 0;
	for(ll i=0;i<n;i++)
		mp[p[i].x][p[i].y] = i + 1;

	for(ll i=1;i<n;i++){
		if(p[i].y < min.y ||(p[i].y == min.y && p[i].x < min.x)){
			min.x = p[i].x;
			min.y = p[i].y;
			minpos = i;
		}
	}

	Point temp = p[0];
	p[0] = p[minpos];
	p[minpos] = temp;
	p0.x = p[0].x;
	p0.y = p[0].y;
	for(ll i=0;i<n;i++)
		cout << p[i].x << " " << p[i].y << "\n";

	cout << p0.x << " - " << p0.y << "\n";
	sort(p, p+n, compare);
	for(ll i=0;i<n;i++)
		cout << p[i].x << " " << p[i].y << "\n";

	ll m = 1;
	for(ll i=1;i<n;i++){
		while(i < n-1 && orientation(p[0], p[i], p[i+1]) == 0)
			i++;
		p[m++] = p[i];
	}

	if(m < 3){
		cout << "0.00\n1\n\n";
		return; 
	}

	cout << fixed << setprecision(2);

	double peri = 0;
	for(ll i=0;i<m;i++)
		peri += sqrt(dist(p[i], p[(i+1)%m]));
	cout << peri << "\n";
	for(ll i=0;i<m;i++)
		cout << mp[p[i].x][p[i].y] << " ";
	cout << "\n\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll t;
	read(t);
	while(t--) te();

	end_clock();							//This too.
	return 0;
}