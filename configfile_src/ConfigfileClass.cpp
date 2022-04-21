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

ConfigfileClass::ConfigfileClass(/* args */) : configFile("../config/conf"), serverCount(0), serverConf(0)
{
}

ConfigfileClass::~ConfigfileClass()
{
}

ConfigfileClass::ConfigfileClass(std::string const & conf)
{
    this->configFile = conf;

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

std::vector<ServerConfig> ConfigfileClass::getServerConfig()
{
    return this->serverConf;
}

void ConfigfileClass::setServer()
{
    std::ifstream   file(this->configFile);
    std::string     buf;
    size_t          n = 0;
    
    /* get line from file and trim buff*/
    /*make the trim function, they don't have it ffs*/
    /* check for server count and throw exception */
    /*push to vector*/
}

void ConfigfileClass::setLocation()
{
    /*to do*/
}