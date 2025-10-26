#include "bank_account.h"
#include "helpers/dollar_cent_conversion_helper.h"

BankAccount::BankAccount(double inputDollars) 
    : balanceInCents(
        DollarCentConversionHelper::DollarsToCents(inputDollars)
    ) 
{}

double BankAccount::GetBalance() const {
    return static_cast<double>(balanceInCents / 100.00);
}

void BankAccount::SubtractFromBalance(double deltaDollars) {
    long long deltaCents = DollarCentConversionHelper::DollarsToCents(deltaDollars);
    balanceInCents -= deltaCents;
}

void BankAccount::AddToBalance(double deltaDollars) {
    long long deltaCents = DollarCentConversionHelper::DollarsToCents(deltaDollars);
    balanceInCents += deltaCents;
}