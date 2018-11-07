#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

typedef unsigned long long ull; 
  
ull nextSameSetBits(ull x){
  	ull a;
  	ull b;
  	ull c;
  	ull ret = 0;
  	if(x) 
  	{
    	a = x & -(signed)x;
    	b = x + a;
    	c = x ^ b;
    	c = (c)/a;
    	c >>= 2; 
    	ret = b | c;
  	}
  	return ret;
}

void te(){
	ll a, b, n;
	cin >> a >> b >> n;

	map<ll, map<ll, ll> > m;
	

	for(ll n=2;n<20;n++){
	for(ll b=1;b<=n/2;b++){

	ll ca = 0, cb = 0;
	a = n - b;	

	ll t = a;
	while(t > 0){
		if(t & 1 != 0)
			ca++;
		t >>= 1;
	}
		
	t = b;
	while(t > 0){
		if(t & 1 != 0)
			cb++;
		t >>= 1;
	}

	ll c = 0;

	ll start = (1 << ca) - 1;

	ll c2;

	ll count = 0;

	while(start > 0 && start <= n){
		count ++;
		c2 = __builtin_popcount(n - start);
		if(c2 == cb){
			// cout << start << " " << n - start << "\n";
			c++;
		}
		start = nextSameSetBits(start);
	}

	// cout << ca << " " << cb << "\n";

	// for(ll i=0;i<=n;i++){
	// 	ll c1 = 0, c2 = 0;
	// 	t = i;
 //    	c1 = __builtin_popcount(t);
		
	// 	t = n-i;
	// 	c2 = __builtin_popcount(t);

	// 	if(c1 == ca && c2 == cb)
	// 		cout << i << " " << c1 << " " << n-i << " " << c2 << "\n";
	// 	if(c1 == ca && c2 == cb)
	// 		c++;
	// }

	// cout << nextSameSetBits(7) << "\n";
	// cout << count << "\n";
	// cout << a << " " << b << " " << c << "\n";
	cout << c  << " ";
	}
	cout << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}