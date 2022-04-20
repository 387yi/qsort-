#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void jiaohuan(char* ab1, char* ab2, int sz1)
{
	int i = 0;
	char mav = 0;
	for (i = 0; i < sz1; i++)
	{
		char mav = *ab1;
		*ab1 = *ab2;
		*ab2 = mav;
		ab1++;
		ab2++;
	}
}
void maopao(void *arr, int sz, int sz1,int (*ps)(void* e1,void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//趟数
	{
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (ps((char*)arr+j*sz1,(char*)arr+sz1*(j+1)) > 0)
			{
				//比较
				jiaohuan(((char*)arr + j * sz1), ((char*)arr + sz1 * (j + 1)), sz1);
			}
		}
	}
}
int text_int(const void* e1,const void* e2)
{
	return *(int*)e1 -*(int*)e2;
}
int text_double(const void* e1, const void* e2)
{
	return ((int)( * (float*)e1 - *(float*)e2));
}

void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	maopao(arr, sz, sizeof(arr[0]), text_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test2()
{
	float arr[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	maopao(arr, sz, sizeof(arr[0]), text_double);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
}
struct stu 
{
	char name[20];
	int age;
};
int text_struct(const void* e1, const void* e2)
{
	return (((struct stu*)e1)->age - ((struct stu*)e2)->age);
}
void test3()
{
	struct stu s[3] = { {"张三",30},{"李四",10},{"王五",20}};
	int sz = sizeof(s) / sizeof(s[0]);
	maopao(s, sz, sizeof(s[0]), text_struct);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %d ", s[i].name,s[i].age);
	}
}
int main()
{
	//test1(); int 型
	//test2(); float 型
	test3();
	return 0;
}