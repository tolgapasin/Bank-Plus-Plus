#pragma once

class BankAccount
{
    private:
        long long balanceInCents; 

    public:
        BankAccount(double balanceInCents);
        double GetBalance() const;
        void SubtractFromBalance(double deltaDollars);
        void AddToBalance(double deltaDollars);
};