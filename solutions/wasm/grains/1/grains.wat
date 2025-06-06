(module
  (import "console" "log_i64_u" (func $log_i64_u (param i64)))
  (global $squareCount i64 (i64.const 64))
  
  ;; Result is unsigned
  (func $square (export "square") (param $squareNum i64) (result i64)
    (if (i32.or
        (i64.lt_s (local.get $squareNum) (i64.const 1))
        (i64.gt_s (local.get $squareNum) (i64.const 64))
      ) (then (return (i64.const 0)))
    )
  
    (i64.shl (i64.const 1) (i64.sub (local.get $squareNum) (i64.const 1)))
  )

  ;; Result is unsigned
  (func (export "total") (result i64)
    (local $i i64)
    (local $sum i64)
    
    (local.set $i (i64.const 1))
    (local.set $sum (i64.const 0))

    (loop
      (local.set $sum (i64.add (local.get $sum) (call $square (local.get $i))))
      (br_if 0 (i64.le_u (local.tee $i (i64.add (local.get $i) (i64.const 1))) (global.get $squareCount)))
    )
    
    (local.get $sum)
  )
)
