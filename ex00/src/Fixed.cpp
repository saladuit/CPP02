/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   Fixed.cpp                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/09/27 15:19:50 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/10/27 15:22:46 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

Fixed::Fixed()
    : _fixedPoint(0)
{
}

Fixed::Fixed(const Fixed& f)
    :
    _fixedPoint(f._fixedPoint)
{
}

Fixed& Fixed::operator=(const Fixed& f)
{
    if (this != &f)
        _fixedPoint = f._fixedPoint;
    return *this;
}
Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (_fixedPoint);
}
void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}
