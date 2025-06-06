
module grains

  implicit none

contains

  double precision function square(n)
    integer :: n
    if (n >= 1 .and. n <= 64) then
      square = 2d0 ** (n - 1)
    else
      square = -1.d0
    end if

  end function

  double precision function total()
    integer :: i
    total = -1.1d0
    do i=1, 64
      total = total + square(i)
    end do
  end function

end module

