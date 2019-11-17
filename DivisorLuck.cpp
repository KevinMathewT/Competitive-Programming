#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll l1, r1, l2, r2, sieve[2000010];
vector<ll> facts;

ll getSum(ll x){
    if(x == 1)
        return 1;
    if(x == 0)
        return 0;

    facts.clear();

    ll sum = 1;

    ll t = x;
    while(t > 1){
        facts.push_back(sieve[t]);
        t /= sieve[t];
    }

    // facts.push_back(1);

    sort(facts.begin(), facts.end());

    // for(ll i=0;i<facts.size();i++)
    //     cout << facts[i] << " ";
    // cout << "\n";

    ll c = 1;

    for(ll i=0;i<facts.size();i++){
        if(i != (facts.size() - 1) && facts[i] == facts[i+1]){
            c++;
            continue;
        }

        sum = sum * ((pow(facts[i], c + 1) - 1) / (facts[i] - 1));
    }

    // cout << x << " " << sum << "\n";
    return sum;
}

void solve(){
	for(ll i=0;i<2000010;i++)
		sieve[i] = i;
	sieve[0] = 0;
	sieve[1] = 0;

	for(ll i=2;i*i<=2000010;i++)
		if(sieve[i] == i)
			for(ll j=i*i;j<=2000010;j+=i)
				sieve[j] = i;

	// for(ll i=0;i<100;i++)
	// 	cout << sieve[i] << "\n";

	cin >> l1 >> r1 >> l2 >> r2;

	vector<ll> Av, Bv;
	ll totA = 0, totB = 0;

	for(ll i=l1;i<=r1;i++){
		getSum(i);
	}

	// for(ll i=l2;i<=r2;i++){
	// 	Bv.push_back(getSum(i));
	// }

	// for(ll i=0;i<Av.size();i++){
	// 	// cout << (lower_bound(Bv.begin(), Bv.end(), Av[i]) - Bv.begin()) << "\n";
	// 	// totA += max((ll)0, ((lower_bound(Bv.begin(), Bv.end(), Av[i]) - Bv.begin()) - 1));
	// }

	// for(ll i=0;i<Bv.size();i++){
	// 	totB += max((ll)0, ((lower_bound(Av.begin(), Av.end(), Bv[i]) - Av.begin()) - 1));
	// }

	if(totB > totA)
		cout << "B";
	else if(totA > totB)
		cout << "A";
	else
		cout << "Draw";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}