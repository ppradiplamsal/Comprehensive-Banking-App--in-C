/* A banking software created by Yavuz Can Kocoglu
				 Pradip Lamsal
				 Yildirim Kocoglu
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Administrator.h"
#include "Customer.h"
#include "Struct.h"

//the first record in the CustomerData file belongs to the admin
char adminPassword[6] = "admin", tempVar[999];

//declare the array of structures
struct Customer allCustomers[999];
int element = 0, length;

//declare structures and integer variables to implement lock in the file
struct flock f;
int fd;

//implementing getInfo function to read the data from the customer file into the array of structure
int getInfo(char argv[]){
    FILE *CustomerData = fopen(argv,"r");

//codes to implement file lock and prevent multiple users from accesing the program at the same time  
fd = open( argv, O_RDWR );
if( fd == -1 ) {
printf("We failed to open %s", argv);  /* error handling */
}
 
f.l_type = F_WRLCK;
f.l_start = 0;
f.l_whence = SEEK_SET;
f.l_len = 0;
 
if( fcntl( fd, F_SETLK, &f ) < 0 ) {
  perror( "Failed to lock" );
}
 
//writing data from the customer file into the respective places in the array of structure   
int counter = 0;

    while(!feof(CustomerData)){
        fscanf(CustomerData, "%s %s %s %s %s %d %s %lf", allCustomers[counter].FirstName,allCustomers[counter].LastName,allCustomers[counter].City,allCustomers[counter].State,allCustomers[counter].Phone,&(allCustomers[counter].AccountID),allCustomers[counter].Password, &(allCustomers[counter].Balance));
        counter++;
    }

    fclose(CustomerData);

    return counter;
}

//function to print the updated data from the array of structures into the file
void giveInfo(char argv[]){
    FILE *CustomerData = fopen(argv,"w");
    int counter = 0;
    while(counter < length){
        fprintf(CustomerData, "%s %s %s %s %s %d %s %.2lf", allCustomers[counter].FirstName,allCustomers[counter].LastName,allCustomers[counter].City,allCustomers[counter].State,allCustomers[counter].Phone,(allCustomers[counter].AccountID),allCustomers[counter].Password, (allCustomers[counter].Balance));
        counter++;
        if(counter < length){
            fprintf(CustomerData, "\r\n");
        }
    }

    fclose(CustomerData);
}

//main function to print the welcome message and direct the user accordingly
int main(int argc, char * argv[]) {
    char password[6], accountID[6], tempID[7];
    int counter = 0, check = 0, trash;


    length = getInfo(argv[1]);


    while(1){
        check = 0;
        element = 0;
        printf("\n\nWelcome to Online Banking/ATM system \n");
        printf("==================================== \n\n");
        printf("(Quit to exit)\n");
        printf("Enter you Customer/Admin ID: ");
        gets(accountID);

        if(strcmp(accountID, "Quit") == 0){
            printf("Thank you for your time...");
            break;
        }
        printf("Enter you Customer/Admin Password: ");
        gets(password);
	
	//if the userID and password both are "admin" then goto the administrator's welcome page
        if(strcmp(accountID, "admin") == 0){
            if(strcmp(password,adminPassword) == 0){
                AdminMenu();
                check++;
            }
        }

	//directing the user to the customer page based on their userID and password
        if(check != 1){
            while(element < length){
                sprintf(tempID, "%d", (allCustomers[element].AccountID));
                if(strcmp(accountID, tempID) == 0){
                    if(strcmp(password,allCustomers[element].Password)==0){
                        CustomerMenu();
                        check++;
                    }
                    break;
                }
                element++;
            }
        }
        if(check != 1){
            printf("Invalid input, Please Try again... \n");
        }
    }
    //updating the file at the end
    giveInfo(argv[1]);

    return 0;

}