public class SalaryCalculator {
    final int MONTHLY_EMPLOYEE_SALES_QUOTA = 20;
    final int BONUS_RATE = 13;
    final int NORMAL_RATE = 10;
    final double BASE_SALARY = 1000.00;
    final double SALARY_CAP = 2000.00;
    
    public double multiplierPerDaysSkipped(int daysSkipped) {
        return daysSkipped > 5 ? 0.85 : 1;
    }

    public int multiplierPerProductsSold(int productsSold) {
        return productsSold <= this.MONTHLY_EMPLOYEE_SALES_QUOTA ? this.NORMAL_RATE : this.BONUS_RATE;
    }

    public double bonusForProductSold(int productsSold) {
        return this.multiplierPerProductsSold(productsSold) * productsSold;
    }

    public double finalSalary(int daysSkipped, int productsSold) {
        double salary = this.BASE_SALARY * this.multiplierPerDaysSkipped(daysSkipped) + this.bonusForProductSold(productsSold);
        return salary <= SALARY_CAP ? salary : SALARY_CAP;
    } 
}
