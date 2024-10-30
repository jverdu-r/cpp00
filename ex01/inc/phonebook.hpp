/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:03:49 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/10/30 18:26:01 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "contact.hpp"

class Phonebook
{
    private:
        Contact contacts[9];
    public:
        Phonebook(void);
        ~Phonebook(void);
        int         check_pb(Phonebook pb);
        Phonebook   del_one(Phonebook pb);
        Phonebook   add_cnt(Phonebook pb, int i);
        void        display_pb(Phonebook pb);
        
};
#endif

