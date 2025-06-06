export const hey = (message) => {
  const trimmed = message.trimEnd();
  if (trimmed.length == 0) return "Fine. Be that way!";

  let letters = trimmed.split("").filter((c) => /[a-zA-Z]/.test(c));
  const is_shouting =
    letters.length == 0 ? false : letters.some((c) => /[a-z]/.test(c)) == false;

  const is_asking = trimmed.charAt(trimmed.length - 1) == "?";

  if (is_asking && is_shouting) return "Calm down, I know what I'm doing!";
  if (is_asking) return "Sure.";
  if (is_shouting) return "Whoa, chill out!";
  return "Whatever.";
};
