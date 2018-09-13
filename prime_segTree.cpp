#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6+9;
const int inf = 1e9+9;
class  prime_segTree{
	public:
	int Gap,n;
    struct node{
		long long sum;
		int max,min;
        node(int x=0,int y=-inf,int z=inf):sum(x),max(y),min(z){}
    };
    
    vector<node> tr;
    void initial(){
        scanf("%d",&n);
        for(Gap=1; Gap<n; Gap<<=1);
		for(int i=1; i<=2*Gap; i++) tr.push_back(node());
    }
    
    void up(int i){
        i>>=1;
        if(i){
            tr[i].sum = tr[i<<1].sum+tr[i<<1|1].sum;
            tr[i].max = max(tr[i<<1].max,tr[i<<1|1].max);
            tr[i].min = min(tr[i<<1].min,tr[i<<1|1].min);
            up(i);
        }
        
    }
    void insert(int pos,int val){
        pos = pos-1+Gap;
        tr[pos].sum = tr[pos].max = tr[pos].min = val;
        up(pos);
    }
    
    node get_data(int i,int l,int r,int ql,int qr){
        int mid = (l+r)>>1;
        node ac;
        if(ql<=l&&r<=qr){
            ac.sum = tr[i].sum, ac.max = tr[i].max, ac.min = tr[i].min;
            
        }
        else if(r<ql||l>qr){}
        else{
            node ac1 = get_data(i<<1,l,mid,ql,qr);
            node ac2 = get_data(i<<1|1,mid+1,r,ql,qr);
            ac.sum = ac1.sum+ac2.sum;
            ac.max = max(ac1.max,ac2.max);
            ac.min = min(ac1.min,ac2.min);
            
        }
        return ac;
    }

	node query(int l,int r){
		return get_data(1,1,Gap,l,r);
	}
};


int main(){
	prime_segTree sgT;
	sgT.initial();
	int n = sgT.n;
	for(int i=1; i<=n; i++){
		sgT.insert(i,0);
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==0){
			sgT.insert(x,y);
		}
		else{
			prime_segTree::node ac = sgT.query(x,y);
			printf("%lld\n",ac.sum-ac.max-ac.min);
		}
	}
    return 0;
}

