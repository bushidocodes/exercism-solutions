(module
  (func (export "squareRoot") (param $radicand i32) (result i32)
    (local.get $radicand)
    (f64.convert_i32_u)
    (f64.sqrt)
    (i32.trunc_f64_u)
  )
)
