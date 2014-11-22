#include<bits/stdc++.h>


using namespace std;

char ch[30][30];

bool check[30][30];

long ans;

void dfs(long i,long j)
{
//cout<<"BUG"<<endl;
                if(ch[i][j]=='#' || ch[i][j] == '0')
                return;
                else if(ch[i][j]=='.')
                ans++;

                if(ch[i-1][j] == '.' && check[i-1][j] ==0 )
                {
                    check[i-1][j]=1;
                    dfs(i-1,j);

                }

                if(ch[i+1][j]=='.' && check[i+1][j] ==0)
                {
                    check[i+1][j]=1;
                    dfs(i+1,j);
                }
                if(ch[i][j+1] == '.' && check[i][j+1] ==0)
                {
                    check[i][j+1]=1;
                    dfs(i,j+1);
                }
                if(ch[i][j-1] == '.'  && check[i][j-1] ==0)
                {
                    check[i][j-1]=1;
                            dfs(i,j-1);

                }



}

int main()
{
    long t;

    scanf("%ld",&t);

    for(long kase=1; kase<=t;kase++)
    {
                ans=1;
                memset(ch,'0',sizeof(ch));
                memset(check,0,sizeof(check));
                long n,k;

                scanf("%ld %ld",&n,&k);
                getchar();
                long r,c;

                for(long i=1;i<=k; i++)
                {

                    for(long j=1;j<=n; j++)
                    {

                            scanf("%c",&ch[i][j]);

                            if(ch[i][j] == '@')
                            {
                                r=i;
                                c=j;
                            }
                    }
                    getchar();
                }



                //cout<<"BUG"<<endl;
                    dfs(r,c);

            printf("Case %ld: %ld\n",kase,ans);

    }

    return 0;
}
