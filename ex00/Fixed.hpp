/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesimsek <sesimsek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:59:09 by sesimsek          #+#    #+#             */
/*   Updated: 2025/10/25 21:34:09 by sesimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int _fixedPointNumberValue;
		static const int _fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
