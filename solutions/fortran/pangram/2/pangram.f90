module pangram
  implicit none
contains

  pure character function tolower(char)
    character, intent(in) :: char
    if (char >= 'A' .and. char <= 'Z') then
      tolower = achar(ichar('a') + (ichar(char) - ichar('A')))
    else 
      tolower = char
    end if
  end function tolower

  pure logical function isalpha(char)
    character, intent(in) :: char
    isalpha = ((char >= 'a' .and. char <= 'z') .or. (char >= 'A' .and. char <= 'Z'))
  end function isalpha

  pure logical function is_pangram(sentence)
    character(*), intent(in) :: sentence
    integer :: sentence_len, i, idx
    integer, dimension(26) :: letter_count

    do i = 1,26
      letter_count(i) = 0
    end do

    sentence_len = len(sentence)
    do i = 1,sentence_len
      if (isalpha(sentence(i:i))) then
        idx = ichar(tolower(sentence(i:i))) - ichar('a') + 1
        letter_count(idx) = letter_count(idx) + 1
      end if
    end do

    do i = 1,26
      if (letter_count(i) == 0) then
        is_pangram = .false.
        return
      end if
    end do

    is_pangram = .true.
  end function is_pangram

end module pangram
