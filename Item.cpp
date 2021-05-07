/* W03 LAB
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-02-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds {
	void Item::setName(const char* name) {  
        strnCpy(m_itemName, name, 20);
        //m_itemName[20] = '\0';
	}
    void Item::setEmpty() {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }
    void Item::set(const char* name, double price, bool taxed) {
        //m_itemName[0] ='\0';
        if (name == nullptr || price < 0) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }
    void Item::display()const {
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(20);
            cout.fill('.');
            cout.setf(ios::fixed);                           
            cout << m_itemName;
            cout << " | ";
            cout.setf(ios::right);
            cout.fill(' ');
            cout.width(7);
            cout.precision(2);
            cout << m_price << " | ";
            
            cout << (m_taxed ? "Yes" : "No ") << " |"<< endl;
            cout.unsetf(ios::right);
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
    bool Item::isValid()const {
        if (m_price != 0.0 && m_itemName[0] != '\0') {
            return true;
        }
        return false;
    }
    double Item::price()const {
        return m_price;
    }
    double Item::tax()const {
        if (m_taxed) {
            const double tax_rate = .13;
            return (m_price * tax_rate);
        }
        else {
            return 0.0;
        }
    }
}