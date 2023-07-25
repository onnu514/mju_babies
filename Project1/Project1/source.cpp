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
	//학생을 관리하는 프로그램
	//모든 기능은 함수로
	//1을 누르면 학생 추가(모든 정보를 입력받아 추가)
	//2를 누르면 학생 삭제(id를 입력받아 비교)
	//3을 누르면 특정 학생 조회(id를 입력받아 비교)
	//4를 누르면 모든 학생 조회
	//5를 누르면 모든 학생을 나이 순으로 정렬
	//6을 누르면 종료 
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