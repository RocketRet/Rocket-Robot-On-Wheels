.globl func_80075CC8
.ent func_80075CC8
func_80075CC8:
  addiu      $sp, $sp, -0x38
  sw         $18, 0x18($sp)
  addu       $18, $4, $0
  sw         $31, 0x28($sp)
  sw         $21, 0x24($sp)
  sw         $20, 0x20($sp)
  sw         $19, 0x1c($sp)
  sw         $17, 0x14($sp)
  sw         $16, 0x10($sp)
  sdc1       $f20, 0x30($sp)
  lwc1       $f2, 0x54($18)
  lui        $1, %hi(D_8001CE4C)
  lwc1       $f0, %lo(D_8001CE4C)($1)
  mul.s      $f0, $f2, $f0
  mtc1       $5, $f20
  trunc.w.s  $f4, $f2
  mfc1       $16, $f4
  lw         $2, 0x4c($18)
  trunc.w.s  $f2, $f0
  mfc1       $17, $f2
  beq        $16, $2, .L80075D4C
   addiu     $2, $0, 2
  lw         $3, 0x48($18)
  bne        $3, $2, .L80075D50
   lui       $2, 0x800a
  andi       $2, $16, 1
  beqz       $2, .L80075D3C
   addiu     $4, $0, 0x2b
  addiu      $4, $0, 0x20
.L80075D3C:
  addu       $5, $0, $0
  addiu      $6, $0, 0x80
  jal        play_sound
   addu      $7, $6, $0
.L80075D4C:
  lui        $2, %hi(D_8009FE10)
.L80075D50:
  sw         $16, 0x4c($18)
  lw         $2, %lo(D_8009FE10)($2)
  beqz       $2, .L80075DC0
   addiu     $2, $0, 2
  lw         $3, 0x48($18)
  bne        $3, $2, .L80075DC4
   addu      $4, $0, $0
  lui        $2, %hi(D_800A6378)
  lw         $2, %lo(D_800A6378)($2)
  andi       $2, $2, 2
  beqz       $2, .L80075DC4
   nop
  lwc1       $f0, 0x54($18)
  sub.s      $f0, $f0, $f20
  mtc1       $0, $f2
  c.le.s     $f0, $f2
  nop
  bc1f       .L80075DC4
   swc1      $f0, 0x54($18)
  swc1       $f2, 0x54($18)
  addiu      $4, $0, 0x21
  addu       $5, $0, $0
  addiu      $6, $0, 0x80
  jal        play_sound
   addu      $7, $6, $0
  addu       $4, $18, $0
  jal        func_80076734
   addu      $5, $0, $0
.L80075DC0:
  addu       $4, $0, $0
.L80075DC4:
  lwc1       $f4, 0x54($18)
  lui        $1, %hi(D_8001CE50)
  ldc1       $f2, %lo(D_8001CE50)($1)
  cvt.d.s    $f0, $f4
  c.lt.d     $f0, $f2
  nop
  bc1f       .L80075E50
   addu      $13, $4, $0
  mul.d      $f0, $f0, $f2
  trunc.w.d  $f2, $f0
  mfc1       $2, $f2
  beq        $2, $17, .L80075E50
   addiu     $2, $0, 3
  lw         $3, 0x48($18)
  beq        $3, $2, .L80075E50
   lui       $2, 0x6666
  lui        $1, %hi(D_8001CE58)
  lwc1       $f0, %lo(D_8001CE58)($1)
  mul.s      $f0, $f4, $f0
  ori        $2, $2, 0x6667
  trunc.w.s  $f2, $f0
  mfc1       $17, $f2
  mult       $17, $2
  addiu      $21, $0, 0xc
  addiu      $13, $0, 1
  addu       $4, $13, $0
  sra        $2, $17, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $20, $3, $2
  sll        $2, $20, 2
  addu       $2, $2, $20
  sll        $2, $2, 1
  j          .L80075EE8
   subu      $19, $17, $2
.L80075E50:
  lwc1       $f0, 0x54($18)
  trunc.w.s  $f2, $f0
  mfc1       $2, $f2
  bne        $2, $16, .L80075EAC
   lui       $2, 0x8888
  lw         $3, 0x48($18)
  addiu      $2, $0, 1
  bne        $3, $2, .L80075EA0
   addiu     $2, $0, 3
  lui        $2, %hi(D_8009FE14)
  lwc1       $f0, %lo(D_8009FE14)($2)
  lwc1       $f2, 0x50($18)
  sub.s      $f0, $f0, $f2
  lui        $1, %hi(D_8001CE5C)
  lwc1       $f2, %lo(D_8001CE5C)($1)
  c.le.s     $f0, $f2
  nop
  bc1t       .L80075EA8
   lui       $2, 0x8888
  addiu      $2, $0, 3
.L80075EA0:
  bne        $3, $2, .L80075EE8
   lui       $2, 0x8888
.L80075EA8:
  lwc1       $f0, 0x54($18)
.L80075EAC:
  ori        $2, $2, 0x8889
  trunc.w.s  $f2, $f0
  mfc1       $16, $f2
  mult       $16, $2
  addiu      $21, $0, 0xb
  addiu      $4, $0, 1
  sra        $3, $16, 0x1f
  mfhi       $14
  addu       $2, $14, $16
  sra        $2, $2, 5
  subu       $20, $2, $3
  sll        $2, $20, 4
  subu       $2, $2, $20
  sll        $2, $2, 2
  subu       $19, $16, $2
.L80075EE8:
  beqz       $4, .L80076584
   lui       $3, %hi(D_800AC1C8)
  lw         $2, 0xc($18)
  addiu      $5, $2, 0x10
  lw         $2, -0x10($5)
  addiu      $3, $3, %lo(D_800AC1C8)
  sll        $2, $2, 2
  addu       $2, $2, $3
  lw         $2, ($2)
  lw         $7, -0xc($5)
  beqz       $2, .L80075F28
   addu      $6, $20, $0
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $7, $7, $2
.L80075F28:
  addiu      $4, $0, 0x3e8
  div        $6, $4
  bnez       $4, .L80075F3C
   nop
  .word 0x0007000D
.L80075F3C:
   addiu     $1, $0, -1
  bne        $4, $1, .L80075F54
   lui       $1, 0x8000
  bne        $6, $1, .L80075F54
   nop
  .word 0x0006000D
.L80075F54:
   mflo      $3
  sw         $7, 4($5)
  addu       $8, $7, $0
  lw         $2, -8($5)
  addu       $7, $5, $0
  addu       $10, $2, $0
  bnez       $3, .L80075FD4
   sw        $2, 8($7)
  lui        $5, 0x6666
  ori        $5, $5, 0x6667
  mult       $4, $5
.L80075F80:
  sra        $2, $4, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $4, $3, $2
  slti       $2, $4, 2
  bnez       $2, .L80075FD8
   addiu     $12, $0, 1
  div        $6, $4
  bnez       $4, .L80075FAC
   nop
  .word 0x0007000D
.L80075FAC:
   addiu     $1, $0, -1
  bne        $4, $1, .L80075FC4
   lui       $1, 0x8000
  bne        $6, $1, .L80075FC4
   nop
  .word 0x0006000D
.L80075FC4:
   mflo      $3
  nop
  .word 0x1060FFEC
  # beqz       $3, .L80075F80
   .word 0x00850018
  #  mult      $4, $5
.L80075FD4:
  addiu      $12, $0, 1
.L80075FD8:
  lui        $2, %hi(D_800AC1C8)
  addiu      $11, $2, %lo(D_800AC1C8)
  lui        $9, 0x6666
  ori        $9, $9, 0x6667
  addiu      $5, $7, 0xc
.L80075FEC:
  div        $6, $4
  bnez       $4, .L80075FFC
   nop
  .word 0x0007000D
.L80075FFC:
   addiu     $1, $0, -1
  bne        $4, $1, .L80076014
   lui       $1, 0x8000
  bne        $6, $1, .L80076014
   nop
  .word 0x0006000D
.L80076014:
   mflo      $2
  mfhi       $3
  sw         $2, ($7)
  sw         $8, -8($5)
  sw         $10, -4($5)
  sw         $12, ($5)
  lw         $2, ($7)
  sll        $2, $2, 2
  addu       $2, $2, $11
  lw         $2, ($2)
  mult       $4, $9
  beqz       $2, .L80076058
   nop
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $8, $8, $2
.L80076058:
  addu       $6, $3, $0
  addiu      $5, $5, 0x10
  sra        $2, $4, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $4, $3, $2
  bnez       $4, .L80075FEC
   addiu     $7, $7, 0x10
  lw         $2, 8($18)
  lw         $3, 0xc($18)
  sll        $2, $2, 4
  addu       $3, $3, $2
  sltu       $2, $7, $3
  beqz       $2, .L800760AC
   addu      $4, $7, $0
  addiu      $5, $0, -1
  sw         $5, ($4)
.L8007609C:
  addiu      $4, $4, 0x10
  sltu       $2, $4, $3
  bnel       $2, $0, .L8007609C
   sw        $5, ($4)
.L800760AC:
  addu       $5, $7, $0
  lui        $3, %hi(D_800AC1C8)
  lw         $2, -0x10($5)
  addiu      $4, $3, %lo(D_800AC1C8)
  sw         $21, ($5)
  sll        $2, $2, 2
  addu       $2, $2, $4
  lw         $2, ($2)
  lw         $3, -0xc($5)
  beql       $2, $0, .L800760EC
   sw        $3, 4($5)
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $3, $3, $2
  sw         $3, 4($5)
.L800760EC:
  lw         $3, -8($5)
  addiu      $2, $0, 1
  sw         $2, 0xc($5)
  sw         $3, 8($5)
  addiu      $5, $5, 0x10
  lw         $2, -0x10($5)
  sll        $2, $2, 2
  addu       $2, $2, $4
  lw         $2, ($2)
  lw         $3, -0xc($5)
  beqz       $2, .L8007612C
   nop
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $3, $3, $2
.L8007612C:
  lw         $9, -8($5)
  slti       $2, $19, 0xa
  sw         $3, 4($5)
  beqz       $2, .L80076308
   sw        $9, 8($5)
  bnez       $13, .L8007630C
   addu      $6, $19, $0
  addu       $6, $0, $0
  addiu      $4, $0, 0x3e8
  div        $6, $4
  bnez       $4, .L80076160
   nop
  .word 0x0007000D
.L80076160:
   addiu     $1, $0, -1
  bne        $4, $1, .L80076178
   lui       $1, 0x8000
  bne        $6, $1, .L80076178
   nop
  .word 0x0006000D
.L80076178:
   mflo      $2
  addu       $7, $5, $0
  lw         $8, 4($7)
  bnez       $2, .L800761EC
   addu      $10, $9, $0
  lui        $5, 0x6666
  ori        $5, $5, 0x6667
  mult       $4, $5
.L80076198:
  sra        $2, $4, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $4, $3, $2
  slti       $2, $4, 2
  bnel       $2, $0, .L800761F0
   addiu     $12, $0, 1
  div        $6, $4
  bnez       $4, .L800761C4
   nop
  .word 0x0007000D
.L800761C4:
   addiu     $1, $0, -1
  bne        $4, $1, .L800761DC
   lui       $1, 0x8000
  bne        $6, $1, .L800761DC
   nop
  .word 0x0006000D
.L800761DC:
   mflo      $2
  nop
  .word 0x1040FFEC
  # beqz       $2, .L80076198
   .word 0x00850018
  #  mult      $4, $5
.L800761EC:
  addiu      $12, $0, 1
.L800761F0:
  lui        $2, %hi(D_800AC1C8)
  addiu      $11, $2, %lo(D_800AC1C8)
  lui        $9, 0x6666
  ori        $9, $9, 0x6667
  addiu      $5, $7, 0xc
.L80076204:
  div        $6, $4
  bnez       $4, .L80076214
   nop
  .word 0x0007000D
.L80076214:
   addiu     $1, $0, -1
  bne        $4, $1, .L8007622C
   lui       $1, 0x8000
  bne        $6, $1, .L8007622C
   nop
  .word 0x0006000D
.L8007622C:
   mflo      $2
  mfhi       $3
  sw         $2, ($7)
  sw         $8, -8($5)
  sw         $10, -4($5)
  sw         $12, ($5)
  lw         $2, ($7)
  sll        $2, $2, 2
  addu       $2, $2, $11
  lw         $2, ($2)
  mult       $4, $9
  beqz       $2, .L80076270
   nop
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $8, $8, $2
.L80076270:
  addu       $6, $3, $0
  addiu      $5, $5, 0x10
  sra        $2, $4, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $4, $3, $2
  bnez       $4, .L80076204
   addiu     $7, $7, 0x10
  lw         $2, 8($18)
  lw         $3, 0xc($18)
  sll        $2, $2, 4
  addu       $3, $3, $2
  sltu       $2, $7, $3
  beqz       $2, .L800762C4
   addu      $4, $7, $0
  addiu      $5, $0, -1
  sw         $5, ($4)
.L800762B4:
  addiu      $4, $4, 0x10
  sltu       $2, $4, $3
  bnel       $2, $0, .L800762B4
   sw        $5, ($4)
.L800762C4:
  addu       $5, $7, $0
  lui        $3, %hi(D_800AC1C8)
  lw         $2, -0x10($5)
  addiu      $3, $3, %lo(D_800AC1C8)
  sll        $2, $2, 2
  addu       $2, $2, $3
  lw         $2, ($2)
  lw         $3, -0xc($5)
  beqz       $2, .L800762FC
   nop
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $3, $3, $2
.L800762FC:
  lw         $2, -8($5)
  sw         $3, 4($5)
  sw         $2, 8($5)
.L80076308:
  addu       $6, $19, $0
.L8007630C:
  addiu      $4, $0, 0x3e8
  div        $6, $4
  bnez       $4, .L80076320
   nop
  .word 0x0007000D
.L80076320:
   addiu     $1, $0, -1
  bne        $4, $1, .L80076338
   lui       $1, 0x8000
  bne        $6, $1, .L80076338
   nop
  .word 0x0006000D
.L80076338:
   mflo      $2
  addu       $7, $5, $0
  lw         $8, 4($7)
  lw         $10, 8($7)
  bnel       $2, $0, .L800763B4
   addiu     $12, $0, 1
  lui        $5, 0x6666
  ori        $5, $5, 0x6667
  mult       $4, $5
.L8007635C:
  sra        $2, $4, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $4, $3, $2
  slti       $2, $4, 2
  bnel       $2, $0, .L800763B4
   addiu     $12, $0, 1
  div        $6, $4
  bnez       $4, .L80076388
   nop
  .word 0x0007000D
.L80076388:
   addiu     $1, $0, -1
  bne        $4, $1, .L800763A0
   lui       $1, 0x8000
  bne        $6, $1, .L800763A0
   nop
  .word 0x0006000D
.L800763A0:
   mflo      $2
  nop
  .word 0x1040FFEC
  # beqz       $2, .L8007635C
   .word 0x00850018
  #  mult      $4, $5
  addiu      $12, $0, 1
.L800763B4:
  lui        $2, %hi(D_800AC1C8)
  addiu      $11, $2, %lo(D_800AC1C8)
  lui        $9, 0x6666
  ori        $9, $9, 0x6667
  addiu      $5, $7, 0xc
.L800763C8:
  div        $6, $4
  bnez       $4, .L800763D8
   nop
  .word 0x0007000D
.L800763D8:
   addiu     $1, $0, -1
  bne        $4, $1, .L800763F0
   lui       $1, 0x8000
  bne        $6, $1, .L800763F0
   nop
  .word 0x0006000D
.L800763F0:
   mflo      $2
  mfhi       $3
  sw         $2, ($7)
  sw         $8, -8($5)
  sw         $10, -4($5)
  sw         $12, ($5)
  lw         $2, ($7)
  sll        $2, $2, 2
  addu       $2, $2, $11
  lw         $2, ($2)
  mult       $4, $9
  beqz       $2, .L80076434
   nop
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $8, $8, $2
.L80076434:
  addu       $6, $3, $0
  addiu      $5, $5, 0x10
  sra        $2, $4, 0x1f
  mfhi       $14
  sra        $3, $14, 2
  subu       $4, $3, $2
  bnez       $4, .L800763C8
   addiu     $7, $7, 0x10
  lw         $2, 8($18)
  lw         $3, 0xc($18)
  sll        $2, $2, 4
  addu       $3, $3, $2
  sltu       $2, $7, $3
  beqz       $2, .L80076488
   addu      $4, $7, $0
  addiu      $5, $0, -1
  sw         $5, ($4)
.L80076478:
  addiu      $4, $4, 0x10
  sltu       $2, $4, $3
  bnel       $2, $0, .L80076478
   sw        $5, ($4)
.L80076488:
  lw         $3, 0x48($18)
  addiu      $2, $0, 3
  bne        $3, $2, .L800764E0
   addu      $5, $7, $0
  lui        $3, %hi(D_800AC1C8)
  addiu      $3, $3, %lo(D_800AC1C8)
  lw         $2, -0x10($5)
  lw         $4, -0xc($5)
  sll        $2, $2, 2
  addu       $2, $2, $3
  lw         $2, ($2)
  lw         $3, 0xc($18)
  beql       $2, $0, .L800764D4
   sw        $4, 4($3)
  lw         $2, 0x24($2)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $4, $4, $2
  sw         $4, 4($3)
.L800764D4:
  lw         $3, 0xc($18)
  lw         $2, -8($5)
  sw         $2, 8($3)
.L800764E0:
  addu       $5, $0, $0
  addu       $6, $5, $0
  addiu      $12, $0, -1
  lui        $2, %hi(D_800AC1C8)
  addiu      $11, $2, %lo(D_800AC1C8)
  lw         $9, 0xc($18)
  lw         $10, 8($18)
  addiu      $8, $9, 8
.L80076500:
  addiu      $10, $10, -1
  bltz       $10, .L8007657C
   nop
  lw         $2, ($9)
  beq        $2, $12, .L80076570
   sll       $2, $2, 2
  addu       $2, $2, $11
  lw         $3, ($2)
  lw         $7, -4($8)
  beqz       $3, .L8007653C
   nop
  lw         $2, 0x24($3)
  lw         $2, ($2)
  lhu        $2, ($2)
  addu       $7, $7, $2
.L8007653C:
  lw         $4, ($8)
  beqz       $3, .L8007655C
   slt       $2, $5, $7
  lw         $2, 0x24($3)
  lw         $2, ($2)
  lhu        $2, 2($2)
  addu       $4, $4, $2
  slt        $2, $5, $7
.L8007655C:
  bnel       $2, $0, .L80076564
   addu      $5, $7, $0
.L80076564:
  slt        $2, $6, $4
  bnel       $2, $0, .L80076570
   addu      $6, $4, $0
.L80076570:
  addiu      $8, $8, 0x10
  j          .L80076500
   addiu     $9, $9, 0x10
.L8007657C:
  jal        func_80077774
   addu      $4, $18, $0
.L80076584:
  lw         $31, 0x28($sp)
  lw         $21, 0x24($sp)
  lw         $20, 0x20($sp)
  lw         $19, 0x1c($sp)
  lw         $18, 0x18($sp)
  lw         $17, 0x14($sp)
  lw         $16, 0x10($sp)
  ldc1       $f20, 0x30($sp)
  addiu      $sp, $sp, 0x38
  jr         $31
   nop
.end func_80075CC8
