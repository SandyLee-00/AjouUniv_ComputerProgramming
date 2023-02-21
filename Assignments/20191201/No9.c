/*
[실습#9] 배열을 이용한 급여 계산 함수
요구사항 : 직원들의 기본급이 배열A[]에 저장되어 있다. 배열 B[]에는 직원들의
보너스가 저장되어 있다. 기본급과 보너스를 합하여 이번 달에 지급할
월급의 총액을 계산하고자 한다. A[]와 B[]를 더하여 배열C[]에
저장하는 함수를 작성하고 테스트하라.

//지급 : 기본급, 식대, 상여금
//공제 : 국민연금, 소득세, 고용보험
//지급총액, 공제총액
//Payment amount, basic salary, meal, bonus
//Deduction, National Pension, Income Tax, Employment Insurance

기본급 + 식대 + 상여금 = 지급
국민연금 + 소득세 + 고용보험 = 공제
지급총액 - 공제총액 = 총 급여

출력하는 함수와 각 금액을 계산하는 함수를 만들었다
메인에서 각 함수를 부르고 값을 저장한다.
*/

#include <stdio.h>
#define array_num 10



void print_array(const char* array_name, int* array) {
	//배열출력

	printf("%s", array_name);
	printf(" =");
	printf("\n {");

	for (int i = 0; i < array_num; i++) {
		printf("%5d", array[i]);
	}
	printf("}\n");
}

void array_fill_salary(int* A)
//기본급
{
	for (int i = 0; i < array_num; i++) {
		A[i] = (rand() % 50) * 10 + 200;
	}
}

void array_fill_bonus(int* A)
//식대
{
	for (int i = 0; i < array_num; i++) {
		A[i] = rand() % 10 + 50;
	}
}


void array_fill_mealpaid(int* A) {
	//상여금
	for (int i = 0; i < array_num; i++) {
		A[i] = 40;
	}
}

void fill_addresult(int fir[], int sec[], int thir[], int result[]) {
	printf("\n************addresult\n");
	for (int i = 0; i < array_num; i++) {
		result[i] = fir[i] + sec[i] + thir[i];
	}
}

void fill_national_pension(int* A) {
	////공제 : 국민연금
	for (int i = 0; i < array_num; i++) {
		A[i] = 60;
	}
}

void fill_income_tax(int* A, int* B) {
	//소득세
	for (int i = 0; i < array_num; i++) {
		(int)B[i] = A[i] * 0.1;
	}
}

void fill_employment_insurence(int* A) {
	//고용보험
	for (int i = 0; i < array_num; i++) {
		A[i] = 20;
	}
}

void fill_total_salary(int fir[], int sec[], int result[]) {
	//지급총액 - 공제총액 = 총 급여
	printf("************total_salary\n");
	for (int i = 0; i < array_num; i++) {
		result[i] = fir[i] - sec[i];
	}
	

}




int main() {
	int salary[array_num];
	array_fill_salary(salary);
	print_array("salary", salary);

	int bonus[array_num];
	array_fill_bonus(bonus);
	print_array("bonus", bonus);

	int mealpaid[array_num];
	array_fill_mealpaid(mealpaid);
	print_array("mealpaid", mealpaid);

	int Payment_amount[array_num];
	fill_addresult(salary, bonus, mealpaid, Payment_amount);
	print_array("Payment_amount", Payment_amount);
	printf("************addresult\n\n");

	int national_pension[array_num];
	fill_national_pension(national_pension);
	print_array("national_pension", national_pension);

	int income_tax[array_num];
	fill_income_tax(salary,income_tax);
	print_array("income_tax", income_tax);

	int employment_insurance[array_num];
	fill_employment_insurence(employment_insurance);
	print_array("employment_insurance", employment_insurance);

	int deduction_amount[array_num];
	fill_addresult(national_pension, income_tax, employment_insurance, deduction_amount);
	print_array("deduction", deduction_amount);
	printf("************addresult\n\n");

	int total_salary[array_num];
	fill_total_salary(Payment_amount, deduction_amount, total_salary);
	print_array("total_salary", total_salary);
	printf("************total_salary\n");

	return 0;

}


