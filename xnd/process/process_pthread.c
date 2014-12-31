/*
 * process_pthread.c
 *
 *	线程是轻量级进程，有进程id,
 *	单进程也有一个主线程,线程id和进程id相同
 *
 *  Created on: 2014年12月26日
 *      Author: xiaoniudu
 */
#include <pthread.h>
#include <stdio.h>
#include <linux/unistd.h>
#include <stdio.h>
#include <string.h>

#define N 5

/**
 * 获取线程id
 */
pid_t gettid() {
	return syscall(__NR_gettid);
}

void *thread_function(void *arg) {
	printf("thread started,pid=%d\n", gettid());
	while (1) {
		sleep(1);
	}
}

int main(void) {
	int i;
	pthread_t tid[N];
	for (i = 0; i < N; i++) {
		pthread_create(&tid[i], NULL, thread_function, NULL);
	}

	sleep(1);

	for (i = 0; i < N; i++) {
		printf("tid=%lu\n", tid[i]);
	}

	while (1) {
		sleep(1);
	}

	return 0;
}

