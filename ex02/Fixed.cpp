/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesimsek <sesimsek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:33:22 by sesimsek          #+#    #+#             */
/*   Updated: 2025/10/28 17:50:51 by sesimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesimsek <sesimsek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:54:51 by sesimsek          #+#    #+#             */
/*   Updated: 2025/10/28 15:00:30 by sesimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	this->_fixedPointNumberValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	this->_fixedPointNumberValue = other.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if(this != &other)
	{
		this->_fixedPointNumberValue = other.getRawBits();
	}
	return(*this);
}

int Fixed::getRawBits() const
{
	return(this->_fixedPointNumberValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNumberValue = raw;
}

// --- DÖNÜŞÜM FONKSİYONLARI ---

// float'tan Fixed'e
Fixed::Fixed(const float fValue)
{
    this->_fixedPointNumberValue = roundf(fValue * (1 << _fractionalBits));
}

// int'ten Fixed'e
Fixed::Fixed(const int iValue)
{
    this->_fixedPointNumberValue = iValue << _fractionalBits;
}

// Fixed'den float'a
float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointNumberValue / (1 << _fractionalBits));
}

// Fixed'den int'e
int Fixed::toInt(void) const
{	
    return (this->_fixedPointNumberValue >> _fractionalBits);
}

// cout için << operatörü
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

// --- ex02: Karşılaştırma Operatörleri ---

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointNumberValue > other._fixedPointNumberValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointNumberValue < other._fixedPointNumberValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointNumberValue >= other._fixedPointNumberValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointNumberValue <= other._fixedPointNumberValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointNumberValue == other._fixedPointNumberValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointNumberValue != other._fixedPointNumberValue;
}

// --- ex02: Aritmetik Operatörler ---

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// --- ex02: Artırma/Azaltma Operatörleri ---

// Ön ek artırma (++a)
Fixed& Fixed::operator++() {
    this->_fixedPointNumberValue++;
    return *this;
}

// Son ek artırma (a++)
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointNumberValue++;
    return temp;
}

// Ön ek azaltma (--a)
Fixed& Fixed::operator--() {
    this->_fixedPointNumberValue--;
    return *this;
}

// Son ek azaltma (a--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointNumberValue--;
    return temp;
}

// --- ex02: Statik Üye Fonksiyonlar ---

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
