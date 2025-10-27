/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesimsek <sesimsek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:54:51 by sesimsek          #+#    #+#             */
/*   Updated: 2025/10/27 19:07:01 by sesimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNumberValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointNumberValue = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_fixedPointNumberValue = other.getRawBits();
	}
	return(*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedPointNumberValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumberValue = raw;
}

Fixed::Fixed(const float fValue)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int iValue)
{
	std::cout << "Int constructor called" << std::endl;
}
float Fixed::toFloat(void) const
{
	return(this->_fixedPointNumberValue);
}

int Fixed::toInt(void) const
{	
	return(this->_fixedPointNumberValue);
}
