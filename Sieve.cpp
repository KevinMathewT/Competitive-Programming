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

vector<int> primesum(int A) {
    long long int sieve[A+1];
    for(long long int i=1;i<=A;i++)
        sieve[i] = 1;
    
    for(long long int i=2;i*i<=A;i++)
        if(sieve[i] == 1)
            for(long long int j=i*i;j<=A;j+=i)
                sieve[j] = 0;

    // for(ll i=0;i<=A;i++)
    // 	cout << i << " - " << sieve[i] << "\n";
    sieve[0] = sieve[1] = 0;
    for(long long int i=2;i<=A;i++)
        if(sieve[i] == 1 && sieve[A-i] == 1){
        	// cout << i << " " << A-i << "\n";
            vector<int> ret;
            ret.push_back(i);
            ret.push_back(A-i);
            return ret;
        }
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	vector<int> a = primesum(996);
	cout << a[0] << " " << a[1] << "\n";

	return 0;
}