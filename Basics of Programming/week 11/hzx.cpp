#include <stdio.h>
#include <stdlib.h>
int rank[1010];

int cmp(const void *e1,const void *e2)
{
    int a=*(int *)e1;
    int b=*(int *)e2;
    if(rank[a]<rank[b]) return -1;
    if(rank[a]>rank[b]) return 1;
    return 0;
}
int main()
{
    int num[15],rank[1010],choice[1010][15],id[1010],place[1010];
    char name[1010][15];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&num[i]);
    for(int i=0;i<n;i++){
        id[i]=i;
        scanf("%s%d",name[i],&rank[i]);
        for(int j=0;j<m;j++) scanf("%d",&choice[i][j]);
    }
    qsort(id,n,sizeof(int),cmp);
    for(int cnt=0;cnt<m;cnt++){
        for(int i=0;i<n;i++){
            if(place[id[i]]==0&&num[choice[i][cnt] - 1]>0){
                //printf("%d %s",choice[id[i]][cnt],name[id[i]]);
                place[id[i]]=choice[id[i]][cnt];
                num[choice[id[i]][cnt]- 1]--;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%s %d\n",name[id[i]],place[id[i]]);
    return 0;
}