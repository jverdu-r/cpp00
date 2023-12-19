/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:31 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/12/04 17:12:41 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            for (size_t j = 0; j< strlen(argv[i]); ++j)
            {
                argv[i][j] = static_cast<char>(toupper(argv[i][j]));
            }
            std::cout << argv[i];
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARBLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
