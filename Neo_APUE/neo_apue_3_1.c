/* ****
 *
 * This program tests whether standard input is capable of seeking 
 *
 * ***/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	if(-1 == lseek(STDIN_FILENO, 0, SEEK_CUR)){		
    	printf("cannot seek\n");
	}
	else{
		printf("seek OK\n");
	}

	exit(0);
}
