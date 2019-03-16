#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[50010];

ll isPrime(ll x){
	ll c = 0;

	for(ll i=1;i*i<=x;i++)
		if(x % i == 0)
			c++;

	if(c == 1)
		return 1;
	else
		return 0;
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a+n);
	ll last_sum;
	ll sum = last_sum = accumulate(a, a+n, 0);
	// cout << sum << " " << last_sum << "\n";
	ll point = n-1;
	while(point > 0){
		sum = last_sum;
		// cout << sum << " "<< last_sum << "\n";
		ll last = a[point];
		while(isPrime(last)){
			point--;
			last = a[point];
		}

		if(point < 1)
			break;

		ll first = a[0];
		ll flag = 0;
		// cout << first << " " << last << " " << point << "\n";
		for(ll i=2;i*i<=last;i++){
			if(last % i == 0 && first < i){
				flag = 1;
				sum -= last;
				sum += last / i;
				a[point] = last / i;
				sum -= first;
				sum += first * i;
				a[0] = first * i;
				break;
			}
		}

		// for(ll i=0;i<n;i++)
			// cout << a[i] << " ";
		// cout << sum << " "<< last_sum << "\n";

		// cout << "\n";
		if(flag == 0)
			break;

		last_sum = sum;
		sort(a, a+n);
	}

	cout << last_sum << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}