#include<bits/stdc++.h>

using namespace std;

#define FastIO      ios_base::sync_with_stdio(0); cin.tie(0)
#define READ(f)     freopen(f,"r",stdin)
#define WRITE(f)    freopen(f,"w",stdout)
#define sc          scanf
#define pf          printf
#define mem(a,val)  memset(a,val,sizeof(a))
#define rep(s,n)    for(long i=s; i<=n;i++)
#define pb          push_back
#define ll          long long
#define pi          (2*acos(0.0))
#define mx          35000
#define ssc         sscanf
#define FOR(val,n)  for(long i=val;i<=n;i++)
#define FORL(val,n) for(long i=val;i<n;i++)
#define PQ          priority_queue
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


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    long t,kase = 1;

    sc("%ld",&t);

    while(t--){


        long n,m;

        sc("%ld %ld",&n,&m);

        unsigned ll ans = 1;

        pf("Case %ld: ",kase++);
        if(n<m)
        pf("0\n");
        else
        {
            long temp ;
            bool b = true;


            if(m > n-m)
            {
                temp = m;
                b = false;
            }
            else
            temp = n-m;

            for(long i = temp+1; i<= n;i++)
            {
                ans *= (unsigned ll)i;
            }

            if(b == true)
            {
                for(long i = 2;i<=m;i++)
                {
                    ans /= i;
                }
            }
            else
            {
                for(long i = 2; i<=n-m;i++)
                ans /= i;
            }

            long tr = n;
            for(long i = 1;i<=m;i++)
            {
                ans *= (unsigned ll)tr;

                tr--;
            }
            pf("%llu\n",ans);

        }



    }

    return 0;
}


