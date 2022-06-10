#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>


/* helper functions */
int _strlen(const char *s);
char *_strdup(const char *str);

#endif /* MAIN_H_ */
