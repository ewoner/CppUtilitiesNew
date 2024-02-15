#ifndef DATABANK_HPP
#define DATABANK_HPP

/* 
Author: Brion Lang
Github: ewwoner
email: ewoner@gmail.com

File Version: 0.0.0.b -- Initial posting.

Change Log: 0.0.0.b:
- added #include <optional>

Initial version: 0.0.0.b

Version a:  Base types were key_type = std::string and value_type = std::string
Version b:  Base types are key_type = std::string and value_type = std::variant<int, double, bool, std::string>
            Removed getAsBool(), getAsInt(), getAsDouble(), getAsString()
*/

#include <charconv>
#include <map>
#include <optional>
#include <variant>
#include <string>
#include <type_traits>

namespace ewoner {
namespace utilities {    

using key_type = std::string;
using value_type = std::variant<int, double, bool, std::string>;


template<class Ktype = key_type>
class Databank {
public:
    constexpr static const size_t INTEGER = 0;
    constexpr static const size_t DOUBLE = 1;
    constexpr static const size_t BOOLEAN = 3;
    constexpr static const size_t STRING = 4;
    
    bool has( const Ktype & key ) const {
        return static_cast<bool>( bank.count( key ) );
    }
    template <typename Vtype>
    std::optional<Vtype> set( const Ktype & key, const Vtype & value){
        if ( has ( key ) ){
            bank[key] = value;
            return value;
        }
        else {
            return add( key, value );
        }
    }
    template <typename Vtype>
    std::optional<Vtype> get(const  Ktype & key ) const {
       return ( bank.find( key ) != bank.end() ?  std::optional<Vtype>{ static_cast<Vtype>(bank.at( key ))} :  std::optional<Vtype>{} );
    }
    template <typename Vtype>
    std::optional<Vtype> add( const Ktype & key, const Vtype & value ){
        return ( ( bank.try_emplace( key, value ) ).second ?  std::optional<Vtype>{value} : std::nullopt );
    }
    template <typename Vtype>
    std::optional<Vtype> del( const Ktype & key ){
        auto rv = bank.find( key );
        Vtype value;
        if ( rv != bank.end() ) {
            value = rv->second;
             bank.erase( key );
            return value;
        }
        else {
            return std::nullopt;
        }
       
    }
    size_t size() const noexcept {
        return bank.size();
    }
    void purge() noexcept {
        bank.clear();
    }
    auto begin() noexcept {
        return bank.begin();
    }
    auto begin() const noexcept {
        return bank.begin();
    }
    auto cbegin() const noexcept {
        return bank.cbegin();
    }
    auto end() noexcept {
        return bank.end();
    }
    auto end() const noexcept {
        return bank.end();
    }
    auto cend() const noexcept {
        return bank.cend();
    }
    bool empty( ) const noexcept {
        return size() == 0;
    }
private:
    std::map<Ktype, value_type> bank;

};

}//namespace
}//namespace
#endif