#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1000001;
int sieve[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] < N; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}

int main(){
	getSieve();
	int x, y, T = 1;
	while(sd2(x,y) == 2){
		if(x == 0 and y == 0) break;
		
		map<int, int> cnt;
		while(x > 1){
			cnt[sieve[x]]++;
			x /= sieve[x];
		}
		
		while(y > 1){
			cnt[sieve[y]]--;
			y /= sieve[y];
		}
		
		int x = cnt.size();
		int d = 0; foreach(it, cnt) d += abs(it->se);
		printf("%d. %d:%d\n", T++, x, d);
	}
	return 0;
}
