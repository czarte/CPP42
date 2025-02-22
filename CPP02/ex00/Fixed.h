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
		Fixed(Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};


#endif //CPP42_FIXED_H
