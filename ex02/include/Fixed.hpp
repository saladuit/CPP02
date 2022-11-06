/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   Fixed.hpp                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/09/26 08:30:27 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/11/06 20:43:06 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <__bit_reference>
#include <bitset>
#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {

public:
    Fixed();
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);

    Fixed(const int accurate);
    Fixed(const float precise);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(const int raw);

    bool operator>(const Fixed& f) const;
    bool operator<(const Fixed& f) const;
    bool operator>=(const Fixed& f) const;
    bool operator<=(const Fixed& f) const;
    bool operator==(const Fixed& f) const;
    bool operator!=(const Fixed& f) const;

    Fixed operator+(const Fixed& f) const;
    Fixed operator-(const Fixed& f) const;
    Fixed operator*(const Fixed& f) const;
    Fixed operator/(const Fixed& f) const;

    Fixed& operator++(void);
    Fixed operator++(int n);
    Fixed& operator--(void);
    Fixed operator--(int n);

    static Fixed& min(Fixed& f1, Fixed& f2);
    static Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    static Fixed& max(const Fixed& f1, const Fixed& f2);

    ~Fixed();

private:
    int _fixedPoint;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& output, const Fixed& fixed);

#endif
