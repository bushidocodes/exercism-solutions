module bob
  implicit none
contains

  function hey(statement)
    character(100) :: hey
    character(len=*), intent(in) :: statement
    logical:: has_lowercase, has_uppercase, is_question, is_silent
    integer:: i
    integer:: statement_len

    has_lowercase = .false.
    has_uppercase = .false.
    is_silent = .true.
    do i=1, len(statement)
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
    statement_len = len(trim(statement))
    is_question = statement(statement_len:statement_len) == '?'

    if (is_silent) then
      hey = "Fine. Be that way!"
    else if (.not. has_lowercase .and. has_uppercase .and. is_question) then
      hey = "Calm down, I know what I'm doing!"
    else if (.not. has_lowercase .and. has_uppercase) then
      hey = "Whoa, chill out!"
    else if (is_question) then
      hey = "Sure."
    else
      hey = 'Whatever.'
    end if

  end function hey

end module bob
