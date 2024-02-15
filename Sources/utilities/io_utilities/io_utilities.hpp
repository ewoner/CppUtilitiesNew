#ifndef IO_UTILITIES_HPP
#define IO_UTILITIES_HPP

#include <any>
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <string_view>
#include <sstream>
#include <variant>
#include <vector>

#include "string_utilities.hpp"

using namespace std::string_literals;

namespace ewoner::utilities::io {



// Obtain a line of text from specified stream. Removes any existing data from input buffer
// is - input stream
// def - optional default text if no text entered
// returns either valid input line or no value if problem obtaining input

std::optional<std::string> getLine(std::istream& is, const std::string_view defaultValue = ""s) noexcept;
std::optional<std::string> getUserInput(const std::string_view prompt = ""s, const std::string_view defaultValue = ""s) noexcept;

// Extract next item of data from specified stream. Data must terminate with a white-space char
// Defaults to type string. Note extraction for string stops at white-space char
// is - stream from which to extract data
// returns either valid extracted data or no value if problem extracting data

template<typename T = std::string>
std::optional<T> getData(std::istream& is )
{
    auto i = T {};
    const bool b = (is >> i) and ( std::isspace( is.peek() ) or is.peek() == EOF );
    std::cout << std::boolalpha <<__func__ << " i = " << i << " b = " << b << std::endl;
    return b ? i : std::optional<T> {};
}


// Obtains a number from specified stream in specified type
// Default of number type is int
// is - stream from which to obtain number
// wholeline - true if only one number per line (default), false if can have multiple numbers per line.
// returns either valid number of required type or no value if problem extracting data

template<typename T = int>
std::optional<T> getNumber(std::istream& is, bool wholeline = true)
{
    const auto o = getData<long double>(is);
    if (wholeline) {
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }    
    return o.has_value() ? std::optional<T>  { static_cast<T>( *o ) }: std::optional<T> {};


}

// Obtains a number from the console. First displays prompt text
// If specified, number must be within the specified min..max range and range displayed as (...) after prm
// prm - optional prompt text to display first
// nmin - optional minimum valid value
// nmax - optional maximum valid value
// wholeline - true if only one number per line (default), false if can have multiple numbers per line
// returns valid number of required type. No error conditions. Only returns when valid number entered

template <typename T = int>
auto getnum(const std::string& prm = "", T nmin = std::numeric_limits<T>::lowest(), T nmax = std::numeric_limits<T>::max(), bool wholeline = true)
{
    const auto showdefs = [nmin, nmax]() {
        std::cout << " (";

        if (nmin != std::numeric_limits<T>::lowest() || std::is_unsigned<T>::value)
            std::cout << nmin;

        std::cout << " - ";

        if (nmax != std::numeric_limits<T>::max())
            std::cout << nmax;

        std::cout << ")";
    };

    std::optional<T> o;

    do {
        std::cout << prm;

        if ((nmin != std::numeric_limits<T>::lowest()) || (nmax != std::numeric_limits<T>::max()))
            showdefs();

        std::cout << " :";
        o = getnum<T>(std::cin, wholeline);
    } while ((!o.has_value() || (((*o < nmin) || (*o > nmax)))) && (std::cout << "Invalid input" << std::endl));

    return *o;
}


// Obtains a char from the specified stream
// is - stream from which to obtain number
// def - default char to return if no character obtained
// wholeline - true if only one char per line (default), false if can have multiple chars per line
// returns either valid character or no value if problem extracting data

std::optional<char> getchr(std::istream& is, char def = '\0', bool wholeline = true) noexcept;

// Obtains a char from the console. First displays prompt text
// prm - optional prompt text to display first
// valid - optional string containing valid values for the char. Displayed within (...)
// def - optional default char to use if none entered. Displayed within [...]
// wholeline - true if only one char per line (default), false if can have multiple chars per line
// returns valid char. No error conditions. Only returns when valid char entered

std::optional<char> getchr(const std::string& prm = "", const std::string& valid = "", char def = 0, bool wholeline = true) noexcept;
}//namespace
#endif
