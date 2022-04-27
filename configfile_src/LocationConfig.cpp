/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationConfig.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:33:32 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/27 11:40:46 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "LocationConfig.hpp"

LocationConfig::LocationConfig(/* args */) : 
    path(""), root(""), auto_index(0), cgi(),
    upload(""), redirect(""), methods()
{
}

LocationConfig::LocationConfig(LocationConfig const & p)
{
    *this = p;
}

LocationConfig LocationConfig::operator= (LocationConfig const &p)
{
    if (!this)
    {
        this->auto_index = p.auto_index;
        this->cgi = p.cgi;
        this->methods = p.methods;
        this->path = p.path;
        this->redirect = p.redirect;
        this->root = p.root;
        this->upload = p.upload;
    }
    return *this;
}

LocationConfig::~LocationConfig()
{
}

std::string LocationConfig::get_path()
{
    return this->path;
}
std::string LocationConfig::get_root()
{
    return this->root;
}

std::string LocationConfig::get_redirect()
{
    return this->redirect;
}

std::string LocationConfig::get_upload()
{
    return this->upload;    
}

std::vector<std::string> LocationConfig::getMethods()
{
    return this->methods;
}
std::vector<std::string> LocationConfig::getCgi()
{
    return this->cgi;
}

void LocationConfig::locationParser(std::string buf)
{
    bool processed = false;
    if(!buf.empty())
    {
        switch (buf[0])
        {
            case 'a' :
                if (processed == false && std::strncmp("autoindex = ", buf.c_str(), 12) == 0)
                {
                    if (std::strncmp("autoindex = on", buf.c_str(), 14 == 0))
                        this->auto_index = 1;
                    else if (std::strncmp("autoindex = off", buf.c_str(), 15 == 0))
                        this->auto_index = 0;
                    break;
                }
                throw Error_exc("syntax err : invalid autoindex");
            case 'p' :
                if(this->path.empty() && std::strncmp("path = ", buf.c_str(), 7) == 0)
                {
                    this->path = buf.substr(buf.find("path = ") + strlen("path = "));
                    if (this->path[this->path.size() - 1] != '/')
                        this->path += '/';
                    break;
                }
                throw Error_exc("syntax err : invalid path");
           // case 'r' // root / redirect 
           // case 'u' upload
           // case 'c' cgi
           // case 'm' methods
            default:
                if (buf.empty())
                    break;
                throw Error_exc("syntax err : invalid location");
        }
    }
}