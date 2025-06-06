const dayToIdx = {
  Sunday: 0,
  Monday: 1,
  Tuesday: 2,
  Wednesday: 3,
  Thursday: 4,
  Friday: 5,
  Saturday: 6,
};

const getFirstDate = (year, month, descriptor) => {
  switch (descriptor) {
    case "first":
      return 1;
    case "second":
      return 8;
    case "teenth":
      return 13;
    case "third":
      return 15;
    case "fourth":
      return 22;
    case "fifth":
      return 29;
    case "last":
      // Confusingly, month is zero indexed, so as used before we are asking for day
      // zero of the subsequent month, which wraps to the last day of the current month.
      return new Date(year, month, 0).getDate() - 6;
  }
};

export const meetup = (year, month, descriptor, day) => {
  let date = getFirstDate(year, month, descriptor);
  let buffer = new Date(year, month - 1, date);

  // We have to set a date and then check the day of the week
  // so set to start of the interval of possible days and then calculate the offset
  let targetDay = dayToIdx[day];
  let currentDay = buffer.getDay();
  let offset = targetDay - currentDay;
  if (offset < 0) offset += 7;
  date += offset;
  if (date > new Date(year, month, 0).getDate())
    throw new Error("Invalid date");
  buffer.setDate(date);

  return buffer;
};
