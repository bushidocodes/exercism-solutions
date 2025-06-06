
module allergies
  implicit none

contains

  logical function allergicTo(allergy_str, allergy_key)
    character(len=*), intent(in) :: allergy_str
    integer, intent(in) :: allergy_key
    allergicTo = .false. 

    select case (allergy_str)
      case ("eggs")
        allergicTo = iand(1, allergy_key) == 1
      case ("peanuts")
        allergicTo = iand(2, allergy_key) == 2
      case ("shellfish")
        allergicTo = iand(4, allergy_key) == 4
      case ("strawberries")
        allergicTo = iand(8, allergy_key) == 8
      case ("tomatoes")
        allergicTo = iand(16, allergy_key) == 16
      case ("chocolate")
        allergicTo = iand(32, allergy_key) == 32
      case ("pollen")
        allergicTo = iand(64, allergy_key) == 64
      case ("cats")
        allergicTo = iand(128, allergy_key) == 128
    end select
  end function


  function allergicList(allergy_key)
    integer, intent(in) :: allergy_key
    character(len=100) :: allergicList
    allergicList = ''

    if (iand(1, allergy_key) == 1) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "eggs"
      else 
        allergicList(len_trim(allergicList)+1:) = "eggs"
      end if
    end if
    if (iand(2, allergy_key) == 2) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "peanuts"
      else 
        allergicList(len_trim(allergicList)+1:) = "peanuts"
      end if
    end if
    if (iand(4, allergy_key) == 4) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "shellfish"
      else 
        allergicList(len_trim(allergicList)+1:) = "shellfish"
      end if
    end if
    if (iand(8, allergy_key) == 8) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "strawberries"
      else 
        allergicList(len_trim(allergicList)+1:) = "strawberries"
      end if
    end if
    if (iand(16, allergy_key) == 16) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "tomatoes"
      else 
        allergicList(len_trim(allergicList)+1:) = "tomatoes"
      end if
    end if
    if (iand(32, allergy_key) == 32) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "chocolate"
      else 
        allergicList(len_trim(allergicList)+1:) = "chocolate"
      end if
    end if
    if (iand(64, allergy_key) == 64) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "pollen"
      else 
        allergicList(len_trim(allergicList)+1:) = "pollen"
      end if
    end if
    if (iand(128, allergy_key) == 128) then
      if (len_trim(allergicList) > 0) then
        allergicList(len_trim(allergicList)+2:) = "cats"
      else 
        allergicList(len_trim(allergicList)+1:) = "cats"
      end if
    end if
  end function
end module
