#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur data untuk menyimpan informasi mobil
struct Car {
    string name;
    bool isRented; // Status apakah mobil sedang disewa
};

// Vektor untuk menyimpan daftar mobil
vector<Car> cars = {
    {"Ferrari F8", false},
    {"Lamborghini Huracan", false},
    {"Porsche 911", false},
    {"McLaren 720S", false},
    {"Bugatti Chiron", false}
};

// Vektor untuk menyimpan mobil yang disewa oleh pelanggan
vector<string> rentedCars;

// Fungsi untuk menampilkan daftar mobil
void displayCars() {
    cout << "<====AVAILABLE CARS====>\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << i + 1 << ". " << cars[i].name;
        if (cars[i].isRented) {
            cout << " (Rented)";
        }
        cout << endl;
    }
    cout << "-----------------------------------\n";
}

// Fungsi untuk menyewa mobil
void rentCar() {
    displayCars();
    int choice;
    cout << "\nEnter the number of the car you want to rent: ";
    cin >> choice;

    if (choice < 1 || choice > cars.size() || cars[choice - 1].isRented) {
        cout << "\nInvalid selection or car already rented. Please try again.\n";
    } else {
        cars[choice - 1].isRented = true;
        rentedCars.push_back(cars[choice - 1].name);
        cout << "\nYou have successfully rented: " << cars[choice - 1].name << "\n";
    }
}

// Fungsi untuk mengembalikan mobil
void returnCar() {
    if (rentedCars.empty()) {
        cout << "\nYou have no rented cars to return.\n";
        return;
    }

    cout << "<====YOUR RENTED CARS====>\n";
    for (size_t i = 0; i < rentedCars.size(); ++i) {
        cout << i + 1 << ". " << rentedCars[i] << endl;
    }
    cout << "-----------------------------------\n";

    int choice;
    cout << "\nEnter the number of the car you want to return: ";
    cin >> choice;

    if (choice < 1 || choice > rentedCars.size()) {
        cout << "\nInvalid selection. Please try again.\n";
    } else {
        // Update status mobil
        for (auto &car : cars) {
            if (car.name == rentedCars[choice - 1]) {
                car.isRented = false;
                break;
            }
        }
        cout << "\nYou have successfully returned: " << rentedCars[choice - 1] << "\n";
        rentedCars.erase(rentedCars.begin() + choice - 1);
    }
}

// Fungsi untuk menampilkan menu pelanggan
void customerMenu() {
    int choice;
    do {
        cout << "<====SPORTS CAR RENTAL - CUSTOMER MENU====>\n";
        cout << "1. Rent a Car\n";
        cout << "2. Return a Car\n";
        cout << "3. View Testimonials\n";
        cout << "4. Logout\n";
        cout << "---------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rentCar();
                break;
            case 2:
                returnCar();
                break;
            case 3:
                cout << "\n>> Viewing testimonials...\n";
                cout << "Customers say: \"Amazing service!\"\n";
                break;
            case 4:
                cout << "\n>> Logging out...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

// Fungsi untuk menampilkan menu admin
void adminMenu() {
    int choice;
    do {
        cout << "<====SPORTS CAR RENTAL - ADMIN MENU====>\n";
        cout << "1. Manage Customer Data\n";
        cout << "2. Manage Car Data\n";
        cout << "3. Print Reports\n";
        cout << "4. Logout\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n>> Managing customer data...\n";
                break;
            case 2:
                cout << "\n>> Managing car data...\n";
                break;
            case 3:
                cout << "\n>> Printing reports...\n";
                break;
            case 4:
                cout << "\n>> Logging out...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

// Fungsi utama untuk login dan navigasi
int main() {
    int role;
    do {
        cout << "<====WELCOME TO SPORTS CAR RENTAL SYSTEM====>\n";
        cout << "Login as:\n";
        cout << "1. Customer\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        cout << "---------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> role;

        switch (role) {
            case 1:
                cout << "\n>> Welcome, Customer!<<\n";
                customerMenu();
                break;
            case 2:
                cout << "\n>> Welcome, Admin!<<\n";
                adminMenu();
                break;
            case 3:
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (role != 3);

    return 0;
}
