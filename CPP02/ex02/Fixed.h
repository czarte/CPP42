	//
// Created by Vojtěch Parkán on 16.02.2025.
//

#ifndef CPP42_FIXED_H
#define CPP42_FIXED_H
#include <iostream>

class Fixed {
	private:
		int value;
		static const int fract_bits;
	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		int getRawBits(void)const;
		void setRawBits(int const raw);
		int toInt()const;
		float toFloat() const;

		Fixed& operator++();
		Fixed operator++(int);
		static Fixed const& max(Fixed const &src1, Fixed const &src2);
		static Fixed& max(Fixed &src1, Fixed &src2);
};

	std::ostream& operator<<(std::ostream&, Fixed const &src);
	bool operator<(Fixed const &src1, Fixed const &src2);
	bool operator>(Fixed const &src1, Fixed const &src2);
	bool operator>=(Fixed const &src1, Fixed const &src2);
	bool operator<=(Fixed const &src1, Fixed const &src2);
	bool operator==(Fixed const &src1, Fixed const &src2);
	bool operator!=(Fixed const &src1, Fixed const &src2);
	float operator+(Fixed const &src1, Fixed const &src2);
	float operator-(Fixed const &src1, Fixed const &src2);
	float operator*(Fixed const &src1, Fixed const &src2);
	float operator/(Fixed const &src1, Fixed const &src2);


#endif //CPP42_FIXED_H
