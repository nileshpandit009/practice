/*
Title : Implementation of SJF Non-Preemptive algorithm
*/
#include<stdio.h>
//#include<conio.h>
void sort();           //non-pre.
void eninfo(int);
void chart();
void dis(int);
void ATAT();
void AWAIT();
void FA();
void REST();
void del();
void sjf();
void in(int);

struct process
{
	char pid[4];
	int bt;
	int at;
	int et;
	int rt;
	int fa;
	int tat;
}p[5],q[5];


	int i,j,n,k,timer=0,totalbt=0,f=-1,r=-1,c;
void main()
{
//	clrscr();
	printf("\nEnter the no of process:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	eninfo(i);

	for(i=0;i<n;i++)
	dis(i);

	sort();

	for(i=0;i<n;i++)
	totalbt=totalbt+p[i].bt;

	printf("\nGantt chart:\n");
	chart();

	ATAT();
	AWAIT();
	REST();
//	getch();
}


void sort()
{
	int i,j;
	struct process temp;
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	if(p[i].at>p[j].at)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}

}


void eninfo(int i)
{
	printf("\n Enter the process name ,arrival time and burst time:");
	scanf("%s %d %d", p[i].pid,&p[i].at,&p[i].bt);
	p[i].rt=p[i].bt;
	p[i].et=0;
}

void chart()
{
	in(0);
	while(timer<totalbt)
   {

	for(i=0;i<q[0].bt;i++)
		{
			printf(" %s",q[0].pid);

			if(q[0].rt==q[0].bt)
			FA();

			timer++;
			q[0].rt--;
			for(k=0;k<n;k++)
				{
					if(timer==p[k].at)
					in(k);
				}
		}
      del();

      sjf();
   }

}

void dis(int i)
{
	printf("\nProcess name is: %s",p[i].pid);
	printf("\nArrival time is: %d",p[i].at);
	printf("\nBurst time is: %d\n",p[i].bt);
}

void ATAT()
{
	int i;
	float avg=0;
	for(i=0;i<n;i++)
	p[i].tat=p[i].et-p[i].at;
	for(i=0;i<n;i++)
	avg=avg+p[i].tat;
	avg=avg/n;
	printf("\nAverage turn around time=%f",avg);
}

void AWAIT()
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
	sum=sum+(p[i].tat-p[i].bt);
	sum=sum/n;
	printf("\nAverage waiting time=%f",sum);
}

void in(int a)
{
	if(f==-1)
		f=r=0;
	else
		r++;
	q[r]=p[a];
}

void del()
{
	for(i=0;i<n;i++)
		{
		if(p[i].at==q[0].at)
		p[i].et=timer;
		}
	for(c=0;c<r;c++)
	q[c]=q[c+1];

	r=c-1;
}

void sjf()
{
int i,j;
struct process temp;
	for(i=0;i<=r;i++)
	{
		for(j=i+1;j<=r;j++)
		{
			if(q[i].bt>q[j].bt)
			{
				temp=q[i];
				q[i]=q[j];
				q[j]=temp;
			}
		}
	}
}

void FA()
{
	int l;
	for(l=0;l<n;l++)
	if(p[l].at==q[0].at)
	p[l].fa=timer;
}

void REST()
{
	float res=0;
	for(i=0;i<n;i++)
	res=res+(p[i].fa-p[i].at);
	res=res/n;
	printf("\nAverage response time=%f",res);
}

