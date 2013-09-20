
DST=../../mruby_binding/cocos2dx_support
TARGETS=$(DST)/MrubyCocos2d.cpp \
        $(DST)/MrubyCocosDenshion.cpp \
        $(DST)/MrubyBox2D.cpp \

all:	$(TARGETS)

$(DST)/MrubyCocos2d.cpp:  MrubyCocos2d.pkg
	ruby tomruby.rb $< > $@

$(DST)/MrubyCocosDenshion.cpp:  MrubyCocosDenshion.pkg
	ruby tomruby.rb $< > $@

$(DST)/MrubyBox2D.cpp:  MrubyBox2D.pkg
	ruby tomruby.rb $< > $@
