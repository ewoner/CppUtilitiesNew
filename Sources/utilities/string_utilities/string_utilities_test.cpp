#include "string_utilities_test.hpp"
namespace ewoner {
namespace utilities {

void test_string_utilities() { 
    const char * cStr = "test";
    std::string s{"test"};
    std::string_view sv{"test"};
    std::cout << "Capitalized: ------->  'test'" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "\tc_str \t\t\t\t" << capitalize(cStr) << std::endl;
    s = capitalize(sv);
    sv = capitalize(s);
    std::cout << "\tstd::string \t\t" << capitalize(s) << std::endl;
    std::cout << "\tstd::string_view \t" << capitalize(sv) << std::endl;

    cStr = "  \t\r\n    hello world!   \n\t\r";
    s = std::string("  \t\r\n    hello world!   \n\t\r");
    sv = std::string_view("  \t\r\n    hello world!   \n\t\r");
    std::cout << "\nTrim: \t\t------->  |  \t\r\n    hello world!   \n\t\r|" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "\tc_str \t\t\t\t|" << trim(cStr) << "|" << std::endl;
    s = trim(sv);
    sv = trim(s);
    std::cout << "\tstd::string \t\t|" << trim(s) << "|" << std::endl;
    std::cout << "\tstd::string_view \t|" << trim(sv) << "|" << std::endl;

    cStr = "Hello World!";
    s = std::string("Hello World!");
    sv = std::string_view("Hello World!");
    std::cout << "\nChange case:  ------->  'Hello World!'" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "\tc_str \t\t\t\t" << change_case(cStr) << std::endl;
    s = change_case(sv);
    sv = change_case(s);
    std::cout << "\tstd::string \t\t" << change_case(s) << std::endl;
    std::cout << "\tstd::string_view \t" << change_case(sv)  << std::endl;

    cStr = "hELLO wORLD!";
    s = std::string("hELLO wORLD!");
    sv = std::string_view("hELLO wORLD!");
    std::cout << "\nTitle case:  ------->  'hELLO wORLD!" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "\tc_str \t\t\t\t" << title_case(cStr) << std::endl;
    s = title_case(sv);
    sv = title_case(s);
    std::cout << "\tstd::string \t\t" << title_case(s)  << std::endl;
    std::cout << "\tstd::string_view \t" << title_case(sv) << std::endl;


    cStr = "hELLO wORLD!";
    s = std::string("hELLO wORLD!");
    sv = std::string_view("hELLO wORLD!");
    std::cout << "\nUpper case:  ------->  'hELLO wORLD!" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "\tc_str \t\t\t\t" << upper_case(cStr) << std::endl;
    s = upper_case(sv);
    sv = upper_case(s);
    std::cout << "\tstd::string \t\t" << upper_case(s)  << std::endl;
    std::cout << "\tstd::string_view \t" << upper_case(sv) << std::endl;

    cStr = "hELLO wORLD!";
    s = std::string("hELLO wORLD!");
    sv = std::string_view("hELLO wORLD!");
    std::cout << "\nLower case:  ------->  'hELLO wORLD!" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "\tc_str \t\t\t\t" << lower_case(cStr) << std::endl;
    s = upper_case(sv);
    sv = upper_case(s);
    std::cout << "\tstd::string \t\t" << lower_case(s)  << std::endl;
    std::cout << "\tstd::string_view \t" << lower_case(sv) << std::endl;

    cStr = "hELLO wORLD !";
    s = std::string("hELLO wORLD !");
    sv = std::string_view("hELLO wORLD !");
    std::cout << "\nSplit:  ------->  'hELLO wORLD!" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::vector<std::string> ss = split(cStr);
    std::cout << "\tc_str \t\t\t\t";
    for ( const std::string& s : ss ) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
    ss = split( s );
    std::cout << "\tstd::string \t\t";
    for ( const std::string& s : ss ) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
    ss = split( sv );
    std::cout << "\tstd::string_view \t";
    for ( const std::string& s : ss ) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;

    cStr = "hELLO wORLD !";
    s = std::string("hELLO wORLD !");
    sv = std::string_view("hELLO wORLD !");
    std::cout << "\nSplit:  ------->  'hELLO wORLD!" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    ss = split(cStr, "oO" );
    std::cout << "\tc_str \t\t\t\t";
    for ( const std::string& s : ss ) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
    ss = split( s, "oO" );
    std::cout << "\tstd::string \t\t";
    for ( const std::string& s : ss ) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
    ss = split( sv, "oO" );
    std::cout << "\tstd::string_view \t";
    for ( const std::string& s : ss ) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
}

}//namespace
}//namespace