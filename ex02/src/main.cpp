/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.cpp                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/09/22 21:27:16 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/11/06 17:01:19 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
