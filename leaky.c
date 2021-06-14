#include<stdio.h>
#include<stdlib.h>
int op, i, packets[5], bucketsize;

void
bktinput (int a, int b) 
{
  
if (a > bucketsize)
    
printf ("\n\t\t bucket overflow\n");
  
  else
    
    {
      
while (a > b)
	
	{
	  
printf ("\n\t\t %d bytes outputed", b);
	  
a -= b;
	
}
      
if (a > 0)
	
printf ("\n\t\t last %d bytes sent", a);
      
printf ("\n\t\t leaky bucket successful\n");
    
}

}


int
main () 
{
  
printf ("enter the bucket size:");
  
scanf ("%d", &bucketsize);
  
printf ("enter the output rate:");
  
scanf ("%d", &op);
  
printf ("enter 5 packets in streams:");
  
for (i = 0; i < 5; i++)
    
scanf ("%d", &packets[i]);
  
for (i = 0; i < 5; i++)
    
    {
      
printf ("\n packet no=%d\t packet size=%d", i, packets[i]);
      
bktinput (packets[i], op);
    
}

}


/* output 
enter the bucket size:30
enter the output rate:20
enter 5 packets in streams:31 
32
1
42
4

 packet no=0	 packet size=31
		 bucket overflow

 packet no=1	 packet size=32
		 bucket overflow

 packet no=2	 packet size=1
		 last 1 bytes sent
		 leaky bucket successful

 packet no=3	 packet size=42
		 bucket overflow

 packet no=4	 packet size=4
		 last 4 bytes sent
		 leaky bucket successful
*/
