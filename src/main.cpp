#include "banking_console.cpp"

int main()
{
    BankingConsole bankingConsole;

    while (!bankingConsole.exitProgram_) {
        bankingConsole.ProcessBankingOptions();
    }

    return 0;
}