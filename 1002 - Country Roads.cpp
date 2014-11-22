#include<bits/stdc++.h>

using namespace std;


#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define sc scanf
#define pf printf
#define mem(a,val) memset(a,val,sizeof(a))
#define rep(s,n) for(long i=s; i<=n;i++)
#define pb push_back
#define ll long long
#define pi (2*acos(0.0))
#define mx 35000
#define ssc sscanf
#define FOR(val,n) for(long i=val;i<=n;i++)
#define FORL(val,n) for(long i=val;i<n;i++)
#define PQ priority_queue
/*bool prime[mx+5];
vector<long>v;

void sieve()
{
    for(long i=4;i<=mx; i=i+2)
    prime[i]=1;

    for(long i=3; i*i<=mx;i=i+2)
    {
        if(prime[i] == 0)
        {
            for(long j=2*i; j<=mx; j=i+j)
            prime[j]=1;
        }
    }


    v.pb(2);
    for(long i=3;i<=mx;i=i+2)
    {
        if(prime[i]==0)
        v.pb(i);
    }
}*/

struct loc{

    long u,idx;
};

struct info{

    long u,w;
    info(long a,long b){
        u = a;
        w = b;
    }
    bool operator<(const info&p)const{
        return w>p.w;
    }
};

vector<long>graph[505],weight[505];

long d[505];
long par[505];

long dijkastra(long src,long dest){

    mem(d,1);
    //long ret = -10;
    mem(par,-1);
    //cout<<"BUG "<<d[0]<<endl;
    PQ<info> p_q;

    //info temp;
    //temp.w = 0;
    //temp.u = src;

    p_q.push(info(src,0));


    d[src] = 0;

    while(!p_q.empty()){


        info top = p_q.top();
        p_q.pop();
        long u = top.u;

        if(u == dest)
        return d[dest];

        for(long i=0;i<(int)graph[u].size();i++){

            long v = graph[u][i];

            if(d[u]+weight[u][i] < d[v])
            {
                d[v] = d[u]+weight[u][i];
                par[v] = u;
                //par[v] = i;
                p_q.push(info(v,d[v]));
            }
        }
    }
    return -1;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    long t,kase = 1;
    sc("%ld",&t);

    while(t--){

        long n,m;

        sc("%ld %ld",&n,&m);

        FOR(1,n)
        {
            graph[i].clear();
            weight[i].clear();
        }

        FOR(1,m){


            long u,v,w;
            sc("%ld %ld %ld",&u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            weight[u].pb(w);
            weight[v].pb(w);
        }


        long tar;

        sc("%ld",&tar);


        pf("Case %ld:\n",kase++);

        FORL(0,n){


            long ans = dijkastra(tar,i);

            if(ans == -1)
            pf("Impossible\n");
            else
            {
                pf("%ld\n",ans);
            }
        }

    }

    return 0;
}


