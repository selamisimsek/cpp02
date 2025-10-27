/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesimsek <sesimsek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:22:41 by sesimsek          #+#    #+#             */
/*   Updated: 2025/10/27 19:04:53 by sesimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _fixedPointNumberValue;
		static const int _fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		Fixed(const float fValue);
		Fixed(const int iValue);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed_point):

#endif
//İstek,Amaç
//Fixed(int),Tam sayıları sabit noktalı formata çevirme.
//Fixed(float),Ondalık sayıları sabit noktalı formata çevirme.
//toFloat(),Sabit noktalı değeri kayan noktalı sayı olarak döndürme.
//toInt(),Sabit noktalı değerin tam sayı kısmını döndürme.
//operator<<,Fixed nesnesini ekrana yazdırırken float değerini gösterme.