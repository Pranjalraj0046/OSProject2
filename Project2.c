#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int p_request=145;
int c_request=143;
int Find(int v)
{
	if(v>0)
	{
		return v;
	}
	else
	{
		return (v*-1);
	}
}
int main()
{
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\tPROBLEM BASED ON C-LOOK DISK SCHEDULING ALGORITHM                    ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n\n\n\n");
	int queue[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
	int m,Begin,l=sizeof(queue)/sizeof(int),d=0,End,initial,pt,n;
	 for (m = 0; m < l; ++m) 
        {
            for (n = m + 1; n < l; ++n)
            {
                if (queue[m] > queue[n]) 
                {
                    pt =  queue[m];
                    queue[m] = queue[n];
                    queue[n] = pt;
                }
            } 
        }
        End = c_request;
    if(c_request>=p_request){
        for(m=0; m<l; m++){
            if(queue[m]>c_request){
                Begin=m;
                break;
            }
        }
        printf("Order    : %4d",End);
        for(m=Begin; m<l; m++){
            printf(", %4d",queue[m]);
             for(m=Begin; m<l; m++)
        for(m=Begin; m>0; m--){
            printf(", %4d",queue[m-1]);
            initial = queue[m];

            d+= Find(End-initial);
            printf("[%d]",Find(End-initial) );
            End = initial;
        }
}
}
      else if(c_request<p_request){
        for(m=0; m<l; m++){
            if(queue[m]>c_request){
                Begin=m;
                break;
            }
        }
        printf("Sequence : %4d",End);
        for(m=Begin-1; m>=0; m--){
            printf(", %4d",queue[m]);
            initial = queue[m];

            d+= Find(End-initial);
            printf("[%d]",Find(End-initial) );
            End = initial;
        }
        for(m=Begin; m<l; m++){
            printf(", %4d",queue[m]);
            initial = queue[m];

            d+= Find(End-initial);
            printf("[%d]",Find(End-initial) );
            End = initial;
        }
    }
    printf("\n\n\nTotal Distance : %d\n",d);
    return 0;
    getch();
}
