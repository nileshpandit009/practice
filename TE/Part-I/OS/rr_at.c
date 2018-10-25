/*
 * Programmer : Nilesh V. Pandit. (TE A-22)
 * Title : Round Robin with Arrival time.
 * Status : Complete.
 * Status details : Goes into infinite loop
 * 			on same AT for multiple processes.
 */

#include<stdio.h>
#include<stdlib.h>

struct process {
	char pid[4];
	int at;
	int bt;
	int rbt;
	int TAT;
	int wt;
	int rt;
	int RQ_exit;
	int PAT;
};
struct process *proc = NULL, *tmp = NULL;
int n, ts = 1, totalbt = 0, timer = 0, rear = -1, front = -1;

void bubsort()
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

void display()
{
	int i;
	for (i=0;i<n;i++) {
		printf("\n\nPID : %s", proc[i].pid);
		printf("\nArrival Time : %d", proc[i].at);
		printf("\nBurst Time : %d", proc[i].bt);
		printf("\nTurnaround time : %d", proc[i].TAT);
		printf("\nWaiting time : %d", proc[i].wt);
		printf("\nResponse time : %d\n", proc[i].rt);
	}
}

void inQueue(int in)
{
	(front == -1) ? front=rear=0 : rear++;
	tmp[rear] = proc[in];
}

void outQueue()
{
	int i;
	for (i=0;i<rear;i++)
		tmp[i] = tmp[i+1];
	rear = i - 1;
}

void shift()
{
	struct process temp;
	int s;
	if (tmp[0].rbt > 0) {
		temp = tmp[0];
		outQueue();
		rear++;
		tmp[rear] = temp;
	}
	else {
		for (s=0;s<n;s++)
			if (proc[s].at == tmp[0].at)
				proc[s].RQ_exit = timer;
		outQueue();
	}
}

void patCalc()
{
	int pc;
	for(pc=0;pc<n;pc++)
		if (proc[pc].at == tmp[0].at)
			proc[pc].PAT = timer;
}

struct process timeCalc(struct process tm)
{
	tm.TAT = tm.RQ_exit - tm.at;
	tm.wt = tm.TAT - tm.bt;
	tm.rt = tm.PAT - tm.at;
	return tm;
}

void gantt()
{
	int cp, j, proctimer = 0, cnt = 0;
	inQueue(0);
	while (timer < totalbt) {
		for(cp=0;cp<ts;cp++) {
			if (tmp[0].rbt != 0) {
				printf("%s ", tmp[0].pid);
				if (tmp[0].rbt == tmp[0].bt)
					patCalc();
				--tmp[0].rbt;
				++timer;
				for (j=0;j<n;j++)
					if (proc[j].at == timer)
						inQueue(j);
			}
		}
		printf("| ");
		shift();
	}
}

int main()
{
	int i = 0;
	float avgTAT = 0, avgWT = 0, avgRT = 0;

	printf("\n\nEnter number of processes you want to create\n");
	scanf("%d", &n);
	proc = (struct process *)calloc(sizeof(struct process), n);
	tmp = (struct process *)calloc(sizeof(struct process), n);
	printf("\nEnter time slice\n");
	scanf("%d", &ts);

	//Input for processes
	for(i=0;i<n;i++) {
		printf("\nEnter PID\n");
	        scanf("%s",proc[i].pid);
		printf("\nEnter Arrival time\n");
	        scanf("%d",&proc[i].at);
	        printf("\nEnter Burst time\n");
	        scanf("%d",&proc[i].bt);
		proc[i].rbt = proc[i].bt;
		tmp[i] = proc[i];
	}

	bubsort();	// Sort by Arrival time.

	//Calculate total burst
	for (i=0;i<n;i++)
		totalbt = totalbt + proc[i].bt;

	//Gantt chart
	gantt();

	/* 
	 * Calculating TurnAround time, Waiting time,
	 * and Response Time for each process.
	 */
//	patCalc();
	for(i=0;i<n;i++)
                proc[i] = timeCalc(proc[i]);

	display();		//Display all inputs

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
