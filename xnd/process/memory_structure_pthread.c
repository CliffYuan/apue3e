/*
 * memory_structure_fork.c
 *
 *  父子进程的内存关系
 *
 *  线程堆栈地址空间一样，没有道理啊？？？/
 *
 *
 *  Created on: 2014年12月18日
 *      Author: xiaoniudu
 */

#include <stdio.h>
#include <pthread.h>
#include <string.h>

int global1 = 0, global2 = 0, global3 = 0;
global4;
void *max(void *arg) {
	int v1_max = 0, v2_max, v3_max = 0;
	int *p_max;
	static static_max1 = 0, static_max2, static_max3 = 0;
	p_max = (int*) malloc(sizeof(int) * 1);

	int *p_max2 = (int*) malloc(sizeof(int) * 1);
	//char* params=(char*)arg;

	printf("====Thread id:%d====arg:%s\n", pthread_self(), "fweg");

	printf("====IN CODE SEGMENT====\n");
	printf("打印max程序地址\n");
	printf("in max     : 0x%08x\n\n", max);
	printf("打印max传入参数地址\n");

	printf("====IN DATA SEGMENT====\n");
	printf("打印max函数中静态变量地址\n");
	printf("static_max1:0x%08x\n", &static_max1); //打印各本地变量的内存地址
	printf("static_max2:0x%08x\n", &static_max2);
	static_max2 = 45;
	printf("static_max2:0x%08x\n", &static_max2);
	printf("static_max3:0x%08x\n\n", &static_max3);

	printf("====IN HEAP====\n");
	printf("打印max函数中malloc分配地址\n");

	if (p_max != NULL) {

		printf("p_max      :0x%08x\n\n", p_max); //打印各本地变量的内存地址
		printf("p_max2     :0x%08x\n\n", p_max2); //打印各本地变量的内存地址

		*p_max = 888;
		int i = 4;
		while (i > 0) {
			printf("p_max      :0x%08x\n\n", p_max); //打印各本地变量的内存地址
			printf("p_max      :%d\n", *p_max); //打印各本地变量的内存地址
			printf("p_max      :%d\n", p_max); //打印各本地变量的内存地址
			i--;
		}
	}

	printf("====IN STACK====\n");
	printf("in max arg: 0x%08x\n\n", &arg);
	printf("打印max函数中局部变量地址\n");
	printf("v1_max     :0x%08x\n", &v1_max); //打印各本地变量的内存地址
	printf("v2_max     :0x%08x\n", &v2_max);
	v2_max = 45;
	printf("v2_max     :0x%08x\n", &v2_max);
	printf("v3_max     :0x%08x\n\n", &v3_max);
	sleep(30);

	free((void*) p_max);

	return 0;
}

void *max2(void *arg) {
	int v1_max = 0, v2_max, v3_max = 0;
	static static_max1 = 0, static_max2, static_max3 = 0;

	int *p_max;
	p_max = (int*) malloc(sizeof(int) * 1);

//	char* params=(char*)arg;
	printf("====Thread id:%d====arg:%s\n", pthread_self(), "d");

	printf("====IN CODE SEGMENT====\n");
	printf("打印max程序地址\n");
	printf("in max     : 0x%08x\n\n", max2);
	printf("打印max传入参数地址\n");

	printf("====IN DATA SEGMENT====\n");
	printf("打印max函数中静态变量地址\n");
	printf("static_max1:0x%08x\n", &static_max1); //打印各本地变量的内存地址
	printf("static_max2:0x%08x\n", &static_max2);
	static_max2 = 45;
	printf("static_max2:0x%08x\n", &static_max2);
	printf("static_max3:0x%08x\n\n", &static_max3);

	printf("====IN HEAP====\n");
	printf("打印max函数中malloc分配地址\n");

	if (p_max != NULL) {

		printf("p_max      :0x%08x\n\n", p_max); //打印各本地变量的内存地址

		*p_max = 999;
		int i = 4;
		while (i > 0) {
			printf("p_max      :0x%08x\n\n", p_max); //打印各本地变量的内存地址
			printf("p_max      :%d\n", *p_max); //打印各本地变量的内存地址
			printf("p_max      :%d\n", p_max); //打印各本地变量的内存地址
			i--;
		}

	}
	printf("====IN STACK====\n");
	printf("in max arg: 0x%08x\n\n", &arg);
	printf("打印max函数中局部变量地址\n");
	printf("v1_max     :0x%08x\n", &v1_max); //打印各本地变量的内存地址
	printf("v2_max     :0x%08x\n", &v2_max);
	v2_max = 45;
	printf("v2_max     :0x%08x\n", &v2_max);
	printf("v3_max     :0x%08x\n\n", &v3_max);
	sleep(30);

	free((void*) p_max);

	return 0;
}

int main(int argc, char **argv) {
	static int static1 = 0, static2, static3 = 0;
	int v1 = 0, v2, v3 = 0;
	int *p;
	p = (int*) malloc(10);

	struct structTest {
		int a;
		int b;
		int *sp;
	};

	struct structTest st;

	printf("====PID====%d\n", getpid());
	printf("====IN CODE SEGMENT====\n");
	printf("main   :0x%08x\n", main);
	printf("max    :0x%08x\n\n", max);

	printf("====IN DATA SEGMENT====\n");
	printf("各全局变量(已初始化)的内存地址\n");
	printf("global1:0x%08x\n", &global1); //打印各全局变量的内存地址
	printf("global2:0x%08x\n", &global2);
	printf("global3:0x%08x\n", &global3);
	printf("global4:0x%08x\n", &global4);
	global4 = 56;
	printf("global4:0x%08x\n", &global4); //赋值前和赋值后地址是一样的

	printf("各静态变量的内存地址\n");
	printf("static1:0x%08x\n", &static1); //打印各静态变量的内存地址
	printf("static2:0x%08x\n", &static2);
	static2 = 6;
	printf("static2:0x%08x\n", &static2);
	printf("static3:0x%08x\n\n", &static3);

	printf("====IN HEAP====\n");
	printf("打印malloc分配的堆地址\n");
	printf("p      :0x%08x\n\n", p);

	printf("====IN STACK====\n");
	printf("打印主参地址\n");
	printf("argv   : 0x%08x\n", argv);
	printf("打印各局部变量的内存地址\n");
	printf("v1     :0x%08x\n", &v1); //打印各本地变量的内存地址
	printf("v2     :0x%08x\n", &v2);
	v2 = 89;
	printf("v2     :0x%08x\n", &v2);
	printf("v3     :0x%08x\n\n", &v3);

	printf("struct :0x%08x\n\n", &st);
	st.a = 12;
	printf("struct :0x%08x\n\n", &st); //struct 在栈上

	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, max, "thread_xnd1");
	pthread_create(&thread2, NULL, max2, "thread_xnd2");
	sleep(30);
	printf("main thread exit \n\n");
	return 0;
}
