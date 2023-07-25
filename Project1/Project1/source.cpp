#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char* name;
	int age;
	char* id;
};

void inputStu(struct student* stu) {
	char tName[30];
	char tId[10];
	scanf("%s", tName);
	scanf("%d", &stu->age);
	scanf("%s", tId);
	stu->name = (char*)malloc(strlen(tName) + 1);
	strcpy_s(stu->name, strlen(tName) + 1, tName);
	stu->id = (char*)malloc(strlen(tId) + 1);
	strcpy_s(stu->id, strlen(tId) + 1, tId);
}

void printStu(struct student* stu) {
	printf("%s %s %d", stu->name, stu->id, stu->age);
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
	struct student** students;
	int num;
	scanf("%d", &num);
	students = (struct student**)malloc(sizeof(struct student*) * num);
	for (int i = 0; i < num; i++) {
		students[i] = (struct student*)malloc(sizeof(struct student));
	}
	for (int i = 0; i < num; i++) {
		inputStu(students[i]);
	}
	for (int i = 0; i < num; i++) {
		printStu(students[i]);
		printf("\n");	// test
	}

	return 0;
}