/*
*****************************************************************************
						  Workshop - #1 (P1)
Full Name  : Vincent Le	
Student ID#: 131117228
Email      : vle21@myseneca.ca	
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <string.h>
#include <string>
#include<iomanip>
#include "carads.h"
using namespace std;
double g_taxrate = 0.13;
double g_discount = 0.05;
namespace sdds{
    void listArgs(int argc, char* argv[]){
        cout<<"Command Line:"<<endl;
        cout<<"--------------------------"<<endl;
        for(int i=0;i<argc;i++){
            cout<<"  "<<i+1<<": "<< argv[i]<<endl;
        }
        cout<<"--------------------------"<<endl<<endl;
    }
    Cars::Cars(){
        brand[0]='\0';
        model[0]='\0';
        year=0;
        price=0;
        status='\0';
        discount=false;  
    }
    void Cars::read(std::istream& is){
        if(is.good()){
            is>>status;
            is.ignore(1000, ',');
            is.getline(brand,10,',');
            is.getline(model, 15, ',');
            is>>year;
            is.ignore(1000, ',');
            is>>price;
            is.ignore(1000, ',');
            char temp;
            is>>temp;
            if (is.peek() == '\n')
                is.ignore();
            if (temp == 'Y')
                discount = true;
            else
                discount = false;
        }
        else{
            return;
        }
    }
    //    Brand     | Model     | Year |Price w/Tax |Special Price
    //1 . Honda     | CRV            | 2015 |    15000.00|    13500.00
    void Cars::display(bool reset){
        static int counter=0;
        if(reset){
            counter =0;
        }
        if (brand[0] != '\0' || model[0]!= '\0'){
            double price_tax=price+(price*g_taxrate);
            double special_price=price_tax-(price_tax*g_discount);
            cout<<setw(2)<<left<<++counter<<". ";
            cout<<setw(10)<<left<<brand<<"| ";
            cout<<setw(15)<<left<<model<<"| ";
            cout<<setw(4)<<left<<year<<" | ";
            cout<<setw(11)<<right<<fixed<<setprecision(2)<<price_tax<<"|";
            if(discount){
                cout<<setw(12)<<right<<fixed<<setprecision(2)<<special_price;
            }
        cout<<endl;
        }
        else{
            cout<<setw(2)<<left<<++counter<<". ";
            cout<<"No car"<<endl;
        }

        
        
    }
    char Cars::getStatus(){
        return status;
    }

}