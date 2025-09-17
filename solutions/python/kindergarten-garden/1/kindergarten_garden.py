from typing import Optional


class Garden:
    default_students = [
        "Alice",
        "Bob",
        "Charlie",
        "David",
        "Eve",
        "Fred",
        "Ginny",
        "Harriet",
        "Ileana",
        "Joseph",
        "Kincaid",
        "Larry",
    ]

    plant_map = {
        "R": "Radishes",
        "C": "Clover",
        "G": "Grass",
        "V": "Violets",
    }

    def __init__(self, diagram: str, students: list[str] = default_students) -> None:
        self.students: list[str] = sorted(students)
        self.cups_by_student: dict[str, list[str]] = {}

        lines = diagram.split("\n")
        if lines and len(lines) == 2:
            for j in range(0, len(lines[0]), 2):
                if j // 2 >= len(self.students):
                    raise ValueError("Diagram has more cups than students")
                student_name = self.students[j // 2]
                self.cups_by_student[student_name] = []
                for line in lines:
                    for el in line[j : j + 2]:
                        try:
                            self.cups_by_student[student_name].append(
                                self.plant_map[el]
                            )
                        except KeyError:
                            raise ValueError(f"Unexpected diagram encoding {el}")

    def plants(self, student: str) -> list[str]:
        if (cups := self.cups_by_student.get(student)) is not None:
            return cups
        raise ValueError(f"Student {student} not found in the garden")
