<?php

declare(strict_types=1);

enum WordyToken
{
    case Start;
    case Number;
    case OperatorOrEnd;
}

enum Operation
{
    case None;
    case Assignment;
    case Addition;
    case Subtraction;
    case Multiplication;
    case Division;
}

function calculate(string $input): int
{
    $cursor = 0;
    $inputLength = strlen($input);
    $expected = WordyToken::Start;
    $nextOperation = Operation::None;
    $accumulator = 0;

    while ($cursor < $inputLength){
        while ($input[$cursor] == ' ') $cursor++;

        switch($expected){
            case WordyToken::Start:
                if (stripos($input, "What is ", $cursor) == $cursor){
                    $expected = WordyToken::Number;
                    $nextOperation = Operation::Assignment;
                    $cursor += strlen("What is ");
                } else {
                    throw new InvalidArgumentException('Does not start with \'What is \'');
                }
                break;
            case WordyToken::Number;
                // Tokenize
                $endCursorExc = $cursor;
                while ($endCursorExc <= $inputLength && ($input[$endCursorExc] != ' '  && $input[$endCursorExc] != '?' ))
                    $endCursorExc++;
                $currentToken = substr($input, $cursor, $endCursorExc - $cursor);

                // Validate Token
                if (!is_numeric($currentToken)) throw new InvalidArgumentException('Expected number, but not numeric');
                
                // Parse
                $value = intval($currentToken);

                // Calculate
                switch($nextOperation){
                    case Operation::Assignment:
                        $accumulator = $value;
                        break;
                    case Operation::Addition:
                        $accumulator += $value;
                        break;
                    case Operation::Subtraction:
                        $accumulator -= $value;
                        break;
                    case Operation::Multiplication:
                        $accumulator *= $value;
                        break;
                    case Operation::Division:
                        $accumulator /= $value;
                        break;
                    case Operation::None:
                    default:
                        throw new InvalidArgumentException('Unknown operation');
                        break;
                }

                // Advance
                $expected = WordyToken::OperatorOrEnd;
                $cursor = $endCursorExc;
                break;
            case WordyToken::OperatorOrEnd:
                // Tokenize
                if ($input[$cursor] == '?'){
                    if ($expected != WordyToken::OperatorOrEnd ) throw new InvalidArgumentException();
                    return $accumulator;
                } else if (stripos($input, "plus", $cursor) == $cursor){
                    $nextOperation = Operation::Addition;
                    $cursor += strlen("plus");
                } else if (stripos($input, "minus", $cursor) == $cursor){
                    $nextOperation = Operation::Subtraction;
                    $cursor += strlen("minus");
                } else if (stripos($input, "multiplied by", $cursor) == $cursor){
                    $nextOperation = Operation::Multiplication;
                    $cursor += strlen("multiplied by");
                } else if (stripos($input, "divided by", $cursor) == $cursor){
                    $nextOperation = Operation::Division;
                    $cursor += strlen("divided by");
                } else {
                    throw new InvalidArgumentException('Invalid operator');
                }

                $expected = WordyToken::Number;
                break;
            default:
                throw new InvalidArgumentException('default');
        }
    }
}
