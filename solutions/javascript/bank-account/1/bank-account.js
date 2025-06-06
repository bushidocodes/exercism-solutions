export class BankAccount {
  #balance = 0;
  #status = "closed";

  open() {
    if (this.#status == "open") throw new ValueError("Account is already open");

    this.#status = "open";
  }

  close() {
    if (this.#status == "closed")
      throw new ValueError("Account is already closed");

    this.#balance = 0;
    this.#status = "closed";
  }

  deposit(amount) {
    if (amount < 0) throw new ValueError("cannot deposit negative amount");
    if (this.#status == "closed") throw new ValueError("Account is closed");
    
    this.#balance += amount;
  }

  withdraw(amount) {
    if (this.#status == "closed") throw new ValueError("Account is closed");
    if (amount < 0) throw new ValueError("cannot withdraw negative amount");
    if (amount > this.#balance)
      throw new ValueError("cannot withdraw more than deposited");

    this.#balance -= amount;
  }

  get balance() {
    if (this.#status == "closed") throw new ValueError("Account is closed");

    return this.#balance;
  }
}

export class ValueError extends Error {
  constructor() {
    super("Bank account error");
  }
}
