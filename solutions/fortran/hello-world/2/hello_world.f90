module hello_world
contains
  function hello()
    ! Alternatively, could be a dynamic variable length array if declared as follows
    ! character(:), allocatable :: hello
    character(len=13), allocatable :: hello
    hello = 'Hello, World!'

  end function hello

end module hello_world
