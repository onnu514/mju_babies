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
			printf("이름: %s 나이 : %d, 학번 :%s\n", (*stu)[i]->name, (*stu)[i]->age, (*stu)[i]->id);
			found = 1;
			break;
		}

		if (found != 1) {
			printf("존재하지않습니다\n");
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

void DeleteStu(struct student** stu, int *size) {				//특정 학생 지우는 함수
	char check[10] ;
	scanf("%s",check);		// id 대조용

	int found = -1;

	for (int i = 0; i < *size; i++) {
		if (strcmp(check, stu[i]->id) == 0) {				//여기서 입력받은 학번 (check) 와 stu->id를 비교
			found = i;										//만약에 찾으면 해당 학번의 학생이 몇번째에 있는지  found 에 저장
			break;	
		}
	}	
	if (found == -1) {										// 만약에 없으면 존재x라고 출력
		printf("존재x\n");
		return ;
	}

	free(stu[found]->name);									//free를 해줘서 없애줌
	free(stu[found]->id);

	for (int j = found; j < *size - 1; j++) {				//한칸씩 땡겨준다
		stu[j] = stu[j + 1];
	}

	free(stu[*size - 1]);
	(*size)--;												//한칸이 사라져서 size 자체도 줄여준다 
}

void inputStu(struct student* stu) {										// 학생 정보 입력하는 함수

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

void printStu(struct student*** stu, int size){									// 모든 학생 정보 출력하는 함수
	
	for (int i = 0; i < size; i++) {
		printf("%s %s %d", (*stu)[i]->name, (*stu)[i]->id, (*stu)[i]->age);
		printf("\n");
	}
	
}

void Totalinput(struct student*** stu, struct student *** substu, int *size){	//	main 에서는 함수 하나만 남겨두기 위해서 stu와 substu, size의 정보를 totalinput 함수에 넘겨줌
	int tempsize = *size;
	
	printf("이름 나이 학번을 입력하세요\n");

	if (tempsize == 0) {														//만약 처음 입력을 받는 경우에는 바로 stu에 저장해준다
		*stu = (struct student**)malloc(sizeof(struct student*));
		(*stu)[0] = (struct student*)malloc(sizeof(struct student));
		inputStu((*stu)[0]);														
		tempsize++;
	}
	else
	{																						//만약 처음이 아니라면 stu의 사이즈를 늘려줘야 하는데 
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
	//학생을 관리하는 프로그램
	//모든 기능은 함수로
	//1을 누르면 학생 추가(모든 정보를 입력받아 추가)
	//2를 누르면 학생 삭제(id를 입력받아 비교)
	//3을 누르면 특정 학생 조회(id를 입력받아 비교)
	//4를 누르면 모든 학생 조회
	//5를 누르면 모든 학생을 나이 순으로 정렬
	//6을 누르면 종료 
	
	struct student** students = NULL;
	int size = 0;
	int menu = 0;


	struct student** substu = NULL;
	

	printf("1.학생 추가\n2.학생 삭제\n3.학생 id 조회\n4.모든 학생 조회\n5.학생 나이순 정렬\n6.종료\n");

	scanf("%d", &menu);
	
	while (menu != 6) {

		if (menu == 1) {
			Totalinput(&students, &substu, &size);		//학생을 추가하는 함수
		}
	
		if (menu == 2) {
			DeleteStu(students,&size);					//학생을 삭제 하는 함수
		}
		if (menu == 3) {
			SearchId(&students, size);					//학생의 학번을 받아서 조회 하는 함수
		}

		if (menu == 4) {	
			printStu(&students,size);					//현재 저장되어있는 학생들의 정보를 출력 하는 함수
		}

		if (menu == 5) {			
			SortByAge(students, size);					// 저장되어 있는 학생들 나이순 정렬
		}
		printf("1.학생추가\n2.학생삭제\n3.학생id조회\n4.모든학생조회\n5.학생 나이순 정렬\n6.종료\n");

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