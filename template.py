import sys
import os
import shutil

# 创建CMakelists
def createMakeLists(srcfile,destfile,srcstr,deststr):
    if not os.path.exists(destfile):
        with open(srcfile,mode='r') as fr,open(destfile,mode='w') as fd:
            for line in fr:
                fd.write(line.replace(srcstr,deststr))
    else:
        pass

if len(sys.argv)>1:
    name=sys.argv[1]
    pwd=os.getcwd()
    # 创建文件夹
    destdir=os.path.join(pwd,name)
    if not os.path.exists(destdir):
        os.mkdir(destdir)
    # 创建同名cpp文件
    cppfile= "{}/{}.cpp".format(destdir,name)
    if not os.path.exists(cppfile):
        fd=open(cppfile,'w')
        fd.close()
    # 创建readme
    readmefile="{}/readme.md".format(destdir)
    if not os.path.exists(readmefile):
        fd=open(readmefile,'w')
        fd.close()
    # 创建CMakeLists
    srcfile=os.path.join(pwd,"template.txt")
    destfile=os.path.join(destdir,"CMakeLists.txt")
    createMakeLists(srcfile,destfile,"HelloWorld",name)

    # 追加CMakeLists add_subdirectory
    cmakefile=os.path.join(pwd,"CMakeLists.txt")
    strcontent="add_subdirectory({})".format(name)
    with open(cmakefile,'a') as fd:
        fd.write(strcontent)
else:
    print("请输入至少一个参数！")

