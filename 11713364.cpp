/* Ten  students  (a,b,c,d,e,f,g,h,i,j)  are  going  to  attend  an  event.  There  are  l
ots  of  gift 
shops, they all are going to the gift shops and randomly picking the gifts. After picking the gifts 
they  are  randomly  arriving  in  the  billing  counter.  The  accountant  gives  the  preference  to  that 
student who has maximum number of gifts. Create a
C or Java program to define order of billed 
students? */
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char p[10][5],temp[5];
	int i,j,process_time[10],wait_time[10],totalwait_time=0,pr[10],temp1;
	float avgwait_time;
	//printf("Enter no of students:");
	//scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		printf("Enter student %d name:",i+1);
  		scanf("%s",&p[i]);
		printf("enter process time:");
		scanf("%d",&process_time[i]);
		printf("enter no of gifts:");
		scanf("%d",&pr[i]);
	}
  	for(i=0;i<10-1;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(pr[i]>pr[j])
			{
				temp1=pr[i];
				pr[i]=pr[j];
				pr[j]=temp1;
				temp1=process_time[i];
				process_time[i]=process_time[j];
				process_time[j]=temp1;
				strcpy(temp,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp);
			}
		}
	}
	wait_time[0]=0;
	for(i=1;i<10;i++)
	{
		wait_time[i]=wait_time[i-1]+wait_time[i-1];
		totalwait_time=totalwait_time+wait_time[i];
	}
	avgwait_time=(float)totalwait_time/10;
	printf("G_name\t P_time\t No.Gifts\tW_time\n");
	for(i=0;i<10;i++)
	{
	   printf(" %s\t %d\t %d\t \t%d\n" ,p[i],process_time[i],pr[i],wait_time[i]);
	}
	printf("total waiting time=%d\navg waiting time=%f",totalwait_time,avgwait_time);
	getch();
}


