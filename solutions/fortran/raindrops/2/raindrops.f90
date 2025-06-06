module raindrops
  implicit none
contains

  function convert(i)
    ! in params
    integer :: i
    ! out params
    character(20) :: convert
    ! constants
    integer, parameter :: plingFactor = 3, plangFactor = 5, plongFactor = 7
    character(*), parameter :: pling = "Pling", plang = "Plang", plong = "Plong"
    ! locals
    logical :: did_match

    did_match = .false.
    convert = ""

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

    if (did_match .eqv. .false.) then
      write (convert, "(I0)") i
    end if

  end function convert

end module raindrops
