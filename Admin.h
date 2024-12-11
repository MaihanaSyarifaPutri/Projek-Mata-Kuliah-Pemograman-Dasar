/**
 * Project Untitled
 */


#ifndef _ADMIN_H
#define _ADMIN_H

class Admin {
public: 
    
Boolean login();
    
Void manageCarData();
    
Void manageCustomerData();
    
Void printReport();
private: 
    String idAdmin;
    String username;
    String password;
};

#endif //_ADMIN_H