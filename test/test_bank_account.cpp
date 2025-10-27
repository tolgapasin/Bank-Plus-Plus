#include <gtest/gtest.h>
#include "../src/bank_account.h"

class BankAccountTests : public ::testing::Test {
protected:
    BankAccount* bankAccount_;

    void SetUp() override {
        bankAccount_ = new BankAccount(100.00);
    }
    
    void TearDown() override {
        delete bankAccount_;
    }
};

TEST_F(BankAccountTests, GetBalance) {
    double balance = bankAccount_->GetBalance();
    EXPECT_EQ(balance, 100.00);
}

TEST_F(BankAccountTests, SubtractFromBalance) {
    bankAccount_->SubtractFromBalance(25.51);
    double balance = bankAccount_->GetBalance();
    EXPECT_EQ(balance, 74.49);
}

TEST_F(BankAccountTests, AddToBalance) {
    bankAccount_->AddToBalance(25.53);
    double balance = bankAccount_->GetBalance();
    EXPECT_EQ(balance, 125.53);
}

// During development entering 32.23 showed as 32.22 because of a bug when casting types
TEST_F(BankAccountTests, BalancePrecision) {
    bankAccount_ = new BankAccount(32.23);
    double balance = bankAccount_->GetBalance();
    EXPECT_EQ(balance, 32.23);
}