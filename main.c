#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int readFromUser(char commands[], char *args[]){
    char *current_LINE[1030];
    int positionCounter=0;
    int total_number_of_words=0; // variable to store the total number of words inputed by user
    char *all_WORDS_INPUTED[100];
    char*tempChar;

    while(1){
        int userINPUT = fgetc(stdin); // this line gets what is inputed by the user

        current_LINE[positionCounter++]=(char)userINPUT; // stores the user input character by character in the array current_LINE

        if(userINPUT=='\n')break; /* this means that the user has already written
                                    the input,so we break the loop  */
    }
    if(positionCounter == 1) return;

    tempChar=strtok(current_LINE," \n");
/*  strtok breaks the line into "tokens"
    so we can parse the line into words (below)
*/
    while( tempChar!= NULL ){

        all_WORDS_INPUTED[total_number_of_words++] = strdup(tempChar);
        tempChar = strtok(NULL, " \n");

    }

    strcpy(commands, all_WORDS_INPUTED[0]); //We store the command as the first element

    int currPar=1; // current parameter number (used as the position when adding the parameters in array
    for(; currPar<total_number_of_words; currPar++){

        //insert the arguments in the array of arguments
        args[currPar]=all_WORDS_INPUTED[currPar];

    }
    args[total_number_of_words]=NULL; // the last argument must be NULL

    return total_number_of_words-1;
}


int main()
{
    char commands[100]; // all commands will be stored there
    char command[100];  // this will be passed as a parameter in readFromUser function
    char *args[10]; // this will hold the parameters

    int run=1;
    while(run){ // with this while loop we repeat forever (until the user terminates it)
        printf("$ ");

        int lastPosOfArgs=readFromUser(command,args); //  reads the command from the terminal
        if(fork()!=0)wait(NULL); // here it waits for the child
        else{
            strcpy(commands,"/bin/");
            strcat(commands, command);
            execvp(commands, args); // execute the command
            if(args[lastPosOfArgs]== '&')wait(); // if command included &, then parent will invoke wait()
        }
        if(strcmp(command, "exit") == 0)run=0; // break the loop
    return 0;
}

}


