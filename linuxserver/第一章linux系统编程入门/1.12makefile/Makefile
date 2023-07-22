# $(CC):gcc  $(CXX):g++  $@:目标  $^:所有依赖  $<:第一个依赖

#定义变量
# add.c sub.c main.c mult.c div.
# 该函数的功能是返回所有匹配的文件名，若有多个，空格隔开
src=$(wildcard ./*.c)

# !!! 注意！！！ 之间用 , 分隔
# 到第三个 $(src) 中去找匹配第一个的,匹配上了,将其转为第二个,返回
# 注意区别 % 和 * , % 匹配的是任意长度的字符串,前后是一致的
objs=$(patsubst %.c, %.o, $(src))

target=app
$(target):$(objs)
#	$(CC) $(objs) -o $(target)
	$(CC) $^ -o $@

# !!! 注意这里的 -o 和 -c
%.o:%.c
	$(CC) -c $< -o $@

# 格式是这样的，第二个clean不能省
.PHONY:clean
clean:
	rm $(objs) -f
