#include<iostream>
#include<string>
using namespace std;

// 1. Define global integer constants
const int annualAverageConsumptionPerPerson = 200;
const int annualAverageConsumptionPerSquareMeter = 9;
const int annualAverageConsumptionPerElectricalDevice = 200;

// 2. Define a structure called Household
struct Household
 {
    string city;
    int numPersons;
    int squareMeters;
    int numE_Devices;
}; 

// 3. Function to calculate annual power consumption
float calculateAnnualPowerConsumption(struct Household& house) 
{
    float AnnualPowerConsumption = (house.numPersons * annualAverageConsumptionPerPerson)
                          + (house.squareMeters * annualAverageConsumptionPerSquareMeter)
                     + (house.numE_Devices * annualAverageConsumptionPerElectricalDevice);

    return AnnualPowerConsumption;
}


// 4. Function to calculate annual power costs
float calculateAnnualPowerCosts(struct Household& house, float pricePerKWh) 
{
    float annualPowerCosts = calculateAnnualPowerConsumption(house) * pricePerKWh;
    return annualPowerCosts;
}


// 5. Function to print household information and costs
void print_household(struct Household& house, float pricePerKWh) 
{
    
    cout << "AVERAGE POWER COSTS\n";
    cout << "==========================\n";
    cout << "household in:                " << house.city << "\n";
    cout << "square meters:               " << house.squareMeters << "\n";
    cout << "Persons:                     " << house.numPersons << "\n";
    cout << "(major) electrical devices:  " << house.numE_Devices << "\n";
    cout << "price for one kWh:           " << pricePerKWh << " EUR\n";
    //float annualPowerConsumption = calculateAnnualPowerConsumption(house);
    cout << "annual power consumption:    " << calculateAnnualPowerConsumption(house) << " kWh\n";
    //float annualPowerCosts = calculateAnnualPowerCosts(house, pricePerKWh);
    cout << "annual power costs:          " << calculateAnnualPowerCosts(house, pricePerKWh)<< " EUR\n";
    cout << "\n";
}

// 6. Main Function
int main() 
{
    cout << "CALCULATION OF AVERAGE POWER COSTS FOR A HOUSEHOLD\n"; 

    struct Household house;
    float pricePerKWh;

    cout << "in which city is the household located:";
    cin >> house.city;
    cout << "how many square metres does the household have:";
    cin >> house.squareMeters;
    cout << "how many (major) electrical devices does the household have:";
    cin >> house.numE_Devices;
    cout << "how many EUR does one kWh in Duisburg cost?:";
    cin >> pricePerKWh;

    for (int n=1; n<=5; n++) 
    {
        house.numPersons=n;
        print_household(house, pricePerKWh);
    }

    return 0;
}
