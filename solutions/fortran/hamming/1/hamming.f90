module hamming
  implicit none
contains

  function compute(strand1, strand2, distance)
      character(*) :: strand1, strand2
      integer :: distance
      logical :: compute
      integer :: i

      compute = .false.
      distance = 0
      i = 1;

      if (len(strand1) == len(strand2)) then
        compute = .true.
        do while (i <= len(strand1))
          if (strand1(i:i) /= strand2(i:i)) then
            distance = distance + 1;
          end if
          i = i + 1
        end do
      end if

  end function compute

end module hamming
