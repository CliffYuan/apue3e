/*
 * =====================================================================================
 *
 *       Filename:  in2out.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年12月19日 16时06分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	
	char c;
	while(read(STDIN_FILENO,&c,1)!=0){
		write(STDOUT_FILENO,&c,1);
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
