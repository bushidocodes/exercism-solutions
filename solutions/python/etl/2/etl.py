def transform(legacy_data: dict[int, list[str]]) -> dict[str, int]:
    return {value.lower(): key for key, values in legacy_data.items() for value in values}
