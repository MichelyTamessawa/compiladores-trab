; ModuleID = 'test.s'
source_filename = "test.s"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @main() {
main:
  %c = alloca i32, align 4
  %b = alloca i32, align 4
  %b1 = load i32, i32* %b, align 4
  store i32 10, i32* %b, align 4
  %c2 = load i32, i32* %c, align 4
  store i32 0, i32* %c, align 4
  call void @imprimei(i32 20)
  call void @imprimei(i32 10)
  store i32 7, i32* %c, align 4
  call void @imprimei(i32 7)
  store i32 6, i32* %c, align 4
  call void @imprimei(i32 6)
  store i32 4, i32* %c, align 4
  call void @imprimei(i32 4)
  store i32 10, i32* %c, align 4
  call void @imprimei(i32 10)
  ret void
}

declare void @imprimei(i32)
