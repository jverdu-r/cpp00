/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:18:11 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/10/30 10:30:04 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, std::string nickname, int phone, std::string d_secret)
{
    this->f_name = f_name;
    this->l_name = l_name;
    this->nickname = nickname;
    this->phone = phone;
    this->d_secret = d_secret;
}

Contact::Contact(void){return;}

Contact::~Contact(void){return;}

Contact& Contact::operator=(Contact const& origin)
{
    this->f_name = origin.f_name;
    this->l_name = origin.l_name;
    this->nickname = origin.nickname;
    this->phone = origin.phone;
    this->d_secret = origin.d_secret;
    return (*this);
}

int Contact::null_contact(Contact contact)
{
    if (contact.f_name.empty())
        return(1);
    else
        return (0);
}

void    Contact::print_info(Contact contact, int i)
{
    switch(i)
    {
        case 1:
            if (contact.f_name.size() > 10)
                std::cout << std::string(contact.f_name.begin(), contact.f_name.begin() + 9) << '.';
            else
                std::cout << std::setw(10) << contact.f_name;
            break;
        case 2:
            if (contact.l_name.size() > 10)
                std::cout << std::string(contact.l_name.begin(), contact.l_name.begin() + 9) << '.';
            else
                std::cout << std::setw(10) << contact.l_name;
            break;
        case 3:
            if (contact.nickname.size() > 10)
                std::cout << std::string(contact.nickname.begin(), contact.nickname.begin() + 9) << '.';
            else
                std::cout << std::setw(10) << contact.nickname;
            break;
    }
}

void    Contact::print_complete(Contact contact)
{
    std::cout << "First name: " << contact.f_name << std::endl;
    std::cout << "Last name: " << contact.l_name << std::endl;
    std::cout << "Nickname: " << contact.nickname << std::endl;
    std::cout << "Phone: " << contact.phone << std::endl;
    std::cout << "Darkest secret: " << contact.d_secret << std::endl;
}
