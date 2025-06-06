<?php

declare(strict_types=1);

class Tournament
{
    private array $mp = [];
    private array $w = [];
    private array $d = [];
    private array $l = [];
    private array $p = [];

    public function __construct(){}

    public function cmp($a, $b)
    {
        return $this->p[$b] == $this->p[$a] ? strcmp($a, $b) : $this->p[$b] - $this->p[$a];
    }

    public function tally(string $scores): string {

        $lines = explode("\n", $scores);
        foreach ($lines as $line){
            $toks = explode(";", $line, 3);
            if (count($toks) == 0 || strlen($toks[0]) == 0) continue;


            $this->p[$toks[0]] = ($this->p[$toks[0]] ?? 0);
            $this->p[$toks[1]] = ($this->p[$toks[1]] ?? 0);
            $this->mp[$toks[0]] = ($this->mp[$toks[0]] ?? 0) + 1;
            $this->mp[$toks[1]] = ($this->mp[$toks[1]] ?? 0) + 1;

            switch ($toks[2]){
                case "loss":
                    $this->l[$toks[0]] = ($this->l[$toks[0]] ?? 0) + 1;
                    $this->w[$toks[1]] = ($this->w[$toks[1]] ?? 0) + 1;
                    $this->p[$toks[1]] = ($this->p[$toks[1]] ?? 0) + 3;
                    break;
                case "win":
                    $this->w[$toks[0]] = ($this->w[$toks[0]] ?? 0) + 1;
                    $this->p[$toks[0]] = ($this->p[$toks[0]] ?? 0) + 3;
                    $this->l[$toks[1]] = ($this->l[$toks[1]] ?? 0) + 1;
                    break;
                case "draw":
                    $this->d[$toks[0]] = ($this->d[$toks[0]] ?? 0) + 1;
                    $this->d[$toks[1]] = ($this->d[$toks[1]] ?? 0) + 1;
                    $this->p[$toks[0]] = ($this->p[$toks[0]] ?? 0) + 1;
                    $this->p[$toks[1]] = ($this->p[$toks[1]] ?? 0) + 1;
                    break;
            }
        }


        $res = "";
        $res .= "Team                           | MP |  W |  D |  L |  P";

        uksort($this->p, [$this, 'cmp']);

        foreach ($this->p as $team => $_p) {
            $res .= sprintf("\n%-31s| %2s | %2s | %2s | %2s | %2s", $team, $this->mp[$team], $this->w[$team] ?? 0, $this->d[$team] ?? 0, $this->l[$team] ?? 0, $_p);
        }

        return $res;
    }
}
