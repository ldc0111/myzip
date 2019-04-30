# myzip

projict---+--build

​                |---bin

​                |---include

​                |---lib

​                |---samples

​                |---src

build/:项目编译目录，各种编译的临时文件和最终的目标文件皆存于此，分为debug/和release/子目录

include/:公共头文件目录，可以按模块划分组织目录来保存模块相关头文件

samples/:样例程序目录

Makefile:项目构建配置文件，当然也有可能是其他类型的构建配置文件,比如bjam

README:项目的总体说明文件

src //存放源代码