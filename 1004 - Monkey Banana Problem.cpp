/*
ID: hanifbo1
PROG: ride
LANG: C++
*/
#include<bits/stdc++.h>

using namespace std;

#define DD          double
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


long input[205][205];


long dp[205][205];

long call(long i,long j){

        if(input[i+1][j-1] == -1 && input[i+1][j+1] == -1)
        return input[i][j];

        if(dp[i][j] != -1 )
        return dp[i][j];
        if(dp[i][j] != -1)
        return dp[i][j];
        long a = 0,b = 0;

        if(input[i+1][j-1]!=-1)
        a = call(i+1,j-1);
        if(input[i+1][j+1]!=-1)
        b = call(i+1,j+1);


        dp[i][j] = max(a,b)+input[i][j];
        return dp[i][j];

}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //ofstream fout ("ride.out");
    //ifstream fin ("ride.in");

    long t,kase = 1;

    sc("%ld",&t);

    while(t--){

        long n;

        sc("%ld",&n);
        mem(input,-1);
        long row = 2*n-1;
        mem(dp,-1);
        long cnt = 1;

        long pos = n;
        for(long i = 1;i<=n;i++)
        {
            long temp = pos;
            for(long j = 1;j<=cnt;j++){

                sc("%ld",&input[i][temp]);
                if(j <cnt)
                temp += 2;
            }
            if(cnt <= n)
            {
                cnt++;
                pos--;
            }

        }

        cnt = n-1;
        pos = 2;
        for(long i = n+1;i<=2*n-1;i++){

            long temp = pos;
            for(long j = 1;j<=cnt;j++)
            {
                sc("%ld",&input[i][temp]);
                temp += 2;
            }
            pos++;
            cnt--;
        }
        /*for(long i=1;i<=n;i++)
        {
            for(long j = 1;j<=2*n-1;j++)
            {
                if(input[i][j] == -1)
                cout<<" ";
                else
                cout<<input[i][j];

            }
            cout<<endl;
        }
        for(long i=n+1;i<=2*n-1;i++)
        {
            for(long j = 1;j<=2*n-1;j++)
            {
                if(input[i][j] == -1)
                cout<<" ";
                else
                cout<<input[i][j];

            }
            cout<<endl;
        }*/

//        dp[1][n] = input[1][n];

        long ans = call(1,n);
        //cout<<ans<<endl;
        pf("Case %ld: %ld\n",kase++,ans);
    }
    return 0;
}


