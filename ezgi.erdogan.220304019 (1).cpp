#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>

using namespace std;

class Car {
private:
    const string make;            
    const string model;          
    string licensePlate;          
    string color;                
    const int year;               
    const string chassisNumber;   
    const string engineNumber;    
    string purposeOfUse;          
    double price;                 
    bool valid;

    bool isValidLicensePlate(const string& plate) const {
        regex format1("^\\d{2}[A-Z]{2}\\d{3}$");
        regex format2("^\\d{2}[A-Z]{1}\\d{3}$");
        regex format3("^\\d{2}[A-Z]{1}\\d{4}$");
        regex format4("^\\d{2}[A-Z]{2}\\d{4}$");
       
        return regex_match(plate, format1) || regex_match(plate, format2) || regex_match(plate, format3) || regex_match(plate, format4);
    }

    bool isValidColor(const string&  c) const {
        string colorUpper = c;
        for (auto& ch : colorUpper) ch = toupper(ch);
        return (colorUpper == "WHITE" || colorUpper == "RED" || colorUpper == "BLACK" || colorUpper == "BLUE");
    }
    bool isValidYear(int y) const {
        return (y >= 1886 && y <= 2025);
    }

    bool isValidChassisOrEngine(const string& num) const {
        return (num.length() == 17);
    }

    bool isValidPrice(double p) const {
        return (p > 0);
    }

    bool isValidPurpose(const string& p) const {
        return (p == "Private" || p == "Commercial");
    }

    void validate() {
        valid = true;

        if (make.empty() || model.empty()) {
            valid = false;
            cout << "Make and model can not be empty." << endl;
        }
        if (!isValidYear(year)) {
            valid = false;
            cout << "Invalid year. Must be a 4-digit year." << endl;
        }
        if (!isValidLicensePlate(licensePlate)) {
            valid = false;
            cout << "Invalid license plate format." << endl;
        }
        if (!isValidColor(color)) {
            valid = false;
            cout << "Invalid color. Must be Blue, White, Red or Black" << endl;
        }
        if (!isValidChassisOrEngine(chassisNumber)) {
            valid = false;
            cout << "Invalid chassis number. Must be 17 characters long." << endl;
        }
        if (!isValidChassisOrEngine(engineNumber)) {
            valid = false;
            cout << "Invalid engine number. Must be 17 characters long." << endl;
        }
        if (!isValidPurpose(purposeOfUse)) {
            valid = false;
            cout << "Invalid purpose of use. Must be Private or Commercial." << endl;
        }
        if (!isValidPrice(price)) {
            valid = false;
            cout << "Invalid price. Must be greater than zero." << endl;
        }
    }
public:
    Car(const string& make, const string& model, const string& licensePlate, const string& color, int year, const string& chassisNumber, const string& engineNumber, const string& purposeOfUse, double price): make(make), model(model), licensePlate(licensePlate), color(color), year(year), chassisNumber(chassisNumber), engineNumber(engineNumber), purposeOfUse(purposeOfUse), price(price), valid(false)
    {
        validate();
    }

    void setLicensePlate(const string& newPlate) {
        if (isValidLicensePlate(newPlate)) {
            cout << "License Plate changed from " << licensePlate << " to " << newPlate << endl;
            licensePlate = newPlate;
            validate();
        }
        else {
            cout << "Invalid license plate format. Change rejected." << endl;                                                                                                                                                                                                                                                      
        }
    }

    void setColor(const string& newColor) {
        if (isValidColor(newColor)) {
            cout << "Color changed from " << color << " to " << newColor << endl;
            color = newColor;
            validate();
        }
        else {
            cout << "Invalid color. Change rejected." << endl;
        }
    }

    void setPurposeOfUse(const string& newPurpose) {
        if (isValidPurpose(newPurpose)) {
            cout << "Purpose of Use changed from " << purposeOfUse << " to " << newPurpose << endl;
            purposeOfUse = newPurpose;
            validate();
        }
        else {
            cout << "Invalid purpose of use. Change rejected." << endl;
        }
    }

    void setPrice(double newPrice) {
        if (isValidPrice(newPrice)) {
            cout << "Price changed from " << fixed << setprecision(2) << price
                << " to " << newPrice << endl;
            price = newPrice;
            validate();
        }
        else {
            cout << "Invalid price. Change rejected." << endl;
        }
    }
    const string& getLicensePlate() const {
        return licensePlate;
    }
    const string& getMake() const {
        return make;
    }
    const string& getModel() const {
        return model;
    }
    const string& getColor() const {
        return color;
    }
    int getYear() const {
        return year;
    }
    const string& getChassisNumber() const {
        return chassisNumber;
    }
    const string& getEngineNumber() const {
        return engineNumber;
    }
    const string& getPurposeOfUse() const {
        return purposeOfUse;
    }
    double getPrice() const {
        return price;
    }
    bool isValid() const {
        return valid;
    }
    bool operator==(const Car& other) const {
        return (chassisNumber == other.chassisNumber) && (engineNumber == other.engineNumber);
    }
    bool operator!=(const Car& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        if (!car.valid) {
            os << "Invalid Car data." << endl;
            return os;
        }
        os  << "Make           : " << car.make << endl
            << "Model          : " << car.model << endl
            << "License Plate  : " << car.licensePlate << endl
            << "Color          : " << car.color << endl
            << "Year           : " << car.year << endl
            << "Chassis Number : " << car.chassisNumber << endl
            << "Engine Number  : " << car.engineNumber << endl
            << "Purpose of Use : " << car.purposeOfUse << endl
            << fixed << setprecision(2)
            << "Price          : $" << car.price << endl << endl;
        return os;
    }
};

int main() {
    vector<Car> cars;

    Car car1("Ford", "Custom", "34RB4214", "Black", 2017,
        "1FAHP3FN9AW123456", "WF0EXXGCDES765432", "Private", 700000);
    Car car2("Mercedes", "G63 AMG", "34E1930", "BLUE", 2025,
        "WDC2539051F765432", "W1N0G8EB6MF123456", "Commercial", 14000000);
    Car car3("Dacia", "Duster", "34FYF249", "White", 2023,
        "UU1HSDCW647895123", "UU1HSDAJ5H6789012", "Private", 900000);

    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);

    cout << "Displaying cars:" << endl;
    for (const auto& car : cars) {
        cout << car;
    }

    cout << "\n-- Changing some mutable fields of first car --" << endl;
    cars[0].setLicensePlate("34AT738");
    cars[0].setColor("Red");
    cars[0].setPurposeOfUse("Commercial");
    cars[0].setPrice(190000);

    cout << "\nUpdated first car info:" << endl << cars[0];

    cout << "\nComparing first two cars by engine and chassis number:" << endl;
    if (cars[0] == cars[1]) {
        cout << "Cars with license plates " << cars[0].getLicensePlate() << " and " << cars[1].getLicensePlate() << " are the same." << endl;
    }
    else {
        cout << "Cars with license plates " << cars[0].getLicensePlate() << " and " << cars[1].getLicensePlate() << " are different." << endl;
    }

    return 0;
}

