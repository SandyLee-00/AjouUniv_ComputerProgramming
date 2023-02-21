/*
[�ǽ�#9] �迭�� �̿��� �޿� ��� �Լ�
�䱸���� : �������� �⺻���� �迭A[]�� ����Ǿ� �ִ�. �迭 B[]���� ��������
���ʽ��� ����Ǿ� �ִ�. �⺻�ް� ���ʽ��� ���Ͽ� �̹� �޿� ������
������ �Ѿ��� ����ϰ��� �Ѵ�. A[]�� B[]�� ���Ͽ� �迭C[]��
�����ϴ� �Լ��� �ۼ��ϰ� �׽�Ʈ�϶�.

//���� : �⺻��, �Ĵ�, �󿩱�
//���� : ���ο���, �ҵ漼, ��뺸��
//�����Ѿ�, �����Ѿ�
//Payment amount, basic salary, meal, bonus
//Deduction, National Pension, Income Tax, Employment Insurance

�⺻�� + �Ĵ� + �󿩱� = ����
���ο��� + �ҵ漼 + ��뺸�� = ����
�����Ѿ� - �����Ѿ� = �� �޿�

����ϴ� �Լ��� �� �ݾ��� ����ϴ� �Լ��� �������
���ο��� �� �Լ��� �θ��� ���� �����Ѵ�.
*/

#include <stdio.h>
#define array_num 10



void print_array(const char* array_name, int* array) {
	//�迭���

	printf("%s", array_name);
	printf(" =");
	printf("\n {");

	for (int i = 0; i < array_num; i++) {
		printf("%5d", array[i]);
	}
	printf("}\n");
}

void array_fill_salary(int* A)
//�⺻��
{
	for (int i = 0; i < array_num; i++) {
		A[i] = (rand() % 50) * 10 + 200;
	}
}

void array_fill_bonus(int* A)
//�Ĵ�
{
	for (int i = 0; i < array_num; i++) {
		A[i] = rand() % 10 + 50;
	}
}


void array_fill_mealpaid(int* A) {
	//�󿩱�
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
	////���� : ���ο���
	for (int i = 0; i < array_num; i++) {
		A[i] = 60;
	}
}

void fill_income_tax(int* A, int* B) {
	//�ҵ漼
	for (int i = 0; i < array_num; i++) {
		(int)B[i] = A[i] * 0.1;
	}
}

void fill_employment_insurence(int* A) {
	//��뺸��
	for (int i = 0; i < array_num; i++) {
		A[i] = 20;
	}
}

void fill_total_salary(int fir[], int sec[], int result[]) {
	//�����Ѿ� - �����Ѿ� = �� �޿�
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


