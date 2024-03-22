/***********************************************************************
Matr.-Nr:                     3085596
Nachname/Surname:             Haque
Vorname/Given name:           Md Anamul
Uni-Email:                    md.haque.696@stud.uni-due.de
Studiengang/Course of studis: ISE(Software Engineering)
***********************************************************************/

#include<iostream>
#include<string>
using namespace std;

// 1. Define global integer constants
const int annualAverageConsumptionPerPerson = 200;
const int annualAverageConsumptionPerSquareMeter = 9;
const int annualAverageConsumptionPerElectricalDevice = 200;
const int annual_average_consumption_per_person_with_electric_water_heating = 550 ;

// 2. Define a structure called Household
struct Household
 {
    string city;
    int numPersons;
    int squareMeters;
    int numE_Devices;
    bool Hot_water;
}; 

// 3. Function to calculate annual power consumption
float calculateAnnualPowerConsumption(struct Household& house) 
{
  if(house.Hot_water)
  {
    return ((house.numPersons * annual_average_consumption_per_person_with_electric_water_heating)
          + (house.squareMeters * annualAverageConsumptionPerSquareMeter)
          + (house.numE_Devices * annualAverageConsumptionPerElectricalDevice));
  }
  else
  {
   return ((house.numPersons * annualAverageConsumptionPerPerson)
          + (house.squareMeters * annualAverageConsumptionPerSquareMeter)
          + (house.numE_Devices * annualAverageConsumptionPerElectricalDevice));
  } 
}


// 4. Function to calculate annual power costs
float calculateAnnualPowerCosts(struct Household& house, float pricePerKWh) 
{
    return calculateAnnualPowerConsumption(house) * pricePerKWh;

    
}


// 5. Function to print household information and costs
void print_household(struct Household& house, float pricePerKWh) 
{
    string heter="no";
    
    if(house.Hot_water)
    {
        heter ="yes";
    }

    cout << "AVERAGE POWER COSTS\n";
    cout << "==========================\n";
    cout << "household in:                  " << house.city << "\n";
    cout << "square meters:                 " << house.squareMeters << "\n";
    cout << "Persons:                       " << house.numPersons << "\n";
    cout << "(major) electrical devices:    " << house.numE_Devices << "\n";
    cout<<  "water heated using electricity:" << heter << "\n";
    cout << "price for one kWh:             " << pricePerKWh << " EUR\n";
    //float annualPowerConsumption = calculateAnnualPowerConsumption(house);
    cout << "annual power consumption:      " << calculateAnnualPowerConsumption(house) << " kWh\n";
    //float annualPowerCosts = calculateAnnualPowerCosts(house, pricePerKWh);
    cout << "annual power costs:            " << calculateAnnualPowerCosts(house, pricePerKWh)<< " EUR\n";
    cout << "\n";
} 

// 5.1 function call input city
void input_city(string &city)
 {
    cout << "in which city is the household located?"<<endl;
    cin>> city;
 }


// 6.1 function called input integer
 void input_integer(string city, int &integer)
 {
    cout<<city<<endl;
    cin>>integer;
 }


 // 7 extention
 void input_electric_water_heating(bool& Hot)
 {
    char ch;
    cout<<"is hot water heated using electricity? (y(es) or n(o))"<<endl;
    cin>>ch;
    if(ch == 'y')
    {
        Hot = true;
    }
    else
    {
        Hot = false;
    }
    
 }

// 6. Main Function
int main() 
{
    cout << "CALCULATION OF AVERAGE POWER COSTS FOR A HOUSEHOLD\n"; 

    struct Household house;
    float pricePerKWh;

    input_city(house.city);
    input_integer("how many square metres does the household have? ", house.squareMeters);
    input_integer("how many (major) electrical devices does the household have? ", house.numE_Devices);
    input_electric_water_heating(house.Hot_water);
    cout<< "is hot water heated using electricity? (y(es) or n(o)) y\n";

 
     
    for (int n=1; n<=5; n++) 
    {
        
        for(pricePerKWh=0.30; pricePerKWh<=0.45; pricePerKWh +=0.05 )
        {
            house.numPersons=n;
            print_household(house, pricePerKWh);
           
        }
    }

    

    return 0;
}