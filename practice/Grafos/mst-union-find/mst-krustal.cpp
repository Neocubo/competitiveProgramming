#include <bits/stdc++.h>
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
typedef vector<int> vi;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)
#define mkp make_pair
#define dpr(v) cout << #v"=" << v << endl //;)
#define dpra(a,n) { forn(i,(n)) cout << (a)[i] << (i==(n)-1?'\n':' '); }
#define dprv(vec) dpra(vec,sz(vec))

struct UnionFind{
	vector<int> f;
	void init(int n){f.clear();f.insert(f.begin(),n,-1);}
	int comp(int x){return f[x]==-1?x:f[x]=comp(f[x]);}
	bool join(int i,int j){
		bool con=comp(i)==comp(j);
		if(!con)f[comp(i)]=comp(j);
		return con;
	}
};

struct Ar{int a,b,w;};
bool operator<(const Ar &a,const Ar &b){return a.w<b.w;};

vector<Ar> E;
UnionFind uf;
int n,m;

ll kruskal(){
	ll cost=0;
	sort(E.begin(),E.end());
	uf.init(n);
	for(auto x:E){
		if(uf.comp(x.a)!=uf.comp(x.b)){
			uf.join(x.a,x.b);
			cost+=x.w;
		}
	}
	return cost;
}

int main() {
	cin>>n>>m;
	forn(i,m){
		Ar aux;
		cin>>aux.a>>aux.b>>aux.w;
		E.pb(aux);
		//cout<<E[i].a<<E[i].b<<E[i].w;
	}
	cout<<kruskal();
    return 0;
}
