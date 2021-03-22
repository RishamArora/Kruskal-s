
#include<algorithm>
#include<iostream>
using namespace std;

struct edge
{
    int wt;
    int u;
    int v;
};
bool myComp(edge a,edge b)
{
    return a.wt<b.wt;
}
int find_parent(int u,int parent[])
{
    if(u==parent[u])
        return u;
    return find_parent(parent[u],parent);
}
bool take_edge(edge e,int parent[])
{
    int p1=find_parent(e.u,parent);
    int p2=find_parent(e.v,parent);
    if(p1==p2)
        return false;
    parent[p1]=p2;
    return true;
}
void Kruskal(edge ar[],int n,int e)
{
    int count=0;
    edge output[n-1];
    int parent[n];
    for(int i=0;i<n;i++)
        parent[i]=i;
    int i=0;
    int j=0;
    while(count!=n-1)
    {
        if(take_edge(ar[i],parent))
        {
            count++;
            output[j]=ar[i];
            j++;
        }
        i++;
    }
    for(int i=0;i<n-1;i++)
        cout<<min(output[i].u,output[i].v)<<" "<<output[i].u+output[i].v-min(output[i].u,output[i].v)<<" "<<output[i].wt<<endl;
}
int main()
{
    int V,E;
    cin >> V >> E;
    edge ar[E];
    for(int i=0;i<E;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        ar[i].u=u;
        ar[i].v=v;
        ar[i].wt=wt;
    }
    sort(ar,ar+E,myComp);
    Kruskal(ar,V,E);
}

