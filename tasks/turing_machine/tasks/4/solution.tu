// Решите поставленную задачу в формате четвёрок
Идея: Задача простая: сложить два двоичных числа без знака. Исходные числа должны остаться на ленте как были, а сумму надо записать справа от них. Складываем столбиком, как обычно, только цифры тут 0 и 1. Сначала на ленте лежат два числа, между ними пустая ячейка. Головка стоит на пустой ячейке справа от второго числа. Например: 1011 101. Тут 1011 — первое число, 101 — второе. После работы должно получиться: 1011 101 10000. То есть 11 + 5 = 16, а 16 в двоичной системе это 10000. Складывать удобнее с конца, то есть с младших разрядов. В двоичной системе вариантов немного: 0+0 даёт 0, 0+1 и 1+0 дают 1, а 1+1 даёт 0 и перенос 1. Ещё надо помнить про перенос от предыдущего разряда. Если складываем 1+1+1, то получается 1 и перенос 1 дальше. Машина сначала идёт к последней цифре второго числа. Запоминает её и временно помечает: x — если там был 0, y — если была 1. Потом идёт влево, к первому числу. Находит его последний ещё не обработанный разряд, тоже помечает и складывает две цифры с учётом переноса. Чтобы помнить перенос, используются состояния с окончанием c0 и c1. c0 — переноса нет, c1 — перенос есть. Результат сложения и новый перенос машина запоминает в состоянии. Потом возвращается вправо, в область результата, и пишет туда очередной бит. Затем снова идёт к исходным числам и обрабатывает следующий разряд. Если числа разной длины, ничего страшного. Просто для отсутствующего разряда считается, что там 0. Если после всех разрядов остался перенос, его тоже записывают в результат. Есть один момент: машина пишет результат с младшего разряда вправо, поэтому сумма сначала получается в обратном порядке. Например, 1000 сначала запишется как 0001. Потом отдельным этапом машина разворачивает результат, используя временные символы u, v, x и y. В конце исходные числа восстанавливаются: x заменяются на 0, y — на 1. Временные отметки убираются. На ленте остаются оба исходных числа и готовая сумма. Головка доходит до пустой ячейки справа от результата и останавливается. Главное тут то, что исходные числа не стираются. Они только временно помечаются, чтобы машина понимала, что уже обработано. Поэтому в конце на ленте одновременно лежат и оба числа, и их сумма.
Код:
q0, ,<,b_c0
b_c0,x,<,b_c0
b_c0,y,<,b_c0
b_c0,0,x,b_mark_0_c0
b_c0,1,y,b_mark_1_c0
b_c0, ,<,a_b0_av0_c0
b_mark_0_c0,x,<,b_to_sep_b0_c0
b_mark_0_c0,y,<,b_to_sep_b0_c0
b_to_sep_b0_c0,0,<,b_to_sep_b0_c0
b_to_sep_b0_c0,1,<,b_to_sep_b0_c0
b_to_sep_b0_c0,x,<,b_to_sep_b0_c0
b_to_sep_b0_c0,y,<,b_to_sep_b0_c0
b_to_sep_b0_c0, ,<,a_b0_av1_c0
b_mark_1_c0,x,<,b_to_sep_b1_c0
b_mark_1_c0,y,<,b_to_sep_b1_c0
b_to_sep_b1_c0,0,<,b_to_sep_b1_c0
b_to_sep_b1_c0,1,<,b_to_sep_b1_c0
b_to_sep_b1_c0,x,<,b_to_sep_b1_c0
b_to_sep_b1_c0,y,<,b_to_sep_b1_c0
b_to_sep_b1_c0, ,<,a_b1_av1_c0
b_c1,x,<,b_c1
b_c1,y,<,b_c1
b_c1,0,x,b_mark_0_c1
b_c1,1,y,b_mark_1_c1
b_c1, ,<,a_b0_av0_c1
b_mark_0_c1,x,<,b_to_sep_b0_c1
b_mark_0_c1,y,<,b_to_sep_b0_c1
b_to_sep_b0_c1,0,<,b_to_sep_b0_c1
b_to_sep_b0_c1,1,<,b_to_sep_b0_c1
b_to_sep_b0_c1,x,<,b_to_sep_b0_c1
b_to_sep_b0_c1,y,<,b_to_sep_b0_c1
b_to_sep_b0_c1, ,<,a_b0_av1_c1
b_mark_1_c1,x,<,b_to_sep_b1_c1
b_mark_1_c1,y,<,b_to_sep_b1_c1
b_to_sep_b1_c1,0,<,b_to_sep_b1_c1
b_to_sep_b1_c1,1,<,b_to_sep_b1_c1
b_to_sep_b1_c1,x,<,b_to_sep_b1_c1
b_to_sep_b1_c1,y,<,b_to_sep_b1_c1
b_to_sep_b1_c1, ,<,a_b1_av1_c1
a_b0_av0_c0,x,<,a_b0_av0_c0
a_b0_av0_c0,y,<,a_b0_av0_c0
a_b0_av0_c0,0,x,a_mark_r0_co0
a_b0_av0_c0,1,y,a_mark_r1_co0
a_b0_av0_c0, ,>,restore_A
a_b0_av0_c1,x,<,a_b0_av0_c1
a_b0_av0_c1,y,<,a_b0_av0_c1
a_b0_av0_c1,0,x,a_mark_r1_co0
a_b0_av0_c1,1,y,a_mark_r0_co1
a_b0_av0_c1, ,>,retA_final
a_b0_av1_c0,x,<,a_b0_av1_c0
a_b0_av1_c0,y,<,a_b0_av1_c0
a_b0_av1_c0,0,x,a_mark_r0_co0
a_b0_av1_c0,1,y,a_mark_r1_co0
a_b0_av1_c0, ,>,retA_r0_co0
a_b0_av1_c1,x,<,a_b0_av1_c1
a_b0_av1_c1,y,<,a_b0_av1_c1
a_b0_av1_c1,0,x,a_mark_r1_co0
a_b0_av1_c1,1,y,a_mark_r0_co1
a_b0_av1_c1, ,>,retA_r1_co0
a_b1_av0_c0,x,<,a_b1_av0_c0
a_b1_av0_c0,y,<,a_b1_av0_c0
a_b1_av0_c0,0,x,a_mark_r1_co0
a_b1_av0_c0,1,y,a_mark_r0_co1
a_b1_av0_c0, ,>,retA_r1_co0
a_b1_av0_c1,x,<,a_b1_av0_c1
a_b1_av0_c1,y,<,a_b1_av0_c1
a_b1_av0_c1,0,x,a_mark_r0_co1
a_b1_av0_c1,1,y,a_mark_r1_co1
a_b1_av0_c1, ,>,retA_r0_co1
a_b1_av1_c0,x,<,a_b1_av1_c0
a_b1_av1_c0,y,<,a_b1_av1_c0
a_b1_av1_c0,0,x,a_mark_r1_co0
a_b1_av1_c0,1,y,a_mark_r0_co1
a_b1_av1_c0, ,>,retA_r1_co0
a_b1_av1_c1,x,<,a_b1_av1_c1
a_b1_av1_c1,y,<,a_b1_av1_c1
a_b1_av1_c1,0,x,a_mark_r0_co1
a_b1_av1_c1,1,y,a_mark_r1_co1
a_b1_av1_c1, ,>,retA_r0_co1
a_mark_r0_co0,x,>,retA_r0_co0
a_mark_r0_co0,y,>,retA_r0_co0
a_mark_r0_co1,x,>,retA_r0_co1
a_mark_r0_co1,y,>,retA_r0_co1
a_mark_r1_co0,x,>,retA_r1_co0
a_mark_r1_co0,y,>,retA_r1_co0
a_mark_r1_co1,x,>,retA_r1_co1
a_mark_r1_co1,y,>,retA_r1_co1
retA_r0_co0,0,>,retA_r0_co0
retB_r0_co0,0,>,retB_r0_co0
retA_r0_co0,1,>,retA_r0_co0
retB_r0_co0,1,>,retB_r0_co0
retA_r0_co0,x,>,retA_r0_co0
retB_r0_co0,x,>,retB_r0_co0
retA_r0_co0,y,>,retA_r0_co0
retB_r0_co0,y,>,retB_r0_co0
retA_r0_co0, ,>,retB_r0_co0
retB_r0_co0, ,>,retOut_r0_co0
retOut_r0_co0,0,>,retOut_r0_co0
retOut_r0_co0,1,>,retOut_r0_co0
retOut_r0_co0, ,0,next_c0
retA_r0_co1,0,>,retA_r0_co1
retB_r0_co1,0,>,retB_r0_co1
retA_r0_co1,1,>,retA_r0_co1
retB_r0_co1,1,>,retB_r0_co1
retA_r0_co1,x,>,retA_r0_co1
retB_r0_co1,x,>,retB_r0_co1
retA_r0_co1,y,>,retA_r0_co1
retB_r0_co1,y,>,retB_r0_co1
retA_r0_co1, ,>,retB_r0_co1
retB_r0_co1, ,>,retOut_r0_co1
retOut_r0_co1,0,>,retOut_r0_co1
retOut_r0_co1,1,>,retOut_r0_co1
retOut_r0_co1, ,0,next_c1
retA_r1_co0,0,>,retA_r1_co0
retB_r1_co0,0,>,retB_r1_co0
retA_r1_co0,1,>,retA_r1_co0
retB_r1_co0,1,>,retB_r1_co0
retA_r1_co0,x,>,retA_r1_co0
retB_r1_co0,x,>,retB_r1_co0
retA_r1_co0,y,>,retA_r1_co0
retB_r1_co0,y,>,retB_r1_co0
retA_r1_co0, ,>,retB_r1_co0
retB_r1_co0, ,>,retOut_r1_co0
retOut_r1_co0,0,>,retOut_r1_co0
retOut_r1_co0,1,>,retOut_r1_co0
retOut_r1_co0, ,1,next_c0
retA_r1_co1,0,>,retA_r1_co1
retB_r1_co1,0,>,retB_r1_co1
retA_r1_co1,1,>,retA_r1_co1
retB_r1_co1,1,>,retB_r1_co1
retA_r1_co1,x,>,retA_r1_co1
retB_r1_co1,x,>,retB_r1_co1
retA_r1_co1,y,>,retA_r1_co1
retB_r1_co1,y,>,retB_r1_co1
retA_r1_co1, ,>,retB_r1_co1
retB_r1_co1, ,>,retOut_r1_co1
retOut_r1_co1,0,>,retOut_r1_co1
retOut_r1_co1,1,>,retOut_r1_co1
retOut_r1_co1, ,1,next_c1
next_c0,0,<,back_output_c0
next_c0,1,<,back_output_c0
back_output_c0,0,<,back_output_c0
back_output_c0,1,<,back_output_c0
back_output_c0, ,<,b_c0
next_c1,0,<,back_output_c1
next_c1,1,<,back_output_c1
back_output_c1,0,<,back_output_c1
back_output_c1,1,<,back_output_c1
back_output_c1, ,<,b_c1
retA_final,0,>,retA_final
retA_final,1,>,retA_final
retA_final,x,>,retA_final
retA_final,y,>,retA_final
retA_final, ,>,retB_final
retB_final,0,>,retB_final
retB_final,1,>,retB_final
retB_final,x,>,retB_final
retB_final,y,>,retB_final
retB_final, ,>,retOut_final
retOut_final,0,>,retOut_final
retOut_final,1,>,retOut_final
retOut_final, ,1,finish_carry
finish_carry,1,<,finish_out_left
finish_out_left,0,<,finish_out_left
finish_out_left,1,<,finish_out_left
finish_out_left, ,<,finish_B_left
finish_B_left,0,<,finish_B_left
finish_B_left,1,<,finish_B_left
finish_B_left,x,<,finish_B_left
finish_B_left,y,<,finish_B_left
finish_B_left, ,<,finish_A_left
finish_A_left,0,<,finish_A_left
finish_A_left,1,<,finish_A_left
finish_A_left,x,<,finish_A_left
finish_A_left,y,<,finish_A_left
finish_A_left, ,>,restore_A
restore_A,x,0,restore_A0
restore_A,y,1,restore_A1
restore_A,0,>,restore_A
restore_A,1,>,restore_A
restore_A, ,>,restore_B
restore_A0,0,>,restore_A
restore_A1,1,>,restore_A
restore_B,x,0,restore_B0
restore_B,y,1,restore_B1
restore_B,0,>,restore_B
restore_B,1,>,restore_B
restore_B, ,>,rev_seek_left
restore_B0,0,>,restore_B
restore_B1,1,>,restore_B
rev_seek_left,x,>,rev_seek_left
rev_seek_left,y,>,rev_seek_left
rev_seek_left,0,u,rev_after_left0
rev_seek_left,1,v,rev_after_left1
rev_seek_left, ,<,rev_restore
rev_after_left0,u,>,rev_go_end0
rev_after_left1,v,>,rev_go_end1
rev_go_end0,0,>,rev_go_end0
rev_go_end0,1,>,rev_go_end0
rev_go_end0,x,>,rev_go_end0
rev_go_end0,y,>,rev_go_end0
rev_go_end0,u,>,rev_go_end0
rev_go_end0,v,>,rev_go_end0
rev_go_end0, ,<,rev_find_right0
rev_find_right0,x,<,rev_find_right0
rev_find_right0,y,<,rev_find_right0
rev_find_right0,0,<,rev_find_left0_d0
rev_find_right0,1,<,rev_find_left0_d1
rev_find_right0,u,x,rev_cleanup_to_end
rev_find_right0,v,y,rev_cleanup_to_end
rev_find_left0_d0,0,<,rev_find_left0_d0
rev_find_left0_d0,1,<,rev_find_left0_d0
rev_find_left0_d0,x,<,rev_find_left0_d0
rev_find_left0_d0,y,<,rev_find_left0_d0
rev_find_left0_d0,u,x,rev_go_end2_0
rev_find_left0_d0,v,x,rev_go_end2_0
rev_find_left0_d1,0,<,rev_find_left0_d1
rev_find_left0_d1,1,<,rev_find_left0_d1
rev_find_left0_d1,x,<,rev_find_left0_d1
rev_find_left0_d1,y,<,rev_find_left0_d1
rev_find_left0_d1,u,y,rev_go_end2_0
rev_find_left0_d1,v,y,rev_go_end2_0
rev_go_end2_0,0,>,rev_go_end2_0
rev_go_end2_0,1,>,rev_go_end2_0
rev_go_end2_0,x,>,rev_go_end2_0
rev_go_end2_0,y,>,rev_go_end2_0
rev_go_end2_0, ,<,rev_mark_right0
rev_mark_right0,x,<,rev_mark_right0
rev_mark_right0,y,<,rev_mark_right0
rev_mark_right0,0,x,rev_round_end
rev_mark_right0,1,x,rev_round_end
rev_go_end1,0,>,rev_go_end1
rev_go_end1,1,>,rev_go_end1
rev_go_end1,x,>,rev_go_end1
rev_go_end1,y,>,rev_go_end1
rev_go_end1,u,>,rev_go_end1
rev_go_end1,v,>,rev_go_end1
rev_go_end1, ,<,rev_find_right1
rev_find_right1,x,<,rev_find_right1
rev_find_right1,y,<,rev_find_right1
rev_find_right1,0,<,rev_find_left1_d0
rev_find_right1,1,<,rev_find_left1_d1
rev_find_right1,u,x,rev_cleanup_to_end
rev_find_right1,v,y,rev_cleanup_to_end
rev_find_left1_d0,0,<,rev_find_left1_d0
rev_find_left1_d0,1,<,rev_find_left1_d0
rev_find_left1_d0,x,<,rev_find_left1_d0
rev_find_left1_d0,y,<,rev_find_left1_d0
rev_find_left1_d0,u,x,rev_go_end2_1
rev_find_left1_d0,v,x,rev_go_end2_1
rev_find_left1_d1,0,<,rev_find_left1_d1
rev_find_left1_d1,1,<,rev_find_left1_d1
rev_find_left1_d1,x,<,rev_find_left1_d1
rev_find_left1_d1,y,<,rev_find_left1_d1
rev_find_left1_d1,u,y,rev_go_end2_1
rev_find_left1_d1,v,y,rev_go_end2_1
rev_go_end2_1,0,>,rev_go_end2_1
rev_go_end2_1,1,>,rev_go_end2_1
rev_go_end2_1,x,>,rev_go_end2_1
rev_go_end2_1,y,>,rev_go_end2_1
rev_go_end2_1, ,<,rev_mark_right1
rev_mark_right1,x,<,rev_mark_right1
rev_mark_right1,y,<,rev_mark_right1
rev_mark_right1,0,y,rev_round_end
rev_mark_right1,1,y,rev_round_end
rev_round_end,x,>,rev_go_output_end
rev_round_end,y,>,rev_go_output_end
rev_go_output_end,0,>,rev_go_output_end
rev_go_output_end,1,>,rev_go_output_end
rev_go_output_end,x,>,rev_go_output_end
rev_go_output_end,y,>,rev_go_output_end
rev_go_output_end, ,<,rev_return_boundary
rev_return_boundary,0,<,rev_return_boundary
rev_return_boundary,1,<,rev_return_boundary
rev_return_boundary,x,<,rev_return_boundary
rev_return_boundary,y,<,rev_return_boundary
rev_return_boundary, ,>,rev_seek_left
rev_cleanup_to_end,0,>,rev_cleanup_to_end
rev_cleanup_to_end,1,>,rev_cleanup_to_end
rev_cleanup_to_end,x,>,rev_cleanup_to_end
rev_cleanup_to_end,y,>,rev_cleanup_to_end
rev_cleanup_to_end, ,<,rev_restore
rev_restore,x,0,rev_restore0
rev_restore,y,1,rev_restore1
rev_restore,0,<,rev_restore
rev_restore,1,<,rev_restore
rev_restore, ,>,final_go_end
rev_restore0,0,<,rev_restore
rev_restore1,1,<,rev_restore
final_go_end,0,>,final_go_end
final_go_end,1,>,final_go_end
final_go_end, ,#,halt