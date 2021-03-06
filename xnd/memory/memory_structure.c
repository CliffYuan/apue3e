/*
 * memory_structure.c
 *
 *  Created on: 2014年12月10日
 *      Author: xiaoniudu
 */

#include <stdio.h>
#include <unistd.h>
int global1 = 0, global2 = 0, global3 = 0;
global4;
int max(int i) {
	int v1_max = 0, v2_max, v3_max = 0, *p_max;
	static static_max1 = 0, static_max2, static_max3 = 0;
	p_max = (int*) malloc(10);
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
	printf("p_max      :0x%08x\n\n", p_max); //打印各本地变量的内存地址

	printf("====IN STACK====\n");
	printf("in max arg: 0x%08x\n\n", &i);
	printf("打印max函数中局部变量地址\n");
	printf("v1_max     :0x%08x\n", &v1_max); //打印各本地变量的内存地址
	printf("v2_max     :0x%08x\n", &v2_max);
	v2_max = 45;
	printf("v2_max     :0x%08x\n", &v2_max);
	printf("v3_max     :0x%08x\n\n", &v3_max);
	sleep(10000);
	free(p_max);
	if (i)
		return 1;
	else
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
	printf("struct :0x%08x\n\n", &st);//struct 在栈上

	//sleep(10000);
	printf(
			"===========================================max=========================================\n");
	max(v1);
	printf(
			"===========================================max=========================================\n");
	printf("打印子函数起始地址\n");
	printf("max   :0x%08x\n\n", max);
	return 0;
}
