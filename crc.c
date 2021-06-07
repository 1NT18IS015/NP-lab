#include<stdio.h>
#include<conio.h>
int rem(int,int);
void main()
{
  int i,j,k,dl,dil;
  int data[10],div[5],newdata[15],crc[5],datacrc[15],revdata[15],remd[5];
  printf("\n Enter the data length= ");
  scanf("%d",&dl);
  printf("\n Enter the divisor  length= ");
  scanf("%d",&dil);
  printf("\n Enter the data : ");
  for(i=0;i<dl;i++)
   scanf("%d",&data[i]);
  printf("\n Enter the divisor : ");
  for(i=0;i<dil;i++)
   scanf("%d",&div[i]);
  printf("\n The new data is : ");
  for(i=0;i<(dl+dil-1);i++)
  {
    if(i<dl)
     newdata[i]=data[i];
    else
     newdata[i]=0;
    printf("%d",newdata[i]);
  }
 for(j=0;j<=dl;j++)
 {
            for(i=0;i<dil;i++)
            {
             crc[i]=newdata[i+j];
             if(crc[0]==1)
              newdata[i+j]=rem(newdata[i+j],div[i]);
             else
              newdata[i+j]=rem(newdata[i+j],0);
            }
 printf("\n The Crc is : ");
 for(i=0;i<dil-1;i++)
  printf("%d",crc[i]);
 }

 printf("\n The data to be send is : ");
 for(i=0;i<(dl+dil-1);i++)
 {
  if(i<dl)
   datacrc[i]=data[i];
  else
   datacrc[i]=crc[i-dl];
  printf("%d",datacrc[i]);
 }
 printf("\n Enter the receiver side data : ");
 for(i=0;i<(dl+dil-1);i++)
  scanf("%d",&revdata[i]);
  for(j=0;j<=dl;j++)
 {
            for(i=0;i<dil;i++)
            {
             remd[i]=revdata[i+j];
             if(remd[0]==1)
              revdata[i+j]=rem(revdata[i+j],div[i]);
             else
              revdata[i+j]=rem(revdata[i+j],0);
            }
 printf("\n The reminder is : ");
 k=0;
 for(i=0;i<dil-1;i++)
  {
  printf("%d",remd[i]);
   if(remd[i]==0)
    k++;
  }
 }
 if(k==dil-1)
 printf("\n There is no error found.");
 else
 printf("\n There is error found.");
 getch();
}

int rem(int x, int y)
{
 if(x==y)
  return 0;
 else
  return 1;
}
