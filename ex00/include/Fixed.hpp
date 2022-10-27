/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   Fixed.hpp                                       |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/09/26 08:30:27 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/10/27 15:22:40 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:
    Fixed();
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _fixedPoint;
    static const int _fractionalBits = 8;
};

#endif
