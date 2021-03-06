#include<bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)
#define mkp make_pair
#define dpr(v) cout << #v"=" << v << endl //;)
#define dpra(a,n) { forn(i,(n)) cout << (a)[i] << (i==(n)-1?'\n':' '); }
#define dprv(vec) dpra(vec,sz(vec))
typedef vector<int> vi;

class UnionFind{
private: vector<int> p,rank,setSizes;
		int numSets;
public:
	UnionFind(int N){
		numSets=N;
		rank.assign(N,0);
		p.assign(N,0);
		setSizes.assign(N,1);
		for(int i=0;i<N;i++) p[i]=i;
	}
	int findSet(int i){
		return (p[i]==i)?i:(p[i]=findSet(p[i]));
	}
	bool isSameSet(int i,int j){
		return findSet(i)==findSet(j);
	}
	void unionSet(int i,int j){
		if(!isSameSet(i,j)){
			int x=findSet(i),y=findSet(j);
			if(rank[x]>rank[y]) p[y]=x;
			else{
				p[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
			}
			numSets--;
		}
	}
	int numDisjointSet(){
		return numSets;
	}
	int setSize(int i){
		return setSizes[findSet(i)];
	}
};

/*
struct UnionFind{
	vector<int> f;
	void init(int n){
		f.clear(); f.insert(f.begin(),n,-1);
	}
	int comp(int x){
		return (f[x]==-1?x:f[x]=comp(f[x]));//O(1)
	}
	bool join(int i,int j){
		bool con=comp(i)==comp(j);
		if(!con)f[comp(i)]=comp(j);
		return con;
	}
};*/

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//freopen("input.txt","r",stdin);
	int n,m,a,b,tc=1;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		UnionFind uf(n);
		for(int i=0;i<m;i++){
			cin>>a>>b;
			a--;b--;
			uf.unionSet(a,b);
		}
		printf("Case %d: %d\n",tc++,uf.numDisjointSet() );
	}	
	return 0;
}