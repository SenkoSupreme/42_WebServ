/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigfileClass.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:42:42 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/15 15:42:42 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigfileClass.hpp"

ConfigfileClass::ConfigfileClass(/* args */)
{
}

ConfigfileClass::~ConfigfileClass()
{
}

ConfigfileClass::ConfigfileClass(std::string const & conf)
{

}

ConfigfileClass::ConfigfileClass( ConfigfileClass const &p )
{
    *this = p;
}

ConfigfileClass &ConfigfileClass::operator=(const ConfigfileClass & p)
{
    if (!this)
    {
        this->configFile = p.configFile;
        this->serverConf = p.serverConf;
        this->serverCount = p.serverCount;
    }
    return *this;
}

std::string ConfigfileClass::getConfigfile()
{
    return this->configFile;
}

size_t ConfigfileClass::getServerCount()
{
    return this->serverCount;
}
