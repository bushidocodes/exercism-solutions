module pangram
  implicit none
  contains
  
  character function tolower(char)
    character :: char
    integer :: char_code
    char_code = ichar(char);
    if (char_code >= ichar('A') .and. char_code <= ichar('Z')) then
      tolower = achar(char_code - 32)
    else 
      tolower = char
    end if
  end function tolower

  logical function isupper(char)
    character :: char
    integer :: char_code
    char_code = ichar(char);
    isupper = (char_code >= ichar('A') .and. char_code <= ichar('Z'))
  end function isupper

  logical function islower(char)
    character :: char
    integer :: char_code
    char_code = ichar(char);
    islower = (char_code >= ichar('a') .and. char_code <= ichar('z'))
  end function islower

  logical function isalpha(char)
    character :: char
    isalpha = islower(char) .or. isupper(char)
  end function isalpha

  logical function is_pangram(sentence)
    character(*) :: sentence
    integer :: sentence_len
    integer :: i
    integer :: idx
    integer, dimension(26) :: letter_count

    sentence_len = len(sentence)

    do i=1, 26
      letter_count(i) = 0
    end do

    do i=1, sentence_len
      if (isupper(sentence(i:i))) then
        idx = ichar(sentence(i:i)) - ichar('A') + 1
        letter_count(idx) = letter_count(idx) + 1
      else if (islower(sentence(i:i))) then
        idx = ichar(sentence(i:i)) - ichar('a') + 1
        letter_count(idx) = letter_count(idx) + 1
      end if
    end do

    do i=1, 26
      if (letter_count(i) == 0) then
        is_pangram = .false.
        return
      end if
    end do

    is_pangram = .true.
  end function is_pangram

end module pangram
