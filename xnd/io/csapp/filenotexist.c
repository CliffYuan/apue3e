/*
 * filenotexist.c
 *
 *  Created on: 2014年12月19日
 *      Author: xiaoniudu
 */


#include	<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{

	int fd1,fd2;
	fd1=open("ioa.txt",O_RDONLY,0);
	close(fd1);
	fd2=open("iob.bat",O_RDONLY,0);
	printf("fd2=%d\n",fd2);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
