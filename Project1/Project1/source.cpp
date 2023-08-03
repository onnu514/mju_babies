#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char* name;
	int age;
	char* id;
};
void Stucpy(struct student* A, struct student* B) {
	
	A->name = (char*)malloc(strlen(B->name)+1);
	A->id = (char*)malloc(strlen(B->id)+1);
	A->age = B->age;
	
	strcpy(A->name, B->name);
	strcpy(A->id, B->id);
}

void SearchId(struct student*** stu, int size) {

	char temp[30];

	scanf("%s", temp);

	for (int i = 0; i < size; i++) {
		int found = 0;
		if (strcmp((*stu)[i]->id, temp) == 0) {
			printf("�̸�: %s ���� : %d, �й� :%s\n", (*stu)[i]->name, (*stu)[i]->age, (*stu)[i]->id);
			found = 1;
			break;
		}

		if (found != 1) {
			printf("���������ʽ��ϴ�\n");
		}

	}
}

void SortByAge(struct student** stu, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (stu[j]->age > stu[j + 1]->age) {
				struct student* temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
}

void DeleteStu(struct student** stu, int *size) {
	char check[10] ;
	scanf("%s",check);		// id ������

	int found = -1;

	for (int i = 0; i < *size; i++) {
		if (strcmp(check, stu[i]->id) == 0) {
			found = i;
			break;
		}
	}
	if (found == -1) {
		printf("����x\n");
		return ;
	}
	free(stu[i]->name);
	free(stu[i]->id);

	for (int j = found; j < *size - 1; j++) {
		stu[j] = stu[j + 1];
	}

	free(stu[*size - 1]);
	(*size)--;
}

void inputStu(struct student* stu) {
	char tName[30];
	char tId[10];
	
	scanf("%s", tName);
	scanf("%d", &(stu->age));	
	scanf("%s", tId);
	
	stu->name = (char*)malloc(strlen(tName) + 1);
	strcpy(stu->name, tName);
	stu->id = (char*)malloc(strlen(tId) + 1);
	strcpy(stu->id, tId);
	
}

void printStu(struct student*** stu, int size){
	
	for (int i = 0; i < size; i++) {
		printf("%s %s %d", (*stu)[i]->name, (*stu)[i]->id, (*stu)[i]->age);
		printf("\n");
	}
	
}

void Totalinput(struct student*** stu, struct student *** substu, int *size){
	int tempsize = *size;
	
	printf("�̸� ���� �й��� �Է��ϼ���\n");

	if (tempsize == 0) {
		*stu = (struct student**)malloc(sizeof(struct student*));
		(*stu)[0] = (struct student*)malloc(sizeof(struct student));
		inputStu((*stu)[0]);														
		tempsize++;
	}
	else
	{
		*substu = (struct student**)malloc(sizeof(struct student *)*tempsize);
		
		for (int i = 0; i < tempsize; i++) {
			(*substu)[i] = (struct student*)malloc(sizeof(struct student));
			Stucpy((*substu)[i], (*stu)[i]);
		}
		tempsize++;
		*stu = (struct student**)malloc(sizeof(struct student*) * tempsize);
		for (int i = 0; i < tempsize-1; i++) {
			(*stu)[i] = (struct student*)malloc(sizeof(struct student));
			Stucpy((*stu)[i], (*substu)[i]);
		}
		(*stu)[tempsize-1] = (struct student*)malloc(sizeof(struct student));
		inputStu((*stu)[tempsize-1]);

	}

	*size = tempsize;
	
}
int main() {
	//�л��� �����ϴ� ���α׷�
	//��� ����� �Լ���
	//1�� ������ �л� �߰�(��� ������ �Է¹޾� �߰�)
	//2�� ������ �л� ����(id�� �Է¹޾� ��)
	//3�� ������ Ư�� �л� ��ȸ(id�� �Է¹޾� ��)
	//4�� ������ ��� �л� ��ȸ
	//5�� ������ ��� �л��� ���� ������ ����
	//6�� ������ ���� 
	
	struct student** students = NULL;
	int size = 0;
	int menu = 0;
//	int num;

//	scanf("%d", &num);
//	students = (struct student**)malloc(sizeof(struct student*) * num);

//	for (int i = 0; i < num; i++) {
//		students[i] = (struct student*)malloc(sizeof(struct student));
//	}

	struct student** substu = NULL;
	

	printf("1.�л� �߰�\n2.�л� ����\n3.�л� id ��ȸ\n4.��� �л� ��ȸ\n5.�л� ���̼� ����\n6.����\n");

	scanf("%d", &menu);
	
	while (menu != 6) {

		if (menu == 1) {
			Totalinput(&students, &substu, &size);
			
		}
	
		if (menu == 2) {
			DeleteStu(students,&size);
		}
		if (menu == 3) {
			SearchId(&students, size);
		}

		if (menu == 4) {	
			printStu(&students,size);		
		}

		if (menu == 5) {			
			SortByAge(students, size);
		}
		printf("1.�л��߰�\n2.�л�����\n3.�л�id��ȸ\n4.����л���ȸ\n5.�л� ���̼� ����\n6.����\n");

		scanf("%d", &menu);

	}

	for (int i = 0; i < size; i++) {
		free(students[i]->name);
		free(students[i]->id);
		free(students[i]);
	}
	free(students);


	return 0;
}