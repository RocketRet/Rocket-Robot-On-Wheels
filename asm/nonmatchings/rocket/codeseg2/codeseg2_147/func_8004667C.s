.globl func_8004667C
.ent func_8004667C
func_8004667C:
  addiu      $sp, $sp, -0x30
  addu       $25, $4, $0
  addu       $14, $6, $0
  addu       $12, $0, $0
  addu       $11, $12, $0
  addu       $8, $5, $0
  sw         $21, 0x24($sp)
  lw         $21, 0x44($sp)
  addu       $10, $11, $0
  sw         $18, 0x18($sp)
  lw         $18, 0x48($sp)
  addu       $24, $10, $0
  sw         $20, 0x20($sp)
  addiu      $20, $0, -1
  sw         $19, 0x1c($sp)
  addiu      $19, $0, 0x25
  sw         $17, 0x14($sp)
  lw         $17, 0x4c($sp)
  lui        $15, 0x6666
  sw         $22, 0x28($sp)
  sw         $16, 0x10($sp)
  lw         $9, 0x34($25)
  lw         $16, 0x40($sp)
  ori        $15, $15, 0x6667
  sh         $7, 4($25)
  sll        $2, $16, 4
  sh         $2, 6($25)
.L800466E8:
  slt        $2, $24, $16
  beqz       $2, .L800469E8
   addu      $13, $0, $0
.L800466F4:
  slt        $2, $7, $13
  bnez       $2, .L80046930
   slti      $2, $11, 0x3c0
  beqz       $2, .L80046A20
   addiu     $2, $0, 0x3c0
.L80046708:
  lbu        $2, ($8)
  bnez       $2, .L80046758
   nop
.L80046714:
  beqz       $12, .L80046728
   nop
  addu       $8, $12, $0
  j          .L80046708
   addu      $12, $0, $0
.L80046728:
  lw         $2, 8($14)
  lw         $3, ($2)
  lw         $4, 4($2)
  lw         $5, 8($2)
  lw         $6, 0xc($2)
  sw         $3, ($9)
  sw         $4, 4($9)
  sw         $5, 8($9)
  sw         $6, 0xc($9)
  sh         $20, ($9)
  j          .L800469F0
   sh        $11, 0x28($25)
.L80046758:
  bne        $2, $19, .L8004688C
   nop
  addiu      $8, $8, 1
  lbu        $3, ($8)
  slti       $2, $3, 0x46
  beqz       $2, .L80046880
   slti      $2, $3, 0x41
  bnez       $2, .L80046880
   sll       $2, $3, 2
  addu       $2, $2, $17
  lw         $5, -0x104($2)
  addiu      $6, $0, 0x64
  div        $5, $6
  bnez       $6, .L80046798
   nop
  .word 0x0007000D
.L80046798:
   addiu     $1, $0, -1
  bne        $6, $1, .L800467B0
   lui       $1, 0x8000
  bne        $5, $1, .L800467B0
   nop
  .word 0x0006000D
.L800467B0:
   mflo      $2
  addiu      $12, $8, 1
  bnez       $2, .L80046818
   addu      $8, $sp, $0
  mult       $6, $15
.L800467C4:
  sra        $2, $6, 0x1f
  mfhi       $22
  sra        $3, $22, 2
  subu       $6, $3, $2
  slti       $2, $6, 2
  bnez       $2, .L80046818
   nop
  div        $5, $6
  bnez       $6, .L800467F0
   nop
  .word 0x0007000D
.L800467F0:
   addiu     $1, $0, -1
  bne        $6, $1, .L80046808
   lui       $1, 0x8000
  bne        $5, $1, .L80046808
   nop
  .word 0x0006000D
.L80046808:
   mflo      $2
  nop
  #  mult      $6, $15
  .word 0x1040FFEC
  # beqz       $2, .L800467C4
   .word 0x00CF0018
.L80046818:
  # div        $5, $6
  .word 0x00A6001A
  bnez       $6, .L80046828
   nop
  .word 0x0007000D
.L80046828:
   addiu     $1, $0, -1
  bne        $6, $1, .L80046840
   lui       $1, 0x8000
  bne        $5, $1, .L80046840
   nop
  .word 0x0006000D
.L80046840:
   mflo      $4
  mfhi       $5
  nop
  nop
  mult       $6, $15
  sra        $2, $6, 0x1f
  mfhi       $22
  sra        $3, $22, 2
  subu       $6, $3, $2
  addiu      $4, $4, 0x30
  sb         $4, ($8)
  bnez       $6, .L80046818
   addiu     $8, $8, 1
  sb         $0, ($8)
  j          .L80046708
   addu      $8, $sp, $0
.L80046880:
  lbu        $2, ($8)
  beqz       $2, .L80046714
   nop
.L8004688C:
  lw         $2, ($14)
  lbu        $4, ($8)
  lw         $2, ($2)
  sltu       $2, $4, $2
  beqz       $2, .L800468E8
   sll       $2, $4, 2
  lw         $3, 4($14)
  addu       $2, $2, $3
  lw         $2, ($2)
  bltz       $2, .L800468E8
   sll       $2, $2, 4
  addiu      $10, $10, 1
  lw         $3, 8($14)
  addu       $2, $2, $3
  lw         $3, ($2)
  lw         $4, 4($2)
  lw         $5, 8($2)
  lw         $6, 0xc($2)
  sw         $3, ($9)
  sw         $4, 4($9)
  sw         $5, 8($9)
  j          .L80046918
   sw        $6, 0xc($9)
.L800468E8:
  lw         $2, 8($14)
  lw         $3, ($2)
  lw         $4, 4($2)
  lw         $5, 8($2)
  lw         $6, 0xc($2)
  sw         $3, ($9)
  sw         $4, 4($9)
  sw         $5, 8($9)
  sw         $6, 0xc($9)
  addiu      $2, $0, 6
  sw         $0, 8($9)
  sh         $2, ($9)
.L80046918:
  addiu      $8, $8, 1
  lh         $2, ($9)
  addiu      $9, $9, 0x10
  addiu      $11, $11, 1
  j          .L800466F4
   addu      $13, $13, $2
.L80046930:
  addiu      $8, $8, -1
  addiu      $9, $9, -0x10
  beqz       $12, .L80046974
   subu      $4, $7, $13
  sltu       $2, $8, $sp
  bnel       $2, $0, .L80046970
   addiu     $8, $12, -3
.L8004694C:
  addiu      $8, $8, -1
  lh         $2, ($9)
  addiu      $9, $9, -0x10
  addiu      $11, $11, -1
  addu       $4, $4, $2
  sltu       $2, $8, $sp
  beqz       $2, .L8004694C
   addiu     $10, $10, -1
  addiu      $8, $12, -3
.L80046970:
  addu       $12, $0, $0
.L80046974:
  lbu        $3, ($8)
  addiu      $2, $0, 0x20
  bnel       $3, $2, .L800469A4
   addiu     $10, $10, -1
  lhu        $2, ($9)
  addu       $2, $2, $4
  sh         $2, ($9)
  sll        $2, $2, 0x10
  bgtz       $2, .L800469DC
   addiu     $8, $8, 1
  j          .L800469E0
   addiu     $11, $11, -1
.L800469A4:
  addiu      $5, $0, 0x20
.L800469A8:
  addiu      $8, $8, -1
  lh         $3, ($9)
  addiu      $10, $10, -1
  sw         $0, 8($9)
  addiu      $9, $9, -0x10
  addiu      $11, $11, -1
  lbu        $2, ($8)
  bne        $2, $5, .L800469A8
   addu      $4, $4, $3
  lhu        $2, ($9)
  addiu      $8, $8, 1
  addu       $2, $2, $4
  sh         $2, ($9)
.L800469DC:
  addiu      $9, $9, 0x10
.L800469E0:
  j          .L800466E8
   addiu     $24, $24, 1
.L800469E8:
  sh         $11, 0x28($25)
  addiu      $24, $24, -1
.L800469F0:
  bnel       $21, $0, .L800469F8
   sw        $8, ($21)
.L800469F8:
  beqz       $18, .L80046A68
   addiu     $2, $24, 1
  lw         $3, ($18)
  bltz       $3, .L80046A64
   slt       $2, $3, $10
  bnel       $2, $0, .L80046A28
   subu      $10, $10, $3
  subu       $2, $3, $10
  j          .L80046A64
   sw        $2, ($18)
.L80046A20:
  j          .L800469F0
   sh        $2, 0x28($25)
.L80046A28:
  lh         $2, 0x28($25)
  lw         $3, 0x34($25)
  sll        $2, $2, 4
  addiu      $2, $2, -0x10
  blez       $10, .L80046A60
   addu      $9, $3, $2
  addiu      $3, $9, 8
.L80046A44:
  lw         $2, ($3)
  beqz       $2, .L80046A58
   nop
  sw         $0, ($3)
  addiu      $10, $10, -1
.L80046A58:
  bgtz       $10, .L80046A44
   addiu     $3, $3, -0x10
.L80046A60:
  sw         $0, ($18)
.L80046A64:
  addiu      $2, $24, 1
.L80046A68:
  lw         $22, 0x28($sp)
  lw         $21, 0x24($sp)
  lw         $20, 0x20($sp)
  lw         $19, 0x1c($sp)
  lw         $18, 0x18($sp)
  lw         $17, 0x14($sp)
  lw         $16, 0x10($sp)
  addiu      $sp, $sp, 0x30
  jr         $31
   nop
.end func_8004667C
