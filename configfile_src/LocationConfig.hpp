/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationConfig.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:32:50 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/19 02:02:08 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../global_src/support_funcs.hpp"

class LocationConfig
{
private:
    std::string path;
    std::string root;
    std::string redirect;
    std::string upload;
    std::vector<std::string> methods;
    std::vector<std::string> cgi;
    bool auto_index;
    
public:
    LocationConfig(/* args */);
    LocationConfig(LocationConfig const & p);
    LocationConfig operator= (LocationConfig const &p);
    ~LocationConfig();

    //getters
    std::string get_path();
    std::string get_root();
    std::string get_redirect();
    std::string get_upload();

    //parse here

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

