#include <cstdio>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

int maze[10][10];
int visited[10][10];

struct Node {
    int r,c;
    Node() {}
    Node(int r,int c) : r(r),c(c) {}
} pre[10][10];


void bfs() {
    memset(visited,0,sizeof(visited));
    int dr[]={-1,1,0,0}; //up down left right
    int dc[]={0,0,-1,1};
    queue<Node> Q;
    visited[0][0]=1;
    Q.push(Node(0,0));
    while(!Q.empty()) {
        Node node=Q.front();Q.pop();
        int r=node.r,c=node.c;
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<5&&nc>=0&&nc<5&&!visited[nr][nc]&&!maze[nr][nc]) {
                visited[nr][nc]=1;
                Q.push(Node(nr,nc));
                pre[nr][nc]=Node(r,c);
                if(nr==4&&nc==4) return;
            }
        }
    }
}

int main() {
    for(int i=0;i<5;i++) 
        for(int j=0;j<5;j++)
            scanf("%d",&maze[i][j]);
    bfs();
    stack<Node> S;
    int cur_r=4,cur_c=4;
    while(true) {
        S.push(Node(cur_r,cur_c));
        if(!cur_r && !cur_c) break;
        Node node=pre[cur_r][cur_c];
        cur_r=node.r,cur_c=node.c;
    }
    while(!S.empty()) {
        Node node=S.top();S.pop();
        printf("(%d,%d)\n",node.r,node.c);
    }
    return 0;
}
