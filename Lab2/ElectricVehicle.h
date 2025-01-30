#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class ElectricVehcile {
private:
	string make;
	string model;
	string color;
	double batteryCapacityInKilowatHours;
	double currentBatteryChargeInKilowatHours;
	double kilometersPerKilowatHour;
	double kilometersDriven;

public:

	/*
	* umgpt
	write the get functions for this class class ElectricVehcile {
	private:
	string make;
	string model;
	string color;
	double batteryCapacityInKilowatHours;
	double currentBatteryChargeInKilowatHours;
	double kilometersPerKilowatHour;
	double kilometersDriven;

	public:
	*/

    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    string getColor() const {
        return color;
    }

    double getBatteryCapacityInKilowatHours() const {
        return batteryCapacityInKilowatHours;
    }

    double getCurrentBatteryChargeInKilowatHours() const {
        return currentBatteryChargeInKilowatHours;
    }

    double getKilometersPerKilowatHour() const {
        return kilometersPerKilowatHour;
    }

    double getKilometersDriven() const {
        return kilometersDriven;
    }

    void charge(double kilowatHoursToCharge) {
        if (currentBatteryChargeInKilowatHours + kilowatHoursToCharge > batteryCapacityInKilowatHours) {
            throw invalid_argument("unable to charge over the capacity");
        }
        currentBatteryChargeInKilowatHours += kilowatHoursToCharge;
    }

    void drive(double kilometersToDrive) {
        if (kilometersToDrive / kilometersPerKilowatHour > currentBatteryChargeInKilowatHours) {
            throw invalid_argument("not enough charge to drive that far");
        }
        currentBatteryChargeInKilowatHours -= kilometersToDrive / kilometersPerKilowatHour;
        kilometersDriven += kilometersToDrive;
    }


};