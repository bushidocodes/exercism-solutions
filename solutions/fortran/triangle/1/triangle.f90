
module triangle
  implicit none

  interface equilateral
    module procedure equilateral_real
    module procedure equilateral_int
  end interface

  interface scalene
    module procedure scalene_real
    module procedure scalene_int
  end interface

  interface isosceles
    module procedure isosceles_real
    module procedure isosceles_int
  end interface

 contains
  logical function is_degenerate_real(edges)
    real,dimension(3) :: edges
    integer :: largest_idx
    real :: largest, rest

    if (minval(edges, 1) == 0) then
      is_degenerate_real = .true.
      return
    end if
    
    largest_idx = maxloc(edges, 1)
    largest = edges(largest_idx)
  
    select case (largest_idx)
        case (1)
          rest = edges(2) + edges(3)
        case (2)
          rest = edges(1) + edges(3)
        case (3)
          rest = edges(1) + edges(2)
    end select
  
    if (largest > rest) then
      is_degenerate_real = .true.
      return
    end if
    
    is_degenerate_real = .false.
  end function

  logical function is_degenerate_int(edges)
    integer,dimension(3) :: edges
    integer :: largest_idx
    integer :: largest, rest

    if (minval(edges, 1) == 0) then
      is_degenerate_int = .true.
      return
    end if
    
    largest_idx = maxloc(edges, 1)
    largest = edges(largest_idx)
  
    select case (largest_idx)
        case (1)
          rest = edges(2) + edges(3)
        case (2)
          rest = edges(1) + edges(3)
        case (3)
          rest = edges(1) + edges(2)
    end select
  
    if (largest > rest) then
      is_degenerate_int = .true.
      return
    end if
    
    is_degenerate_int = .false.
  end function


  logical function equilateral_real(edges)
    real,dimension(3) :: edges

    if (is_degenerate_real(edges)) then
      equilateral_real = .false.
      return
    end if

    equilateral_real = abs(edges(1) - edges(2)) < 1.0D-5 .and. abs(edges(2) - edges(3)) < 1.0D-5
  end function

  logical function equilateral_int(edges)
    integer,dimension(3) :: edges

    if (is_degenerate_int(edges)) then
      equilateral_int = .false.
      return
    end if

    equilateral_int = edges(1) == edges(2) .and. edges(2) == edges(3)
  end function

  logical function isosceles_real(edges)
    real,dimension(3) :: edges

    if (minval(edges, 1) == 0) then
      isosceles_real = .false.
      return
    end if

    isosceles_real = abs(edges(1) - edges(2)) < 1.0D-5 .or. abs(edges(2) - edges(3)) < 1.0D-5 .or. abs(edges(1) - edges(3)) < 1.0D-5
  end function

  logical function isosceles_int(edges)
    integer,dimension(3) :: edges

    if (is_degenerate_int(edges)) then
      isosceles_int = .false.
      return
    end if

    isosceles_int = edges(1) == edges(2) .or. edges(2) == edges(3) .or. edges(1) == edges(3)
  end function


  logical function scalene_real(edges)
    real,dimension(3) :: edges

    if (is_degenerate_real(edges)) then
      scalene_real = .false.
      return
    end if

    scalene_real = abs(edges(1) - edges(2)) > 1.0D-5 .and. abs(edges(2) - edges(3)) > 1.0D-5 .and. abs(edges(1) - edges(3)) > 1.0D-5
  end function

  logical function scalene_int(edges)
    integer,dimension(3) :: edges

    if (is_degenerate_int(edges)) then
      scalene_int = .false.
      return
    end if

    scalene_int = edges(1) /= edges(2) .and. edges(2) /= edges(3) .and. edges(1) /= edges(3)
  end function

end module
