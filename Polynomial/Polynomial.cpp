#ifndef Polynomial_Polynomial_H_
#define Polynomial_Polynomial_H_

#include <Vector.cpp>
#include <stdexcept>
#include <complex>
#include <cmath>
#include <iostream>
using namespace std;

namespace polynomial {

	template<typename T>
	class Polynomial {
		Vector<T> _coefficients;
	public:

		Polynomial();
		Polynomial(int max_level);
		Polynomial(const Vector<T>& other);

		Vector<T>& get_coefficients();
		Polynomial<T> set(T coefficient, int level);
		T compute(T argument);

		Polynomial<T> operator+=(const Polynomial<T>& other);
		Polynomial<T> operator+(const Polynomial<T>& other)const;
		Polynomial<T> operator-=(const Polynomial<T>& other);
		Polynomial<T> operator-(const Polynomial<T>& other)const;
		Polynomial<T> operator*(T scalar) const;
		Polynomial<T>& operator=(Polynomial<T> other);

		T& operator[](int level);
		T operator[](int level) const;

		bool operator==(Polynomial<T>& other) const;
		bool operator!=(Polynomial<T>& other) const;
		
		Polynomial<T> shrink_to_fit();
		Polynomial<T> expand(int level);

		~Polynomial() = default;

		friend std::ostream& operator<<(std::ostream& out, const Polynomial<T>& polynomial) {
			int new_size = polynomial._coefficients.get_size() - 1;

			for (int i = new_size; i >= 0; --i) {
				T coefficient = polynomial[i];
				if (i < new_size) {
					if (coefficient >= T(0)) {
						out << " +";
					}
					if (coefficient < T(0)) {
						out << " ";
					}
				}
				if (i > 0) {
					out << coefficient << "x^" << i;
				}
				else {
					out << coefficient;
				}
			}
			return out;
		};
	};

	template<typename T>
	Polynomial<T>::Polynomial() {
		this->_coefficients = Vector<T>();
	}

	template<typename T>
	Polynomial<T>::Polynomial(int max_level) {
		this->_coefficients = Vector<T>(max_level);
	}

	template<typename T>
	Polynomial<T>::Polynomial(const Vector<T>& other) {
		_coefficients = other;
	}

	template<typename T>
	Vector<T>& Polynomial<T>::get_coefficients()
	{
		return _coefficients;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::set(T coefficient, int level) {
		if (level < 0 ) { throw runtime_error("Invalid level"); }
		if (level > _coefficients.get_size()){
			expand(level);
			_coefficients[level - 1] = coefficient;
			return *this;
		}
		_coefficients[level] = coefficient;
		return *this;
	}

	template<typename T>
	T Polynomial<T>::compute(T arg) {
		T sum=0;
		for (int i = 0; i < _coefficients.get_size(); ++i) {
			sum += _coefficients[i]* pow(arg, i);
		}
		return sum;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator+=(const Polynomial<T>& other) {
		_coefficients += other._coefficients;
		return *this;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const {
		int max_size = std::max(_coefficients.get_size(), other._coefficients.get_size());
		Polynomial<T> result(max_size);

		for (int i = 0; i < max_size; ++i) {
			T coefficient1 = (i < _coefficients.get_size()) ? _coefficients[i] : 0;
			T coefficient2 = (i < other._coefficients.get_size()) ? other._coefficients[i] : 0;

			result._coefficients[i] = coefficient1 + coefficient2;
		}

		return result;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator-=(const Polynomial<T>& other) {
		_coefficients -= other._coefficients;
		return *this;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& other) const {
		int max_size = std::max(_coefficients.get_size(), other._coefficients.get_size());
		Polynomial<T> result(max_size);

		for (int i = 0; i < max_size; ++i) {
			T coefficient1 = (i < _coefficients.get_size()) ? _coefficients[i] : 0;
			T coefficient2 = (i < other._coefficients.get_size()) ? other._coefficients[i] : 0;

			result._coefficients[i] = coefficient1 - coefficient2;
		}

		return result;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator*(T scalar) const {
		Polynomial<T> result = *this;
		for (int i = 0; i < result._coefficients.get_size(); ++i) {
			result._coefficients[i] = result._coefficients[i] * scalar;
		}
		return result;
	}
	template<typename T>
	Polynomial<T> operator*(T scalar, Polynomial<T>& other) {
		Polynomial<T> result = other;
		for (int i = 0; i < other.get_coefficients().get_size(); ++i) {
			result.get_coefficients()[i] = scalar * other.get_coefficients()[i];
		}
		return result;
	}

	template<typename T>
	T& Polynomial<T>::operator[](int level) {
		if (level < 0 || level >= _coefficients.get_size()) {
			throw runtime_error("Invalid level");
		}
		return _coefficients[level];
	}

	template<typename T>
	T Polynomial<T>::operator[](int level) const {
		if (level < 0 || level >= _coefficients.get_size()) {
			throw runtime_error("Invalid level");
		}
		return _coefficients[level];
	}

	template<typename T>
	bool Polynomial<T>::operator==(Polynomial<T>& other) const {
		return (this->_coefficients == other._coefficients);
	}

	template<typename T>
	bool Polynomial<T>::operator!=(Polynomial<T>& other) const {
		return (this->_coefficients != other._coefficients);
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::shrink_to_fit() {
		int new_size = _coefficients.get_size();

		while (new_size > 0 && _coefficients[new_size - 1] == T(0)) {
			new_size--;
		}

		Polynomial<T> result(new_size);

		for (int i = 0; i < new_size; ++i) {
			result._coefficients[i] = _coefficients[i];
		}
		_coefficients = result._coefficients;
		return *this;
	}

	template<typename T>
		Polynomial<T>& Polynomial<T>::operator=(Polynomial<T> other) {
			std::swap(_coefficients, other._coefficients);
			return *this;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::expand(int level) {
		Polynomial<T> temp(level);
		for (int i = 0; i < _coefficients.get_size(); ++i) {
			temp[i] = _coefficients[i];
		}
		_coefficients = temp.get_coefficients();
		return *this;
	}

	}
#endif