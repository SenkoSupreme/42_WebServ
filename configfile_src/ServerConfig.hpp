/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:29:22 by mbrija            #+#    #+#             */
/*   Updated: 2022/04/18 11:28:53 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../global_src/support_funcs.hpp"

class ServerConfig
{
private:
    size_t port;
    std::string name;
    std::string root;
    std::string redirect;
    std::string index;
    std::string log;
    std::string error;
    size_t body_size;
    size_t location_count;
    std::vector<int> location; // location type edit later
    
    
public:
    ServerConfig(/* args */);
    ServerConfig(ServerConfig const &p);
    ServerConfig operator=(ServerConfig const &p);
    ~ServerConfig();

    //getters 
};

