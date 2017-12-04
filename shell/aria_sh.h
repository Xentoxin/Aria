#ifndef ARIA_SH_H
#define ARIA_SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../exec/exec.h"
#include "../parser/parser.h"

int aria_sh();

void builtin(char **);

char *readline();

void signhandler(int);

#endif
