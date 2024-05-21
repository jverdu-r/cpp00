/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:19:06 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/21 17:16:26 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"
#include <ctype.h>
#include <stdlib.h>
#include <cstdlib>
#include <cerrno>
#include <climits>

Phonebook::Phonebook(void){return;}

Phonebook::~Phonebook(void){return;}

int isnum(std::string s, int i)
{
    if (s.size() != 1)
        return (0);
    if (48 <= s[0] && s[0] <= 48 + i)
        return (1);
    return (0);
}

std::string add_info(std::string msg)
{
    std::string cnt;

    std::cout << msg;
    while(1)
    {
        std::getline(std::cin, cnt);
        cnt.erase(0, cnt.find_first_not_of("\t\v\r\f"));
        while(isspace(cnt[cnt.length() - 1]))
            cnt.erase(cnt.find_first_not_of("\t\v\r\f") + 1, cnt[cnt.length() - 1]);
        if (cnt.empty())
            std::cout << "Field could not be empty" << std::endl << msg;
        else
            break;
    }
    return (cnt);
}
int stringToInteger(const std::string& s) {
    char* end = 0;
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);

    if (end == s.c_str() || *end != '\0' || errno == ERANGE || val > INT_MAX || val < INT_MIN) {
        throw std::invalid_argument("Invalid integer: " + s);
    }
    return static_cast<int>(val);
}

bool isNumber(std::string& s) {
    if (s.empty()) {
        return false;
    }
    std::size_t start = 0;
    if (s[0] == '+' || s[0] == '-') {
        start = 1;
    }
    for (std::size_t i = start; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int add_phone()
{
    int         num;
    std::string msg;
    bool        ck;

    num = 0;
    std::cout << "Phone number:";
    std::getline(std::cin, msg);
    //std::cout << std::endl;
    ck = isNumber(msg);
    while (ck == false)
    {
	    std::cout << "only num values" << std::endl;
	    std::cout << "Phone number:";
        std::getline(std::cin, msg);
        //std::cout << std::endl;
        ck = isNumber(msg);
    }
    if (ck == true)
        return (stringToInteger(msg));
    return (0);
}

Phonebook    Phonebook::add_cnt(Phonebook pb, int i)
{
    Contact n_cnt(add_info("First name: "), add_info("Last name: "),
                  add_info("Nickname: "), add_phone(),
                  add_info("Darkest secret: "));
    pb.contacts[i] = n_cnt;
    return(pb);
}

int Phonebook::check_pb(Phonebook pb)
{
    int i;

    for (i = 0; i <= 8; i++)
    {
        if (pb.contacts[i].null_contact(pb.contacts[i]))
            return(i);
    }
    return (0);
}

Phonebook   Phonebook::del_one(Phonebook pb)
{
    int i = 0;

    while (i < 7)
    {
        pb.contacts[i] = pb.contacts[i + 1];
        i++;
    }
    return(pb);
}

void    Phonebook::display_pb(Phonebook pb)
{
    int i = 0;
    int max;
    std::string index;

    if (pb.contacts[0].null_contact(pb.contacts[0]))
    {
        std::cout << "The phonebook is empty" << std::endl;
        return;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    while (i < 8)
    {
        if (pb.contacts[i].null_contact(pb.contacts[i]))
            break;
        std::cout << "|" << std::setw(10) << i << "|";
        pb.contacts[i].print_info(pb.contacts[i], 1);
        std::cout << "|";
        pb.contacts[i].print_info(pb.contacts[i], 2);
        std::cout << "|";
        pb.contacts[i].print_info(pb.contacts[i], 3);
        std::cout << "|" << std::endl;
        std::cout << "|-------------------------------------------|" << std::endl;
        i++;
    }
    max = i - 1;
    while (1)
    {
        std::cout << "select index for more info: ";
        getline(std::cin, index);
        index.erase(0, index.find_first_not_of("\t\v\r\f"));
        while (std::isspace(index[index.length() - 1]))
            index.erase(index.find_first_not_of("\t\v\r\f") + 1, index[index.length() - 1]);
        if (index.empty())
            continue;
        if (isnum(index, max))
            i = (int)index[0] - 48;
        else if (index == "EXIT")
            break;
        else
        {
            std::cout << "Please enter a valid number" << std::endl;
            continue;
        }
        pb.contacts[i].print_complete(pb.contacts[i]);
            break;
    }
}
