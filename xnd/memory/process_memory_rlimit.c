/*
 * =====================================================================================
 *
 *       Filename:  process_memory_rlimit.c
 *
 *    Description:  进程的内存上限
 *
 *        Version:  1.0
 *        Created:  2014年12月16日 09时54分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include <sys/resource.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{

	struct rlimit *limit=(struct rlimit *)malloc(sizeof(struct rlimit));

	getrlimit(RLIMIT_AS,limit);

	printf("soft limit:%ld,hard limit:%ld\n",limit->rlim_cur,limit->rlim_max);




	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
