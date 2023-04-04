//  main.cpp
//  Semester project
//
//  Created by Mike Nguyen on 4/5/21.
//  mnguyen18@dmacc.edu

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class budget {
public:
    
    budget ();
    
    void setSpending (int monthlySpending) {
        spendingAmountMonthly = monthlySpending;
    }
    
    int getSpendingMonthly (int monthlySpending) {
        return spendingAmountMonthly;
    }
    
    void printPersonal () {
        cout << "The recommended budget is" << endl;
        cout << fixed << setprecision(2) << '$' << spendingAmountMonthly * 0.5 << " goes to bills." << endl;
        cout << fixed << setprecision(2) << '$' << spendingAmountMonthly * 0.3 << " goes to fun money." << endl;
        cout << fixed << setprecision(2) << '$' << spendingAmountMonthly * 0.2 << " goes to savings." << endl << endl;
    }
    
    void printBusinessRecommend () {
        cout << "The recommended budget is" << endl;
        cout << fixed << setprecision(2) << '$' << spendingAmountMonthly * 0.5 << " goes to bills, supplies, and payroll." << endl;
        cout << fixed << setprecision(2) << '$' << spendingAmountMonthly * 0.3 << " adverstisement." << endl;
        cout << fixed << setprecision(2) << '$' << spendingAmountMonthly * 0.2 << " goes to investments for the business." << endl << endl;
    }
    
private:
    int budgetAmount;
    int spendingAmountMonthly;
    
};

budget::budget() {
    spendingAmountMonthly = -1;
}


int main(int argc, const char * argv[]) {
    string userAnswer;
    int categoryAmount = 0;
    vector <string> categories(categoryAmount);
    vector <double> userBudget(categoryAmount);
    vector <double> userSpendingOnBudget(categoryAmount);
    double totalSpent = 0;
    budget budget;
    int monthSalary;
    
    unsigned int i;
    
    // Prompts the user to enter if budget is for business or person
    cout << "Is this a business budget or personal budget? (p for personal, b for business): ";
    cin >> userAnswer;
    
    // Checks if what user inputs is correct
    while (userAnswer != "p" && userAnswer != "b") {
        cout << "Sorry didn't get that, try again: ";
        cin >> userAnswer;
    }
    
    // Personal account budget
    if (userAnswer == "p") {
        
        // Prompts user for how much they make monthly
        cout << "How much do you usually make a month?: ";
        cin >> monthSalary;
        if (monthSalary < 0) {
            cout << "Invalid amount, try again: ";
            cin >> monthSalary;
        }
        
        // Sets and prints recommended budget
        budget.setSpending(monthSalary);
        budget.printPersonal();
        
        // Prompts the user if they would like to create their own budget
        cout << "If you would like to start your own budget, type the the amount of categories or \"0\" to quit the program: " << endl;
        cin >> categoryAmount;
        
        if (categoryAmount == 0) {
            return -1;
        }
        
        // resizes the vectors to the proper size
        categories.resize(categoryAmount);
        userBudget.resize(categoryAmount);
        userSpendingOnBudget.resize(categoryAmount);
        
        // Prompts user to enter category, budget, and amount spent in the category for how many categories they added
        for (i = 0; i < categories.size(); i++) {
            cout << "Enter category " << i + 1 << ": ";
            cin >> categories.at(i);
            
            
            cout << "What is your budget for " << categories.at(i) << ": ";
            cin >> userBudget.at(i);
            // Checks if budget is valid
            while (userBudget.at(i) < 0) {
                cout << "Invalid entry, try again for budget: ";
                cin >> userBudget.at(i);
            }

            
            
            cout << "How much do you spend on " << categories.at(i) << ": ";
            cin >> userSpendingOnBudget.at(i);
            // Checks if spending is valid
            while (userSpendingOnBudget.at(i) < 0) {
                cout << "Invalid entry, try again for spending: ";
                cin >> userSpendingOnBudget.at(i);
            }
            cout << endl;
        }
        
        
        // Accumulates total for user spending habits
        for (i = 0; i < categories.size(); ++i) {
            totalSpent = totalSpent + userSpendingOnBudget.at(i);
        }
        
        
        // This loop checks if they've done a good job saving their money or not
        for (i = 0; i < categories.size(); ++i) {
            if (userSpendingOnBudget.at(i) < userBudget.at(i)) {
                cout << "For the category " << categories.at(i) << endl;
                cout << "Your spending is less than your budget, keep up the good work!" << endl;
                cout << "You saved: $" << userBudget.at(i) - userSpendingOnBudget.at(i) << endl << endl;
                
            }
            
            else {
                cout << "For the category " << categories.at(i) << endl;
                cout << "Your spending is more than your budget, you should cut back on the spending" << endl;
                cout << "You lost: $" << userSpendingOnBudget.at(i) - userBudget.at(i) << endl << endl;
            }
        }
        
        // Checks if user spending habits exceeded what they make in a month
        if (totalSpent > monthSalary) {
            cout << "You've exceeded the amount you make, cut back your spending!" << endl;
            cout << "You could have saved $" << totalSpent - monthSalary << endl;
        }
        else {
            cout << "You spent less than the amount you make, good job!" << endl;
            cout << "You saved $" << monthSalary - totalSpent << endl;
        }
    }
    
    // FINISH CODE FOR BUSINESS... TRY TO GET IT DONE AS SOON AS POSSIBLE...
    else {
        cout << "How much money are you putting into your business?: ";
        cin >> monthSalary;
        if (monthSalary < 0) {
            cout << "Invalid amount, try again: ";
            cin >> monthSalary;
        }
        
        budget.setSpending(monthSalary);
        budget.printBusinessRecommend();
        
        cout << "If you would like to start your own budget, type the the amount of categories or \"0\" to quit the program: " << endl;
        cin >> categoryAmount;
        
        if (categoryAmount == 0) {
            return -1;
        }
        
        // resizes the vectors to the proper size
        categories.resize(categoryAmount);
        userBudget.resize(categoryAmount);
        userSpendingOnBudget.resize(categoryAmount);
        
        // Prompts user to enter category, budget, and amount spent in the category for how many categories they added
        for (i = 0; i < categories.size(); i++) {
            cout << "Enter category " << i + 1 << ": ";
            cin >> categories.at(i);
            
            
            cout << "What is your budget for " << categories.at(i) << ": ";
            cin >> userBudget.at(i);
            // Checks if budget is valid
            while (userBudget.at(i) < 0) {
                cout << "Invalid entry, try again for budget: ";
                cin >> userBudget.at(i);
            }

            
            
            cout << "How much do you spend on " << categories.at(i) << ": ";
            cin >> userSpendingOnBudget.at(i);
            // Checks if spending is valid
            while (userSpendingOnBudget.at(i) < 0) {
                cout << "Invalid entry, try again for spending: ";
                cin >> userSpendingOnBudget.at(i);
            }
            cout << endl;
        }
        
        
        // Accumulates total for user spending habits
        for (i = 0; i < categories.size(); ++i) {
            totalSpent = totalSpent + userSpendingOnBudget.at(i);
        }
        
        
        // This loop checks if they've done a good job saving their money or not
        for (i = 0; i < categories.size(); ++i) {
            if (userSpendingOnBudget.at(i) < userBudget.at(i)) {
                cout << "For the category " << categories.at(i) << endl;
                cout << "You have extra money left over, keep up the good work!" << endl;
                cout << "You saved: $" << userBudget.at(i) - userSpendingOnBudget.at(i) << endl << endl;
                
            }
            
            else {
                cout << "For the category " << categories.at(i) << endl;
                cout << "Your spending is more than your budget, you should cut back on the spending" << endl;
                cout << "You lost: $" << userSpendingOnBudget.at(i) - userBudget.at(i) << endl << endl;
            }
        }
        
        // Checks if user spending habits exceeded what they make in a month
        if (totalSpent > monthSalary) {
            cout << "You've exceeded the amount you bring into the business, cut back your spending!" << endl;
            cout << "You could have saved $" << totalSpent - monthSalary << endl;
        }
        else {
            cout << "You are under your budget, keep up the good work!" << endl;
            cout << "You saved $" << monthSalary - totalSpent << endl;
        }
    
    }
    return 0;
}

/* Test results
 
 Is this a business budget or personal budget? (p for personal, b for business): p
 How much do you usually make a month?: 1200
 The recommended budget is
 $600.00 goes to bills.
 $360.00 goes to fun money.
 $240.00 goes to savings.

 If you would like to start your own budget, type the the amount of categories or "0" to quit the program:
 2
 Enter category 1: Food
 What is your budget for Food: 100
 How much do you spend on Food: 80

 Enter category 2: Clothes
 What is your budget for Clothes: 50
 How much do you spend on Clothes: 80

 For the category Food
 Your spending is less than your budget, keep up the good work!
 You saved: $20.00

 For the category Clothes
 Your spending is more than your budget, you should cut back on the spending
 You lost: $30.00

 You spent less than the amount you make, good job!
 You saved $1040.00
 Program ended with exit code: 0
 
 */

/* Testing code for business
 
 Is this a business budget or personal budget? (p for personal, b for business): b
 How much money are you putting into your business?: -500
 Invalid amount, try again: 2800
 The recommended budget is
 $1400.00 goes to bills, supplies, and payroll.
 $840.00 adverstisement.
 $560.00 goes to investments for the business.

 If you would like to start your own budget, type the the amount of categories or "0" to quit the program:
 2
 Enter category 1: Payroll
 What is your budget for Payroll: -40
 Invalid entry, try again for budget: 800
 How much do you spend on Payroll: -50
 Invalid entry, try again for spending: 1200

 Enter category 2: Marketing
 What is your budget for Marketing: 1000
 How much do you spend on Marketing: 925

 For the category Payroll
 Your spending is more than your budget, you should cut back on the spending
 You lost: $400.00

 For the category Marketing
 You have extra money left over, keep up the good work!
 You saved: $75.00

 You are under your budget, keep up the good work!
 You saved $675.00
 Program ended with exit code: 0
 
 */
