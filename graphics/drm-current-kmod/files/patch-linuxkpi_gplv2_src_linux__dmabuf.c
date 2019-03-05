--- linuxkpi/gplv2/src/linux_dmabuf.c.orig	2019-03-05 11:03:24 UTC
+++ linuxkpi/gplv2/src/linux_dmabuf.c
@@ -139,7 +139,8 @@ dma_buf_fill_kinfo(struct file *fp, struct kinfo_file 
 static int
 dma_buf_mmap_fileops(struct file *fp, vm_map_t map, vm_offset_t *addr,
 	     vm_size_t size, vm_prot_t prot, vm_prot_t cap_maxprot,
-	     int flags, vm_ooffset_t foff, struct thread *td)
+	     int flags, vm_ooffset_t foff, struct thread *td,
+             struct metaio *miop)
 {
 	struct dma_buf *db;
 	struct vm_area_struct vma;
