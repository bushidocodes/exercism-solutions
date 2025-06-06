module difference_of_squares
  implicit none
contains

  integer function square_of_sum(n)
    integer :: n, sum, i
    sum = 0
    do i=1, n
      sum = sum + i
    end do
    square_of_sum = sum ** 2
  end function square_of_sum

  integer function sum_of_squares(n)
    integer :: n, i
    sum_of_squares = 0
    do i=1, n
      sum_of_squares = sum_of_squares + i ** 2
    end do
  end function sum_of_squares

  integer function difference(n)
    integer :: n
    difference = square_of_sum(n) - sum_of_squares(n)
  end function difference

end module difference_of_squares
