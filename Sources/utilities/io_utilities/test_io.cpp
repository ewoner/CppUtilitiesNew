////// futuretest_menu.cpp
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>

#include "io_utilities.hpp"

using namespace std::literals::string_literals;
using namespace ewoner::utilities::io;

void test_getUserInput();
void test_getData();
void test_getNumber();

#include <sstream>

int run_tests( void ) {
    using namespace std;
    istringstream iss{""};
    while ( iss.good() ) {
        char c = iss.peek();
        cout << static_cast<int>(c) << endl;
    }
    if ( iss.eof() ) { cout << "EOF!" << endl; }
    
    
    test_getUserInput();
    test_getData();
    test_getNumber();
    std::cout << "\n\n\n\n\nHello Testing World!" << std::endl;
    return 0;
}
void test_getNumber(){
    const uint NUM_OF_TESTS = 3;
    uint failed = NUM_OF_TESTS;
    int intData{};
    double dData{};
    
    std::cerr << "\n\nNow testing 'ewoner::utilities::menu::getNumber<T>()'\n"
        << std::setfill('=') << std::setw(80) << "\n";
    {//test scope to mask auto data;
        std::cerr << "Getting integer data: " << std::endl;
        std::cout << "Enter a integer: (Use '10' for input)\n";
        auto data =  getNumber<int>( std::cin );
        if ( data.has_value() ) {
            intData = data.value();
        }
        if ( intData == 10 ) {
            std::cout << "ewoner::utilities::menu::getNumber<int>() works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getNumber<int>() failed" << std::endl;
        }
    }//end of scope
    
    {//test scope to mask auto data;
        intData = 0;
        std::cerr << "Getting real not integer data: " << std::endl;
        std::cout << "Enter a integer: (Use '10.9' for input)\n";
        auto data =  getNumber<int>( std::cin );
        if ( data.has_value() ) {
            intData = data.value();
        }else {
            std::cerr << "ewoner::utilities::menu::getNumber<int>() failed - bad integer" << std::endl;
        }
        if ( intData == 10 ) {
            std::cout << "ewoner::utilities::menu::getNumber<int>() works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getNumber<int>() failed" << std::endl;
        }
    }//end of scope
    {//test scope to mask auto data;
        std::cout << "Enter a doulbe: (Use '10.9' for input)\n";
        auto data =  getNumber<double>( std::cin );
        if ( data.has_value() ) {
            dData = data.value();
            std::cout << "dData = " << dData << std::endl;
        }
        if ( dData == 10.9 ) {
            std::cout << "ewoner::utilities::menu::getNumber<double>() works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getNumber<double>() failed" << std::endl;
        }
    }//end of scope
    //Test Final print off
    std::cerr << std::setfill('=') << std::setw(80) << "\n" << "Done testing 'ewoner::utilities::menu::getNumber()' --> " 
        << failed << " out of  " << NUM_OF_TESTS  << " failed\n"
        << std::setfill('=') << std::setw(80) << "\n" << std::flush;
}
void test_getData() {
    const uint NUM_OF_TESTS = 5;
    uint failed = NUM_OF_TESTS;
    std::string strData{};
    int intData{};
    double dData{};
    bool bData{};

    {//test scope to mask auto data;
        std::cerr << "\n\nNow testing 'ewoner::utilities::menu::getData<T>()'\n"
            << std::setfill('=') << std::setw(80) << "\n";
        std::cerr << "Getting string data: " << std::endl;
        std::cout << "Enter a string: (Use 'test' for input)\n";
        auto data =  getData( std::cin );
        if ( data.has_value() ) {
            strData = data.value();
        }
        if ( strData == "test"s ) {
            std::cout << "ewoner::utilities::menu::getData<string>() works" << std::endl;
            failed--;
        }else {
            std::cerr << "ewoner::utilities::menu::getData<string>() failed" << std::endl;
        }
    }//end of scope
    {//test scope to mask auto data;
        std::cerr << "Getting integer data: " << std::endl;
        std::cout << "Enter a integer: (Use '10' for input)\n";
        auto data =  getData<int>( std::cin );
        if ( data.has_value() ) {
            intData = data.value();
        }
        if ( intData == 10 ) {
            std::cout << "ewoner::utilities::menu::getData<int>() works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getData<int>() failed" << std::endl;
        }
    }//end of scope
    {//test scope to mask auto data;
        intData = 0;
        std::cerr << "Getting bad integer data: " << std::endl;
        std::cout << "Enter a integer: (Use '10.9' for input)\n";
        auto data =  getData<int>( std::cin );
        if ( data.has_value() == false ) {
            std::cout << "ewoner::utilities::menu::getData<int>() w/bad integer works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getData<int>() w/bad integer failed" << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }//end of scope
    {//test scope to mask auto data;
        std::cerr << "Getting double data: " << std::endl;
        std::cout << "Enter a double: (Use '10.9' for input)\n";
        auto data =  getData<double>( std::cin );
        if ( data.has_value() ) {
            dData = data.value();
        }
        if ( dData == 10.9 ) {
            std::cout << "ewoner::utilities::menu::getData<double>() works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getData<double>() failed" << std::endl;
        }
    }//end of scope
    {//test scope to mask auto data;
        std::cerr << "Getting boolean data: " << std::endl;
        std::cout << "Enter a boolean: (Use 'true' for input)\n";
        std::cin >> std::boolalpha;
        auto data =  getData<bool>( std::cin );
        std::cin >> std::noboolalpha;
        if ( data.has_value() ) {
            bData = data.value();
        }
        if ( bData == true ) {
            std::cout << "ewoner::utilities::menu::getData<bool>() works" << std::endl;
            failed--;
        } else {
            std::cerr << "ewoner::utilities::menu::getData<bool>() failed" << std::endl;
        }
    }//end of scope
    
    //Test Final print off
    std::cerr << std::setfill('=') << std::setw(80) << "\n" << "Done testing 'ewoner::utilities::menu::getUserInput()' --> " 
        << failed << " out of  " << NUM_OF_TESTS  << " failed\n"
        << std::setfill('=') << std::setw(80) << "\n" << std::flush;
}


void test_getUserInput ( void ) { // void test_getUserInput( void )
    //getUserInput()
    const uint NUM_OF_TESTS = 5;
    std::string prompt{"Enter your name"};
    std::string defaultValue{"DValue"};
    std::optional<std::string> answer;
    uint failed = NUM_OF_TESTS;

    std::cerr << "\n\nNow testing 'ewoner::utilities::menu::getUserInput()'\n"
        << std::setfill('=') << std::setw(80) << std::endl;    
    
    std::cout << "Default Values:\n"
        << "\tprompt       = '" << prompt << "'\n"
        << "\tdefaultValue = '" << defaultValue << "'\n";
    
    std::cout << "\nTesting Prompt: \n"
        << "\n\n\tPrompting '" << prompt << "' (Just hit enter for input)\n"
        << std::setfill('=') << std::setw(80) << "\n";
    answer = getUserInput( prompt );
    std::cout << "\n\nDid '" << prompt << "' prompt work? (y/N): ";
    std::string userInput;
    std::getline( std::cin, userInput );
    if ( answer.has_value() ) {
      if ( *answer == "" and ( userInput == "y" or userInput == "Y" ) ) {
          std::cout << "ewoner::utilities::menu::getUserInput(prompt) w/ default returned value works" << std::endl;
          failed--;
      } else {
          std::cerr << "ewoner::utilities::menu::getUserInput(prompt) w/ default returned value broken" << std::endl;
      }
    } 
    
    std::cout << "\n\n\tPrompting '' (Just hit enter for input)\n"
        << std::setfill('=') << std::setw(80) << "\n";
    answer = getUserInput( );
    std::cout << "\n\nDid '""' prompt work? (y/N): ";
    std::getline( std::cin, userInput );
    if ( answer.has_value() ) {
      if ( *answer == "" and ( userInput == "y" or userInput == "Y" ) ) {
          std::cout << "ewoner::utilities::menu::getUserInput() w/ default returned value works" << std::endl;
          failed--;
      } else {
          std::cerr << "ewoner::utilities::menu::getUserInput() w/ default returned value broken" << std::endl;
      }
    } 

    std::cout << "\n\n\tPrompting ''" << prompt << "' (Testing bad stream; Should not halt for input)\n"
        << std::setfill('=') << std::setw(80) << "\n";
    std::cin.setstate( std::ios::badbit );
    answer = getUserInput( );
    std::cin.clear();
    if ( answer.has_value() == false ) {
          std::cout << "ewoner::utilities::menu::getUserInput(prompt) w/ bad stream works" << std::endl;
        failed--;
    } else {
          std::cerr << "ewoner::utilities::menu::getUserInput(prompt) w/ bad stream broken" << std::endl;
    }
    
    std::cout << "\n\n\tPrompting ''" << prompt << "' (Just hit enter for input)\n"
        << std::setfill('=') << std::setw(80) << "\n";
    answer = getUserInput( prompt, defaultValue );
    if ( answer.has_value() and *answer == defaultValue ) {
          std::cout << "ewoner::utilities::menu::getUserInput(prompt, defaultValue) w/ defaulte vaule returned works" << std::endl;
        failed--;
    } else {
          std::cerr << "ewoner::utilities::menu::getUserInput(prompt, defaultValue) w/ defaulte vaule returned broken" << std::endl;
    }

    std::cout << "\n\n\tPrompting ''" << prompt << "' (Type 'Lang' for input)\n"
        << std::setfill('=') << std::setw(80) << "\n";
    answer = getUserInput( prompt );
    if ( answer.has_value() and *answer == "Lang"s ) {
          std::cout << "ewoner::utilities::menu::getUserInput(prompt) w/ 'Lang' vaule returned works" << std::endl;
        failed--;
    } else {
          std::cerr << "ewoner::utilities::menu::getUserInput(prompt) w/ 'Lang' vaule returned broken" << std::endl;
    }
    std::cerr << std::setfill('=') << std::setw(80) << "\n" << "Done testing 'ewoner::utilities::menu::getUserInput()' --> " 
        << failed << " out of  " << NUM_OF_TESTS  << " failed\n"
        << std::setfill('=') << std::setw(80) << "\n" << std::flush;
}