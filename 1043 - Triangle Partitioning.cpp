/*
ID: hanifbo1
PROG: ride
LANG: C++
*/
#include<bits/stdc++.h>

using namespace std;

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
#define DD          double
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

double area(double ab,DD ac,DD bc){



    DD s = (ab+ac+bc)/2;

    DD ret = sqrt(s * (s-ab)*(s-ac)*(s-bc));

    return ret;
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


        DD AB,AC,BC,R;

        sc("%lf %lf %lf %lf",&AB,&AC,&BC,&R);

        DD A = area(AB,AC,BC);

        DD start  = 0, end= AB;

        DD M = (start+end)/2;

        DD pre  = -100;

        //cout<<pre-pre<<endl;

        /*if(0<0.000001)
        cout<<"ABU"<<endl;*/

        while(start<=end){

            DD ab = M;
            DD ac = AC*M/AB;
            DD bc = BC*M/AB;

            DD A1 = area(ab,ac,bc);

            DD temp = A - A1;

            if(A1/temp >= R){

                end = M;
            }
            else{

                start = M;
            }

            M = (start+end)/2;

            pre = M-pre;

            if(pre < 0)
            pre =- pre;

            if(pre < eps)
            break;

            pre = M;
        }


    pf("Case %ld: %.10lf\n",kase++,M);
    }
    return 0;
}


