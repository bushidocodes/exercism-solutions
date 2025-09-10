from collections.abc import Iterable
from typing import Callable, TypeVar, List

T = TypeVar("T")
U = TypeVar("U")


def append(list1: list[T], list2: list[T]) -> list[T]:
    return [*list1, *list2]


def concat(lists: list[list[T]]) -> list[T]:
    result = []
    for list_ in lists:
        result.extend(list_)
    return result


def filter(function: Callable[[T], bool], list: list[T]) -> list[T]:
    return [el for el in list if function(el)]


def length(list: list) -> int:
    return len(list)


def map(function: Callable[[T], U], list: list[T]) -> list[U]:
    return [function(el) for el in list]


def foldl(function: Callable[[T, U], T], list: list[U], initial: T) -> T:
    result = initial
    for el in list:
        result = function(result, el)
    return result


def foldr(function: Callable[[T, U], T], list: list[U], initial: T) -> T:
    result = initial
    for el in reversed(list):
        result = function(result, el)
    return result


def reverse(list: list[T]) -> list[T]:
    return list[::-1]
