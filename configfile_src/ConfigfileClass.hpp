/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigfileClass.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:43:24 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/15 15:43:24 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <sstream>
# include <vector>
# include <algorithm>

class ConfigfileClass
{
private:
    std::string		configFile;
	size_t			serverCount;
	std::vector<std::string>	serverConf; //vector of servers

public:
    ConfigfileClass(/* args */);
    ~ConfigfileClass();
    ConfigfileClass( std::string const & conf );
	ConfigfileClass( ConfigfileClass const &p );
	ConfigfileClass & operator=( const ConfigfileClass & p);

    //getters & setters here
    std::string getConfigfile();
    size_t getServerCount();
    //server_conf  

    //parse here ...

    class Error_exc : public std::exception {
        private:
            std::string error_msg;
        public:
            explicit Error_exc( const std::string &error_msg ) throw() : error_msg(error_msg) {}
            ~Error_exc() throw() {}

            virtual const char * what() const throw() {
                return (error_msg.c_str());
            }
        };
};

