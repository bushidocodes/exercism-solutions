
module armstrong_numbers
  implicit none
contains

  logical function isArmstrongNumber(i)
    integer, intent(in) :: i
    integer :: sumOfDigitsRaised
    integer :: numberOfDigits
    integer :: buffer

    buffer = i
    numberOfDigits = 0
    do while (buffer /= 0)
      numberOfDigits = numberOfDigits + 1
      buffer = buffer / 10
    end do

    buffer = i
    sumOfDigitsRaised = 0
    do while (buffer /= 0)
      sumOfDigitsRaised = sumOfDigitsRaised + mod(buffer, 10) ** numberOfDigits
      buffer = buffer / 10
    end do
  
    isArmstrongNumber = sumOfDigitsRaised == i
  end function

end module
