#[derive(Debug)]
pub enum CalculatorInput {
    Add,
    Subtract,
    Multiply,
    Divide,
    Value(i32),
}

pub fn evaluate(inputs: &[CalculatorInput]) -> Option<i32> {
    let mut operand_stack = Vec::<i32>::new();
    
    for input in inputs {
        match input {
            CalculatorInput::Value(val) => operand_stack.push(*val),
            CalculatorInput::Add => {
                if let (Some(second), Some(first)) = (operand_stack.pop(), operand_stack.pop()) {
                    let sum = first + second;
                    operand_stack.push(sum);
                } else { 
                    return None;
                }
            }
            CalculatorInput::Subtract => {
                if let (Some(second), Some(first)) = (operand_stack.pop(), operand_stack.pop()) {
                    let difference = first - second;
                    operand_stack.push(difference);
                } else { 
                    return None;
                }
            }
            CalculatorInput::Multiply => {
                if let (Some(second), Some(first)) = (operand_stack.pop(), operand_stack.pop()) {
                    let product = first * second;
                    operand_stack.push(product);
                } else { 
                    return None;
                }
            }
            CalculatorInput::Divide => {
                if let (Some(second), Some(first)) = (operand_stack.pop(), operand_stack.pop()) {
                    let quotient = first / second;
                    operand_stack.push(quotient);
                } else { 
                    return None;
                }
            }
        }
    }
    
    if operand_stack.len() > 1 {
        None
    } else {
        operand_stack.pop()
    }
}
