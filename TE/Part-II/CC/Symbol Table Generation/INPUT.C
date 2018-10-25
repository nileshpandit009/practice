# include < stdio . h >
void main ( ) {

int rollno;
char name1[10];
float percent;
printf ( "Enter name, roll number and percentage of student ");
scanf("%s %d %f", name1 , &rollno, &percent);
printf(" \t Name = %s \t Roll no = %d \t percentage = %f",name1,rollno,percent);

return 0 ;
}