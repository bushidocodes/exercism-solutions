def transform(legacy_data: dict[int, list[str]]) -> dict[str, int]:
    result = {}
    for key in legacy_data.keys():
        for value in legacy_data[key]:
            result[value.lower()] = key
    return result
