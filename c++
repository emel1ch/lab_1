#include <iostream>
#include <string>
#include <iomanip>

class Bank {
private:
    std::string name;
    double interestRate;
    int numberOfDeposits;
    double singleDepositAmount;

public:
    Bank(std::string bankName, double rate) {
        name = bankName;
        interestRate = rate;
        numberOfDeposits = 0;
        singleDepositAmount = 0.0;
    }

    void setNumberOfDeposits(int count) {
        if ((count >= 0) && (count <= 10000)) {
            numberOfDeposits = count;
        }
        else {
            std::cout << "Ошибка: Число вкладов не может быть отрицательным." << std::endl;
        }
    }

    void setSingleDepositAmount(double amount) {
        if ((amount >= 0) && (amount <=10000)) {
            singleDepositAmount = amount;
        }
        else {
            std::cout << "Ошибка: Размер вклада не может быть отрицательным." << std::endl;
        }
    }

    double calculateTotalInterestPayout() const {
        double totalDepositSum = numberOfDeposits * singleDepositAmount;
        double payout = totalDepositSum * (interestRate / 100.0);
        return payout;
    }

    std::string getName() const {
        return name;
    }

    void displayInfo() const {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Банк: \"" << name << "\"" << std::endl;
        std::cout << "Ставка по вкладам: " << interestRate << "%" << std::endl;
        std::cout << "Количество вкладов: " << numberOfDeposits << std::endl;
        std::cout << "Размер одного вклада: " << singleDepositAmount << " у.е." << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }
};

int main() {
#ifdef _WIN32
    setlocale(LC_ALL, "Russian");
#endif

    Bank bankA("Надежный Банк", 5.0);
    bankA.setNumberOfDeposits(250);
    bankA.setSingleDepositAmount(100000);

    bankA.displayInfo();
    double payoutA = bankA.calculateTotalInterestPayout();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Общая выплата по процентам в \"" << bankA.getName() << "\": " << payoutA << " у.е." << std::endl << std::endl;
    
    return 0;
}
