<?php

declare(strict_types=1);

class Matrix
{
    private array $matrix;

    public function __construct(string $matrixStr)
    {
        $rowsStr = explode("\n", $matrixStr);

        $matrix = array_map(function($row) {
            return array_map(function($cell){
                return intval($cell);
            }, explode(' ', $row));
        }, $rowsStr);

        $this->matrix = $matrix;
    }

    public function getRow(int $row){
        if ($row > count($this->matrix)) return [];
        if ($row < 1) return [];
        return $this->matrix[($row - 1)];
    }

    public function getColumn(int $col){
        if ($col > count($this->matrix[0])) return [];
        if ($col < 1) return [];
        return array_map(function($row) use($col){
            return $row[$col - 1];
        }, $this->matrix);
    }

    
}
