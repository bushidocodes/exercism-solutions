module bob
  implicit none
contains

  character(len=34) function hey(statement)
    character(*), intent(in) :: statement
    character(len=1) :: c

    character(len=34), parameter :: fine = "Fine. Be that way!"
    character(len=34), parameter :: calm = "Calm down, I know what I'm doing!"
    character(len=34), parameter :: chill = "Whoa, chill out!"
    character(len=34), parameter :: sure = "Sure."
    character(len=34), parameter :: whatever = "Whatever."
    
    logical :: has_lowercase, has_uppercase, is_question, is_silent
    integer :: i, statement_len

    has_lowercase = .false.
    has_uppercase = .false.
    is_silent = .true.
    statement_len = len(trim(statement))
    
    do i = 1,len(statement)
      if (statement(i:i) /= ' ') then
        is_silent = .false.
      end if
      if (statement(i:i) >= 'a' .and. statement(i:i) <= 'z') then
        has_lowercase = .true.
      else if (statement(i:i) >= 'A' .and. statement(i:i) <= 'Z') then
        has_uppercase = .true.
      end if
    end do

    ! Check for terminating question mark
    is_question = statement(statement_len:statement_len) == '?'

    if (is_silent) then
      hey = fine
    else if (.not. has_lowercase .and. has_uppercase .and. is_question) then
      hey = calm
    else if (.not. has_lowercase .and. has_uppercase) then
      hey = chill
    else if (is_question) then
      hey = sure
    else
      hey = whatever
    end if

  end function hey

end module bob
