/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   Fixed.cpp                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/09/27 15:19:50 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/11/06 21:06:19 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <cmath>

Fixed::Fixed()
    : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int accurate)
    : _fixedPoint(accurate << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float accurate)
    : _fixedPoint((int)roundf(accurate * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
    : _fixedPoint(f.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f)
{
    if (this != &f)
        _fixedPoint = f.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPoint);
}

int Fixed::toInt(void) const
{
    return ((int)(roundf((float)_fixedPoint / (1 << _fractionalBits))));
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPoint / (1 << _fractionalBits));
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}

bool Fixed::operator>(const Fixed& f) const
{
    return (this->_fixedPoint > f._fixedPoint);
}

bool Fixed::operator<(const Fixed& f) const
{
    return (this->_fixedPoint < f._fixedPoint);
}

bool Fixed::operator>=(const Fixed& f) const
{
    return (this->_fixedPoint >= f._fixedPoint);
}

bool Fixed::operator<=(const Fixed& f) const
{
    return (this->_fixedPoint <= f._fixedPoint);
}

bool Fixed::operator==(const Fixed& f) const
{
    return (this->_fixedPoint == f._fixedPoint);
}

bool Fixed::operator!=(const Fixed& f) const
{
    return (this->_fixedPoint != f._fixedPoint);
}

Fixed Fixed::operator+(const Fixed& f) const
{
    return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator-(const Fixed& f) const
{
    return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator*(const Fixed& f) const
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(const Fixed& f) const
{
    return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    ++(this->_fixedPoint);
    return (*this);
}

Fixed Fixed::operator++(int n)
{
    Fixed tmp(*this);

    (void)n;
    operator++();
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
    --(this->_fixedPoint);
    return (*this);
}

Fixed Fixed::operator--(int n)
{
    Fixed tmp(*this);

    (void)n;
    operator--();
    return (tmp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 <= f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 <= f2)
        return (f1);
    return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 >= f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 >= f2)
        return (f1);
    return (f2);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    output << fixed.toFloat();
    return (output);
}
