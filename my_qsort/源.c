#include"stdio.h"
#include"string.h"
#include"stdlib.h"

typedef struct person
{
	char *name;
	int age;
}person;


//比较person类型的年龄
int person_cmp(void* ele1, void* ele2)
{
	if (((person*)ele1)->age- ((person*)ele2)->age > 0 )
	{
		return 1;
	}
	else if ((*(int*)ele1) - (*(int*)ele2) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}



//整形比较函数
int int_cmp(void* ele1, void* ele2)
{
	if ((*(int*)ele1) - (*(int*)ele2) > 0)
	{
		return 1;
	}
	else if ((*(int*)ele1) - (*(int*)ele2) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}

}

//因为不确定原来的数据类型，所以用char*接收，这个函数的逻辑是交换两个数的值
void my_swap(char* buff1,char* buff2 , int width) 
{

	//一个字节一个字节的交换，交换width个长度。如果是整形，则交换四个字节的内容，达到交换的效果
	for (int i = 0; i < width; i++)
	{
		//char*每次只移动一个字节
		char t = buff1[i];
		buff1[i] = buff2[i];
		buff2[i] = t;
	}
}

//arr 数组的起始地址， number数组的个数，width数组元素的类型，cmp_ptr比较函数的地址
void my_qsort(void* arr, int number, int width, int(*cmp_ptr)(void* ele1, void* ele2) )
{
	for (size_t i = 0; i < number; i++)
	{
		for (int j = 0; j < number - 1-i; j++)
		{
			//将arr强转为char*,所以不管原来的数组元素类型是什么，占用多少个字节，前一个元素+1*width个宽度都能指向后一个元素
			if(  cmp_ptr( (char*)arr+j*width ,(char*)arr+(j+1)*width) > 0  )
			{
				//从小到大排序，前一个元素比后一个元素大则交换他们对应地址里面值
				my_swap((char*)arr + j * width, (char*)arr + (j+1) * width , width);
			}
		}
	}
}




int main()
{
	//初始化数组
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//得到数组的长度
	int arr_number = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, arr_number, sizeof(arr[0]), int_cmp);
	for (size_t i = 0; i < arr_number; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	person p1 = { "张三",20 };
	person p2 = { "李四",60 };
	person p3 = {"王五",40};
	person p_arr[] = { p1,p2,p3 };
	my_qsort(p_arr, 3, sizeof(p_arr[0]), person_cmp);
	for (size_t i = 0; i < 3; i++)
	{
		printf("姓名：%s, 年龄：%d\n", p_arr[i].name,p_arr[i].age);
	}


}

