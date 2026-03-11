#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void printHeading();
int displayAndSelect(string flavorArr[], double priceArr[], int size);
double printReceipt(string flavor, double price, double stateTax, double cityTax);

int main() {
    const int menu_size = 4;
    string flavorArr[menu_size] = {"Chocolate", "Strawberry", "Protein", "Peach"};
    double priceArr[menu_size] = {5.45, 6.99, 8.89, 7.45};

    printHeading();

    int selection_number = displayAndSelect(flavorArr, priceArr, menu_size);
    int index = selection_number - 1;

    double price = priceArr[index];
    double stateTax = price * 0.06;
    double cityTax = price * 0.015;

    double total = printReceipt(flavorArr[index], price, stateTax, cityTax);

    cout << fixed << setprecision(2);
    cout << "Returned Total: $" << total << endl;

    return 0;
}

// Prints shop heading.
void printHeading() {
    cout << "--- Rich's Smoothie Shop ---" << endl;
}

// Displays menu and returns selected menu number.
int displayAndSelect(string flavorArr[], double priceArr[], int size) {
    cout << fixed << setprecision(2);
    cout << "Smoothie Menu" << endl;

    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". "
             << left << setw(12) << flavorArr[i]
             << "$" << right << setw(6) << priceArr[i] << endl;
    }

    int selection = 0;
    cout << "Please Enter Selection Number:" << endl;
    cin >> selection;

    return selection;
}

// Prints receipt and returns total amount due.
double printReceipt(string flavor, double price, double stateTax, double cityTax) {
    double total = price + stateTax + cityTax;

    printHeading();
    cout << fixed << setprecision(2);
    cout << "Receipt" << endl;
    cout << "Selection: " << flavor << endl;
    cout << "Price:     $" << price << endl;
    cout << "State Tax: $" << stateTax << endl;
    cout << "City Tax:  $" << cityTax << endl;
    cout << "Total:     $" << total << endl;
    cout << "Thank you for visiting Rich's Smoothie Shop!" << endl;

    return total;
}
