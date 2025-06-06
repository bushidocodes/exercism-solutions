class ArmstrongNumbers {

	boolean isArmstrongNumber(int numberToCheck) {
		int numberOfDigits = Integer.valueOf(numberToCheck).toString().length();
		int candidate = 0;
		int buffer = numberToCheck;
		while (buffer > 0) {
			int digit = buffer % 10;
			candidate += Math.pow(digit, numberOfDigits);
			buffer /= 10;
		}
		return candidate == numberToCheck;
	}

}
