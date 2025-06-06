
module acronym
  implicit none
contains

  function abbreviate(s)
    character(len=*), intent(in) :: s
    character(len=len_trim(s)) :: abbreviate
    integer:: s_idx, abbreviate_idx
    logical:: start_of_word 
    
    start_of_word = .true.
    abbreviate = ''
    abbreviate_idx = 1

    do s_idx=1,len(s)
      outer: if (start_of_word .and. s(s_idx:s_idx) /= ' ' .and. s(s_idx:s_idx) /= '-' .and. s(s_idx:s_idx) /= '_') then
        if (s(s_idx:s_idx) >= 'A' .and. s(s_idx:s_idx) <= 'Z') then
          abbreviate(abbreviate_idx:abbreviate_idx)=s(s_idx:s_idx)
        else if (s(s_idx:s_idx) >= 'a' .and. s(s_idx:s_idx) <= 'z') then
          abbreviate(abbreviate_idx:abbreviate_idx)= achar(iachar(s(s_idx:s_idx)) - 32);
        end if
        abbreviate_idx = abbreviate_idx + 1;
        start_of_word = .false.
      end if outer
      
      if (s(s_idx:s_idx) == ' ' .or. s(s_idx:s_idx) == '-' .or. s(s_idx:s_idx) == '_') then
        start_of_word = .true.
      end if 
      
    end do
    
  end function

end module
