#[derive(Debug, PartialEq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> Comparison {
    if _first_list.len() == _second_list.len() && _first_list == _second_list {
        return Comparison::Equal;
    } else if _first_list.len() > _second_list.len() && (_second_list.len() == 0 || _first_list.windows(_second_list.len()).any(|window| window == _second_list)) {
        return Comparison::Superlist;
    } else if _first_list.len() < _second_list.len() && (_first_list.len() == 0 || _second_list.windows(_first_list.len()).any(|window| window == _first_list)) {
        return Comparison::Sublist;
    } else {
        return Comparison::Unequal;
    }
}
