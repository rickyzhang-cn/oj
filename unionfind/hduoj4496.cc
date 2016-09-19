#include <cstdio>
#include <cstring>

const int max_n=10005;
const int max_m=100005;

int uf[max_n];
int edge[max_m][2];
int result[max_m];
int m,n;

int _find(int t) {
    return uf[t]==t ? t : uf[t]=_find(uf[t]);
}

int _union(int a,int b) {
    int pa=_find(a);
    int pb=_find(b);

    if(pa != pb) {
        uf[pb]=pa;
        return 1;
    }
    return 0;
}

int main() {
    //freopen("4496.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2) {
        for(int i=0;i<n;i++) uf[i]=i;
        for(int i=0;i<m;i++) {
            scanf("%d%d",&edge[i][0],&edge[i][1]);
        }
        int cnt=n;
        result[m-1]=cnt;
        for(int i=m-2;i>=0;i--) {
            cnt-=_union(edge[i+1][0],edge[i+1][1]);
            result[i]=cnt;
        }
        for(int i=0;i<m;i++) {
            printf("%d\n",result[i]);
        }
    }
}
