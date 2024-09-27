#include "contact.h"
extern Contact dummyContacts[10];
void red () {
  printf("\033[1;31m");
}
void yellow (){
  printf("\033[1;33m");
}

void blue ()
{
    printf("\033[0;34m ");
}

void cyan()
{
    printf("\033[0;36m ");
}
void green()
{
    printf("\033[0;32m");
}
void reset () {
  printf("\033[0m");
}

void print_info()
{
printf(": %-10s: %-30s: %-30s: %-20s:\n","S.No","Name","Phone No","Email ID");
}
void listContacts(AddressBook *addressBook) 
{
        print_equalto();
        printf("\n");
        print_info();
        print_equalto();
        printf("\n");
        for(int i=0;i<addressBook->contactCount;i++)
        {
        printf(": %-10d: %-30s: %-30s: %-20s:\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        print_equalto();
        printf("\n");
}

void initialize(AddressBook *addressBook) 
{
        int num=sizeof(dummyContacts)/sizeof(dummyContacts[0]);
        for(int i=0;i<num;i++)
        {
        addressBook->contacts[i]=dummyContacts[i];
        }
        addressBook->contactCount=num;
}

void createContact(AddressBook *addressBook) 
{
        char tempname[50];
        char tempphone[20];
        char tempemail[50];
        int n=0,p=0,e=0;
        yellow();
        printf("##### Address Book #####\n");
        printf("##### Add Contact: #####\n");
        reset();
name:
        blue();
        printf("\nEnter the name : ");
        reset();
        scanf(" %[^\n]",tempname);
        for(int i=0;tempname[i]!='\0';i++)
        {
        if((tempname[i]>='a' && tempname[i]<='z')||(tempname[i]>='A' && tempname[i]<='Z'));
        else
        {
        red();
        printf("##### Please Enter Only Characters in Name #####\n");
        reset();
        goto name;
        }
        }
        for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(addressBook->contacts[i].name,tempname)==0)
        {
        n=0;
        red();
        printf("##### Name already present #####\n");
        reset();
        goto name;
        }
        }
        n=1;  
        if(n==1){
        blue();
        printf("\nName : ");
        reset();
        printf("%s",tempname);
        
phone:
        blue();
        printf("\nEnter the ph.no: ");
        reset();
        scanf(" %[^\n]",tempphone);
        int i=0;
        for( i=0;tempphone[i];i++)
        {
        if(tempphone[i]>='0' && tempphone[i]<='9');
        else
        {
        red();
        printf("#####Number consists of characters#####");
        reset();
        goto phone;
        break;
        }
        }
        if(i==10){
        for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(addressBook->contacts[i].phone,tempphone)==0)
        {     
        red();
        printf("Number is already present\n");
        reset();
        goto phone;
        p=0;
        }
        else
        {
        p=1;
        }
        }
        }
        else
        {
        p=0;
        red();
        printf("\n#####Invalid Phone number##### \n");
        reset();
        //goto phone;
        if(i<10)
        {
        red();
        printf("..... Number consists of less Digits .....\n");
        reset();
        }
        else if(i>10)
        {
        red();
        printf("..... Number consists of More Digits .....\n");
        reset();
        }
        goto phone;
        }  
        }
       if(p==1)
        {
        blue();
        printf("\nName :");
        reset();
        printf("%s",tempname);
        blue();
        printf("\nPhone :");
        reset();
        printf("%s",tempphone);
        
email:
        blue();
        printf("\nEnter the e.mail: ");
        reset();
        scanf(" %[^\n]",tempemail);
        e=1;
        if(strrchr(tempemail,'@')!=NULL)
        {
        if(strstr(tempemail,".com")!=NULL)
        {
        if(strrchr(tempemail,'@')+1*sizeof(char)!=strstr(tempemail,".com"))
        {
        for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(addressBook->contacts[i].email,tempemail)==0)
        {
        red();
        printf("Email is Already Present\n");
        reset();
        e=0;
        goto email;
        }
        else
        {
        e=1;     
        }
        }
        }
        else
        {
        red();
        printf("Email don't have any characters b/w @ and .com\n");
        reset();
        goto email;
        }
        }
        else
        {
        e=0;
        red();
        printf("##### Invalid email format ######\n");
        printf(" Email don't have \".com\" \n");
        reset();
        goto email;
        }
        }
        else
        {
        e=0;
        red();
        printf("##### Invalid email format ######\n");
        printf(" Email don't have \"@\" \n");
        reset();
        goto email;
        }
        }
        if(e==1)
        {
        blue();
        printf("\nName :");
        reset();
        printf("%s",tempname);
        blue();
        printf("\nPhone :");
        reset();
        printf("%s",tempphone);
        blue();
        printf("\nEmail :");
        reset();
        printf("%s",tempemail);
        }
        if (n && p && e) 
        {
        strcpy(addressBook->contacts[addressBook->contactCount].name,tempname);
        strcpy(addressBook->contacts[addressBook->contactCount].phone,tempphone);
        strcpy(addressBook->contacts[addressBook->contactCount].email,tempemail);
        addressBook->contactCount++;
        green();
        printf("\nContact added successfully!\n");
        reset();
        }       
}
int checksno(int sno,int count)
{
        if (sno < 1 || sno > count) 
        {
        return 1;
        }
        return 0;
}
int initialise_sno(int sno,int*arr)
{
        for(int i=0;i<=sno;i++)
        {
        if(sno==i)
        {
        sno=arr[i];
        break;
        }
        }
        return sno;
}
void editContact(AddressBook *addressBook) 
{
        int sno,res=1;
        char ch;
        char tempname[50];
        char tempphone[20];
        char tempemail[50];
        int *arr= searcheditContact(addressBook);
        if(arr[1]==0)
        {
                res=0;
        }
        else
        {
        blue();
        printf("Enter the serial no to edit contact: ");
        reset();
        scanf("%d",&sno);
        }
        
        sno=initialise_sno(sno,arr);
       if(res==1)
       {
        int out=checksno(sno,addressBook->contactCount);
        if(out) 
        {
                red();
                printf("Invalid serial number!\n");
                reset();
                res=0;
        }
        do
        {
        yellow();
        printf("##### Address Book #####\n");
        printf("##### Edit Contact:\n");
        reset();
        blue();
        printf("\n0. Back\n");
        printf("1. Name: ");
        reset();
        printf("%s",addressBook->contacts[sno-1].name);
        blue();
        printf("\n2. ph.no: ");
        reset();
        printf("%s",addressBook->contacts[sno-1].phone);
        blue();
        printf("\n3. e.id: ");
        reset();
        printf("%s",addressBook->contacts[sno-1].email);
        blue();
        printf("\nPlease select an option to Edit: ");
        reset();
        scanf(" %c",&ch);
        switch(ch)
        {
        case '0':
        green();
        printf("Exit successfully\n");
        reset();
        ch='0';
        break;
        case '1':
                //name:
                blue();
                printf("\nEnter the name : ");
                reset();
                scanf(" %[^\n]",tempname);
                for(int i=0;tempname[i]!='\0';i++)
                {
                if((tempname[i]>='0' && tempname[i]<'9'))
                {
                red();
                printf("Please enter only characters in name\n");
                reset();
                 ch='0';
                 break;
                }
                }
                for(int i=0;i<addressBook->contactCount;i++)
                {
                if(strcmp(addressBook->contacts[i].name,tempname)==0)
                {
                        red();
                        printf("Name already present\n");
                        reset();
                         ch='0';
                         break;
                }
                }
                strcpy(addressBook->contacts[sno-1].name,tempname);
                ch='0';
                green();
                printf("Edited the name Successfully\n");
                reset();
                break;
                               
        case '2':
                blue();
                printf("\nEnter the ph.no: ");
                reset();
                scanf(" %[^\n]",tempphone);
                int i=0;
                for( i=0;tempphone[i];i++)
                {
                if(tempphone[i]<'0' || tempphone[i]>'9') 
                {
                red();
                printf("#####Number consists of characters#####");
                reset();
                ch='0';          
                break;
                }
                };
                if(i==10)
                {
                for(int i=0;i<addressBook->contactCount;i++)
                {
                if(strcmp(addressBook->contacts[i].phone,tempphone)==0)
                {          
                red();     
                printf("Number is already present\n");
                reset();
                ch='0';          
                }
                }
                }
                else
                {
                red();
                printf("\n#####Invalid Phone number##### \n");
                reset();
                ch='0';
                break;
                }
                strcpy(addressBook->contacts[sno-1].phone,tempphone);
                ch='0';
                green();
                printf("Edited the phone number Successfully\n");
                reset();
                break;
        case '3':
                char *res,*out;
                blue();
                printf("\nEnter the e.mail: ");
                reset();
                scanf(" %[^\n]",tempemail);
                res=strrchr(tempemail,'@');
                out=strstr(tempemail,".com");
                if(res!=NULL)
                {
                if(out!=NULL)
                {
                for(int i=0;i<addressBook->contactCount;i++)
                {
                if(strcmp(addressBook->contacts[i].email,tempemail)==0)
                {
                red();
                printf("email is already present\n");
                reset();
                ch='0';
                break;
                }
                }
                }
                else
                {
                ch='0';
                red();
                printf("##### Invalid email format ######\n");
                printf(" Please enter \".com\"\n");
                reset();
                break;   
                }
                }
                else
                {
                ch='0';
                red();
                printf("##### Invalid email format ######\n");
                printf(" Please enter \"@\"\n");
                reset();
                break;
                }
                strcpy(addressBook->contacts[sno-1].email,tempemail);
                ch='0';
                green();
                printf("Edited the email Successfully\n");
                reset();
                break;
        default:
                red();
                printf("Invalid choice! Please try again.\n");
                reset();
                break;
        }
        }
        while(ch!='0');
       }            
}

void deleteContact(AddressBook *addressBook) 
{
        int sno,i,res=1;
        int *arr= searcheditContact(addressBook);
        if(arr[1]==0)
        {
                res=0;
        }
        else
        {
        blue();
        printf("Enter the serial no to edit contact: ");
        reset();
        scanf("%d",&sno);
        }
        if(res==1)
        {
        int out=checksno(sno,addressBook->contactCount);
        if(out) 
        {
        red();
        printf("Invalid serial number!\n");
        reset();
        res=0;
        }
        sno=initialise_sno(sno,arr);
        blue();
        printf("1. Name: ");
        reset();
        printf("%s",addressBook->contacts[sno-1].name);
        blue();
        printf("\n2. ph.no: ");
        reset();
        printf("%s",addressBook->contacts[sno-1].phone);
        blue();
        printf("\n3. e.id: ");
        reset();
        printf("%s",addressBook->contacts[sno-1].email);
        if(res==1){
        for(i=sno-1;i<addressBook->contactCount-1;i++){
        addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
        green();
        printf("\nContact Deleted Successfully\n");
        reset();
        }
        }        
}
void print_equalto(){
        for(int i=0;i<MAX_CONTACTS;i++)
        {
        printf("=");
        }  
}
void display(AddressBook *addressBook,int sno,int i)
{
        printf(": %-10d: %-30s: %-30s: %-20s:\n",sno,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);   
}
int *searcheditContact(AddressBook*addressBook)
{
        char ch;
        int temp,ex=1;
        int count=0;
        static int arr[10];
        arr[0]=0;
        do{
        yellow();
        printf("##### Address Book ######\n");
        printf("##### Search Contact by: \n");
        reset();
        blue();
        printf("0. Back\n");
        printf("1. Name\n");
        printf("2. Phone No\n");
        printf("3. Email ID\n");
        printf("4. Serial No:\n");
        printf("Please Select an option :");
        reset();
        scanf(" %c",&ch);
        switch(ch){
        case '0':
                green();
                printf("Exit Successfully\n");
                reset();
                ex=0;
                arr[1]=0;
                return arr;
                break;
        case '1':
                red();
                printf("\nEnter the name : ");
                reset();
                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
                print_equalto();
                printf("\n");
                cyan();
                print_info();
                reset();
                print_equalto();
                printf("\n");
                int sno=1;
                count=0;
                for(int i=0;i<addressBook->contactCount;i++)
                {                        
                if(strstr(addressBook->contacts[i].name,addressBook->contacts[addressBook->contactCount].name)!=NULL)
                {
                count++;
                arr[sno]=i+1;
                display(addressBook,sno++,i);
                }
                }
                print_equalto();
                printf("\n");
                if(!count){
                red();
                printf("Name Not Found\n");
                reset();
                ex=0;
                }
                ex=0;
                break;
        case '2':
                count=0;
                blue();
                printf("Enter the phone no :\n");
                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
                print_equalto();
                printf("\n");
                yellow();
                print_info();
                reset();
                print_equalto();
                printf("\n");
                for(int i=0;i<addressBook->contactCount;i++){
                if(strstr(addressBook->contacts[i].phone,addressBook->contacts[addressBook->contactCount].phone)!=NULL)
                {
                  arr[++count]=i+1;
                display(addressBook,count,i);   
                }
                }
                print_equalto();
                printf("\n");
                if(!count){
                red();
                printf("Phone number not found\n");
                reset();
                ex=0;  
                }
                ex=0;
                break;     
        case '3':
                count=0;
                blue();
                printf("Enter the email:\n");
                reset();
                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
                print_equalto();
                printf("\n");
                yellow();
                print_info();
                reset();
                print_equalto();
                printf("\n");
               for(int i=0;i<addressBook->contactCount;i++){
                if(strstr(addressBook->contacts[i].email,addressBook->contacts[addressBook->contactCount].email)!=NULL)
                {
                arr[++count]=i+1;
                display(addressBook,count,i);
                }
                }
                print_equalto();
                printf("\n");
                if(!count){
                red();
                printf("Email not Found\n");
                reset();
                ex=0;
                }
                ex=0;
                break; 
        case '4':
                blue();
                printf("Enter the serial number : ");
                reset();
                scanf("%d",&temp);
                if (temp < 1 || temp > addressBook->contactCount) 
                {
                red();
                printf("Invalid serial number!\n");
                reset();
                ex=0;
                }
                else{
                int count=1;
                print_equalto();
                printf("\n");
                yellow();
                print_info();
                reset();
                print_equalto();
                printf("\n");
                display(addressBook,count,temp-1);
                ex=0;
                print_equalto();
                printf("\n");
                }
                break;
        default :
        red();
                printf("Invalid Choice\n");
                reset();
                ex=0;
                break;
                }
        }while(ex!=0);
        return arr;
}
