//Designed in Turbo C++

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Students
{
	int rn;
	char nm[100];
	float mks;
}arr[500];

main()
{
	clrscr();
	char f_loc[100];
	printf("Please Enter a Location where you want the Student.dat file to be saved:\n");
	fgets(f_loc, 100, stdin);
	FILE *fp=fopen(f_loc, "w");
	int f=0, i=0, j, k, r, x;
	char ch;
	for(i=0; i<500; )
	{
		printf("Enter Roll No., Name and Marks : \n");
		scanf("%d %s %f", &arr[i].rn, arr[i].nm, &arr[i].mks);
		fprintf(fp, "%d %s %f\n",arr[i].rn, arr[i].nm, arr[i].mks);
		i++;
		printf("Enter 'y' to continue, else enter any value:\n");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y')
		{
			i--;
			break;
		}
	}
	fclose(fp);
	do
	{
		printf("\n\n\nEnter '1' to Add Student\n'2' to Display Students\n'3' to Remove Student\n'4' to Update Student\n'5' to Search Student\n'6' to Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				fp=freopen(f_loc, "w");
				char ch;
				do
				{
					clrscr();
					printf("Enter Student's Roll Number, Name and Marks:\n");
					scanf("%d %s %f\n", &arr[i].rn, arr[i].nm, &arr[i].mks);
					fprintf(fp,"%d %s %f", &arr[i].rn, arr[i].nm, &arr[i].mks);
					printf("Another entry? (y/n)\n");
					fflush(stdin);
					scanf("%c",&ch);
				}while(ch=='y');
				fclose(fp);
				break;
			case 2:
				printf("Roll No\tName\tMarks\n");
				for(j=0; j<=i; j++)
					printf("%d\t%s\t%f", arr[i].rn, arr[i].nm, arr[i].mks);
				break;
			case 3:
				do
				{
					fclose(fp);
					fp=freopen(f_loc, "w", fp);
					printf("Enter Roll Number of Student whose record you want to delete:\n");
					scanf("%d", &r);
					for(j=0; j<=i; j++)
						if(r==arr[j].rn)
						{
							arr[j]=arr[j+1];
							i--;
							break;
						}
					j++;
					for(; j<=i; j++)
						fprintf(fp, "%d %s %f\n", arr[j].rn, arr[j].nm, arr[j].mks);
					printf("To Remove another record, enter 'y':\n");
					scanf("%c" ,&ch);
				}while(ch=='y');
				break;
			case 4:
				do
				{
					fclose(fp);
					fp=freopen(f_loc, "w");
					printf("Enter Roll No of Student:\n");
					scanf("%d", &r);
					f=0;
					while(j=0; j<=i; j++)
					{
						if(r==arr[i].ro)
						{
							f=1;
							printf("Enter '1' to update Roll No\n'2' to update Name\n'3' to update Marks\n");
							scanf("%d", &j);
							if(j==1)
							{
								printf("Enter New Roll Number:\n");
								scanf("%d", &arr[i].rn);
							}
							else if(j==2)
							{
								printf("Enter New Name:\n");
								gets(arr[i].nm);
							}
							else if(j==3)
							{
								printf("Enter New Marks:\n");
								scanf("%d", &arr[i].mks);
							}
							else
								printf("Invalid Input!");
							break;
						}
						if(f==0)
						{
							printf("Invalid Input!");
							break;
						}	
						printf("Another Update? (y/n)\n");
					}
				}while(ch=='y');
				break;
			case 5:
				do
				{
					printf("Enter Roll Number of Student to be found:\n");
					fflush(stdin);
					scanf("%f",&r);
					f=0;
					for(j=0;j<=i;j++)
						if(r==arr[j].rn)
						{
							printf("%d\t%s\t%f",arr[j].rn,arr[j].nm,arr[j].mks);
							f=1;
							break;
						}
					if(f==0)
						printf("Invalid Input.\n");
					printf("Enter 'y' to Search Another Student:\n");
					scanf("%c",&ch);
				}while(ch=='y');
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid Input\n");
		}
	}while(x!=6);
	getch();
}
