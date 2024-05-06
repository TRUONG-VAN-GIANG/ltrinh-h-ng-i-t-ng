#include <iostream>
#include <string>
#include <ctime>

class Vehicle {
private:
    std::string vehicleID;
    std::string brand;
    std::string model;
    int year;
    std::string color;

public:
    // Constructor to initialize the object with specific information
    Vehicle(std::string id, std::string brand, std::string model, int year, std::string color) {
        this->vehicleID = id;
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->color = color;
    }

    // Getter and setter methods for all attributes
    std::string getVehicleID() const { return vehicleID; }
    void setVehicleID(const std::string& id) { vehicleID = id; }

    std::string getBrand() const { return brand; }
    void setBrand(const std::string& brand) { this->brand = brand; }

    std::string getModel() const { return model; }
    void setModel(const std::string& model) { this->model = model; }

    int getYear() const { return year; }
    void setYear(int year) { this->year = year; }

    std::string getColor() const { return color; }
    void setColor(const std::string& color) { this->color = color; }

    // Method to display full information of the vehicle
    void displayInfo() const {
        std::cout << "Vehicle ID: " << vehicleID << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Color: " << color << std::endl;
    }

    // Method to check if the vehicle is vintage
    bool isVintage() const {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int currentYear = 1900 + localTime->tm_year;
        return (currentYear - year) >= 25;
    }
};

int main() {
    // Example usage:
    Vehicle continental("C123456", "Lincoln", "Continental", 2023, "Silver");
    continental.displayInfo();

    if (continental.isVintage()) {
        std::cout << "This vehicle is vintage." << std::endl;
    } else {
        std::cout << "This vehicle is not vintage." << std::endl;
    }

    return 0;
}

