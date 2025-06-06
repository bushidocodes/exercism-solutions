use enum_iterator::IntoEnumIterator;
use int_enum::IntEnum;

#[repr(usize)]
#[derive(Debug, PartialEq, Clone, Copy, IntEnum, IntoEnumIterator)]
pub enum ResistorColor {
    Black = 0,
    Brown = 1,
    Red = 2,
    Orange = 3,
    Yellow = 4,
    Green = 5,
    Blue = 6,
    Violet = 7,
    Grey = 8,
    White = 9,
}

pub fn color_to_value(_color: ResistorColor) -> usize {
    _color.int_value()
}

pub fn value_to_color_string(value: usize) -> String {
    let resistor = ResistorColor::from_int(value);
    if resistor.is_err() {
        return String::from("value out of range");
    };

    match ResistorColor::from_int(value).unwrap() {
        ResistorColor::Black => String::from("Black"),
        ResistorColor::Brown => String::from("Brown"),
        ResistorColor::Red => String::from("Red"),
        ResistorColor::Orange => String::from("Orange"),
        ResistorColor::Yellow => String::from("Yellow"),
        ResistorColor::Green => String::from("Green"),
        ResistorColor::Blue => String::from("Blue"),
        ResistorColor::Violet => String::from("Violet"),
        ResistorColor::Grey => String::from("Grey"),
        ResistorColor::White => String::from("White"),
    }
}

pub fn colors() -> Vec<ResistorColor> {
    ResistorColor::into_enum_iter().collect()
}
