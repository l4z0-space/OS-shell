# Shell Code Description

* Code is mainly made of main(), and readFromUser() function.
* Initially I have declared three arrays or chars in the int main(): commands, command and args (parameters or arguments).
* After that, a while loop which run  infinitely firstly print the prompt for the user showing the “$” sign, after which the user can enter command. 
* Then, the readFromUser() function follows, which takes as parameters the command array of chars and parameters. What we do here, is to get the user input and store it in the current_LINE() arrays of chars declared in the beginning of the function.
* The we parse all the words one by one, and we store the first word as the command and the other remaining words as arguments.
* Also, an important thing is to make sure that we store the last element of arguments as NULL, in order to make signalize an end of parameters. In the end we return 
* After we read the input from the user, we fork a child process using fork(), then the child process will invoke execvp(), which will execute the command.
* And lastly, if the command inputted included an ampersand “&”, then the parent and the child will run concurrently (child will run in the background). The use of “&” is very important because otherwise the parent process would have to wait for the child to finish executing.
* Lastly, an “exit” command will terminate the whole shell.
