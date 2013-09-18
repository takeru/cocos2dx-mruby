

#ifndef __MRUBYCOCOS2D_H_
#define __MRUBYCOCOS2D_H_

#include "mruby.h"

void installMrubyCocos2dBindings(mrb_state *mrb);

int registerProc(mrb_state *mrb, mrb_value proc);
mrb_value getRegisteredProc(mrb_state *mrb, int id);

#endif // __MRUBYCOCOS2D_H_
