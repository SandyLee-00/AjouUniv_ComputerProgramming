/*
[실습#3] 주사위 각 면 횟수 출력 프로그램
요구사항 : 주사위를 던져서 각각의 면이 몇 번 나왔는지를 출력하는 프로그램을
작성하시오. 주사위를 던지는 함수 get_dice_face()함수를 만들고
이 함수 안에서 각각의 면이 나올 때마다 그 횟수를 정적 지역변수를
이용하여 저장한다. get_dice_face()함수 호출회수가 100이 되면
각 면의 횟수를 출력한다

**********************************************************
100번을 돌리는 것 / n을 입력받아 n번 돌리는 것으로 둘 다 작성함.
100번 :
1. for문으로 주사위함수(100)을 100번 실행한다
2. 123456을 랜덤하게 생성해서 맞으면 각 숫자의 개수를 올려 저장한다
3. 100번 굴렸으면 종료하고 각 숫자의 개수를 출력한다.

n번 :
1. for문으로 주사위함수(n)을 n번 실행한다
2. 123456을 랜덤하게 생성해서 맞으면 각 숫자의 개수를 올려 저장한다
3. n번 굴렸으면 종료하고 각 숫자의 개수를 출력한다.

핵심 내용 :
static으로 변수의 값이 맞은 횟수를 카운트 하기
static으로 각 함수의 불린 횟수 카운트 하기
**************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_dice_face(int count);
void get_dice_face_100();

int main(void)
{
	srand(time(NULL));
	int i, n;
	for (i = 0; i < 100; i++)
		get_dice_face_100();
	/*
	위에는 100번, 밑에는 입력 받은 만큼
	*/
	printf("\n주사위를 몇 번 굴릴 것인가?");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		get_dice_face(n);
	return 0;
}
//100번 입력 함수
void get_dice_face_100()
{
	int number = (rand() % 6) + 1;
	static int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	static call_count = 0;
	call_count++;
	switch (number) {
	case 1:
		one++;
		break;
	case 2:
		two++;
		break;
	case 3:
		three++;
		break;
	case 4:
		four++;
		break;
	case 5:
		five++;
		break;
	case 6:
		six++;
		break;
	}
	if (call_count == 100) {
		printf("1 -> %d\n", one);
		printf("2 -> %d\n", two);
		printf("3 -> %d\n", three);
		printf("4 -> %d\n", four);
		printf("5 -> %d\n", five);
		printf("6 -> %d\n", six);
	}
}
//n번 입력 함수
void get_dice_face(int count)
{
	int number = (rand() % 6) + 1;
	static int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	static call_count = 0;
	call_count++;
	switch (number) {
	case 1:
		one++;
		break;
	case 2:
		two++;
		break;
	case 3:
		three++;
		break;
	case 4:
		four++;
		break;
	case 5:
		five++;
		break;
	case 6:
		six++;
		break;
	}
	if (call_count == count) {
		printf("1 -> %d\n", one);
		printf("2 -> %d\n", two);
		printf("3 -> %d\n", three);
		printf("4 -> %d\n", four);
		printf("5 -> %d\n", five);
		printf("6 -> %d\n", six);
	}
}