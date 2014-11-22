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

long N,K;
long inp[1005];

long validation(long exp_val){

    long part = 0;
    long tmp = 0;
    FOR(1,N+1){

        tmp += inp[i];

        if(tmp > exp_val){

            part++;
            tmp = inp[i];
        }

    }
    return part;
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


        long hi = 0 ,low = -1;
        sc("%ld %ld",&N,&K);

        FOR(1,N+1){

                long a;

                sc("%ld",&a);
                inp[i] = a;
                hi+=a;
                low = max(low,a);
        }

        //cout<<hi<<" "<<low<<endl;

        long ans = 0;

        while(low<=hi){

            long mid = (low+hi)/2;

            long chk = validation(mid);

            if(chk <= K){


                //if(chk == K+1)
                ans = mid;

                hi = mid-1;
            }
            else{

                low = mid+1;
            }
        }

        pf("Case %ld: %ld\n",ks++,ans);

        long tmp = 0;
        long cnt = 0;
        vector<long>v;
        stack<long>st;

        FOR(1,N+1){

            tmp += inp[i];

            if(tmp > ans){

                //pf("%ld\n",tmp-inp[i]);
                st.push(tmp-inp[i]);
                tmp = inp[i];
                cnt++;
            }
        }
        //if(tmp <= ans)
        //pf("%ld\n",tmp);
        st.push(tmp);
        //long pos = v.size()-1;
        long lst = N+1;
        //cout<<st.size()<<endl;
        while(st.size()+v.size() != K+1){

            //long tmp =
            long tp = st.top();
            st.pop();
            //v.erase(v.begin()+pos);

            if(tp - inp[lst] > 0)
            {
                st.push(tp-inp[lst]);

                v.pb(inp[lst]);
                lst--;
            }
            else{
                v.pb(inp[lst]);
                lst--;
            }

        }

        while(!st.empty())
        {
            v.pb(st.top());
            st.pop();
        }

        for(long i = v.size()-1; i>= 0;i--)
        pf("%ld\n",v[i]);


    }
    return 0;
}


