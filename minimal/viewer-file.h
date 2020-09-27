#ifndef __VIEWER_FILE_H__
#define __VIEWER_FILE_H__

#include <glib-object.h>

G_BEGIN_DECLS

/*
 * type declaration.
 */
#define VIEWER_TYPE_FILE viewer_file_get_type ()

// Following macro creates: VIEWER_FILE(obj), VIEWER_FILE_CLASS(klass), VIEWER_IS_FILE(obj), VIEWER_IS_FILE_CLASS(klass), VIEWER_FILE_GET_CLASS(obj)
// Also, the class structure is created, ViewerFileClass -- why in header?
G_DECLARE_FINAL_TYPE(ViewerFile, viewer_file, VIEWER, FILE, GObject)

/*
 * method defn.
 */
ViewerFile *viewer_file_new(void);

G_END_DECLS

#endif /* __VIEWER_FILE_H__ */
