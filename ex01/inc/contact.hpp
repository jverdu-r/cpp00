/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:26 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/10/30 18:26:10 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:

        std::string f_name;
        std::string l_name;
        std::string nickname;
        int phone;
        std::string d_secret;
    
    public:

        int     null_contact(Contact contact);
        void    print_info(Contact contact, int i);
        void    print_complete(Contact contact);
        Contact(std::string f_name, std::string l_name, std::string nickname, int phone, std::string d_secret);
        Contact(void);
        ~Contact(void);      
};
#endif
