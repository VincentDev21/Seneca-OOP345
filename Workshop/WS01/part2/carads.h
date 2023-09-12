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
#ifndef SDDS_CARADS_H_
#define SDDS_CARADS_H_
extern double g_taxrate;
extern double g_discount;
namespace sdds{
    void listArgs(int argc, char* argv[]);
    class Cars
    {
    private:
        char* brand;
        char model[15];
        int year;
        double price;
        char status;
        bool discount;
    public:
        Cars();
        ~Cars();
        Cars(const Cars& data);
        Cars& operator=(const Cars& other);
        void read(std::istream& is);
        void display(bool reset);
        char getStatus();
        operator bool() const;
    };
    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);
}
#endif 
