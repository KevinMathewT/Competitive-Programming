#include <bits/stdc++.h>
#include <iostream>
#include <vector>

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

 
void createSegTree(vector<long long> &segTree,vector<long long> &arr,long long left,long long right,long long counter){
	
	if(left == right){
		segTree[counter] = arr[left];
	}
	else{
		long long mid = (left + right) >> 1;
		createSegTree(segTree,arr,left,mid,2*counter);
		createSegTree(segTree,arr,mid+1,right,2*counter+1);
		segTree[counter] = max(segTree[2*counter],segTree[2*counter+1]);
	}
}
 
void update(vector<long long> &segTree,vector<long long> &lazy,long long ql,long long qr,long long value,long long left,long long right,long long counter){
	
	if(lazy[counter] != 0){
		
		segTree[counter] = segTree[counter] + lazy[counter];
		if(left != right){
			
			lazy[2*counter] += lazy[counter];
			lazy[2*counter +1] += lazy[counter];
		}
		lazy[counter] = 0;
	}	
	
	if(left > qr || right < ql){
		
		return;
	}
	if(left >= ql && right <= qr){
		
		segTree[counter] = segTree[counter] + value;
		if(left != right){
			
			lazy[2*counter] += value;
			lazy[2*counter + 1] += value;
		}
		return;
	}
	long long mid = (left + right) >> 1;
	update(segTree,lazy,ql,qr,value,left,mid,2*counter);
	update(segTree,lazy,ql,qr,value,mid+1,right,2*counter+1);
	segTree[counter] = max(segTree[2*counter],segTree[2*counter+1]);
}
 
long long query(vector<long long> &segTree,vector<long long> &lazy,long long ql,long long qr,long long left,long long right,long long counter){
	
	if(lazy[counter] != 0){
		segTree[counter] = segTree[counter] + lazy[counter];
		if(left != right){
			
			lazy[2*counter] += lazy[counter];
			lazy[2*counter +1] += lazy[counter];
		}
		lazy[counter] = 0;
	}
	
	if(left > qr || right < ql){
		
		return INT_MIN;
	}
	if(left >= ql && right <= qr){
		
		return segTree[counter];
	}
	long long mid = (left + right) >> 1;
	return max(query(segTree,lazy,ql,qr,left,mid,2*counter) , query(segTree,lazy,ql,qr,mid+1,right,2*counter+1));
}
 
int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	
	long long n,q;
	cin >> n;
	
	vector<long long> arr(n+1),segTree(6*n,0LL),lazy(6*n,0LL);
	
	for(long long i=1;i<=n;i++){
		
		cin >> arr[i];
	}
	read(q);
	
	createSegTree(segTree,arr,1LL,n,1LL);
	
	while(q--){
		
		char ch;
		cin >> ch;
		
		if(ch == '1'){
			
			long long ql,qr,value;
			cin >> ql >> qr >> value;
			
			update(segTree,lazy,ql,qr,value,1LL,n,1LL);
		}
		else{
			
			long long qr;
			cin >> qr;
			ll ans = query(segTree,lazy,qr-1,n-1,1LL,n,1LL);
			if(ans == query(segTree, lazy, qr-1, qr, 1LL, n, 1LL))
				cout << "WOW" << "\n";
			else
				cout << ans << "\n";
		}
	}
	end_clock();
}