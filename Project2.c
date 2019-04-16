#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct cylinder
{
	int r_no;
	bool kt;
};

int main()
{
	printf("\n\n\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\tPROBLEM BASED ON C-LOOK DISK SCHEDULING ALGORITHM                    ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n\n\n\n");
	
	int m,n_request,current_h,limit,n,flag,p_head;
	printf("Enter the head requests number: ");
	scanf("%d",&n_request);
	struct cylinder a[n_request];
	
	for (m = 0; m < n_request; ++m)
	{
		printf("Enter the %d requests: ",m+1);
		scanf("%d",&a[m].r_no);
		a[m].kt = false;
	}
	printf("\nEnter the current request of head: ");
	scanf("%d",&current_h);

	printf("\nEnter the previous request of head: ");
	scanf("%d",&p_head);

	printf("\nEnter the maximum size cylinder: ");
	scanf("%d",&limit);
	
	printf("\nSequence of Head Movement\n\n");
	if(p_head - current_h > 0 )
	{
		flag = 2;
	}
	else
		flag = 1;
	int distance=0;
	printf("%d -> ",current_h );
	int i_head = current_h;
	if(flag == 1)
	{
		for(m=current_h;m<limit;m++)
		{
			for(n=0;n<n_request;n++)
			{
				if(a[n].r_no == m && a[n].kt == false)
				{
					printf("%d -> ", a[n].r_no);
					a[n].kt = true;
					distance += abs(a[n].r_no - current_h);
					current_h = a[n].r_no;
				}
			}
		}
		for(m=0;m<i_head;m++)
		{
			for(n=0;n<n_request;n++)
			{
				if(a[n].r_no == m && a[n].kt == false)
				{
					printf("%d -> ", a[n].r_no);
					a[n].kt = true;
					distance += abs(a[n].r_no - current_h);
					current_h = a[n].r_no;
				}
			}
		}
		printf("\n");
	}
	else if(flag == 2)
	{
		for(m=current_h;m>=0;m--)
		{
			for(n=0;n<n_request;n++)
			{
				if(a[n].r_no == m && a[n].kt == false)
				{
					printf("%d -> ", a[n].r_no);
					a[n].kt = true;
					distance += abs(a[n].r_no - current_h);
					current_h = a[n].r_no;
				}
			}
		}
		current_h = limit-1;
		for(m=limit;m>i_head;m--)
		{
			for(n=0;n<n_request;n++)
			{
				if(a[n].r_no == m && a[n].kt == false)
				{
					printf("%d -> ", a[n].r_no);
					a[n].kt = true;
					distance += abs(a[n].r_no - current_h);
					current_h = a[n].r_no;
				}
			}
		}
		printf("\n");
	}
	printf("\nTotal Distance: %d\n", distance);
}

