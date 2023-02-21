/*
[실습#5] 순환기법을 이용한 계산 프로그램
요구사항 : 1부터 N까지의 합(1+2+3+…+N)을 계산하는 문제를
순환기법을 이용해서 작성해보자.
힌트 : sum(3)은 3+sum(2)로 바꿀 수 있다
****************************************
1. 메인함수에서 값을 입력한다
2. 더해주는 함수에서 -1씩 하면서 재귀적으로 호출하며 더한 값을 리턴한다
3. 점점 줄어들며 1이 되면 위의 함수로 올라가며 최종 값을 반환한다.

핵심 판단 :
n에서 1씩 빼주면서 재귀함수 사용, 값을 더해준다.
*/

#include <stdio.h>
int sum(int n);
int main()
{
	int number, result;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &number);
	result = sum(number);
	printf("1부터 %d까지의 합 = %d\n", number, result);
}
int sum(int num)
{
	if (num == 1) {
		return 1;
	}
	else {
		return num + sum(num - 1);
	}

}