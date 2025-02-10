//Name: Caden-Gamer14 
//Date: 2/10/2025 
//File: process_program.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define finalChildNum 10

void taskCommands(int childProcessNum) {

    char *args[3];

    //Creates a switch statement to output each child process 
    switch (childProcessNum) { 

        //Each case represents a different child process command 
        //Case 0 uses an echo command 
        case 0:
            args[0] = "echo"; 
            args[1] = "Hello Caden-Gamer14!"; 
            args[2] = NULL; 
            break; 
        //Case 1 uses an ls command 
        case 1: 
            args[0] = "ls"; 
            args[1] = NULL; 
            break; 
        //Case 2 uses the date command 
        case 2: 
            args[0] = "date"; 
            args[1] = NULL; 
            break; 
        //Case 3 uses the pwd command 
        case 3:
            args[0] = "pwd"; 
            args[1] = NULL; 
            break; 
        //Case 4 uses another echo command 
        case 4:
            args[0] = "echo"; 
            args[1] = "Hello Again D00d!"; 
            args[2] = NULL; 
            break; 
        //Case 5 uses the whoami command 
        case 5: 
            args[0] = "whoami"; 
            args[1] = NULL; 
            break; 
        //Case 6 uses the uptime command 
        case 6: 
            args[0] = "uptime"; 
            args[1] = NULL; 
            break; 
        //Case 7 uses another echo command 
        case 7:
            args[0] = "echo"; 
            args[1] = "Hello Yet Again D00ds!"; 
            args[2] = NULL; 
            break; 
        //Case 8 uses the uname command 
        case 8:
            args[0] = "uname"; 
            args[1] = NULL; 
            break; 
        //Case 9 uses a final echo command 
        case 9: 
            args[0] = "echo"; 
            args[1] = "Hello for the last time D00ds!"; 
            args[2] = NULL; 
            break; 
        //Creates a default case if the child processes do not work 
        default:
            fprintf(stderr, "Error D00d!\n"); 
            exit(EXIT_FAILURE); 

    }

    //Uses the execvp to execute the commands 
    execvp(args[0], args); 

    //Uses perror if the child processes fail in the execution 
    perror("Execution Failed"); 

    //Gives an error output 
    exit(EXIT_FAILURE);

}

//The main c method 
int main() {

    //Uses pids to find the child ID 
    pid_t pids[finalChildNum]; 

    //Creates the commandStatusVar variable to determine what the status of each command is 
    int commandStatusVar; 

    //Creates a for loop to go through each child process 
    for (int i = 0; i < finalChildNum; i++) { 

        //Uses the fork() command to run each child process 
        pids[i] = fork(); 

        //Creates an if statement to determine if the child processes fail or not 
        if (pids[i] < 0) {

            perror("Fork Unsuccessful"); 
            
            exit(EXIT_FAILURE); 

        //Creates an else if statement for when the child processes succeed 
        } else if (pids[i] == 0) { 
            
            //Runs the taskCommands method to run all of the child processes 
            taskCommands(i); 

            exit(EXIT_SUCCESS); 

        }
    }

    //Creates a for loop to run the parent processes 
    for (int i = 0; i < finalChildNum; i++) {

        //Creates the childID variable of type pid, using the wait command for each child process to finish 
        pid_t childID = wait(&commandStatusVar);

        //Creates an if statement to determine the outputs 
        if (childID > 0) { 
            
            //Creates a second if statement to showcase the child processes 
            if (WIFEXITED(commandStatusVar)) {

                printf("Child Process %d Completed\n", childID, WEXITSTATUS(commandStatusVar));

            //Creates an else if statement to showcase if the child processes terminate 
            } else if (WIFSIGNALED(commandStatusVar)) {

                printf("Child Process %d Terminated\n", childID, WTERMSIG(commandStatusVar));

            } 

        //Creates an else statement if anything fails 
        } else {

            perror("Complete Failure");

        }
    }

    //Creates a final printf statement to complete the program 
    printf("All child processes have completed.\n"); 
    
    return 0; 

} 