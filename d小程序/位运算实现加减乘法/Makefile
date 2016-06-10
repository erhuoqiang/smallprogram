vpath %.c src
#VPATH := ./src:./
XXX = hahah

ifeq (hahah,$(XXX))
	XXX =aaa
endif 
xiao:xiao.o;gcc -o $@  $^            
#	gcc xiao.o -o xiao

xiao.o:%.o:%.c 
	gcc -c $^
 
#使用VPATH 或直vpath的时候只是在目标文件和依赖文件上添加路径	
#在gcc指令的操作文件上是不会加的，所以在指令中需要用$@ $^代替
.PHONY:clean all 
	#.PHONY的目的是声明不管是否有文件和clean同名，这个目标就是当伪目标
clean:
	-rm    *.o  xiao
all:one  three two
one:
	echo $(XXX)
two:
	echo two
three:
	echo three
