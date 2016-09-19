#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    int r,c;
    int dir;
    int dist;
    Node(int r,int c,int dir,int dist):r(r),c(c),dir(dir),dist(dist) {}
};

int m,n;
const int MAXN=110;
char maze[MAXN][MAXN];
int visited[MAXN][MAXN];
int dists[MAXN][MAXN];
int K,sr,sc,er,ec;

bool bfs() {
    memset(visited,0,sizeof(visited));
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    queue<Node> Q;
    for(int i=0;i<4;i++) {
        int nr=sr+dr[i];
        int nc=sc+dc[i];
        if(nr>=0&&nr<m&&nc>=0&&nc<n&&maze[nr][nc]=='.') {
            if(nr==er&&nc==ec) return true;
            visited[nr][nc]=1;
            dists[nr][nc]=0;
            Q.push(Node(nr,nc,i,0));
        }
    }
    while(!Q.empty()) {
        Node node=Q.front();Q.pop();
        int r=node.r,c=node.c,dir=node.dir,dist=node.dist;
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dr[i];
            int ndist=dist+(dir==i?0:1);
            if(ndist>K) continue;
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&maze[nr][nc]=='.') {
                if(nr==er&&nc==ec) return true;
                if(visited[nr][nc]&&ndist>=dists[nr][nc]) continue;
                visited[nr][nc]=1;
                dists[nr][nc]=ndist;
                Q.push(Node(nr,nc,i,ndist));
            }

        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%c",&maze[i][j]);
        scanf("%d %d %d %d %d",&K,&sc,&sr,&ec,&er);
        sc--,sr--,ec--,er--;
        if(bfs()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
