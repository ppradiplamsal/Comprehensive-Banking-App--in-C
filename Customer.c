#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "Struct.h"

//Let program know the external values
extern char tempVar[999];
extern struct Customer allCustomers[999];
extern int element, length;

//Set ChangePassword function with void
void ChangePassword(){
    printf("You are now changing your password...\n");
    printf("Input \"Cancel\" at any time to quit...\n");
    //Set infinite loop that when user can break out when he/she wants to  
    while(1){
        printf("What would you like the password to be: ");
     	//Allow user to input value with gets 
	gets(tempVar);
        if(strlen(tempVar) == 5){
            //Break from the loop 
	    break;
        }
        else if(strcmp(tempVar,"Cancel") == 0){
            //break from the loop 
	    break;
        }
        else{
            printf("Invalid input, try again...\n");
        }
    }
    if (strcmp(tempVar,"Cancel") == 0);
    else{
        strcpy(allCustomers[element].Password,tempVar);
        printf("Your new password is %s.\n", allCustomers[element].Password);
    }

}
//set ViewMyInformation with void
void ViewMyInformation(){
    char phone[9];
    phone[0] = allCustomers[element].Phone[0];
    phone[1] = allCustomers[element].Phone[1];
    phone[2] = allCustomers[element].Phone[2];
    phone[3] = '-';
    phone[4] = allCustomers[element].Phone[3];
    phone[5] = allCustomers[element].Phone[4];
    phone[6] = allCustomers[element].Phone[5];
    phone[7] = allCustomers[element].Phone[6];


    printf("User information;\nFirst name: %s \nLast name: %s \nCity: %s \nState: %s \nPhone number: %s\n", allCustomers[element].FirstName, allCustomers[element].LastName, allCustomers[element].City, allCustomers[element].State, phone);

}
//set ViewBalance function with void
void ViewBalance(){

    printf("Your balance is %.2lf$.\n", allCustomers[element].Balance);

}
//Set MakeaDeposit function with void
void MakeaDeposit(){
    //Set infinite loop that when user can break out when he/she wants to 
    while(1){
        printf("your current balance is: %.2lf\n", allCustomers[element].Balance);
        printf("Please Enter an amount you want to deposit:\n");
     	//Allow user to input value with gets 
	gets(tempVar);
        //initialize depositamt with float set to atof(tempVar) 
	float depositamt = atof(tempVar);
        if(depositamt <= 0){
            printf("Invalid input...\nPlease enter a numerical value greater than 0.\n");
        }
        else{
            //Add value to costumer balance and display the result with printf and break from the loop 
	    allCustomers[element].Balance += depositamt;
            printf("your new balance is %.2lf$\n", allCustomers[element].Balance);
            break;
        }
    }
}

//implement the transfermoney function
void TransferMoney(){
    //Initialize count with int and set to 0 
    int count = 0;
    //Initilaize accountid with int 
    int accountid;
    //Set infinite loop that when user can break out when he/she wants to 
    while(1){
        printf("your current balance is: %.2lf\n", allCustomers[element].Balance);
        printf("Please enter a the transfer amount: ");
        //Allow user to input value with gets 
	gets(tempVar);
        //Initialize transferamt with float and set to atof(tempVar); 
	float transferamt = atof(tempVar);
        if(transferamt > 0){
            //remove the input value from current balance 
	    allCustomers[element].Balance -= transferamt;
            //Set infinite loop that when user can break out when he/she wants to   
	    LOOP: while(1){
                //set count to 0 
		count = 0;
                printf("Please enter an account ID to transfer this cash to: ");
                //Allow user to input value with gets 
		gets(tempVar);
                if(strlen(tempVar) == 5){
                    //set accountid to atoi(tempVar) 
		    accountid = atoi(tempVar);
                    //create a while loop for when count smaller than length 
		    while(count < length){
                        if(accountid == allCustomers[count].AccountID){
                            //Add value to the chosen ID balance and display the result with printf then break from the loop 
			    allCustomers[count].Balance += transferamt;
                            printf("Transfer successful");
                            break;
                        }
                        else{
                            count++;
                        }
                        if(count == length){
                            printf("Invalid Account ID, please try again...\n");
                            goto LOOP;
                        }
                    }
                    break;
                }
                else{
                    printf("Please enter a valid AccountID");
                }

            }
            break;

        }
        else if(transferamt < 0){
            printf("Please try again!!");
        }

    }

}

//implement the money withdraw function
void withdraw(){
    while(1){
        if(allCustomers[element].Balance == 0){
            printf("You have no money to withdraw...\n");
            break;
        }
        printf("You are now withdrawing money from your account...\n");
        printf("Input \"Cancel\" to cancel.\n");
        printf("Please enter an amount you want to withdraw: ");
        gets(tempVar);
        if(strcmp(tempVar, "Cancel") == 0){
            printf("Canceling...\n");
            break;
        }
        float withdrawamt = atof(tempVar);
        if (withdrawamt > 0){
            if(withdrawamt <= allCustomers[element].Balance){
                printf("Now withdrawing %.2f$\n",withdrawamt);
                allCustomers[element].Balance -= withdrawamt;
                printf("your new balance is %.2lf$\n", allCustomers[element].Balance);
                break;
            }
            else{
                printf("Insuficient balance for this transaction.\n");
            }
        }
        else{
            printf("Invalid input...\nPlease enter a numerical value greater than 0.\n");
        }
    }
}

//display the menu and various options for the customer
void CustomerMenu(){
    while(1){
        printf("-------------------------\n");
        printf("Customer Menu\n");
        printf("-------------------------\n");
        printf("a) Change Password\n");
        printf("b) View Customer Information\n");
        printf("c) View Balance\n");
        printf("d) Make a Deposit\n");
        printf("e) Transfer Money\n");
        printf("f) Withdraw Money\n");
        printf("g) Exit\n");
        printf("Enter option: ");
        gets(tempVar);

        if(strcmp(tempVar,"a") == 0){
            ChangePassword();
        }
        else if(strcmp(tempVar,"b") == 0){
            ViewMyInformation();
        }
        else if(strcmp(tempVar,"c") == 0){
            ViewBalance();
        }
        else if(strcmp(tempVar,"d") == 0){
            MakeaDeposit();
        }
        else if(strcmp(tempVar,"e") == 0){
            TransferMoney();
        }
        else if(strcmp(tempVar,"f") == 0){
            withdraw();
        }
        else if(strcmp(tempVar,"g") == 0){
            printf("Logging out...");
            break;
        }
        else{
            printf("Invalid input, try again...\n");
        }

    }

}

