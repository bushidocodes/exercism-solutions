module raindrops
  implicit none
contains

  function convert(i)
    integer, parameter :: plingFactor = 3
    character(len=5), parameter :: pling = "Pling"
    integer, parameter :: plangFactor = 5
    character(len=5), parameter :: plang = "Plang"
    integer, parameter :: plongFactor = 7
    character(len=5), parameter :: plong = "Plong"
    
    logical:: did_match
    integer :: i
    character(20) :: convert, temp

    convert = ""
    did_match = .false.

    if (mod(i, plingFactor) == 0) then
      convert(len_trim(convert)+1:) = pling
      did_match = .true.
    end if
    
    if (mod(i, plangFactor) == 0) then
      convert(len_trim(convert)+1:) = plang
      did_match = .true.
    end if    

    if (mod(i, plongFactor) == 0) then
      convert(len_trim(convert)+1:) = plong
      did_match = .true.
    end if

    if (did_match.eqv..false.) then
      write (convert, "(I0)") i
    end if

  end function convert

end module raindrops
