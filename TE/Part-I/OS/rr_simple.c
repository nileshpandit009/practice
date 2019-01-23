/*
 * Programmer : Nilesh V. Pandit. (TE A-22)
 * Status : Completed.
 * Status details : No Bugs till now
 */

#include<stdio.h>
#include<stdlib.h>

struct process {
	char pid[10];
	int at;
	int bt;
	int rbt;
	int TAT;
	int wt;
	int rt;
	int RQ_exit;
	int PAT;
};
struct process *proc = NULL;
int n, ts = 1, totalbt = 0, timer = 0;

void display()
{
	int i;
	for (i=0;i<n;i++) {
		printf("\n\nPID : %s", proc[i].pid);
		printf("\nBurst Time : %d", proc[i].bt);
		printf("\nTurnaround time : %d", proc[i].TAT);
		printf("\nWaiting time : %d", proc[i].wt);
		printf("\nResponse time : %d", proc[i].rt);
	}
}

void gantt()
{
	int cp, j, proctimer = 0, cnt = 0;
	while (timer < totalbt) {
/*		if (proc[cp].bt < ts) {
			for (j=0;j<proc[cp].bt;j++) {
				printf("%s ", proc[cp].pid);
				++proctimer;
				++timer;
			}
		}
		else {
			for (j=0;j<ts;j++) {
				printf("%s ", proc[cp].pid);
				++proctimer;
				++timer;
			}
		}
*/
		++cnt;
		for (cp=0;cp<n;cp++) {
			if (cnt == 1)
				proc[cp].PAT = timer;
			else {
				proctimer = 0;
				if (proc[cp].rbt == 0)
					continue;
				else {
					/* Below for loop eliminates the need of above 
					 * commented code (just after the while statement).
					 */
					for (j=0;j<((proc[cp].rbt < ts)?proc[cp].rbt:ts);j++) {
						printf("%s ", proc[cp].pid);
						++proctimer;
						++timer;
					}
				}
				proc[cp].rbt-=proctimer;
				proc[cp].RQ_exit = timer;
				printf(" |  ");
			}
		}
	}
}

/*
// This might help in RR with Arrival time inputs.
void patCalc()
{
	int i, j = 1;
	proc[0].PAT = proc[0].at;
	for(i=0;i<n;i++,j++)
		proc[j].PAT = proc[i].PAT + proc[i].bt;
}
*/

struct process timeCalc(struct process temp)
{
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
	scanf("%d", &n);
	proc = (struct process *)calloc(sizeof(struct process), n);
	printf("\nEnter time slice\n");
	scanf("%d", &ts);

	//Input for processes
	for(i=0;i<n;i++) {
		printf("\nEnter PID\n");
	        scanf("%s",proc[i].pid);
	        printf("\nEnter Burst time\n");
	        scanf("%d",&proc[i].bt);
		proc[i].rbt = proc[i].bt;
	}

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
