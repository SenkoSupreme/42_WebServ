/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationConfig.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:33:32 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/21 18:04:05 by mbrija           ###   ########.fr       */
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