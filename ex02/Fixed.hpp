/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesimsek <sesimsek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:22:41 by sesimsek          #+#    #+#             */
/*   Updated: 2025/10/28 17:37:02 by sesimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int					_fixedPointNumberValue;
        static const int	_fractionalBits;

    public:
        // ex00'dan gelen Ortodoks Kanonik Form
        Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        // ex01'den gelen kurucular
        Fixed(const int intValue);
        Fixed(const float floatValue);

        // ex00/ex01'den gelen metotlar
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // --- ex02: Karşılaştırma Operatörleri ---
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        // --- ex02: Aritmetik Operatörler ---
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // --- ex02: Artırma/Azaltma Operatörleri ---
        Fixed& operator++();     // Ön ek artırma (++a)
        Fixed operator++(int);  // Son ek artırma (a++)
        Fixed& operator--();     // Ön ek azaltma (--a)
        Fixed operator--(int);  // Son ek azaltma (a--)

        // --- ex02: Statik Üye Fonksiyonlar ---
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
};

// ex01'den gelen << operatörü
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
//İstek,Amaç
//Fixed(int),Tam sayıları sabit noktalı formata çevirme.
//Fixed(float),Ondalık sayıları sabit noktalı formata çevirme.
//toFloat(),Sabit noktalı değeri kayan noktalı sayı olarak döndürme.
//toInt(),Sabit noktalı değerin tam sayı kısmını döndürme.
//operator<<,Fixed nesnesini ekrana yazdırırken float değerini gösterme.