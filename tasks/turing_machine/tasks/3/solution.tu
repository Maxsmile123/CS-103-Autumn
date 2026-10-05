// Решите поставленную задачу в формате четвёрок. P.S.: Выполнена в формате .tu4 в https://faq8.ru/read.php?2,16605
00, ,<,movetoend1
movetoend1,1,<,movetoend1 movetoend1,0,<,movetoend1 movetoend1,Z,>,copy movetoend1,N,>,copy movetoend1, ,>,copy
movetostart2,Z,<,movetostart2 movetostart2, ,<,copynum2 movetostart2,N,<,movetostart2
move1startwith0,Z,>,move1startwith0 move1startwith0,N,>,move1startwith0 move1startwith0, ,>,copy02
move1startwith1,Z,>,move1startwith1 move1startwith1,N,>,move1startwith1 move1startwith1, ,>,copy12
copy,0,Z,copy0 copy,1,N,copy1 copy,Z,<,copy copy,N,<,copy copy, ,<,movetostart2
copynum2,0,Z,move1startwith0 copynum2,1,N,move1startwith1 copynum2,Z,<,copynum2 copynum2,N,<,copynum2 copynum2, ,>,gotostart1
copy02,Z,>,copy02 copy02,N,>,copy02 copy02, ,>,gotocopy0 copy02,1,>,copy02 copy02,0,>,copy02
copy12,Z,>,copy12 copy12,N,>,copy12 copy12, ,>,gotocopy1 copy12,0,>,copy12 copy12,1,>,copy12
copy0,Z,>,copy0 copy0,N,>,copy0 copy0, ,>,paste0 copy0,1,>,copy0 copy0,0,>,copy0
copy1,Z,>,copy1 copy1,N,>,copy1 copy1, ,>,paste1 copy1,0,>,copy1 copy1,1,>,copy1
paste0,0,>,paste0 paste0,1,>,paste0 paste0, ,0,movetocopy
paste1,0,>,paste1 paste1,1,>,paste1 paste1, ,1,movetocopy
gotocopy0,0,>,gotocopy0 gotocopy0,1,>,gotocopy0 gotocopy0, ,>,paste02
gotocopy1,0,>,gotocopy1 gotocopy1,1,>,gotocopy1 gotocopy1, ,>,paste12
paste02,0,>,paste02 paste02,1,>,paste02 paste02, ,0,gothrowcopy
paste12,0,>,paste12 paste12,1,>,paste12 paste12, ,1,gothrowcopy
gothrowcopy,1,<,gothrowcopy gothrowcopy,0,<,gothrowcopy gothrowcopy, ,<,movetocopy
movetocopy,1,<,movetocopy movetocopy,0,<,movetocopy movetocopy, ,<,movetoend1
gotostart1,Z,0,gotostart1 gotostart1,N,1,gotostart1 gotostart1,1,>,gotostart1 gotostart1,0,>,gotostart1 gotostart1, ,>,gotostart2
gotostart2,Z,0,gotostart2 gotostart2,N,1,gotostart2 gotostart2,1,>,gotostart2 gotostart2,0,>,gotostart2 gotostart2, ,>,gotostart3
gotostart3,1,>,gotostart3 gotostart3,0,>,gotostart3 gotostart3, ,>,gotostart4
gotostart4,1,>,gotostart4 gotostart4,0,>,gotostart4 gotostart4, ,#,gotostart4
