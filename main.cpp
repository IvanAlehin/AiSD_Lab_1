#include<Polynomial.cpp>
#include<iostream>
using namespace std;
using namespace polynomial;


int main() {
	setlocale(LC_ALL, "RUS");

	cout << "Работа класса для int:" << endl << endl;

	Polynomial<int> polynom1(5);
	cout << "Конструктор с максимальной степенью многочлена:" << polynom1 << endl << endl;

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
	cout << "Конструктор с вектором значений при соответствующих степенях: " << polynom2 << endl << endl;

	cout << "Оператор [] для чтения коэффиента при заданной степени: " << polynom3[2] << endl << endl;

	polynom3.set(15, 3);
	cout << "Метод set для установки коэффициента при заданной степени : " << polynom3 << endl << endl;

	cout << "Сложение многочленов: " << polynom3 + polynom2 << endl;
	cout << "Вычитание многочленов: " << polynom2 - polynom3 << endl << endl;

	cout << "Оператор умножения на скаляр(с комутативностью): " << polynom2 * 3 << endl;
	cout << "Коммутативность: " << 4 * polynom3 << endl << endl;

	cout << "Вычисление значения многочлена при заданном х: " << polynom2.compute(2) << endl << endl;

	polynom1.set(4,0);
	polynom1.set(15, 2);
	polynom1.shrink_to_fit();
	cout << "Метод shrink_to_fit: " << polynom1 << endl;

	polynom3.expand(7);
	cout << "Метод expand: " << polynom3 << endl << endl;

	cout << "Поиск производной: " << derivative(polynom2) << endl;

	cout << "---------------------------------------------------" << endl;


	cout << "Работа класса для float:" << endl << endl;

	Polynomial<float> polynom1f(5);
	cout << "Конструктор с максимальной степенью многочлена:" << polynom1f << endl << endl;

	Vector<float> vec3(6);
	vec3[0] = 1.254f;
	vec3[1] = -0.2f;
	vec3[2] = -3.035f;
	vec3[3] = 4.1f;
	vec3[4] = -15.15f;
	vec3[5] = 6.8f;
	Polynomial<float> polynom2f(vec3);

	Vector<float> vec4(4);
	vec4[0] = 4.4f;
	vec4[1] = -9.2569f;
	vec4[2] = -7.36f;
	vec4[3] = 1.134f;
	Polynomial<float> polynom3f(vec4);
	cout << "Конструктор с вектором значений при соответствующих степенях: " << polynom2f << endl << endl;

	cout << "Оператор [] для чтения коэффиента при заданной степени: " << polynom3f[2] << endl << endl;

	polynom3f.set(15.25f, 3);
	cout << "Метод set для установки коэффициента при заданной степени : " << polynom3f << endl << endl;

	cout << "Сложение многочленов: " << polynom3f + polynom2f << endl;
	cout << "Вычитание многочленов: " << polynom2f - polynom3f << endl << endl;

	cout << "Оператор умножения на скаляр(с комутативностью): " << polynom2f * -3.58f << endl;
	cout << "Коммутативность: " << 4.36f * polynom3f << endl << endl;

	cout << "Вычисление значения многочлена при заданном х: " << polynom2f.compute(2) << endl << endl;

	polynom1f.set(-24.23f, 0);
	polynom1f.set(1.75f, 2);
	polynom1f.shrink_to_fit();
	cout << "Метод shrink_to_fit: " << polynom1f << endl;

	polynom3f.expand(7);
	cout << "Метод expand: " << polynom3f << endl << endl;

	cout << "Поиск производной: " << derivative(polynom2f) << endl;

	cout << "---------------------------------------------------" << endl;


	cout << "Работа класса для double:" << endl << endl;

	Polynomial<double> polynom1d(5);
	cout << "Конструктор с максимальной степенью многочлена:" << polynom1d << endl << endl;

	Vector<double> vec5(6);
	vec5[0] = 17.254;
	vec5[1] = -10.2;
	vec5[2] = 39.035;
	vec5[3] = -43.1;
	vec5[4] = -135.15;
	vec5[5] = 66.8;
	Polynomial<double> polynom2d(vec5);

	Vector<double> vec6(4);
	vec6[0] = -34.4;
	vec6[1] = -99.29569;
	vec6[2] = 7.88836;
	vec6[3] = 1.8834;
	Polynomial<double> polynom3d(vec6);
	cout << "Конструктор с вектором значений при соответствующих степенях: " << polynom2d << endl << endl;

	cout << "Оператор [] для чтения коэффиента при заданной степени: " << polynom3d[2] << endl << endl;

	polynom3d.set(91.5, 3);
	cout << "Метод set для установки коэффициента при заданной степени : " << polynom3d << endl << endl;

	cout << "Сложение многочленов: " << polynom3d + polynom2d << endl;
	cout << "Вычитание многочленов: " << polynom2d - polynom3d << endl << endl;

	cout << "Оператор умножения на скаляр(с комутативностью): " << polynom2d * -3.58f << endl;
	cout << "Коммутативность: " << 4.36 * polynom3d << endl << endl;

	cout << "Вычисление значения многочлена при заданном х: " << polynom2d.compute(2) << endl << endl;

	polynom1d.set(-43.23, 0);
	polynom1d.set(78.75, 2);
	polynom1d.shrink_to_fit();
	cout << "Метод shrink_to_fit: " << polynom1d << endl;

	polynom3d.expand(7);
	cout << "Метод expand: " << polynom3d << endl << endl;

	cout << "Поиск производной: " << derivative(polynom2d) << endl;

	cout << "---------------------------------------------------" << endl;



	cout << "Работа класса для complex<float>:" << endl << endl;

	Polynomial<complex<float>> polynom1cf(4);
	cout << "Конструктор с максимальной степенью многочлена:" << polynom1cf << endl << endl;

	Vector<complex<float>> vec7(3);
	vec7[0] = complex<float>(1.2f, 12.2f);
	vec7[1] = complex<float>(-5.7f, 13.32f);
	vec7[2] = complex<float>(8.2f, -92.29f);
	
	Polynomial<complex<float>> polynom2cf(vec7);

	Vector<complex<float>> vec8(4);
	vec8[0] = complex<float>(-36.8f, -57.89f);
	vec8[1] = complex<float>(-1.2f, 12.6f);
	vec8[2] = complex<float>(19.9f, 15.8f);
	vec8[3] = complex<float>(7.7f, -13.62f);
	Polynomial<complex<float>> polynom3cf(vec8);
	cout << "Конструктор с вектором значений при соответствующих степенях: " << polynom2cf << endl << endl;

	cout << "Оператор [] для чтения коэффиента при заданной степени: " << polynom3cf[2] << endl << endl;

	complex<float> complex_float(1.25f, -19.32f);
	polynom3cf.set(complex_float, 3);
	cout << "Метод set для установки коэффициента при заданной степени : " << polynom3cf << endl << endl;

	cout << "Сложение многочленов: " << polynom3cf + polynom2cf << endl;
	cout << "Вычитание многочленов: " << polynom2cf - polynom3cf << endl << endl;

	cout << "Оператор умножения на скаляр(с комутативностью): " << polynom2cf * complex_float << endl;
	cout << "Коммутативность: " << complex_float * polynom3cf << endl << endl;

	cout << "Вычисление значения многочлена при заданном х: " << polynom2cf.compute(2) << endl << endl;

	polynom1cf.set(complex_float, 0);
	polynom1cf.set(complex_float, 2);
	polynom1cf.shrink_to_fit();
	cout << "Метод shrink_to_fit: " << polynom1cf << endl;

	polynom3cf.expand(7);
	cout << "Метод expand: " << polynom3cf << endl << endl;

	cout << "Поиск производной: " << derivative(polynom2cf) << endl;

	cout << "---------------------------------------------------" << endl;



	cout << "Работа класса для complex<double>:" << endl << endl;

	Polynomial<complex<double>> polynom1cd(4);
	cout << "Конструктор с максимальной степенью многочлена:" << polynom1cd << endl << endl;

	Vector<complex<double>> vec9(3);
	vec9[0] = complex<double>(1.453012, 12.552);
	vec9[1] = complex<double>(-5.85257, 13.232);
	vec9[2] = complex<double>(8.042, -92.20329);

	Polynomial<complex<double>> polynom2cd(vec9);

	Vector<complex<double>> vec10(4);
	vec10[0] = complex<double>(-5636.58, -57.89);
	vec10[1] = complex<double>(-1.902, 12.7826);
	vec10[2] = complex<double>(19.94569, 415.4528);
	vec10[3] = complex<double>(7.7867, -13.88662);
	Polynomial<complex<double>> polynom3cd(vec10);
	cout << "Конструктор с вектором значений при соответствующих степенях: " << polynom2cd << endl << endl;

	cout << "Оператор [] для чтения коэффиента при заданной степени: " << polynom3cd[2] << endl << endl;

	complex<double> complex_double(91.02525, -19.951032);
	polynom3cd.set(complex_double, 3);
	cout << "Метод set для установки коэффициента при заданной степени : " << polynom3cd << endl << endl;

	cout << "Сложение многочленов: " << polynom3cd + polynom2cd << endl;
	cout << "Вычитание многочленов: " << polynom2cd - polynom3cd << endl << endl;

	cout << "Оператор умножения на скаляр(с комутативностью): " << polynom2cd * complex_double << endl;
	cout << "Коммутативность: " << complex_double * polynom3cd << endl << endl;

	cout << "Вычисление значения многочлена при заданном х: " << polynom2cd.compute(2) << endl << endl;

	polynom1cd.set(complex_double, 0);
	polynom1cd.set(complex_double, 2);
	polynom1cd.shrink_to_fit();
	cout << "Метод shrink_to_fit: " << polynom1cd << endl;

	polynom3cd.expand(7);
	cout << "Метод expand: " << polynom3cd << endl << endl;

	cout << "Поиск производной: " << derivative(polynom2cd) << endl;

	cout << "---------------------------------------------------" << endl;
}