#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

//static int arr[10];
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void display(AddressBook *addressBook,int sno,int i);
void print_equalto();
int*searcheditContact(AddressBook*addressBook);
int checksno(int sno,int count);
int intialise_sno(int sno,int*arr);
void red();
void green();
void yellow();
void blue();
void cyan();
#endif
