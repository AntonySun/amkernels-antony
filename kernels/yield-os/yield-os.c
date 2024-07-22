#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#define STACK_SIZE (4096 * 8)
typedef union {
  uint8_t stack[STACK_SIZE];
  struct { Context *cp; };
} PCB;
static PCB pcb[2], pcb_boot, *current = &pcb_boot;

static void f(void *arg) {
  while (1) {
  
  // printf("arg value: %p\n", (void *)arg) ;
    //for (int volatile i = 0; i < 10000000; i++) ;
    putch("?AB"[(uintptr_t)arg > 2 ? 0 : (uintptr_t)arg]);
   // printf("f0 cp0 value: %p\n", (void *)pcb[0].cp);
    //printf("f0 cp1 value: %p\n", (void *)pcb[1].cp);
   for (int volatile i = 0; i < 10000; i++) ;
   //printf("f cp0 value: %p\n", (void *)pcb[0].cp);
   //printf("f cp1 value: %p\n", (void *)pcb[1].cp);
  //asm volatile("addi sp, sp, 16" : :);
   yield();
   //printf("ABC\n");

  }
}

static Context *schedule(Event ev, Context *prev) {
  //printf("prev value: %p\n", (void *)prev) ;
  current->cp = prev;
  current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
  //printf("s cp0 value: %p\n", (void *)pcb[0].cp);
  //printf("cp0 value: %p\n", (void *)pcb[0].cp);
  //printf("cp1 value: %p\n", (void *)pcb[1].cp);
  //printf("current cp value: %p\n", current->cp);
  return current->cp;
}

int main() {
  cte_init(schedule);
  pcb[0].cp = kcontext((Area) { pcb[0].stack, &pcb[0] + 1 }, f, (void *)1L);
  pcb[1].cp = kcontext((Area) { pcb[1].stack, &pcb[1] + 1 }, f, (void *)2L);
 //printf("cp0 value: %p\n", (void *)pcb[0].cp);
  //printf("cp1 value: %p\n", (void *)pcb[1].cp);
  //printf("pcb0 satck addr is %p\n", (void *)pcb[0].stack);
  //printf("pcb1 satck addr is %p\n", (void *)pcb[1].stack);
  //printf("pc0 addr is %p\n", (void *)&pcb[0]);
  //printf("pc1 addr is %p\n", (void *)&pcb[1]);
  //printf("pcb0 + 1 is %p\n", (void*)(&pcb[0] + 1));
  yield();
  panic("Should not reach here!");
}
