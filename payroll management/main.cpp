#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define max 100

void add();                          //add a new employee record
int emp_id(int id);                  //
void search();                       //search for an employee record
void display();                      //display details of a given employee
void displayall();                   //display all employee records
void modify();                       //modify details of a given employee
void delete_emp();                   //delete a given employee record
void delete_all();                   //delete all employee records
void tot();                          //displays total number of employees
void sort_disp();                    //
void sort_id();                      //Insertion sort for Employee-ID
void display_id(int s_id);           //Display function with Employee-id as argument
void sort_sal();                     //Bubble sort for employee's salary
void display_sal(int s_sal);         //Display function with Employee's salary as argument
void sort_exp_co();                  //Selection sort for employee's experience in this company
void display_exp_co(int s_exp_co);   //Display function with Employee's experience as argument
void quit();                         //quit the application

//structure that contains employee details
struct employee
{
    char name[20];  //employee's name
    char add[60];   //employee's address
    int id;         //employee's ID
    long long pno;  //employee's phone number
    int whrs;       //number  of working hours
    float sal;      //employee's salary
    int exp;        //employee's experience in this field
    int exp_co;     //employee's experience in this company
    int age;        //employee's age
    char dob[20];   //employee's date of birth
    char doj[20];   //employee's date of join
    char email[40]; //employee's email-ID
    struct employee *next;
}*head=NULL;

//main function
int main()
{
    cout<<endl;
    cout<<"***************************************************PAYROLL MANAGEMENT***************************************************";
    int ch;
    char choice;
    do
    {
        system("cls");
        cout<<endl;
        cout<<"--------------------------------------------------------MENU------------------------------------------------------------";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"1.Add an employee";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"2.Search for an employee";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"3.Display all employee details";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"4.Modify Employee Details";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"5.Display as per option";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"6.Delete an employee record";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"7.Delete all employee details";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"8.Sort and display";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"9.Total number of employees";
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t     ";
        cout<<"ENTER A VALID CHOICE: ";
        cin>>ch;
        switch(ch)
        {
        case 1: add();
                break;
        case 2: search();
                break;
        case 3: displayall();
                break;
        case 4: modify();
                break;
        case 5: display();
                break;
        case 6: delete_emp();
                break;
        case 7: delete_all();
                break;
        case 8: sort_disp();
                break;
        case 9: tot();
                break;
        default:cout<<"This option does not exist!Enter a valid one!!";
                break;
        }
        cout<<endl;
        cout<<"\n DO YOU WANT TO CONTINUE (y-yes n-no)";
        cin>>choice;
        if(choice=='n'||choice=='N')
        {
            quit();
        }
    }while(choice=='y'||choice=='Y');

}

 //add a new employee record
void  add()
{
    system("cls");
    int x,t;
    char ch;
    do
    {
    struct employee *ptr=new employee;
    char dname[30],dadd[60],demail[40],ddob[20],ddoj[20];
    int did,dwhrs,dsal,dexp,dexp_co,dage;
    long long dpno;
    struct employee *data = new employee;
    cout<<"\nEnter the following details: ";
    cout<<"\nName: ";
    cout<<endl;
    cin>>dname;
    cout<<"\nDate of birth: ";
    cout<<endl;
    cin>>ddob;
    while(ddob<0)
    {
        cout<<endl;
        cout<<"Enter a valid value for age:";
        cin>>ddob;
    }
    cout<<"\nAge: ";
    cout<<endl;
    cin>>dage;
    while(dage<18)
    {
        cout<<endl;
        cout<<"Enter a valid value for age:";
        cin>>dage;
    }
    cout<<"\nAddress: ";
    cout<<endl;
    cin>>dadd;
    cout<<"\nPhone Number: ";
    cout<<endl;
    cin>>dpno;
    while(dpno<0)
    {
        cout<<endl;
        cout<<"Enter a valid value for phone number:";
        cin>>ddob;
    }
    cout<<"\nMail-ID: ";
    cout<<endl;
    cin>>demail;
    cout<<"\nNumber of years  of experience in this field: ";
    cout<<endl;
    cin>>dexp;
    cout<<"\nNumber of years  of experience in this company: ";
    cout<<endl;
    cin>>dexp_co;
    while(dexp<0)
    {
        cout<<endl;
        cout<<"Enter a valid value for experience: ";
        cin>>dexp;
    }
    cout<<"\nEmployee-ID: ";
    cout<<endl;
    cin>>did;
    t=0;
    do
    {
        x=emp_id(did);
        if(x==1)
        {
            cout<<"\n Employee id already exists ";
            cout<<"\n Enter new one :";
            cin>>did;
            t=1;
        }
        else
        {
            t=0;
        }
    }while(t==1);
    cout<<"\nDate of join: ";
    cout<<endl;
    cin>>ddoj;
    while(ddoj<0)
    {
        cout<<endl;
        cout<<"Enter a valid value for age:";
        cin>>ddoj;
    }
    cout<<"\nWorking hours: ";
    cout<<endl;
    cin>>dwhrs;
    while(dwhrs<0||dwhrs>24)
    {
        cout<<endl;
        cout<<"Enter a valid value for working hours: ";
        cin>>dwhrs;
    }
    cout<<"\nSalary: ";
    cout<<endl;
    cin>>dsal;
    while(dsal<0)
    {
        cout<<endl;
        cout<<"Enter a valid value for salary: ";
        cin>>dsal;
    }
    strcpy(data->dob,ddob);
    strcpy(data->email,demail);
    strcpy(data->name,dname);
    data->age=dage;
    strcpy(data->add,dadd);
    data->pno=dpno;
    data->exp=dexp;
    data->exp_co=dexp_co;
    data->id=did;
    strcpy(data->doj,ddoj);
    data->whrs=dwhrs;
    data->sal=dsal;
    if(head==NULL)
    {
        head=data;
        head->next=NULL;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=data;
    }
    cout<<endl;
    cout<<"Do you want to add another employee?(y-yes or n-no)";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
}

int emp_id(int id)
{
    int flag=0;
    struct employee *temp=new employee;
    temp=head;
    while(temp!=NULL)
    {
        if(id==temp->id)
        {
            flag=1;
            break;
            cout<<endl;
        }
        else
        {
            temp=temp->next;
        }
    }
    if(flag==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


//search for an employee record
void search()
{
    system("cls");
    int flag1=0;
    struct employee *temp=new employee;
    temp=head;
    char search_name[30];
    cout<<"\nEnter the name of the employee: ";
    cin>>search_name;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,search_name)==0)
        {
            flag1=1;
            cout<<"\nEmployee record of "<<search_name<<" exists";
            break;
            cout<<endl;
        }
        else
        {
            temp=temp->next;
        }
    }
    if(flag1==0)
    {
        cout<<endl;
        cout<<"Employee named "<<search_name<<" does not exist!!!";
    }
}

//display all employee records
void displayall()
{
    system("cls");
    struct employee *disp=new employee;
    disp=head;
   // struct *ptr;
    if(head==NULL)
    {
        cout<<endl;
        cout<<"Record is empty!!!";
    }
    else
    {
        cout<<endl;
        cout<<"\t\t\tEMPLOYEE DETAILS: ";
        while(disp!=NULL)
        {
            cout<<endl;
            cout<<"Name: ";
            cout<<disp->name;
            cout<<endl;
            cout<<"Date of birth: ";
            cout<<disp->dob;
            cout<<endl;
            cout<<"Age: ";
            cout<<disp->age;
            cout<<endl;
            cout<<"Address: ";
            cout<<disp->add;
            cout<<endl;
            cout<<"Phone Number: ";
            cout<<disp->pno;
            cout<<endl;
            cout<<"Mail-ID: ";
            cout<<disp->email;
            cout<<endl;
            cout<<"Number of years  of experience in this field: ";
            cout<<disp->exp;
            cout<<endl;
            cout<<"Number of years  of experience in this company: ";
            cout<<disp->exp_co;
            cout<<endl;
            cout<<"Employee-ID: ";
            cout<<disp->id;
            cout<<endl;
            cout<<"Date of join: ";
            cout<<disp->doj;
            cout<<endl;
            cout<<"Working hours: ";
            cout<<disp->whrs;
            cout<<endl;
            cout<<"Salary: ";
            cout<<disp->sal;
            cout<<endl;
            cout<<"\t\t********************************";
            disp=disp->next;
        }
    }
}

//display details of a given employee
void display()
{
    int flag=0;
    system("cls");
    struct employee *temp=new employee;
    temp=head;
    char disp_name[30];
    cout<<"\nEnter the name of the employee: ";
    cin>>disp_name;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,disp_name)==0)
        {
            cout<<"\n\t\tEMPLOYEE DETAILS: ";
            cout<<endl;
            cout<<"Name: ";
            cout<<temp->name;
            cout<<endl;
            cout<<"Date of birth: ";
            cout<<temp->dob;
            cout<<endl;
            cout<<"Age: ";
            cout<<temp->age;
            cout<<endl;
            cout<<"Address: ";
            cout<<temp->add;
            cout<<endl;
            cout<<"Phone Number: ";
            cout<<temp->pno;
            cout<<endl;
            cout<<"Mail-ID: ";
            cout<<temp->email;
            cout<<endl;
            cout<<"Number of years  of experience in this field: ";
            cout<<temp->exp;
            cout<<endl;
            cout<<"Number of years  of experience in this company: ";
            cout<<temp->exp_co;
            cout<<endl;
            cout<<"Employee-ID: ";
            cout<<temp->id;
            cout<<endl;
            cout<<"Date of join: ";
            cout<<temp->doj;
            cout<<endl;
            cout<<"Working hours: ";
            cout<<temp->whrs;
            cout<<endl;
            cout<<"Salary: ";
            cout<<temp->sal;
            cout<<endl;
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        cout<<endl;
        cout<<"Employee named "<<disp_name<<" does not exist!!!";
    }
}

//modify details of a given employee
void modify()
{
    int flag=0,t,x;
    system("cls");
    struct employee *temp=new employee;
    temp=head;
    char mod_name[30];
    cout<<"\nEnter the name of the employee: ";
    cin>>mod_name;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,mod_name)==0)
        {
            cout<<"\nEnter the following details: ";
            cout<<"\nName: ";
            cout<<endl;
            cin>>temp->name;
            cout<<"\nDate of birth: ";
            cout<<endl;
            cin>>temp->dob;
            while(temp->dob<0)
            {
                cout<<endl;
                cout<<"Enter a valid value for age:";
                cin>>temp->dob;
            }
            cout<<"\nAge: ";
            cout<<endl;
            cin>>temp->age;
            while(temp->age<18)
            {
                cout<<endl;
                cout<<"Enter a valid value for age:";
                cin>>temp->age;
            }
            cout<<"\nAddress: ";
            cout<<endl;
            cin>>temp->add;
            cout<<"\nPhone Number: ";
            cout<<endl;
            cin>>temp->pno;
            while(temp->pno<0)
            {
                cout<<endl;
                cout<<"Enter a valid value for age:";
                cin>>temp->pno;
            }
            cout<<"\nMail-ID: ";
            cout<<endl;
            cin>>temp->email;
            cout<<"\nNumber of years  of experience in this field: ";
            cout<<endl;
            cin>>temp->exp;
            cout<<"\nNumber of years  of experience in this company: ";
            cout<<endl;
            cin>>temp->exp_co;
            cout<<"\nEmployee-ID: ";
            cout<<endl;
            cin>>temp->id;
            t=0;
            do
            {
                x=emp_id(temp->id);
                if(x==1)
                {
                    cout<<"\n Employee id already exists ";
                    cout<<"\n Enter new one :";
                    cin>>temp->id;
                    t=1;
                }
                else
                {
                    t=0;
                }
            }while(t==1);
            cout<<"\nDate of join: ";
            cout<<endl;
            cin>>temp->doj;
            while(temp->doj<0)
            {
                cout<<endl;
                cout<<"Enter a valid value for age:";
                cin>>temp->doj;
            }
            cout<<"\nWorking hours: ";
            cout<<endl;
            cin>>temp->whrs;
            while(temp->whrs<0||temp->whrs>24)
            {
                cout<<endl;
                cout<<"Enter a valid value for working hours: ";
                cin>>temp->whrs;
            }
            cout<<"\nSalary: ";
            cout<<endl;
            cin>>temp->sal;
            while(temp->sal<0)
            {
                cout<<endl;
                cout<<"Enter a valid value for salary: ";
                cin>>temp->sal;
            }
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        cout<<endl;
        cout<<"Employee named "<<mod_name<<" does not exist!!!";
    }
}

 //delete a given employee record
void delete_emp()
{
    int flag=0;
    system("cls");
    char del_name[30];
    struct employee *ptr=head;
    struct employee *temp;
    cout<<endl;
    cout<<"Enter the name of the employee: ";
    cin>>del_name;
    if(head==NULL)
    {
        cout<<endl;
        cout<<"Employee record is empty!!!";
    }
    else if(head->next==NULL)
    {
       head=NULL;
       cout<<"\nRecord deleted";
       flag=-1;
    }
    else
    {
        while(strcmp(ptr->name,del_name)!=0)
        {
            flag=1;
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        free(ptr);
    }
    if(flag==0)
    {
        cout<<endl;
        cout<<"Employee named "<<del_name<<" does not exist!!!";
    }
    if(flag==1)
    {
        cout<<endl;
        cout<<"Employee named "<<del_name<<" is deleted!!!";
    }
}

//delete all employee records
void delete_all()
{
    system("cls");
    struct employee *temp;
    temp=head;
    while(head->next!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    head=NULL;
    delete(head);
}


void sort_disp()
{
    int op;
    cout<<endl;
    cout<<"1] Sort Employee-ID Number"; //INSERTION SORT
    cout<<endl;
    cout<<"2] Sort Employee salary";    //BUBBLE SORT
    cout<<endl;
    cout<<"3] Sort Employee seniority"; //SELECTION SORT
    cout<<endl;
    cout<<"Enter a option:";
    cin>>op;
    switch(op)
    {
        case 1: sort_id();
                break;
        case 2: sort_sal();
                break;
        case 3: sort_exp_co();
                break;
        default:cout<<"The option is incorrect!!!Enter a valid one.";
                cin>>op;
    }
}


//INSERTION SORT
void sort_id()
{
    int n=0;
    system("cls");
    struct employee *srt=new employee;
    srt=head;
    while(srt!=NULL)
    {
        n++;
        srt=srt->next;
    }
    int sort_id[n];
    if(head==NULL)
    {
        cout<<endl;
        cout<<"Record is empty!!!";
    }
    else
    {
        cout<<endl;
        int i=0;
        srt=head;
        while(srt!=NULL)
        {
             sort_id[i++]=srt->id;
             srt=srt->next;
        }
    }
    int temp,k;
    for(int i=1;i<n;i++)
    {
        temp=sort_id[i];
        k=i-1;
        while((k>=0)&&(sort_id[k]>temp))
        {
            sort_id[k+1]=sort_id[k];
            k=k-1;
        }
        sort_id[k+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
         display_id(sort_id[i]);
    }
}

//Display function with Employee-id as argument
void display_id(int s_id)
{
    struct employee *temp=head;
    while(temp!=NULL)
    {
        if(s_id==temp->id)
        {
            cout<<"\n\t\tEMPLOYEE DETAILS: ";
            cout<<endl;
            cout<<"Employee-ID: ";
            cout<<temp->id;
            cout<<endl;
            cout<<"Name: ";
            cout<<temp->name;
            cout<<endl;
            cout<<"Date of birth: ";
            cout<<temp->dob;
            cout<<endl;
            cout<<"Age: ";
            cout<<temp->age;
            cout<<endl;
            cout<<"Address: ";
            cout<<temp->add;
            cout<<endl;
            cout<<"Phone Number: ";
            cout<<temp->pno;
            cout<<endl;
            cout<<"Mail-ID: ";
            cout<<temp->email;
            cout<<endl;
            cout<<"Number of years  of experience in this field: ";
            cout<<temp->exp;
            cout<<endl;
            cout<<"Number of years  of experience in this company: ";
            cout<<temp->exp_co;
            cout<<endl;
            cout<<"Date of join: ";
            cout<<temp->doj;
            cout<<endl;
            cout<<"Working hours: ";
            cout<<temp->whrs;
            cout<<endl;
            cout<<"Salary: ";
            cout<<temp->sal;
            cout<<endl;
        }
        temp=temp->next;
    }
}

//BUBBLE SORT
void sort_sal()
{
    int n=0;
    system("cls");
    struct employee *srt=new employee;
    srt=head;
    while(srt!=NULL)
    {
        n++;
        srt=srt->next;
    }
    int sort_sal[n];
    if(head==NULL)
    {
        cout<<endl;
        cout<<"Record is empty!!!";
    }
    else
    {
        cout<<endl;
        int i=0;
        srt=head;
        while(srt!=NULL)
        {
             sort_sal[i++]=srt->sal;
             srt=srt->next;
        }
    }
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(sort_sal[j]<sort_sal[j+1])
            {
                temp=sort_sal[j];
                sort_sal[j]=sort_sal[j+1];
                sort_sal[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
         display_sal(sort_sal[i]);
    }
}

//Display function with Employee salary as argument
void display_sal(int s_sal)
{
    struct employee *temp=head;
    while(temp!=NULL)
    {
        if(s_sal==temp->sal)
        {
            cout<<"\n\t\tEMPLOYEE DETAILS: ";
            cout<<endl;
            cout<<"Employee salary: ";
            cout<<temp->sal;
            cout<<endl;
            cout<<"Name: ";
            cout<<temp->name;
            cout<<endl;
            cout<<"Date of birth: ";
            cout<<temp->dob;
            cout<<endl;
            cout<<"Age: ";
            cout<<temp->age;
            cout<<endl;
            cout<<"Address: ";
            cout<<temp->add;
            cout<<endl;
            cout<<"Phone Number: ";
            cout<<temp->pno;
            cout<<endl;
            cout<<"Mail-ID: ";
            cout<<temp->email;
            cout<<endl;
            cout<<"Number of years  of experience in this field: ";
            cout<<temp->exp;
            cout<<endl;
            cout<<"Number of years  of experience in this company: ";
            cout<<temp->exp_co;
            cout<<endl;
            cout<<"Date of join: ";
            cout<<temp->doj;
            cout<<endl;
            cout<<"Working hours: ";
            cout<<temp->whrs;
            cout<<endl;
            cout<<"Salary: ";
            cout<<temp->sal;
            cout<<endl;
        }
        temp=temp->next;
    }
}

//SELECTION SORT
void sort_exp_co()
{
    int n=0;
    system("cls");
    struct employee *srt=new employee;
    srt=head;
    while(srt!=NULL)
    {
        n++;
        srt=srt->next;
    }
    int sort_exp_co[n];
    if(head==NULL)
    {
        cout<<endl;
        cout<<"Record is empty!!!";
    }
    else
    {
        cout<<endl;
        int i=0;
        srt=head;
        while(srt!=NULL)
        {
             sort_exp_co[i++]=srt->exp_co;
             srt=srt->next;
        }
    }
    int i,j,k,l,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            k=j;
            for(l=j+1;l<n;l++)
            {
                if(sort_exp_co[l]>sort_exp_co[k])
                {
                    k=l;
                }
            t=sort_exp_co[j];
            sort_exp_co[j]=sort_exp_co[k];
            sort_exp_co[k]=t;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
         display_exp_co(sort_exp_co[i]);
    }
}

//Display function with Employee's experience in this company as argument
void display_exp_co(int s_exp_co)
{
    struct employee *temp=head;
    while(temp!=NULL)
    {
        if(s_exp_co==temp->exp_co)
        {
            cout<<"\n\t\tEMPLOYEE DETAILS: ";
            cout<<endl;
            cout<<"Employee-ID: ";
            cout<<temp->id;
            cout<<endl;
            cout<<"Name: ";
            cout<<temp->name;
            cout<<endl;
            cout<<"Number of years  of experience in this company: ";
            cout<<temp->exp_co;
            cout<<endl;
            cout<<"Date of birth: ";
            cout<<temp->dob;
            cout<<endl;
            cout<<"Age: ";
            cout<<temp->age;
            cout<<endl;
            cout<<"Address: ";
            cout<<temp->add;
            cout<<endl;
            cout<<"Phone Number: ";
            cout<<temp->pno;
            cout<<endl;
            cout<<"Mail-ID: ";
            cout<<temp->email;
            cout<<endl;
            cout<<"Number of years  of experience in this field: ";
            cout<<temp->exp;
            cout<<endl;
            cout<<"Date of join: ";
            cout<<temp->doj;
            cout<<endl;
            cout<<"Working hours: ";
            cout<<temp->whrs;
            cout<<endl;
            cout<<"Salary: ";
            cout<<temp->sal;
            cout<<endl;
        }
        temp=temp->next;
    }
}

//displays total number of employees
void tot()
{
    system("cls");
    struct employee *temp;
    temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt==0)
    {
        cout<<endl;
        cout<<"No employee record exists!!";
    }
    else if(cnt==1)
    {
        cout<<endl;
        cout<<"Total number of employee is 1";
    }
    else
    {
        cout<<endl;
        cout<<"Total number of employees are "<<cnt;
    }
}

//quit the application
void quit()
{
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"************************************************************************************************************************";
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    cout<<endl;
    cout<<"\t\t\t\t\t\tTHANK YOU!!!";
    cout<<endl;
    cout<<"\t\t\t\t\t\tPAYROLL MANAGEMENT SYSTEM";
    cout<<endl;
    cout<<"\t\t\t\t\t\tDONE BY:";
    cout<<endl;
    cout<<"\t\t\t\t\t\t19PD09-DHIKSHITHA.A";
    cout<<endl;
    cout<<"\t\t\t\t\t\t19PD38-SWATHI PRATHAA.P";
    cout<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    cout<<"************************************************************************************************************************";
}
