module rna_transcription
    implicit none
contains

function to_rna(dna) result(rna)
    character(*), intent(in) :: dna
    character(len(dna)) :: rna
    integer :: i
      
    do i = 1, len(dna)
        select case(dna(i:i))
        case('G')
            rna(i:i) = 'C'
        case('C')
            rna(i:i) = 'G'
        case('T')
            rna(i:i) = 'A'
        case('A')
            rna(i:i) = 'U'
        case default
            print *, "Invalid DNA base:", dna(i:i), "at position", i
            error stop 1
        end select
    end do
end function to_rna

end module rna_transcription
