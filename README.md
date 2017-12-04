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
* parser.c
```
** char **parser **
