#include "bank_account.h"
#include "helpers/console_helper.cpp"

class BankingConsole {
    private:
        ConsoleHelper* consoleHelper_;
        BankAccount* bankAccount_;

        void DepositMoney() {
            double input;
            consoleHelper_->Print("How much money would you like to deposit?");

            input = consoleHelper_->GetInput<double>();
            bankAccount_->AddToBalance(input);

            consoleHelper_->ClearConsole();
            PrintCurrentBalance();
        }

        void WithdrawMoney() {
            double input;
            consoleHelper_->Print("How much money would you like to withdraw?");

            input = consoleHelper_->GetInput<double>();
            bankAccount_->SubtractFromBalance(input);

            consoleHelper_->ClearConsole();
            PrintCurrentBalance();

            // TODO: show message like $5 has been withdrawn
        }

        void CloseAccount() {
            long long remainingBalance = bankAccount_->GetBalance();
            bankAccount_->SubtractFromBalance(remainingBalance);

            consoleHelper_->PrintPreciseDouble(
                "Your account has been closed and the following amount has been withdrawn: $",
                remainingBalance,
                2   
            );
            consoleHelper_->Print("Thank you for choosing Bank++");
            exitProgram_ = true;
        }

        void PrintCurrentBalance() {
            consoleHelper_->PrintPreciseDouble("Current balance: $", bankAccount_->GetBalance(), 2);
        }

    public:
        bool exitProgram_ = false;

        BankingConsole() {
            consoleHelper_ = new ConsoleHelper();
            
            double inputDollars;
            
            std::vector<std::string> startupMessage = {
                "Welcome to Bank++",
                "How much money would you like to open your account with?"
            };

            consoleHelper_->Print(startupMessage);
            inputDollars = consoleHelper_->GetInput<double>();
            bankAccount_ = new BankAccount(inputDollars);

            consoleHelper_->ClearConsole();
            PrintCurrentBalance();
        }

        ~BankingConsole() {
            delete consoleHelper_;
            delete bankAccount_;
        }

        void ProcessBankingOptions() {
            int input;

            std::vector<std::string> bankingOptions = {
                "Please choose a banking option to perform:",
                "1. Deposit money to your account",
                "2. Withdraw money from your account",
                "3. Display the current balance of your account",
                "4. Close account and withdraw all money",
                "5. Exit Bank++"
            };

            consoleHelper_->Print(bankingOptions);
            input = consoleHelper_->GetInput<int>();
            consoleHelper_->ClearConsole();

            // TODO: add delay between options because console clears to quickly and it looks jumpy
            switch (input) {
                case 1:
                    DepositMoney();
                    break;
                case 2:
                    WithdrawMoney();
                    break;
                case 3:
                    PrintCurrentBalance();
                    break;
                case 4:
                    CloseAccount();
                case 5:
                    exitProgram_ = true;
                    break;
            }
        }
};