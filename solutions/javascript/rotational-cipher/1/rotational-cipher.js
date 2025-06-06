export class RotationalCipher {
  static lowerBase = "a".charCodeAt(0);
  static upperBase = "A".charCodeAt(0);

  static rotate(input, rot) {
    return input
      .split("")
      .map((c) => {
        if (/[A-Z]/.test(c)) {
          return String.fromCharCode(
            RotationalCipher.upperBase +
              ((c.charCodeAt(0) - RotationalCipher.upperBase + rot) % 26)
          );
        } else if (/[a-z]/.test(c)) {
          return String.fromCharCode(
            RotationalCipher.lowerBase +
              ((c.charCodeAt(0) - RotationalCipher.lowerBase + rot) % 26)
          );
        } else {
          return c;
        }
      })
      .join("");
  }
}
