/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:24:36 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/12/13 18:24:40 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/phonebook.hpp"

int main(void)
{
    std::string cmd;
    Phonebook   pb;
    int         i = 0;

    while(1)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, cmd);
        cmd.erase(0, cmd.find_first_not_of("\t\v\r\f"));
        while (isspace(cmd[cmd.length() - 1]))
            cmd.erase(cmd.find_first_not_of("\t\v\r\f") + 1, cmd[cmd.length() - 1]);
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
        {
            i = pb.check_pb(pb);
            if (i > 7)
            {
                std::cout << "Maximum contacts reached" << std::endl;
                std::cout << "If you continue the oldest contact will be deleted" << std::endl;
                std::getline(std::cin, cmd);
                cmd.erase(0, cmd.find_first_not_of("\t\v\r\f"));
                while (isspace(cmd[cmd.length() - 1]))
                    cmd.erase(cmd.find_first_not_of("\t\v\r\f") + 1, cmd[cmd.length() - 1]);
                if (cmd == "Y" || cmd == "y" || cmd == "YES" || cmd == "yes" || cmd == "Yes")
                {
                    pb = pb.del_one(pb);
                    i = 7;
                }
                else if (cmd == "N" || cmd == "NO" || cmd == "No" || cmd == "no")
                    i = -1;
                else
                    std::cout << "ERROR" << cmd << "not a valid command" << std::endl;
            }
            if (i >= 0)
                pb = pb.add_cnt(pb, i);
        }
        else if (cmd == "SEARCH")
            pb.display_pb(pb);
        else if (cmd.empty())
            continue;
        else
            std::cout << "ERROR" << cmd << "not a valid command" << std::endl;
    }
    return (0);
}