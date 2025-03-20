#include"stdio.h"
#include"string.h"
#include"stdlib.h"

typedef struct person
{
	char *name;
	int age;
}person;


//�Ƚ�person���͵�����
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



//���αȽϺ���
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

//��Ϊ��ȷ��ԭ�����������ͣ�������char*���գ�����������߼��ǽ�����������ֵ
void my_swap(char* buff1,char* buff2 , int width) 
{

	//һ���ֽ�һ���ֽڵĽ���������width�����ȡ���������Σ��򽻻��ĸ��ֽڵ����ݣ��ﵽ������Ч��
	for (int i = 0; i < width; i++)
	{
		//char*ÿ��ֻ�ƶ�һ���ֽ�
		char t = buff1[i];
		buff1[i] = buff2[i];
		buff2[i] = t;
	}
}

//arr �������ʼ��ַ�� number����ĸ�����width����Ԫ�ص����ͣ�cmp_ptr�ȽϺ����ĵ�ַ
void my_qsort(void* arr, int number, int width, int(*cmp_ptr)(void* ele1, void* ele2) )
{
	for (size_t i = 0; i < number; i++)
	{
		for (int j = 0; j < number - 1-i; j++)
		{
			//��arrǿתΪchar*,���Բ���ԭ��������Ԫ��������ʲô��ռ�ö��ٸ��ֽڣ�ǰһ��Ԫ��+1*width����ȶ���ָ���һ��Ԫ��
			if(  cmp_ptr( (char*)arr+j*width ,(char*)arr+(j+1)*width) > 0  )
			{
				//��С��������ǰһ��Ԫ�رȺ�һ��Ԫ�ش��򽻻����Ƕ�Ӧ��ַ����ֵ
				my_swap((char*)arr + j * width, (char*)arr + (j+1) * width , width);
			}
		}
	}
}




int main()
{
	//��ʼ������
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//�õ�����ĳ���
	int arr_number = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, arr_number, sizeof(arr[0]), int_cmp);
	for (size_t i = 0; i < arr_number; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	person p1 = { "����",20 };
	person p2 = { "����",60 };
	person p3 = {"����",40};
	person p_arr[] = { p1,p2,p3 };
	my_qsort(p_arr, 3, sizeof(p_arr[0]), person_cmp);
	for (size_t i = 0; i < 3; i++)
	{
		printf("������%s, ���䣺%d\n", p_arr[i].name,p_arr[i].age);
	}


}

