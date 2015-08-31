#include<stdio.h> 
#include<vector> 
#include<queue> 
#include<algorithm> 
using namespace std; 
#define MaxSize 20010 
int n,m,dis[MaxSize],from[MaxSize],s,e; 
vector< pair<int,int> > road[MaxSize]; 
priority_queue< pair<int,int> > pq; 
void input() 
{ 
    int i,tx,ty,tz; 
    scanf("%d%d",&n,&m); 
    for(i=1; i<=m; i++) 
    { 
        scanf("%d%d%d",&tx,&ty,&tz); 
        road[tx].push_back(make_pair(ty,tz)); 
    } 
    s=1; e=n; 
} 
void process() 
{ 
    int i,tmp_dis,tmp_pos; 
    fill(dis+1,dis+1+n,0x7fffffff); 
    dis[s]=0; 
    pq.push(make_pair(0,s)); 
    while(!pq.empty()) 
    { 
        tmp_dis=-pq.top().first; 
        tmp_pos=pq.top().second; 
        pq.pop(); 
        if(dis[tmp_pos]!=tmp_dis) continue; 
        for(i=0; i<road[tmp_pos].size(); i++) 
        { 
            if(dis[tmp_pos]+road[tmp_pos][i].second<dis[road[tmp_pos][i].first]) 
            { 
                from[road[tmp_pos][i].first]=tmp_pos; 
                dis[road[tmp_pos][i].first]=dis[tmp_pos]+road[tmp_pos][i].second; 
                pq.push(make_pair(-dis[road[tmp_pos][i].first],road[tmp_pos][i].first)); 
            } 
        } 
    } 
} 
void output() 
{ 
    int i,tmp_cnt=0,tmp_pos=e,ans[MaxSize]; 
    while(tmp_pos!=0) 
    { 
        ans[++tmp_cnt]=tmp_pos; 
        tmp_pos=from[tmp_pos]; 
    } 
    printf("%d\n",dis[e]); 
    for(i=tmp_cnt; i>=1; i--) 
    { 
        printf("%d\n",ans[i]); 
    } 
} 
int main() 
{ 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    input(); 
    process(); 
    output(); 
    return 0; 
}

