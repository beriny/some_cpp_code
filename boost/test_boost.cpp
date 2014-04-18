/*
 * test_boost.cpp
 * Copyright (C) 2014 - Jiang
 *
 * test_boost.cpp is free software; you can redistribute it and/or modify
 * it under the terms of the Just-For-Fun Public License  or How Casually License as published 
 *
 * test_boost.cpp is distributed while I don't know whether it is useful.  
 *
 * See the Just-For-Fun Public License for more details, 
 * BUT You may not receive a copy of the Just-For-Fun Public License
 * along with test_boost.cpp. So, please see <http://www.ligelaige.com/just-for-fun/license/>.
 */

/*
 *             File Name: test_boost.cpp
 * Operating Environment: ubuntu linux
 *                Author: Jiang
 *                 Email: ligelaige@gmail.com
 *          Created Time: 2014-04-18 19:04:27.516522 
 */

/*
 * g++ -I/usr/local/include/ test_boost.cpp /usr/local/lib/libboost_regex.a
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <boost/regex.hpp>

using namespace std;

int main (void)
{
    	string email_address;

    	boost::regex pattern("([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
    
	while ( cin >> email_address ) // 输入文件结尾符（Windows用Ctrl+Z，UNIX用Ctrl+D）结束循环
	{
		if ( boost::regex_match( email_address, pattern ) )
		{
			cout << "您输入的电子邮件地址合法" << endl;                       
		} else {
			cout << "您输入的电子邮件地址不合法" << endl;
		}
	}
	return 0;
}
