/*
ID: hanifbo1
PROG: ride
LANG: C++
*/
#include<bits/stdc++.h>

using namespace std;

#define DD          double
#define llu            unsigned long long
#define eps         0.000001
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
#define sr(v)       sort(v.begin(),v.end())
#define mod         1000000007

long GCD(long a,long b)
{
    if(b==0)return a;

    return GCD(b,a%b);
}

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


long long bigMod(long long b,long long p, long long m)
{
    //cout<<"eee"<<endl;
    if(b == 1)
        return b;
    if(p == 0 )return 1;
    if( p == 1)return b;
    if(p%2 == 0)
    {
        ll temp = bigMod(b,p/2,m);
        return (temp*temp)%m;
    }
    else
        return (b  *  bigMod(b,p-1,m))%m;
}


ll modInverse(ll a,ll m)
{


    return bigMod(a,m-2,m);

}

long n;
long dp[25][5];
long arr[25][5];

long call(long i,long j){



        if(i>n)
        return 0;

        if(dp[i][j] != -1)return dp[i][j];

        long ret = 100000000;

        if(j == 0){

            ret = min(ret,call(i+1,1)+arr[i][j]);
            ret = min(ret,call(i+1,2)+arr[i][j]);
        }
        else if(j == 1){

            ret = min(ret,call(i+1,0)+arr[i][j]);
            ret = min(ret,call(i+1,2)+arr[i][j]);
        }
        else if(j == 2){

            ret = min(ret,call(i+1,0)+arr[i][j]);
            ret = min(ret,call(i+1,1)+arr[i][j]);
        }

        return dp[i][j] = ret;

}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //ofstream fout ("ride.out");
    //ifstream fin ("ride.in");

    long t,ks = 1;

    sc("%ld",&t);

    while(t--){


        mem(dp,-1);
        sc("%ld",&n);

        FOR(1,n){

            long a,b,c;

            sc("%ld %ld %ld",&arr[i][0],&arr[i][1],&arr[i][2]);

            //v[i].pb(a);
            //v[i].pb(b);
            //v[i].pb(c);
        }

        //cout<<call(1,0)<<endl;

        long ans = min(call(1,0),call(1,1));
        //cout<<ans<<endl;
        ans = min(ans,call(1,2));
        //cout<<ans<<endl;
        pf("Case %ld: %ld\n",ks++,ans);
        //cout<<dp[1][2]<<endl;
    }
    return 0;
}


