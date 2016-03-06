#include<stdio.h>
int main()
{
  int n,
      i,j,k,step,
      path[20][20][20],
      get,
      seq[20];
  double best[20][20][20],
         temp;
  while(scanf("%d",&n)==1)
  {
    get=0;
    for(step=0;step<n;step++)
      if(step==0)
      {
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
            if(i==j)
              best[i][j][step]=1.0;
            else
              scanf("%lf",&best[i][j][step]);
            path[i][j][step]=i;
          }
      }
      else
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
            best[i][j][step]=0;
    for(step=1;step<n;step++)
      for(k=0;k<n;k++)
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
            temp=best[i][k][step-1]*best[k][j][0];
            if(temp>best[i][j][step])
            {
              best[i][j][step]=temp;
              path[i][j][step]=k;
            }
          }
    for(step=1;step<n;step++)
    {
      for(i=0;i<n;i++)
      {
        if(best[i][i][step]>1.01)
        {
          seq[step]=path[i][i][step];
          for(j=step-1;j>=0;j--)
            seq[j]=path[i][seq[j+1]][j];
          for(j=0;j<=step;j++)
            printf("%d ",seq[j]+1);
          printf("%d\n", i + 1);
          get=1;
          break;
        }
      }
      if(get==1)
        break;
    }
    if(get!=1)
    printf("no arbitrage sequence exists\n");
  }
  return 0;
}