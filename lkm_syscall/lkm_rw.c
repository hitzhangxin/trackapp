#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
#include <asm/uaccess.h>
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("my track module");
MODULE_AUTHOR("zhanganzhen");
#define MAX_TRACK_LENGTH       PAGE_SIZE
static struct proc_dir_entry *proc_entry;
static char *kernel_buffer;  // Space for strings（track data）
static int write_index;  // Index to write next fortune
static int read_index;  // Index to read next fortune
//the init function will be called when track module is installed
int init_track_module( void )
{
  int ret = 0;
  kernel_buffer = (char *)vmalloc( MAX_TRACK_LENGTH );
  if (! kernel_buffer ) {
    ret = -ENOMEM;
  } else {
else {
    memset(  kernel_buffer , 0, MAX_TRACK_LENGTH );// apply for memory 
    track_entry = create_proc_entry( "track", 0644, NULL );// new a file
    if (track_entry == NULL) {
      ret = -ENOMEM;
      vfree(kernel_buffer );
      printk(KERN_INFO "track: Couldn't create proc entry\n");
    } else {
      write_index = 0;
      read_index = 0;
      track_entry->read_proc = track_read; // set read function
      track_entry->write_proc = track_write; // set write function
      track_entry->owner = THIS_MODULE;
      printk(KERN_INFO "track: Module loaded.\n");
    }
  }
  return ret;
}
// this function will be called when unsmode is called
void cleanup_track_module( void )
{
  remove_proc_entry("track", &proc_root);
  vfree(kernel_buffer);  // free the memory
  printk(KERN_INFO "track: Module unloaded.\n");
}

module_init( init_track_module );
module_exit( cleanup_track_module );
      
// the new write function, write the kernel buffer with the user buffer contents
ssize_t track_write( struct file *filp, const char __user *buff,
                        unsigned long len, void *data )
{
  int space_available = (MAX_TRACK_LENGTH-write_index)+1;
  if (len > space_available) {
    printk(KERN_INFO "track: buffer is full!\n");
    return -ENOSPC;
  }
  if (copy_from_user( &kernelbuffer[write_index], buff, len )) {// copy from the user space 
    return -EFAULT;
  }
  write_index += len;
  kernelbuffer[write_index-1] = 0;
  return len;
}

// read the kernel buffer contents, and transfer to usr buffer.
int track_read( char *page, char **start, off_t off,
                   int count, int *eof, void *data )
{
  int len;
  if (off > 0) {
    *eof = 1;
    return 0;
  }
  /* Wrap-around */
  if (write_index >= cookie_index) write_index  = 0;
  len = sprintf(page, "%s\n", &kernelbuffer[write_index ]);
  write_index  += len;
  return len;
}




