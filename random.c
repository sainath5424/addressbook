
/*void searchContact(AddressBook *addressBook) 
{
        char ch;
        char tempname[50];
        char tempphone[20];
        char tempemail[50];
        int temp,count,ex=1;
        do{
                printf("##### Address Book ######\n");
                printf("##### Search Contact by: \n");
                printf("0. Back\n");
                printf("1. Name\n");
                printf("2. Phone No\n");
                printf("3. Email ID\n");
                printf("4. Serial No:\n");
                printf("Please Select an option :");
                scanf(" %c",&ch);
                switch(ch){
                        case '0':
                        printf("Exit Successfully\n");
                        ex=0;
                        break;
                        case '1':
                                printf("\nEnter the name : ");
                                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
                                for(int i=0;tempname[i]!='\0';i++){
                                if((tempname[i]<'a' && tempname[i]>'z')|| (tempname[i]<'A' && tempname[i]>'Z')){
                                printf("Please enter only characters in name\n");
                                ex=0;
                                break;
                                }
                                }
                                print_equalto();
                                printf("\n");
                                printf(": %-10s: %-30s: %-30s: %-20s:\n","S.No","Name","Phone No","Email ID");
                                print_equalto();
                                printf("\n");
                                for(int i=0;i<addressBook->contactCount;i++){
                                if(strstr(addressBook->contacts[i].name,addressBook->contacts[addressBook->contactCount].name)!=NULL)
                                {
                                        temp=i;
                                        count++; 
                                        display(addressBook,count,temp,temp+1);
                                }
                                }
                                print_equalto();
                                printf("\n");
                                if(!count){
                                        printf("Name Not Found\n");
                                     ex=0;
                                }
                                ex=0;
                        break;
                        case '2':
                              
                                count=0;
                                printf("Enter the phone no :\n");
                                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
                                print_equalto();
                                printf("\n");
                                printf(": %-10s: %-30s: %-30s: %-20s:\n","S.No","Name","Phone No","Email ID");
                                print_equalto();
                                printf("\n");
                                for(int i=0;i<addressBook->contactCount;i++){
                                if(strstr(addressBook->contacts[i].phone,addressBook->contacts[addressBook->contactCount].phone)!=NULL)
                                {
                                        temp=i;
                                        count++;
                                        display(addressBook,count,temp,temp+1);
                                }
                                }
                                print_equalto();
                                printf("\n");
                                if(!count){
                                        printf("Phone number not found\n");
                                        ex=0;
                                }
                                ex=0;
                                break; 
                        case '3':
                                count=0;
                                printf("Enter the email:\n");
                                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
                                 print_equalto();
                                printf("\n");
                                printf(": %-10s: %-30s: %-30s: %-20s:\n","S.No","Name","Phone No","Email ID");
                                print_equalto();
                                printf("\n");
                               for(int i=0;i<addressBook->contactCount;i++){
                                if(strstr(addressBook->contacts[i].email,addressBook->contacts[addressBook->contactCount].email)!=NULL)
                                {
                                        temp=i;
                                        count++;
                                        display(addressBook,count,temp,temp+1);
                                        
                                      
                                }
                                }
                                print_equalto();
                                printf("\n");
                                if(!count){
                                printf("email not found\n");
                                ex=0;   
                                }
                                ex=0;
                                break;
                                
                        case '4':
                                printf("Enter the serial number : ");
                                scanf("%d",&temp);
                                 if (temp < 1 || temp > addressBook->contactCount) 
                                 {
                                printf("Invalid serial number!\n");
                                ex=0;
                                 }
                                else{
                                        int count=1;
                                print_equalto();
                                printf("\n");
                                printf(": %-10s: %-30s: %-30s: %-20s:\n","S.No","Name","Phone No","Email ID");
                                print_equalto();
                                printf("\n");
                                display(addressBook,count,temp-1,temp);
                                ex=0;
                                print_equalto();
                                printf("\n");
                                }
                                break;
                        default :
                        printf("Invalid Choice\n");
                        ex=0;
                        break;
                }
        }while(ex!=0);
}*/