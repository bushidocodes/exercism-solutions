def flatten_(result, node):
    if isinstance(node, list):
        for nested in node:
            flatten_(result, nested)
    else:
        if node is not None:
            result.append(node)

def flatten(iterable):
    result = []
    flatten_(result, iterable)
    return result
