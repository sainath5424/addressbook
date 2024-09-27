#include "contact.h"
int main()
{
    //all function calls should be inside the main 
    AddressBook addressBook;
    initialize(&addressBook);
    char ch;
    do{
    printf("Menu: \n");
    printf("1.create contact\n2.search contact\n3.edit contact\n4.delete contact\n5.list contact\n6.Exit");
    printf("Enter the choice:\n");
    scanf(" %c",&ch);
    switch(ch)
    {
        case '6':
                ch='n';
                break;
        case '1':
                createContact(&addressBook);
                break;
        case '2':
                searcheditContact(&addressBook);
                break;
        case '3':
                editContact(&addressBook);
                break;
        case '4':
                deleteContact(&addressBook);
                break;
        case '5':
                listContacts(&addressBook);
                break;
        default:
                break;
    }
    if(ch!='n'){
    printf("do you want to continue(y/n)");
    scanf(" %c",&ch);
    }
    }while(ch=='y');
}