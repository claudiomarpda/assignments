#include <iostream>
#include <limits>

using namespace std;

void ex01() {
    int price, age;
    float discount;

    cout << "Enter the price: ";
    cin >> price;
    cout << "Enter the age: ";
    cin >> age;

    if (age <= 18) {
        discount = price * 0.1;
    } else {
        discount = price * 0.2;
    }

    printf("Discount: %.2f\n", discount);
    printf("Final price: %.2f\n", price - discount);

}

void ex02() {
    float salary, inss, discount;
    cout << "Enter salary: ";
    cin >> salary;

    if (salary < 420) {
        inss = 8;
    } else if (salary >= 420 && salary < 1350) {
        inss = 9;
    } else {
        inss = 10;
    }

    discount = salary / 100 * inss;
    //salary -= salary / 100 * inss;
    salary -= discount;
    cout << "Discount with " << inss << "% of INSS: " << discount << endl;
    cout << "Salary with " << inss << "% of INSS: " << salary << endl;
}

void ex03() {
    int greater = INT32_MIN;
    int input;
    while (input != 0) {
        cout << "Enter a value (0 to stop): ";
        cin >> input;
        if (input > greater) {
            greater = input;
        }
    }
    cout << "Greatest value: " << greater << endl;
}

void ex04() {
    int previous = 1, current = 1, next, n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << previous << " " << current << " ";
    for (int i = 0; i < n; i++) {
        next = previous + current;
        cout << next << " ";
        previous = current;
        current = next;
    }
    cout << endl;
}