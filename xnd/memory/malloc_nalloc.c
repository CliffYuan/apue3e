/*
 * malloc_nalloc.c
 *
 *  Created on: 2014年12月27日
 *      Author: xiaoniudu
 */


#include	<stdlib.h>
#include <string.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{

	char * t=(char*)malloc(sizeof(char)*10);
	char* ccc="xnd";

	strcpy(t,ccc);

	printf("malloc value:%s\n",t);
	printf("malloc value:%s\n",&t);



	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
