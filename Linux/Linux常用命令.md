## Linux常用命令


工作目录切换命令

    pwd: 显示用户当前所处的工作目录
    ls:显示当前目录下文件列表
    cd 文件夹名: 进入文件夹
    mkdir 文件夹名: 新建文件夹
    rmdir 文件夹名: 删除文件夹
    touch : 新建文件
    code 文件名: 使用编辑器编辑打开文件
    rm 文件名: 删除文件
    mv 旧文件名 新文件名: 文件重命名
    
    cp a.js b.js: 将a.js复制为b.js
    
    cd或cd ~: 返回根目录
    cd ..: 返回上一级目录
    ls -l: 显示文件和目录的详细资料
    ls -a: 显示隐藏文件
    
    tar -c: 创建压缩文件
    tar -x: 解压缩文件
    
文本文件编辑命令

    cat : 查看文件内容
    more : 查看长文本文件
    
    
常用系统指令
    
    echo : 打印字符串或变量
    date : 显示或设置系统时间
    reboot: 重启系统
    poweroff: 关闭系统
    wget : 下载网络文件
    ps : 查看系统中的进程状态
    top: 动态监视系统进程和系统负载
    pidof : 查询某个指定服务进程的PID
    kill : 终止某个PID的进程
    killall : 终止某个指定名称的服务
    
系统状态指令

    ifconfig: 获取网卡配置与网络状态信息
    uname -a: 查看系统内核与版本信息
    uptime: 查看系统负载信息
    free -h: 查看系统内存使用量信息
    who: 查看当前登入主机的用户终端信息
    last: 查看系统登录记录
    history: 查看历史执行过的命令
    history -c: 清除历史命令记录
    
    
杂项

    read -p "提示语" 变量名: 向用户展示提示语并赋值给变量(可通过$变量名读取)
    
    at 时间: 在指定时间执行一次性的任务
    at -l: 查看所有计划任务
    atrm 任务id: 移除指定任务
    
    
用户权限

    id : 查看当前用户id信息
    useradd : 添加用户
    groupadd : 创建用户组
    usermod : 修改用户属性
    passwd : 修改用户密码认证信息等
    userdel : 删除用户
    
    
