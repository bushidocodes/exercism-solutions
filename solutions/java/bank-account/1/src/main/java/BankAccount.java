class BankAccount {
    private boolean isOpen;
    private int balance;
    
    public BankAccount(){
        this.isOpen = false;
        this.balance = 0;
    }

    public void open() {
        this.isOpen = true;
    }

    public void close() {
        this.isOpen = false;
    }

    public synchronized void deposit(int amount) throws BankAccountActionInvalidException {
        if (!this.isOpen) 
            throw new BankAccountActionInvalidException("Account closed");
        if (amount < 0) 
            throw new BankAccountActionInvalidException("Cannot deposit or withdraw negative amount");

        this.balance += amount;
    }

    public synchronized void withdraw(int amount) throws BankAccountActionInvalidException {
        if (!this.isOpen) 
            throw new BankAccountActionInvalidException("Account closed");
        if (this.balance == 0) 
            throw new BankAccountActionInvalidException("Cannot withdraw money from an empty account");
        if (amount < 0) 
            throw new BankAccountActionInvalidException("Cannot deposit or withdraw negative amount");
        if (amount > this.balance) 
            throw new BankAccountActionInvalidException("Cannot withdraw more money than is currently in the account");

        this.balance -= amount;
    }

    public int getBalance() throws BankAccountActionInvalidException {
        if (!this.isOpen) throw new BankAccountActionInvalidException("Account closed");

        return this.balance;
    }
}