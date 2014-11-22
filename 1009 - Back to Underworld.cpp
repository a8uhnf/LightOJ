#include<bits/stdc++.h>

using namespace std;

#define sc scanf
#define pf printf
#define mem(ar,val) memset(ar,val,sizeof(ar))


vector<long>E[20005];
long sign[20005];
bool mark[20005][20005];

long Ly,Vam;

void dfs()
{
        for(long k=1;k<=20000; k++)
        {
            if(!E[k].empty())
            {

            }
        }
}

int main()
{


    long t;

    sc("%ld",&t);

    for(long i=1;i<=t;i++)
    {
            mem(sign,0);
            mem(mark,0);
            Ly=0,Vam=0;
            //cout<<sign[1000]<<endl;
            long fight;

            sc("%ld",&fight);

            long a,b;
            sc("%ld %ld",&a,&b);
            E[a].push_back(b);
            E[b].push_back(a);
            sign[a]=1;sign[b]=2;

            for(long j=1;j<fight; j++)
            {
                //long a,b;
                sc("%ld %ld",&a,&b);
                E[a].push_back(b);
                E[b].push_back(a);
                if(sign[a] == 1)
                sign[b]=2;
                else if(sign[b]==1)
                sign[a]=2;
                else if(sign[a] == 2)
                sign[b]=1;
                else if(sign[b] == 2)
                sign[a]=1;
                else if(sign[a] == 0  && sign[b] == 0)
                {
                    sign[a]=1;sign[b]=2;
                }



            }

    }

    return 0;
}
