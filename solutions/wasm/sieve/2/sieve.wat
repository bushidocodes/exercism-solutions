(module
  (memory (export "mem") 1)

  ;;
  ;; Determine all the prime numbers below a given limit.
  ;; Return the offset and length of the resulting array of primes.
  ;;
  ;; @param {i32} limit - the upper bound for the prime numbers
  ;;
  ;; @return {i32} - offset off the u32[] array
  ;; @return {i32} - length off the u32[] array in elements
  ;;
  (func (export "primes") (param $limit i32) (result i32 i32)
    ;; locals are automatically set to zero
    (local $numPrimes i32)
    (local $resultOffset i32)
    (local $resultCount i32)
    (local $i i32)
    (local $j i32)

    ;; No primes < 2
    (if (i32.lt_u (local.get $limit) (i32.const 2))
      (return (i32.const 0) (i32.const 0)))
    
    ;; We'll use the first page as a static array of bools for candidates
    ;; assert out if we don't fit in a single page
    ;; Initialize 0..=limit to true
    (if (i32.gt_u (local.get $limit) (i32.const 65535)) (unreachable))
    (memory.fill (i32.const 0) (i32.const 1) (i32.add (local.get $limit) (i32.const 1)))

    ;; We'll use the second page as the results
    (memory.grow (i32.const 1))
    (local.set $resultOffset (i32.const 65536))

    (local.set $i (i32.const 2))
    (loop
      ;; (call $log_i32_u (local.get $i))
      (if (i32.load8_u (local.get $i))
        (then 
          ;; Add prime to results
          (i32.store (i32.add (local.get $resultOffset) (i32.mul (local.get $resultCount) (i32.const 4))) (local.get $i))
          (local.set $resultCount (i32.add (local.get $resultCount) (i32.const 1)))

          (local.set $j (i32.const 2))
          (loop
            (i32.store8 (i32.mul (local.get $i) (local.get $j)) (i32.const 0))

            ;; i * ++j <= limit
            (br_if 0 (i32.le_u 
              (i32.mul (local.get $i) (local.tee $j (i32.add (local.get $j) (i32.const 1)))) 
              (local.get $limit))))))

      ;; ++i <= limit
      (br_if 0 (i32.le_u (local.tee $i (i32.add (local.get $i) (i32.const 1))) (local.get $limit))))
    
    (return (local.get $resultOffset) (local.get $resultCount))))