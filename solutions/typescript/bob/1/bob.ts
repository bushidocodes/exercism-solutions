class Bob {
  private static containsASCIILetter(input: string): boolean {
    return input
      .split("")
      .some(
        (char) => (char >= "A" && char <= "Z") || (char >= "a" && char <= "z")
      );
  }

  hey(statement: string) {
    const trimmedStatement = statement.trim();

    // Silence = only whitespace
    if (trimmedStatement.length === 0) return "Fine. Be that way!";

    const isYelling =
      Bob.containsASCIILetter(trimmedStatement) &&
      statement.localeCompare(statement.toLocaleUpperCase()) == 0;

    // Question ~ question mark, optionally followed by whitespace
    if (trimmedStatement.charAt(trimmedStatement.length - 1) == "?") {
      return isYelling ? "Calm down, I know what I'm doing!" : "Sure.";
    }

    return isYelling ? "Whoa, chill out!" : "Whatever.";
  }
}

export default Bob;
