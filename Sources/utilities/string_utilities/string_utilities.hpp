#ifndef STRING_UTILITIES_HPP
#define STRING_UTILITIES_HPP

#include <cstring>
#include <locale>
#include <iostream>
#include <sstream>
#include <optional>
#include <string_view>
#include <vector>

namespace ewoner {
namespace utilities {

const std::string WHITE_SPACE { " \t\n\r\v\f" };

std::string capitalize( const std::string_view sv);
std::string trim( const std::string_view sv);
std::string change_case( const std::string_view sv );
std::string title_case( const std::string_view sv );
std::string lower_case( const std::string_view sv );
std::string upper_case( const std::string_view sv );
std::vector<std::string> split( const std::string_view& sv, const std::string_view& delim = WHITE_SPACE );
    
/*
    
    
//std::string& trim(std::string& s);

std::string trim( const std::string_view sv);
std::string& title_case( std::string& s );
std::string title_case(std::string_view& sv);

std::vector<std::string> split_str( const std::string_view& s,  const std::string_view& delim = " ");
template
<typename charT>
charT uppercase(const charT& c ) {
    std::locale loc;
    return (std::toupper<charT>(c, loc));
}
template
<typename charT>
charT lowercase(const charT& c ) {
    return (std::tolower<charT>(c));
}
void clear_istream( std::istream& is = std::cin ); 
    
void put_prompt(const std::string_view s, const std::string_view s2 = "", std::ostream& os = std::cout );
    
template<typename T = int>
bool startsWithDigit(const std::string_view s)
{
    if (s.empty())
        return false;
        
    if (std::isdigit(s.front()))
        return true;
        
    return (((std::is_signed<T>::value && ( ( (s.front() == '-')) || (s.front() == '+')) )
                && ((s.size() > 1) && std::isdigit(s[1]))));
}

template<typename T = int>
std::optional<T> stonum(std::string_view sv)
{
	std::string s{ trim(sv) };
	auto value = T {};

	if ( startsWithDigit<T>(s) ) {
		std::istringstream ss{s};
		ss >> value;
		if (ss.peek() == EOF) {
            return value;
        }
	}
	return std::nullopt;
}

    */
}//namespace
}//namespace    

#endif