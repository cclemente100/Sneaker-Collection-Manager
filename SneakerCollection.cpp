// SneakerCollection.cpp
// Assignment: Sneaker Collection Manager
// Author: Christina Clemente 
// Description:In this project, you will create a C++ console application that manages information about a small sneaker collection.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Brand enumeration
enum SneakerBrand
{
    Nike,
    Adidas,
    Jordan,
    NewBalance,
    Puma
};

// Condition enumeration
enum SneakerCondition
{
    New,
    Excellent,
    Good,
    Fair,
    Poor
};

// Sneaker structure
struct Sneaker
{
    string model;
    SneakerBrand brand;
    double size;
    SneakerCondition condition;
    double purchasePrice;
    double estimatedValue;
};

// Function to display the available brands
void displayBrands()
{
    cout << "Select a brand:\n";
    cout << "1. Nike\n";
    cout << "2. Adidas\n";
    cout << "3. Jordan\n";
    cout << "4. New Balance\n";
    cout << "5. Puma\n";
}

// Function to convert a brand enum to a string
string getBrandName(SneakerBrand brand)
{
    switch (brand)
    {
        case Nike:
            return "Nike";
        case Adidas:
            return "Adidas";
        case Jordan:
            return "Jordan";
        case NewBalance:
            return "New Balance";
        case Puma:
            return "Puma";
        default:
            return "Unknown";
    }
}

// Function to display the available conditions
void displayConditions()
{
    cout << "Select a condition:\n";
    cout << "1. New\n";
    cout << "2. Excellent\n";
    cout << "3. Good\n";
    cout << "4. Fair\n";
    cout << "5. Poor\n";
}

// Function to convert a condition enum to a string
string getConditionName(SneakerCondition condition)
{
    switch (condition)
    {
        case New:
            return "New";
        case Excellent:
            return "Excellent";
        case Good:
            return "Good";
        case Fair:
            return "Fair";
        case Poor:
            return "Poor";
        default:
            return "Unknown";
    }
}

// Function to enter information for one sneaker
void enterSneakerInfo(Sneaker& sneaker, int number)
{
    cout << "\n================================\n";
    cout << "Enter information for Sneaker #" << number << "\n";
    cout << "================================\n";

    cout << "Model Name: ";
    getline(cin, sneaker.model);

    int brandChoice;
    displayBrands();
    cout << "Enter your choice: ";
    cin >> brandChoice;

    // Convert user's numbered choice to the enum value
    sneaker.brand = static_cast<SneakerBrand>(brandChoice - 1);

    cout << "Size: ";
    cin >> sneaker.size;

    int conditionChoice;
    displayConditions();
    cout << "Enter your choice: ";
    cin >> conditionChoice;

    // Convert user's numbered choice to the enum value
    sneaker.condition = static_cast<SneakerCondition>(conditionChoice - 1);

    cout << "Purchase Price: $";
    cin >> sneaker.purchasePrice;

    cout << "Estimated Current Value: $";
    cin >> sneaker.estimatedValue;

    // Clear the newline before the next getline()
    cin.ignore(1000, '\n');
}

// Function to display one sneaker
void displaySneaker(const Sneaker& sneaker, int number)
{
    cout << "\nSneaker #" << number << "\n";
    cout << "Model: " << sneaker.model << "\n";
    cout << "Brand: " << getBrandName(sneaker.brand) << "\n";
    cout << "Size: " << sneaker.size << "\n";
    cout << "Condition: " << getConditionName(sneaker.condition) << "\n";
    cout << "Purchase Price: $" << sneaker.purchasePrice << "\n";
    cout << "Estimated Value: $" << sneaker.estimatedValue << "\n";
}

int main()
{
    // Create three Sneaker variables
    Sneaker sneaker1;
    Sneaker sneaker2;
    Sneaker sneaker3;

    // Set money values to display with two decimal places
    cout << fixed << setprecision(2);

    // Enter information for all three sneakers
    enterSneakerInfo(sneaker1, 1);
    enterSneakerInfo(sneaker2, 2);
    enterSneakerInfo(sneaker3, 3);

    // Calculate totals
    double totalPurchasePrice =
        sneaker1.purchasePrice +
        sneaker2.purchasePrice +
        sneaker3.purchasePrice;

    double totalEstimatedValue =
        sneaker1.estimatedValue +
        sneaker2.estimatedValue +
        sneaker3.estimatedValue;

    double gainLoss = totalEstimatedValue - totalPurchasePrice;

    // Display collection
    cout << "\n\n================================\n";
    cout << "       SNEAKER COLLECTION\n";
    cout << "================================\n";

    displaySneaker(sneaker1, 1);
    displaySneaker(sneaker2, 2);
    displaySneaker(sneaker3, 3);

    // Display summary
    cout << "\n================================\n";
    cout << "       COLLECTION SUMMARY\n";
    cout << "================================\n";

    cout << "Total Paid:       $" << totalPurchasePrice << "\n";
    cout << "Current Value:    $" << totalEstimatedValue << "\n";
    cout << "Gain/Loss:        $" << gainLoss << "\n";

    // Determine whether the collection gained, lost, or stayed the same
    if (gainLoss > 0)
    {
        cout << "\nYour collection has increased in value!\n";
    }
    else if (gainLoss < 0)
    {
        cout << "\nYour collection has decreased in value.\n";
    }
    else
    {
        cout << "\nYour collection has stayed the same in value.\n";
    }

    return 0;
}
