#ifndef MENU_HPP
#define MENU_HPP

#include <any>
#include <optional>
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace ewoner::utilities::menu {

using Menu_ptr = std::shared_ptr<class Menu_T>;
using Func_T = void(*)(std::any& param);

struct MenuItem {
        std::string item_name;
        std::variant<Func_T,Menu_ptr> menu_action;
};
    
class Menu_T {
private:
    using MenuItemContainer = std::vector<MenuItem>;

public:
    Menu_T() = delete;
    Menu_T( const std::string_view title = "" , const MenuItemContainer& menuItems = {} ) 
        : title(title), menuItems(menuItems) 
        {}
    Menu_T( const Menu_T& ) = default;
    Menu_T( Menu_T&& ) = default;
    Menu_T& operator=( const Menu_T& ) = default;
    Menu_T& operator=( Menu_T&& ) = default;
    ~Menu_T() = default;
    

    const std::string& getTitle() const noexcept
    {
        return title;
    }

    void setTitle (const std::string_view title )
    {
        this->title = std::string{title};
    }

    //void menu( std::any& param )
    //{
    //    menu( *this, param );
    //}

    bool erase( size_t index )
    {
        if ( index < menuItems.size() ) {
            menuItems.erase( menuItems.begin() + index );
            return true;
        }
        return false;
    }

    MenuItem append( const MenuItem& item )
    {
        
        return menuItems.emplace_back( item );
    }

   bool insert(size_t index, const MenuItem& item )
    {
        if ( index < menuItems.size() ) {
            menuItems.insert( menuItems.begin() + index, item );
            return true;
        }

        return false;
    }

private:

    class RunVisitor
    {
    public:
        RunVisitor(std::any& par) : param(par) {}

        void operator()(func_T func) { func(param); }
        void operator()(Menu_ptr menu) { Menu::menu(*menu, param); }

    private:
        std::any& param;
    };

    static void menu(const Menu& m, std::any& param)
    {
        const static auto show = [](const Menu& mu) {
            std::ostringstream oss;
            const auto nom = mu.mitems.size();

            oss << '\n' << mu.title() << "\n\n";

            for (size_t i = 0U; i < nom; ++i)
                oss << i + 1 << ")  " << mu.mitems[i].name << '\n';

            oss << "0)  Exit menu\n\nEnter menu option number";
            return getnum<size_t>(oss.str(), 0, nom);
        };


        for (size_t opt = 0U; (opt = show(m)) > 0; )

            //if (const auto& mi = m.mitems[opt - 1]; std::holds_alternative<Menu::f_type>(mi.func))
            //	std::get<Menu::f_type>(mi.func)(param);
            //else
            //	menu(*std::get<Menu*>(mi.func), param);


            //std::visit(RunVisitor(param), m.mitems[opt - 1].func);
    }

    std::string title;
    MenuItemContainer menuItems;
};//class menu
}//namespace ewoner::utilites::menu

#endif