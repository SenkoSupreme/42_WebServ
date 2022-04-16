/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:27:31 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/15 15:27:31 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configfile_src/ConfigfileClass.hpp"


int main(int ac, char **av)
{
    if (ac > 2)
    {
        std::cout << " bad parameters \n Usage: ./webserv configfile_path" << std::endl;
        return -1;
    }
    if (ac < 2)
    {

    }
    if (ac == 2)
    {
        
    }

}