const gigasecondMS = 1_000_000_000_000;

export const gigasecond = (date) => {
  return new Date(date.getTime() + gigasecondMS);
};
