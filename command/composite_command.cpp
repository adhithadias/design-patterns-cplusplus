#include <initializer_list>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

struct BankAccount {
    int balance{0};
    int overdraft_limit{-500};

    void deposit(int amount) {
        balance += amount;
        cout << "deposited " << amount
            << ", balance is not " << balance << endl;
    }

    bool withdraw(int amount) {
        if (balance - amount >= overdraft_limit) {
            balance -= amount;
            cout << "withdraw " << amount
                << ", balance is now " << balance << endl;
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const BankAccount &account) {
        os << "balance: " << account.balance;
        return os;
    }
};

struct Command {
    bool succeeded;
    virtual void call() = 0;
    virtual void undo() = 0;
};

struct BankAccountCommand : Command {
    BankAccount& account;
    enum Action {deposit, withdraw} action;
    int amount;

    BankAccountCommand(BankAccount &account, Action action, int amount) 
        : account(account), action(action), amount(amount) {
            succeeded = false;
        }

    void call() override {
        switch (action) {
            case deposit:
                account.deposit(amount);
                succeeded = true;
                break;

            case withdraw:
                succeeded = account.withdraw(amount);
                break;
        }
    }

    void undo() override {
        if (!succeeded) return;

        switch (action) {
            case deposit:
                account.withdraw(amount);
                break;

            case withdraw:
                account.deposit(amount);
                break;
        }
    }
};

struct CompositBankAccountCommand : vector<BankAccountCommand>, Command {
    CompositBankAccountCommand(const initializer_list<BankAccountCommand> &items)
        : vector(items) {}

    void call() override {
        for (auto& cmd : *this) 
            cmd.call();
    }
    
    void undo() override {
        for (auto it = rbegin(); it != rend(); ++it) {
            it->undo();
        }
    }

};

struct DependentCompositeCommand : CompositBankAccountCommand {
    DependentCompositeCommand(const initializer_list<BankAccountCommand> &items)
        : CompositBankAccountCommand(items) {}

    void call() override {
        bool ok = true;
        for (auto& cmd : *this) {
            if (ok) {
                cmd.call();
                ok = cmd.succeeded;
            }
            else {
                cmd.succeeded = false;
            }
        }
    }
};

struct MoneyTransferCommand : DependentCompositeCommand {
    MoneyTransferCommand(BankAccount &from, BankAccount &to, int amount) 
        : DependentCompositeCommand( 
            {
                BankAccountCommand(from, BankAccountCommand::withdraw, amount),
                BankAccountCommand(to, BankAccountCommand::deposit, amount)
            }
        ) {}
};

int main() {
    BankAccount ba1, ba2;
    ba1.deposit(100);

    MoneyTransferCommand cmd{ba1, ba2, 5000}; // with DependentBankAccountComand it works

    cmd.call();

    cout << ba1 << endl << ba2 << endl;

    cmd.undo();

    cout << ba1 << endl << ba2 << endl;


    return 0;
}