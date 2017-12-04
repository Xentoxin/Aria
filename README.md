# Aria - A Shell in C
by Haoyu Chen
### Features
* Forking children adn executing commands from them
* Parsing multiple commands in one lane with ;
* Builtin Commands : exit & cd
* Signal handling

### Attempted
* Redirection with < & > 
* Piping using |
* Handling the SIGSTP signal

### Buggos
* Handling SIGstp does not work. After sending SIGSTp signal , program keeps on sending > to stdout

### Files and Headers
* parser.c : parses a line into arguments forcommands
```
/*=====char **parser(char *)=====
Inputes : char *line
Outputs : char **args where each char * is a argument of the command

Dynamically allocates memory for a string array and a copy of the input

Iterates through a copy of the input and uses strsep for the  ' ' delimitor. 
The index by index, each returned pointer from strsep is places in consecutive indexes of the string array. 

Returns string array char**
*/
```


* exec.c : executes commands
```
/*=====int exec(char **)=====
Inputes: char ** arguments obtained from parser
Outputs: returns 0

Recursively goes through the input string array and executes based on detection of tokens  ; < > | 

Should return 0 with no errors*/
```


* aria_sh.c : reads from stdin and executes commands withe exec.c
```
/*=====int aria_sh()=====
Inputes: void
Outputs: 0
Runs readline() to get line froms stdin
Uses parser() to change the line to arguments
If the arguments are builtin commmands(cd and exit) it executes those with builtin()
Execute non-cd/exit commands with exec()
Returns 0 if nothing goes wrong*/

/*=====void builtin(char **)=====
Inputs: char **
Outputs: void
Checks for builting functions like exit and cd
If exit, exit(0).
If cd, chdir(<NEXT ARGUMENT>). */

/*=====char *readline()=====
Inputs: void
Outputs: char * containing input string from stdin
Allocates memory to a char * pointer.
Uses fgets() to read from stdin to char pointer
Removes \n newlines and replaces with \0 null terminators
Returns the pointer */

/*===== void sighandler(int)======
Inputs: int
Outputs: void
Takes in an input int from signal() in main().
If SIGINT, re-run aria_sh() and clear buffer
If SIGSTP, send SIGSTP to process. **Does not work and the line is removed from code**
*/
```


* aria.c : main file. Loops to run aria_sh()
```
/*=====int main()=====
Inputs: void
Outputs: 0
Runs the program. 
Returns 0 if nothing goes wrong.
```
