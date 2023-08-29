#ifndef DATABANK_HPP
#define DATABANK_HPP

/* 
Author: Brion Lang
Github: ewwoner
email: ewoner@gmail.com

File Version: 0.0.0.b -- Initial posting.

Change Log: 0.0.0.b:
- added #include <optional>

Initial version: 0.0.0.a
*/

#include <map>
#include <optional>
#include <string>

namespace ewoner {
namespace utilities {    


template<class Ktype = std::string, class Vtype = std::string >
class Databank {
public:
    bool has( const Ktype & key ) const {
        return static_cast<bool>( bank.count( key ) );
    }
    std::optional<Vtype> set( const Ktype & key, const Vtype & value){
        if ( has ( key ) ){
            bank[key] = value;
            return value;
        }
        else {
            return add( key, value );
        }
    }
    std::optional<Vtype> get(const  Ktype & key ) const {
       return ( bank.find( key ) != bank.end() ?  std::optional<Vtype>{bank.at( key )} :  std::nullopt );
    }
    std::optional<Vtype> add( const Ktype & key, const Vtype & value ){
        return ( ( bank.emplace( key, value ) ).second == false ? std::nullopt :  std::optional<Vtype>{value} );
    }
    std::optional<Vtype> del( const Ktype & key ){
        auto rv = bank.find( key );
        Vtype value;
        if ( rv != bank.end() ) {
            value = rv->second;
        }
        else {
            return std::nullopt;
        }
        bank.erase( key );
        return value;
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
    std::optional<int> getAsInt( const Ktype & key ) const noexcept{
        if ( has( key ) == false ) {
            return {};
        }
        else if constexpr (std::is_same_v<int, Vtype> ) {
            return bank.at( key );
        }
        else if constexpr ( std::is_same_v<double, Vtype> ){
            return int( bank.at( key ) );
        }
        else if constexpr ( std::is_same_v<std::string, Vtype> ) {
            try {
                return std::stoi( bank.at( key ) );
            } catch ( ... ) {
                return std::nullopt;
            }
           
        }
         else {
            return std::nullopt;
        }
    }
    std::optional<bool> getAsBool( const Ktype & key ) const noexcept{
        if ( has( key ) == false ) {
            return {};
        }
        else if constexpr (std::is_same_v<int, Vtype> ) {
            return not (bank.at( key ) != 0);
        }
        else if constexpr ( std::is_same_v<double, Vtype> ){
            return not (int( bank.at( key ) != 0) );
        }
        else if constexpr ( std::is_same_v<std::string, Vtype> ) {
            return bank.at( key ) == "true";           
        }
         else {
            return std::nullopt;
        }
    }
    bool empty( ) const noexcept {
        return size() == 0;
    }
    std::optional<double> getAsDouble( const Ktype & key ) const noexcept{
        if ( has( key ) == false ) {
            return {};
        }
        else if constexpr ( std::is_same_v<double, Vtype> ){
            return bank.at( key );
        }
        else if constexpr ( std::is_same_v<int, Vtype> ) {
            return ( double )( bank.at( key ) );
        }
        else if constexpr ( std::is_same_v<std::string, Vtype> ) {
            try {
                return std::stod( bank.at( key ) );
            } catch ( ... ) {
                return std::nullopt;
            }
        }
        else {
            return std::nullopt;
        }
    }
private:
    std::map<Ktype, Vtype> bank;

};

}//namespace
}//namespace
#endif
