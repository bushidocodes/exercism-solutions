from heapq import nlargest


class HighScores:
    def __init__(self, scores: list[int]) -> None:
        self._scores = scores[:]

    @property
    def scores(self) -> list[int]:
        return self._scores

    def latest(self) -> int | None:
        return self._scores[-1] if self._scores else None

    def personal_best(self) -> int | None:
        return max(self._scores) if self._scores else None

    def personal_top_three(self) -> list[int]:
        return nlargest(3, self._scores)
