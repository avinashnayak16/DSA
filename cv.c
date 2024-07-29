#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define doctor struct doc
void add(FILE * fp); //to add to list
FILE * del(FILE * fp);//to delete from list
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
struct doc
{
    char name[100];
    char specialisation[50];
    int id;
    double salary;
};
int main()
{
 FILE * fp;
 doctor d;
int option;
char another;
if((fp=fopen("doctorInfo.txt","rb+"))==NULL)
{
    if((fp=fopen("doctorInfo.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}
while(1)
{
    printf("\n\t");
    printChar('-',64);
    printf("\n\n\t\t\t1. ADD Record");
    printf("\n\n\t\t\t2. DELETE Record");
    printf("\n\n\t\t\t3. MODIFY ");
    printf("\n\n\t\t\t4. DISPLAY");
    printf("\n\n\t\t\t5. Search Record");
    printf("\n\n\t\t\t0. EXIT");
    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);
    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: fp=del(fp);
               break;
        case 3: modify(fp);
                break;
        case 4: displayList(fp);
                break;
       case 5: searchRecord(fp);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  exit(0);
    }
}
return 1;
}
//----printing character ch at n times ------
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}
//-----Printing Head Line of the program -----
void printHead()
{
system("cls");
printf("\n\n\t");
printChar('=',16);
printf("[STUDENT] [INFORMATION] [SYSTEM]");
printChar('=',16);
printf("\n");
}

// ==========ADDING NEW RECORD==========================
void add(FILE * fp)
{
char another='y';
doctor d;
int i;
fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{
    printf("\n\n\t\tEnter Full Name of Doctor\t");
    fflush(stdin);
    fgets(d.name,100,stdin); //fgets takes an extra \n character as input
    d.name[strlen(d.name)-1]='\0';
    printf("\n\n\t\tEnter Specialisation\t");
    fflush(stdin);
    fgets(d.specialisation,50,stdin);
    d.specialisation[strlen(d.specialisation)-1]='\0';
    printf("\n\n\t\tEnter id \t");
    scanf("%d",&d.id);
    printf("\n\n\t\tEnter salary \t");
    scanf("%u",&d.salary);
    fwrite(&d,sizeof(d),1,fp);
    printf("\n\n\t\tWant to enter another  info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}
//====================DISPLAY THE LIST =================
void displayList(FILE * fp)
{
    doctor d;
    int i,siz=sizeof(d);
    rewind(fp);
    while((fread(&d,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",d.name);
        printf("\n\n\t\tSPECIALISATION : %s",d.specialisation);
        printf("\n\n\t\tID : %d",d.id);
        printf("\n\n\t\tSALARY: %u",d.salary);
        printChar('-',65);
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}
//===================DELETING A RECORD FROM LIST ============
FILE * del(FILE * fp)
{
doctor d;
int flag=0,tempRoll,siz=sizeof(d);
FILE *ft;
if((ft=fopen("temp.txt","wb+"))==NULL)
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}
printf("\n\n\tEnter ID of Doctor to Delete the Record");
printf("\n\n\t\t\tID : ");
scanf("%d",&tempRoll);
rewind(fp);
while((fread(&d,siz,1,fp))==1)
{
    if(d.id==tempRoll)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\n\t\t%d\n\t",d.name,d.specialisation,d.id,d.salary);
    continue;
    }
   fwrite(&d,siz,1,ft);
}
fclose(fp);
fclose(ft);
remove("doctorInfo.txt");
rename("temp.txt","doctorInfo.txt");
if((fp=fopen("doctorInfo.txt","rb+"))==NULL)
{
    printf("ERROR");
    return  NULL;
}
if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");
printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}
//===========MODIFY A RECORD ===========================
void modify(FILE * fp)
{
doctor d;
int i,flag=0,tempRoll,siz=sizeof(d);
printf("\n\n\tEnter ID of Doctor to MODIFY the Record : ");
scanf("%d",&tempRoll);
rewind(fp);
while((fread(&d,siz,1,fp))==1)
{
    if(d.id==tempRoll)
        {flag=1;
        break;
        }
}
if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");
    printf("\n\n\t\tEnter Full Name of Doctor\t");
    fflush(stdin);
    fgets(d.name,100,stdin);
    d.name[strlen(d.name)-1]='\0';
    printf("\n\n\t\tEnter Specialisation\t");
    fflush(stdin);
    fgets(d.specialisation,50,stdin);
    d.specialisation[strlen(d.specialisation)-1]='\0';
    printf("\n\n\t\tEnter ID \t");
    scanf("%d",&d.id);
    printf("\n\n\t\tEnter Salary\n\t");
    scanf("%d",&d.salary);
    fwrite(&d,sizeof(d),1,fp);
}
else
	 printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");
printf("\n\n\t");
system("pause");
}
//===========SEARCHING A RECORD ===========================
void searchRecord(FILE *fp)
{
int tempRoll,flag,siz,i;
doctor d;
char another='y';
siz=sizeof(d);
while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID of Doctor to search the record : ");
scanf("%d",&tempRoll);
rewind(fp);
while((fread(&d,siz,1,fp))==1)
{
    if(d.id==tempRoll)
        {flag=1;
        break;
        }
}
if(flag==1)
    {
    printf("\n\t\tNAME : %s",d.name);
        printf("\n\n\t\tSPECIALISATION : %d",d.specialisation);
        printf("\n\n\t\tID : %d",d.id);
        printf("\n\n\t\tSALARY: %d",d.salary);
}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}