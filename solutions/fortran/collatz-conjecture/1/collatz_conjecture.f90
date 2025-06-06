
module collatz_conjecture
  implicit none
contains

  integer function steps(i)
    integer :: i, j

    steps = -1
    j = i

    if (j >= 1) then
      steps = 0
      do while (j > 1)
        if (mod(j, 2) == 0) then
          steps = steps + 1;
          j = j / 2;
        else
          steps = steps + 1;
          j = (3 * j) + 1;
        end if
      end do
    end if
  end function

end module
