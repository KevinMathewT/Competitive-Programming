#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll getToSingle(ll n){
	if(n < 10) return 0;
	ll c = 0;
	ll sum = 0;
	ll t = n;
	while(true){
		t = n;
		sum = 0;
		while(t > 0){
			sum += t % 10;
			t /= 10;
		}
		c++;
		n = sum;
		if(sum < 10) break;
	}
	return c;
}

ll getSumOfDigits(ll n){
	ll t = n, sum = 0;
	while(t > 0){
		sum += t % 10;
		t /= 10;
	}
	return sum;
}

void te(){
	ll n, d;
	cin >> n >> d;

	ll a, b, mina = LLONG_MAX, minn = LLONG_MAX;
	ll lim = 20;
	ll t = n;
	ll j;

	for(ll i=0;i<lim;i++){
		if(n == 0) a = 0;
		else if(n % 9 == 0) a = 9;
		else a = n % 9;

		if(a == mina)
			break;

		if(a < mina){
			j = i;
			mina = a;
			minn = n;
		}

		if(LLONG_MAX - n < d)
			break;
		// cout << n << " " << a << "\n";
		n += d;
	}
	n = t;

	queue<pair<ll, ll> > q;

	q.push(make_pair(n, 0));
	while(!q.empty()){
		pair<ll, ll> p = q.front();
		//cout << p.first << "\t" << p.second << "\n";
		q.pop();

		if(p.first == mina){
			cout << mina << " " << p.second << "\n";
			break;
		}

		q.push(make_pair(getSumOfDigits(p.first), p.second+1));
		q.push(make_pair(p.first+d, p.second+1));
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