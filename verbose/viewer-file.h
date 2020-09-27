#ifndef __VIEWER_FILE_H__
#define __VIEWER_FILE_H__

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _ViewerFile ViewerFile;
typedef struct _ViewerFileClass ViewerFileClass;

GType viewer_file_get_type (void);

/*
 * conv macros
 */
#define VIEWER_TYPE_FILE viewer_file_get_type()
#define VIEWER_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VIEWER_TYPE_FILE, ViewerFile))
#define VIEWER_IS_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VIEWER_TYPE_FILE))
#define VIEWER_IS_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VIEWER_TYPE_FILE))
#define VIEWER_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), VIEWER_TYPE_FILE, ViewerFileClass))
/*
 * method defn.
 */
ViewerFile *viewer_file_new(void);

G_END_DECLS

#endif /* __VIEWER_FILE_H__ */
