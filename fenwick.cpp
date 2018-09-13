#include <iostream>
using namespace std;
const int maxn= 1e6+9;
long long  fen[maxn];
long long a[maxn];
int N;
void add(int x,int dv){
	while(x<=N){
		fen[x]+=dv;
		x += x&(-x);
	}
}

long long getsum(int x){
	long long ac=0;
	while(x>0){
		ac += fen[x];
		x -= x&(-x);
	}
	return ac;
}

int main(){
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>a[i];
		add(i,a[i]);
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<getsum(r)-getsum(l-1)<<endl;
	}
	return 0;
}

