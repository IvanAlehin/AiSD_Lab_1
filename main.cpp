#include<Polynomial.cpp>
#include<iostream>
using namespace std;
using namespace polynomial;


int main() {
	setlocale(LC_ALL, "RUS");

	cout << "������ ������ ��� int:" << endl << endl;

	Polynomial<int> polynom1(5);
	cout << "����������� � ������������ �������� ����������:" << polynom1 << endl << endl;

	Vector<int> vec1(6);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = -3;
	vec1[3] = 4;
	vec1[4] = -15;
	vec1[5] = 6;
	Polynomial<int> polynom2(vec1);

	Vector<int> vec2(4);
	vec2[0] = 4;
	vec2[1] = -9;
	vec2[2] = -7;
	vec2[3] = 1;
	Polynomial<int> polynom3(vec2);
	cout << "����������� � �������� �������� ��� ��������������� ��������: " << polynom2 << endl << endl;

	cout << "�������� [] ��� ������ ���������� ��� �������� �������: " << polynom3[2] << endl << endl;

	polynom3.set(15, 3);
	cout << "����� set ��� ��������� ������������ ��� �������� ������� : " << polynom3 << endl << endl;

	cout << "�������� �����������: " << polynom3 + polynom2 << endl;
	cout << "��������� �����������: " << polynom2 - polynom3 << endl << endl;

	cout << "�������� ��������� �� ������(� ������������ ���������������): " << polynom2 * 3 << endl;
	cout << "���������������: " << 4 * polynom3 << endl << endl;

	cout << "���������� �������� ���������� ��� �������� �: " << polynom2.compute(2) << endl << endl;

	polynom1.set(4,0);
	polynom1.set(15, 2);
	polynom1.shrink_to_fit();
	cout << "����� shrink_to_fit: " << polynom1 << endl;

	polynom3.expand(7);
	cout << "����� expand: " << polynom3 << endl << endl;

	cout << "����� �����������: " << derivative(polynom2) << endl;

	cout << "---------------------------------------------------" << endl;





/*	cout << "������ ������ ������ � ������� ���� float:" << endl;
	Polynomial<float> pol3(3);
	cout << "����������� �� ������������ ������� ����������:" << pol3 << endl;

	Vector<float> vec4(4);
	vec4[0] = 5.6f;
	vec4[1] = -2.2f;
	vec4[2] = 10.15f;
	Polynomial<float> pol4(vec4);
	cout << "����������� �� ������� �������������: " << pol4 << endl;

	cout << "�������� [] ��� ������ �����������: " << pol4[1] << endl;

	pol3.set(3.15f, 0);
	cout << "����� set ��� ��������� ������������ ��� �������: " << pol3 << endl;

	cout << "�������� �����������: " << pol3 + pol4 << endl;
	cout << "��������� �����������: " << pol4 - pol3 << endl;

	cout << "�������� ��������� �� ������(� ������������ ���������������): " << pol3 * 3.15f << endl;
	cout << "���������������: " << -1.05f * pol4 << endl;

	cout << "���������� �������� ���������� ��� �������� X: " << pol4.compute(2.25) << endl;

	pol3.shrink_to_fit();
	cout << "����� shrink_to_fit: " << pol3 << endl;

	pol3.expand(5);
	cout << "����� expand: " << pol3 << endl;

	cout << "����� ��������������� ���������: " << integral_compute(pol4) << endl;

	cout << "---------------------------------------------------" << endl;

	cout << "������ ������ ������ � ������� ���� std::complex<float>: " << endl;
	Polynomial<std::complex<float>> pol5(4);
	cout << "����������� �� ������������ ������� ����������:" << pol5 << endl;

	Vector<std::complex<float>> vec6(2);
	vec6[0] = std::complex<float>(1.2f, 12.2f);
	vec6[1] = std::complex<float>(-3.4f, 2.6f);
	Polynomial<std::complex<float>> pol6(vec6);
	cout << "����������� �� ������� �������������: " << pol6 << endl;

	cout << "�������� [] ��� ������ �����������: " << pol6[1] << endl;

	std::complex<float> CN1(1.25f, -19.32f);
	pol5.set(CN1, 1);
	cout << "����� set ��� ��������� ������������ ��� �������: " << pol5 << endl;

	cout << "�������� �����������: " << pol5 + pol6 << endl;
	cout << "��������� �����������: " << pol6 - pol5 << endl;

	cout << "�������� ��������� �� ������(� ������������ ���������������): " << pol5 * CN1 << endl;
	cout << "���������������: " << CN1 * pol6 << endl;

	cout << "���������� �������� ���������� ��� �������� X: " << pol6.compute(CN1) << endl;

	pol5.shrink_to_fit();
	cout << "����� shrink_to_fit: " << pol5 << endl;

	pol6.expand(8);
	cout << "����� expand: " << pol6 << endl;

	cout << "����� ��������������� ���������: " << integral_compute(pol5) << endl;*/
}