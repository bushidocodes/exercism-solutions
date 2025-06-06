(module
  (memory (export "mem") 1)

  (func (export "rotate") (param $textOffset i32) (param $textLength i32) (param $shiftKey i32) (result i32 i32)
    (local $charOffset i32)
    (local $char i32)
    (local $i i32)
    (local.set $i (i32.const 0))

    (loop
      (local.tee $charOffset (i32.add (local.get $textOffset) (local.get $i)))
      (local.set $char (i32.load8_u))

      ;; Assume ASCII
      (if (i32.and (i32.ge_u (local.get $char) (i32.const 65)) (i32.le_u (local.get $char) (i32.const 90)) ) ;; 'A' - 'Z'
        (then
          (i32.store8 (local.get $charOffset) 
            (i32.add (i32.const 65) (i32.rem_u (i32.add (i32.sub (local.get $char) (i32.const 65)) (local.get $shiftKey)) (i32.const 26))))  
        )
        (else (if (i32.and (i32.ge_u (local.get $char) (i32.const 97)) (i32.le_u (local.get $char) (i32.const 122)) )
          (i32.store8 (local.get $charOffset) 
            (i32.add (i32.const 97) (i32.rem_u (i32.add (i32.sub (local.get $char) (i32.const 97)) (local.get $shiftKey)) (i32.const 26))))            
        ))
      )
      (br_if 0 (i32.lt_u (local.tee $i (i32.add (local.get $i) (i32.const 1))) (local.get $textLength)))
    )
  
    (return (local.get $textOffset) (local.get $textLength))
  )
)
