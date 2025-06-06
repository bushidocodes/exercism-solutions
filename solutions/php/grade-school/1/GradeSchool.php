<?php

declare(strict_types=1);

class School
{
    private $_grade = array();

    public function add(string $name, int $grade): void
    {
        if ($grade < 1 || $grade > 6) throw new \BadMethodCallException("Implement the add method");

        if (!isset($this->_grade[$grade])) $this->_grade[$grade] = array($name);
        else array_push($this->_grade[$grade], $name);
    }

    public function grade($grade)
    {
        if (!isset($this->_grade[$grade])) return array();
        return $this->_grade[$grade];
    }

    public function studentsByGradeAlphabetical(): array
    {
        foreach($this->_grade as &$grade) {
            sort($grade, SORT_STRING);
        }

        ksort($this->_grade);

        return $this->_grade;
    }
}
