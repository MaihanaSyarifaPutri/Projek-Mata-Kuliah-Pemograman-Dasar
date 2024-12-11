/**
 * Project Untitled
 */


#ifndef _RENT_H
#define _RENT_H

class Rent {
public: 
    
Void rentConfirmation();
    
Void returnConfirmation();
private: 
    String rentData;
    Date rentDate;
    Date returnDate;
    Float totalPayment;
};

#endif //_RENT_H