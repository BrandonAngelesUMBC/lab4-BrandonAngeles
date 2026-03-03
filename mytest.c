#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern int sum_ints(int *arr, int size);                        // Assembly function with two parameters and int return type
int main()
{
    FILE *dataFile;
    bool validFile = false;
    char fileName[100];                                         // Initialize fileName 

    while(!validFile){
        printf("Enter file name: ");                            // Prompt for user input
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = '\0';               // Remove "\n" from the string to prevent extra bits

        dataFile = fopen(fileName, "r");

        if(dataFile == NULL){                                   // If unable to open text file, prompt user again
            printf("Error opening file\n");
        }else{
            printf("Reading data from file..\n");               // When valid file opened, exit while loop
            validFile = true;
        }
    }

    int totalNums = 0;
    int counter = 0;
    int currNum = 0;
    
    fscanf(dataFile, "%d", &totalNums);                         // Total nums obtained from first line of text file

    int nums[totalNums];                                        // Initialize integer array of size totalNums

    while(fscanf(dataFile, "%d", &currNum) == 1){               // Store the following nums in the array
        nums[counter] = currNum;   
        counter++;
    }

    fclose(dataFile);                                           // Close the file

    int sum = sum_ints(nums, totalNums);                        // Call the Assembly function sum_ints

    printf("Total sum: %d\n", sum);                             // Print returned sum

    return 0;
}