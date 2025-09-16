class School:
    def __init__(self):
        self.students: dict[int, list[str]] = {}
        self.added_: list[bool] = []

    def add_student(self, name: str, grade: int) -> None:
        self.students.setdefault(grade, [])

        if any(name in names for names in self.students.values()):
            self.added_.append(False)
            return

        self.students[grade].append(name)
        self.added_.append(True)

    def roster(self) -> list[str]:
        return [
            name
            for grade in sorted(self.students)
            for name in sorted(self.students[grade])
        ]

    def grade(self, grade_number) -> list[str]:
        return sorted(self.students.get(grade_number, []))

    def added(self) -> list[bool]:
        return self.added_
