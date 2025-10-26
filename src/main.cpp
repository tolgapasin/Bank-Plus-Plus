#include "banking_console.cpp"

int main()
{
    BankingConsole bankingConsole;

    while (!bankingConsole.exitProgram_) {
        bankingConsole.ProcessBankingOptions();
    }

    return 0;
}

// To compile make
// To run ./BankingConsoleApp 
// To run tests ctests

// TODO: write unit tests for rounding (Input 32.23 spits out 32.22, fixed but needs testing)
// TODO: fix function casing :(