/*
 * Programmer : Nilesh Pandit
 * Roll no. : TE A22
 * Program : Preentive Shorted Job First Algorithm
 */


#include<stdio.h>
#include<stdlib.h>

int n, timer = 0, totalbt = 0;

struct process {
	char pid[10];
	int at;
	int bt;
	int TAT;
	int wt;
	int rt;
	int RQ_exit;
	int PAT;
};
struct process *proc = NULL, *preproc = NULL;

void atSort()			//Arrival time Sort
{
	int i, j;
	struct process tmp;
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(proc[i].at > proc[j].at) {
				tmp = proc[i];
				proc[i] = proc[j];
				proc[j] = tmp;
			}
		}
	}
}

void btSort()			//Burst time Sort from 2nd proc
{
	int i, j;
	struct process tmp;
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(proc[i].bt > proc[j].bt) {
				tmp = proc[i];
				proc[i] = proc[j];
				proc[j] = tmp;
			}
		}
	}
}

void display()
{
	int i;
	for(i=0;i<n;i++) {
		printf("\nPID = %s", proc[i].pid);
		printf("\nArrival Time = %d", proc[i].at);
		printf("\nBurst Time = %d", proc[i].bt);
		printf("\nTurnaround Time = %d", proc[i].TAT);
		printf("\nWaiting Time = %d", proc[i].wt);
		printf("\nResponse Time = %d\n", proc[i].rt);
	}
}

int inCheck(int a, int et)
{
	int i;
	for (i=1;i<n;i++) {
		if (et == proc[i].at) {
			proc[a].bt = proc[a].bt - et;
			preproc[0] = proc[i];
			return 1;
		}
	}
}

void gantt()
{
	int i, cp = 0, preempted = 0;
	printf("\n\nGantt Chart : \n");
	for (i=0;i<n;i++)
		totalbt = totalbt + proc[i].bt;
	while (timer < totalbt) {
		for (i=0;i<preproc[0].bt;i++) {
			printf("%s ", preproc[0].pid);
			++timer;
			preempted = inCheck(cp, timer);
			if (preempted == 1) {
				++cp;
				preempted = 0;
			}
		}
		printf(" |  ");
	}
}

void patCalc()
{
	int i, j = 1;
	proc[0].PAT = proc[0].at;
	for(i=0;i<n;i++,j++)
		proc[j].PAT = proc[i].PAT + proc[i].bt;
}

struct process timeCalc(struct process temp)
{
	patCalc();
	temp.TAT = temp.RQ_exit - temp.at;
	temp.wt = temp.TAT - temp.bt;
	temp.rt = temp.PAT - temp.at;
	return temp;
}

int main()
{
	int i = 0;
	float avgTAT = 0, avgWT = 0, avgRT = 0;

	printf("\n\nEnter number of processes you want to create\n");
	scanf("%d",&n);
	proc = (struct process *)calloc(sizeof(struct process), n);
	preproc = (struct process *)calloc(sizeof(struct process), n);

	//Input for processes
	for(i=0;i<n;i++) {
		printf("\nEnter PID\n");
	        scanf("%s",proc[i].pid);
        	printf("\nEnter Arrival time\n");
	        scanf("%d",&proc[i].at);
	        printf("\nEnter Burst time\n");
	        scanf("%d",&proc[i].bt);
	}

	for (i=0;i<n;i++)
                preproc[i] = proc[i];

	printf("\n\n--------------------Before Sorting--------------------\n");
	display();		//Display before Bubble Sort.

	atSort();		//Sorting according Arrival time.

//	btSort();		//Sorting according Burst time from 2nd proc.

	gantt();		//Gantt Chart generation.

	//Times calculation for processes.
	for(i=0;i<n;i++)
                proc[i] = timeCalc(proc[i]);

	printf("\n\n--------------------After Sorting--------------------\n");
	display();		//Display after Bubble Sort.

	/*
	 * Calculating Average TurnAround time, Average Waiting time,
	 * and Average Response Time.
	 */

	for(i=0;i<n;i++) {
		avgTAT = avgTAT + proc[i].TAT;
		avgWT = avgWT + proc[i].wt;
		avgRT = avgRT + proc[i].rt;
	}
	avgTAT = avgTAT/n;
	avgWT = avgWT/n;
	avgRT = avgRT/n;


	printf("\n\nAverage TurnAround time = %.2f", avgTAT);
	printf("\nAverage Waiting time = %.2f", avgWT);
	printf("\nAverage Response time = %.2f\n\n", avgWT);

	return 0;
}
