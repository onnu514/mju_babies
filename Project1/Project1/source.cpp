#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ڷ���? -> � �����͸� ������ �� �ִ� ����
//int -> ���� �����͸� ������ �� �ִ� ����
//���ο� �ڷ��� -> �л� �ڷ����� ������
struct student {
	//�Ӽ���
	//�̸� ���� �й�
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
	//���ڸ� �Է¹޾Ƽ� �ش� �� ��ŭ struct student*�� ����� ���
	struct student** students;// == struct student*�� �迭
	int num;
	scanf("%d", &num);
	students = (struct student**)malloc(sizeof(struct student*) * num);
	//���� ��Ȳ
	//�迭�� �������
	//�ٵ� �迭 ��ҵ�(struct student* ��)�� �ʱ�ȭ�� ���� ����
	//students[0]->age = 4;//������ �߻��� ����
	//������ ���� �Ҵ��� ���� �� �ؼ�
	//�迭�� �������
	//struct student*���� num�� ��ŭ ����?
	//struct student*�� ���� struct student�� �ּҸ� ����Ŵ
	//������ ���� �Ҵ��� �ؾ� �Ѵ�
	for (int i = 0; i < num; i++) {
		students[i] = (struct student*)malloc(sizeof(struct student));
	}

	//�迭�� �������, ��� ��ҵ鵵 �����Ҵ�(�ʱ�ȭ) �Ϸ�.
	//���� ���� ���� �غ� ��
	for (int i = 0; i < num; i++) {
		inputStu(students[i]);
	}
	for (int i = 0; i < num; i++) {
		printStu(students[i]);
		printf("\n");
	}

	return 0;
}