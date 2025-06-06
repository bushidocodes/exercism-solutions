! Fortran 90 added the concept of modules
module hamming
  ! implicit types cause types to be inferred from the first character of the variable name
  implicit none
contains

  function compute(strand1, strand2, distance)
      ! Fortran requires parameters and locals to be declared at the top of a function
      ! The return value is a local variable with the same name as the function
      ! The parenthesized asterisk indicates that the name is defined as having the length of the constant.
      ! I assume this is similar to a char * in C.
      character(*) :: strand1, strand2 
      integer :: distance, i
      logical :: compute

      ! Locals are assigned separately from declarations
      compute = .false.
      distance = 0
      i = 1;

      if (len(strand1) == len(strand2)) then
        compute = .true.
        do while (i <= len(strand1))
          ! /= is inequality operator
          ! string(m:n) evaluates to substring from idx m to idx n (inclusive)
          if (strand1(i:i) /= strand2(i:i)) then
            ! No increment operator
            distance = distance + 1;
          end if
          i = i + 1
        end do
      end if

  end function compute

end module hamming
