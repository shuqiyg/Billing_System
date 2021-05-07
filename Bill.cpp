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
#include "Bill.h"
using namespace std;
namespace sdds {
    double Bill::totalTax()const {
        double total_tax = 0;
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            total_tax += m_items[i].tax();
        }
        return total_tax;
  
    }
    double Bill::totalPrice()const {
        double total_price = 0;
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            total_price += m_items[i].price();
        }
        return total_price;
    }
    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
            cout.unsetf(ios::left);
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }
    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: ";
            //cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.width(10);          
            cout.precision(2);
            cout << totalTax() << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << (totalPrice() + totalTax()) << " |" << endl;
            cout.unsetf(ios::right);
            cout.precision(6);
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }
    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    bool Bill::isValid()const {
        /*if (m_title[0] != '\0' && m_items != nullptr) {
            int valid_c = 0;
            for (int i = 0; i < m_noOfItems; i++) {
                if (m_items[i].isValid()) {
                    valid_c++;
                }
            }
            return m_noOfItems == valid_c;
        }
        return false;*/
        bool valid_c = m_title[0] != '\0' && m_items != nullptr;
        int i;
        for (i = 0; i < m_noOfItems && valid_c; i++) {
            valid_c = m_items[i].isValid();
        }
        return valid_c;
    }
    void Bill::init(const char* title, int noOfItems) {
        if (title[0] != '\0' && noOfItems > 0) {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;        
            strnCpy(m_title, title, 36);
            //m_title[36] = '\0';
            m_items = new Item[m_noOfItems];
            int i;
            for (i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }          
        }
        else {
            setEmpty();
        }
    }
    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
        
    }
    void Bill::display()const {
        Title();
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].display();   
        }
        footer();
    }
    void Bill::deallocate() {
        for (int i = 0; i < m_noOfItems; i++) {
           m_items[i].setEmpty();
        }
        //m_title[0] = '\0';
        //setEmpty();
        //m_noOfItems = 0;
        //m_itemsAdded = 0;
        delete[] m_items;
        m_items = nullptr;
    }
}