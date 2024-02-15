#include "io_utilities.hpp"

namespace ewoner::utilities::io {
    

std::optional<std::string> getLine(std::istream& is, const std::string_view defaultValue ) noexcept{
    std::optional<std::string> rv{};
    if ( is.good() ) {
        std::string value { defaultValue };

        if ( std::getline( is, value ).bad() or value.empty() ) {
            rv = std::string{ defaultValue };
        } 
        else {
           rv = { value };
        }
    }
    return rv;
}
std::optional<std::string> getUserInput(const std::string_view prompt, const std::string_view defaultValue ) noexcept {
    std::optional<std::string> rv{};
    if ( prompt.empty() == false ) {
        std::cout << prompt << ": ";
    }
    return getLine( std::cin, defaultValue );
}
}//namespace