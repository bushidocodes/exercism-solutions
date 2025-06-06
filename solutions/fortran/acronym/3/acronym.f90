
module acronym
  implicit none
contains

  pure function is_delimiter(c)
    character, intent(in) :: c
    logical :: is_delimiter
    is_delimiter = c == ' ' .or. c == '-' .or. c == '_'
  end function

  pure function is_lower(c)
    character, intent(in) :: c
    logical :: is_lower
    is_lower = (c >= 'a' .and. c <= 'z')
  end function

  pure function to_lower(c)
    character, intent(in) :: c
    character :: to_lower
    if (is_lower(c)) then
      to_lower = achar(iachar(c) + iachar('A') - iachar('a'))
    else
      to_lower = c
    end if
  end function

  pure function is_upper(c)
    character, intent(in) :: c
    logical :: is_upper
    is_upper = (c >= 'A' .and. c <= 'Z')
  end function

  function abbreviate(s)
    character(len=*), intent(in) :: s
    character(len=50) :: abbreviate
    integer :: i, j
    logical :: start_of_word

    abbreviate = ""
    j = 1
    start_of_word = .true.

    do i = 1,len(s)
      if (start_of_word .and. .not. is_delimiter(s(i:i))) then
        if (is_upper(s(i:i))) then
          abbreviate(j:j) = s(i:i)
        else if (is_lower(s(i:i))) then
          abbreviate(j:j) = to_lower(s(i:i))
        end if
        j = j + 1
        start_of_word = .false.
      end if

      if (is_delimiter(s(i:i))) then
        start_of_word = .true.
      end if 
    end do
    
  end function

end module
