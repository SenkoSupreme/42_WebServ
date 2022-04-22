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
    while (getline(file, buf))
    {
        buf = trim(buf, " ");
        if (buf == "server {")
            n++;
    }
    if (n > 0)
        this->serverCount = n;
    else
        throw Error_exc("Server not found");
    for (size_t i = 0; i < this->serverCount; i++)
    {
        this->serverConf.push_back(ServerConfig());
    }
    

}

void ConfigfileClass::setLocation()
{
    /*to do*/
    std::ifstream file(this->configFile);
    std::string buf;
    size_t n_servers;
    size_t n_locations;

    while (getline(file, buf))
    {
        buf = trim(buf, " ");
        if (buf == "server {")
        {
            while (getline(file, buf))
            {
                buf = trim(buf, " ");
                if (buf.find("}") != std::string::npos && buf != "}")
                    throw Error_exc("Synatax Err");
                if (buf == "}")
                {
                    if (n_locations > 0)
                       this->serverConf[n_servers].location_count = n_locations;
                    else
                        throw Error_exc("Invalid Location");
                    for (size_t i = 0; i < n_locations; i++)
                    {
                        this->serverConf[n_servers].location.push_back(LocationConfig());
                    }
                    n_servers++;
                    n_locations = 0;
                    break;
                }
                else if (buf == "location = [")
                    n_locations++;
            }
        }
    }
}

void ConfigfileClass::configfileparser()
{
    std::ifstream file(this->configFile);
    std::string   buf;
    size_t n_servers = 0;
    this->setServer();
    this->setLocation();

    while(getline(file, buf))
    {
        buf = trim(buf, " ");
        if (buf != "server {")
        {
            if ((buf[0] == '#' && buf.find_first_of("#") == 0) || buf.empty())
                continue;
            else
                throw Error_exc("Invalid Syntax");
        }
        else
        {
            size_t n_locations;

            while (getline(file, buf))
            {
                buf = trim(buf, " ");
                if (buf == "}")
                    break;
                /*now how to make this shit work*/
            }
        }
    }
}