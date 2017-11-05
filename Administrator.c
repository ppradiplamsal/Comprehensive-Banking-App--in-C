#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Administrator.h"
#include "Struct.h"


extern char adminPassword[6], tempVar[999];
extern struct Customer allCustomers[999];
extern int length;

//A Function to create customer account

void CreateCustomerAccount(){
    int element = 0, accountID;


    printf("Let's create a new Customer Account.\n");

    // First Name of the customer
    while(1){

        printf("Please enter the new Customer's First Name: ");
        gets(tempVar);

        if(strlen(tempVar) <= 0 || strlen(tempVar) > 8){
            printf("Invalid input, try again...\n");
        }
        else{
            strcpy(allCustomers[length].FirstName, tempVar);
            break;
        }

    }

    // Last Name of the customer
    while(1){

        printf("Please enter the new Customer's Last Name: ");
        gets(tempVar);

        if(strlen(tempVar) <= 0 || strlen(tempVar) > 8){
            printf("Invalid input, try again...\n");
        }
        else{
            strcpy(allCustomers[length].LastName, tempVar);
            break;
        }

    }

    // City of the customer
    while(1){

        printf("Please enter the new Customer's City Name: ");
        gets(tempVar);

        if(strlen(tempVar) <= 0 || strlen(tempVar) > 10){
            printf("Invalid input, try again...\n");
        }
        else{
            strcpy(allCustomers[length].City, tempVar);
            break;
        }

    }

    // State of the customer
    while(1){

        printf("Please enter the new Customer's State (abbreviation): ");
        gets(tempVar);

        if(strlen(tempVar) != 2){
            printf("Invalid input, try again...\n");
        }
        else{
            strcpy(allCustomers[length].State, tempVar);
            break;
        }

    }

    // Phone of the customer
    while(1){

        printf("Please enter the new Customer's 7-digit Phone Number (no \"-\"): ");
        gets(tempVar);

        if(strlen(tempVar) != 7 || atoi(tempVar) <= 0){
            printf("Invalid input, try again...\n");
        }
        else{
            strcpy(allCustomers[length].Phone, tempVar);
            break;
        }

    }

    // Account ID of the customer
    while(1){
        FAILED:
        element = 0;
        printf("Please enter the new Customer's Account ID: ");
        gets(tempVar);

        if(strlen(tempVar) != 5 || atoi(tempVar) <= 0){
            printf("Invalid input, try again...\n");
        }
        else{
            accountID = atoi(tempVar);
            while(element < length){
                if(accountID == allCustomers[element].AccountID){
                    printf("That account ID already exists... try again...\n");
                    goto FAILED;
                }
                else{
                    element++;
                }
                if(element == length){
                    allCustomers[length].AccountID = accountID;
                    goto SUCCESS;
                }
            }
        }
    }
    SUCCESS:



    // Password
    while(1){

        printf("Please enter the new Customer's Password: ");
        gets(tempVar);

        if(strlen(tempVar) <= 0 || strlen(tempVar) > 5){
            printf("Invalid input, try again...\n");
        }
        else{
            strcpy(allCustomers[length].Password, tempVar);
            break;
        }

    }

    printf("The account is now made with a balance of 0.00$.\n");
    allCustomers[length].Balance = 0;
    length++;
}

// B Changing Administrator's password

void ChangeAdminPassword(){
    printf("You are now changing the admin password...\n");
    printf("Input \"Cancel\" at any time to quit...\n");
    while(1){
        printf("What would you like to set the new password as: ");
        gets(tempVar);
        if(strlen(tempVar) == 5){
            break;
        }
        else if(strcmp(tempVar,"Cancel") == 0){
            break;
        }
        else{
            printf("Invalid input, try again...\n");
        }
    }
    if (strcmp(tempVar,"Cancel") == 0){
        printf("Canceling...");
    }
    else{
        strcpy(adminPassword,tempVar);
        printf("The new admin password is %s.\n", adminPassword);
    }

}

//  C To view the customer information

void ViewCustomerInformation(){
    int accountID, element;
    while(1){
        FAILED:
        element = 0;
        printf("Now trying to view a customer's account information.\n");
        printf("Input \"Cancel\" at any time to quit...\n");
        printf("Please enter a Customer's Account ID to view their information: ");
        gets(tempVar);
        if (strcmp(tempVar,"Cancel") == 0){
            printf("Canceling...");
            goto SUCCESS;
        }
        if(strlen(tempVar) != 5 || atoi(tempVar) <= 0){
            printf("Invalid input, try again...\n");
        }
        else{
            accountID = atoi(tempVar);
            while(element < length){
                if(accountID == allCustomers[element].AccountID){
                    char phone[9];
                    phone[0] = allCustomers[element].Phone[0];
                    phone[1] = allCustomers[element].Phone[1];
                    phone[2] = allCustomers[element].Phone[2];
                    phone[3] = '-';
                    phone[4] = allCustomers[element].Phone[3];
                    phone[5] = allCustomers[element].Phone[4];
                    phone[6] = allCustomers[element].Phone[5];
                    phone[7] = allCustomers[element].Phone[6];
                    printf("Account information....\n");
                    printf("First Name: %s\n",allCustomers[element].FirstName);
                    printf("Last Name:  %s\n",allCustomers[element].LastName);
                    printf("City:       %s\n",allCustomers[element].City);
                    printf("State:      %s\n",allCustomers[element].State);
                    printf("Phone:      %s\n",phone);
                    printf("Account ID: %d\n",allCustomers[element].AccountID);
                    printf("Password:   %s\n",allCustomers[element].Password);
                    printf("Balance:    %.2lf$\n",allCustomers[element].Balance);

                    goto SUCCESS;
                }
                else{
                    element++;
                }
                if(element == length){
                    printf("That account doesn't exist, Try again...\n");
                    goto FAILED;
                }
            }
        }
    }
    SUCCESS:;

}

//    D To change the customer information

void ChangeCustomerInformation(){
    int accountID, element, checker;
    while(1){
        FAILED:
        element = 0;
        printf("\n\nChanging customer information.\n");
        printf("Input \"Cancel\" at any time to quit...\n");
        printf("Please enter a Customer's Account ID to change their information: ");
        gets(tempVar);
        if (strcmp(tempVar,"Cancel") == 0){
            printf("Canceling...");
            goto SUCCESS;
        }
        if(strlen(tempVar) != 5 || atoi(tempVar) <= 0){
            printf("Invalid input, try again...\n");
        }
        else{
            accountID = atoi(tempVar);
            while(element < length){
                if(accountID == allCustomers[element].AccountID){
                    while(1){
                        printf("\n\n-------------------------\n");
                        printf("Change Menu\n");
                        printf("-------------------------\n");
                        printf("a) First Name\n");
                        printf("b) Last Name\n");
                        printf("c) City\n");
                        printf("d) State\n");
                        printf("e) Phone\n");
                        printf("f) Account ID\n");
                        printf("g) Password\n");
                        printf("h) Balance\n");
                        printf("i) Cancel\n");
                        printf("Enter option: ");
                        gets(tempVar);



                        //  First Name
                        if(strcmp(tempVar,"a") == 0){
                            while(1){

                                printf("Please enter the Customer's new First Name: ");
                                gets(tempVar);

                                if(strlen(tempVar) <= 0 || strlen(tempVar) > 8){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    strcpy(allCustomers[element].FirstName, tempVar);
                                    break;
                                }

                            }
                        }

                            //  Last name
                        else if(strcmp(tempVar,"b") == 0){
                            while(1){

                                printf("Please enter the Customer's new Last Name: ");
                                gets(tempVar);

                                if(strlen(tempVar) <= 0 || strlen(tempVar) > 8){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    strcpy(allCustomers[element].LastName, tempVar);
                                    break;
                                }

                            }
                        }
                            // City
                        else if(strcmp(tempVar,"c") == 0){
                            while(1){

                                printf("Please enter the customer's new city name: ");
                                gets(tempVar);

                                if(strlen(tempVar) <= 0 || strlen(tempVar) > 10){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    strcpy(allCustomers[element].City, tempVar);
                                    break;
                                }

                            }
                        }
                            //  State
                        else if(strcmp(tempVar,"d") == 0){
                            while(1){

                                printf("Please enter the Customer's new State (abbreviation): ");
                                gets(tempVar);

                                if(strlen(tempVar) != 2){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    strcpy(allCustomers[element].State, tempVar);
                                    break;
                                }

                            }
                        }
                            //  Phone
                        else if(strcmp(tempVar,"e") == 0){
                            while(1){

                                printf("Please enter the new Customer's 7-digit Phone Number (no \"-\"): ");
                                gets(tempVar);

                                if(strlen(tempVar) != 7 || atoi(tempVar) <= 0){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    strcpy(allCustomers[element].Phone, tempVar);
                                    break;
                                }

                            }
                        }
                            // Account ID
                        else if(strcmp(tempVar,"f") == 0){

                            while(1){
                                FAILED2:
                                checker = 0;
                                printf("Please enter the customer's new account ID: ");
                                gets(tempVar);

                                if(strlen(tempVar) != 5 || atoi(tempVar) <= 0){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    accountID = atoi(tempVar);
                                    while(checker < length){
                                        if(accountID == allCustomers[checker].AccountID){
                                            printf("That account ID already exists... try again...\n");
                                            goto FAILED2;
                                        }
                                        else{
                                            checker++;
                                        }
                                        if(checker == length){
                                            allCustomers[element].AccountID = accountID;
                                            goto SUCCESS2;
                                        }
                                    }
                                }
                            }
                            SUCCESS2:;
                        }
                            //  Password
                        else if(strcmp(tempVar,"g") == 0){
                            while(1){

                                printf("Please enter the Customer's new Password: ");
                                gets(tempVar);

                                if(strlen(tempVar) <= 0 || strlen(tempVar) > 5){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    strcpy(allCustomers[element].Password, tempVar);
                                    break;
                                }

                            }
                        }
                            //  Balance
                        else if(strcmp(tempVar,"h") == 0){
                            while(1){

                                printf("Please enter the customer's new balance: ");
                                gets(tempVar);

                                if(strlen(tempVar) == 0 || atof(tempVar) <= 0){
                                    printf("Invalid input, try again...\n");
                                }
                                else{
                                    allCustomers[element].Balance = atof(tempVar);
                                    break;
                                }

                            }
                        }
                            //  Cancel
                        else if(strcmp(tempVar,"i") == 0){
                            printf("Canceling...");
                            goto SUCCESS;
                        }

                    }
                }
                else{
                    element++;
                }
                if(element == length){
                    printf("That account doesn't exist, Try again...\n");
                    goto FAILED;
                }
            }
        }
    }
    SUCCESS:;
}

//    To delete customer account  E

void DeleteCustomerAccount(){
    int element, accountID;
    while(1){
        FAILED:
        element = 0;
        printf("Now trying to delete a customer's account.\n");
        printf("Input \"Cancel\" to quit...\n");
        printf("Please enter the customer's account ID to delete: ");
        gets(tempVar);
        if (strcmp(tempVar,"Cancel") == 0){
            printf("Canceling...");
            goto SUCCESS;
        }
        if(strlen(tempVar) != 5 || atoi(tempVar) <= 0){
            printf("Invalid input, try again...\n");
        }
        else{
            accountID = atoi(tempVar);
            while(element < length){
                if(accountID == allCustomers[element].AccountID){

                    allCustomers[element] = allCustomers[length - 1];

                    length--;
                    printf("Account deleted.");
                    goto SUCCESS;
                }
                else{
                    element++;
                }
                if(element == length){
                    printf("That account ID doesn't exist... try again...\n");
                    goto FAILED;
                }
            }
        }
    }
    SUCCESS:;
}

//   F  Displaying the top accounts

void ShowTopAccounts(){
    int i, j;
    struct Customer switcher;
    printf("The top five accounts;\n\n");
    for(i = 0; i <= length - 2; i++){
        for(j = i + 1; j <= length - 1; j++){
            if(allCustomers[i].Balance < allCustomers[j].Balance){
                switcher = allCustomers[i];
                allCustomers[i] = allCustomers[j];
                allCustomers[j] = switcher;
            }
        }
    }
    for(i = 0; i <= 4; i++){
        printf("%d) %s %s (%d)\n", i+1,allCustomers[i].FirstName,allCustomers[i].LastName,allCustomers[i].AccountID);
        printf("   with %.2lf$\n\n",allCustomers[i].Balance);
    }
}

//    G  Sorting the customer accounts

void ShowCustomerAccountsAlphabetically(){
    int i, j;
    struct Customer switcher;
    printf("The top five accounts;\n\n");
    for(i = 0; i <= length - 2; i++){
        for(j = i + 1; j <= length - 1; j++){
            if(strcmp(allCustomers[i].LastName,allCustomers[j].LastName) > 0){
                switcher = allCustomers[i];
                allCustomers[i] = allCustomers[j];
                allCustomers[j] = switcher;
            }
            else if(strcmp(allCustomers[i].LastName,allCustomers[j].LastName) == 0){
                if(strcmp(allCustomers[i].FirstName,allCustomers[j].FirstName) > 0){
                    switcher = allCustomers[i];
                    allCustomers[i] = allCustomers[j];
                    allCustomers[j] = switcher;
                }
            }
        }
    }
    for(i = 0; i < length; i++){
        printf("%d) %s %s (%d)\n", i+1,allCustomers[i].FirstName,allCustomers[i].LastName,allCustomers[i].AccountID);
        printf("   with %.2lf$\n\n",allCustomers[i].Balance);
    }
}

// the main control function to direct various user choices
void AdminMenu(void){
    while(1){
        printf("\n\n-------------------------\n");
        printf("Administrator Menu\n");
        printf("-------------------------\n");
        printf("a) Create Customer Account\n");
        printf("b) Change Password\n");
        printf("c) View Customer Information\n");
        printf("d) Change Customer Information\n");
        printf("e) Delete Customer Account\n");
        printf("f) Show Top 5 Accounts\n");
        printf("g) Show Customer Accounts Alphabetically\n");
        printf("h) Exit\n");
        printf("Enter option: ");
        gets(tempVar);

        if(strcmp(tempVar,"a") == 0){
            CreateCustomerAccount();
        }
        else if(strcmp(tempVar,"b") == 0){
            ChangeAdminPassword();
        }
        else if(strcmp(tempVar,"c") == 0){
            ViewCustomerInformation();
        }
        else if(strcmp(tempVar,"d") == 0){
            ChangeCustomerInformation();
        }
        else if(strcmp(tempVar,"e") == 0){
            DeleteCustomerAccount();
        }
        else if(strcmp(tempVar,"f") == 0){
            ShowTopAccounts();
        }
        else if(strcmp(tempVar,"g") == 0){
            ShowCustomerAccountsAlphabetically();
        }
        else if(strcmp(tempVar,"h") == 0){
            printf("Logging out...");
            break;
        }
        else{
            printf("Invalid input, try again...\n");
        }
    }
}
