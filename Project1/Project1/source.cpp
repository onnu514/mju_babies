#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//자료형? -> 어떤 데이터를 저장할 수 있는 형태
//int -> 정수 데이터를 저장할 수 있는 형태
//새로운 자료형 -> 학생 자료형을 만들어보자
struct student {
	//속성들
	//이름 나이 학번
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
	//숫자를 입력받아서 해당 수 만큼 struct student*를 만드는 경우
	struct student** students;// == struct student*의 배열
	int num;
	scanf("%d", &num);
	students = (struct student**)malloc(sizeof(struct student*) * num);
	//현재 상황
	//배열은 만들어짐
	//근데 배열 요소들(struct student* 들)은 초기화가 되지 않음
	//students[0]->age = 4;//오류가 발생할 것임
	//이유는 동적 할당을 아직 안 해서
	//배열을 만들었음
	//struct student*들이 num개 만큼 있죠?
	//struct student*는 뭐냐 struct student의 주소를 가리킴
	//쓸려면 동적 할당을 해야 한다
	for (int i = 0; i < num; i++) {
		students[i] = (struct student*)malloc(sizeof(struct student));
	}

	//배열도 만들었고, 모든 요소들도 동적할당(초기화) 완료.
	//이제 값을 넣을 준비가 됨
	for (int i = 0; i < num; i++) {
		inputStu(students[i]);
	}
	for (int i = 0; i < num; i++) {
		printStu(students[i]);
		printf("\n");
	}

	return 0;
}