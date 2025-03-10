	//
// Created by Vojtěch Parkán on 16.02.2025.
//

#ifndef CPP42_FIXED_H
#define CPP42_FIXED_H
#include <iostream>
#include <cmath>

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
		friend std::ostream& operator<<(std::ostream&, Fixed const &src);
};


#endif //CPP42_FIXED_H
