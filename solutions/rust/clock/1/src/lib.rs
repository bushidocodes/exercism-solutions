use chrono::{Duration, NaiveTime};
use std::fmt;

#[derive(Debug)]
pub struct Clock {
    time: NaiveTime,
}

impl PartialEq for Clock {
    fn eq(&self, other: &Self) -> bool {
        self.time == other.time
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.time.format("%H:%M").to_string())
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let mut hours = hours;
        let mut minutes = minutes;
        while minutes < 0 {
            minutes += 60;
            hours -= 1;
        }
        while hours < 0 {
            hours += 24
        }

        hours = (hours + minutes / 60) % 24;
        minutes = minutes % 60;

        Clock {
            time: NaiveTime::from_hms(hours as u32, minutes as u32, 0),
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Clock {
            time: self.time + Duration::minutes(minutes as i64),
        }
    }
}
